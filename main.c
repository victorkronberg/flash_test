/******************************************************************************************
* Copyright (C) 2018 by Victor Kronberg
*
* Redistribution, modification or use of this software in source or binary forms is 
* permitted as long as files maintain this copyright. Laura Gong and the University
* of Colorado are not liable for any misuse of this material.
*
*******************************************************************************************
/**
* @file main.c
* @brief This file implements the write function
*
* The write function is used for writing a 32-bit word to the flash of a FRDM-KL25Z board
*
* @author: Victor Kronberg
* @date October 27 2018
* @version 1.0
* 
* @compiler: GNU GCC
*
*/

void main (void)
{

}

ferr_t fprogram( uint32_t *address, uint32_t data )
{
	if(!address)
	{
		return F_NULLPTR;
	}
	
	FLASH_SSD_CONFIG flashSSDConfig = 
	{
	FTFx_REG_BASE,          /*! FTFx control register base address */
    P_FLASH_BASE,           /*! Base address of PFlash block */
    P_FLASH_SIZE,           /*! Size of PFlash block */
	}
	uint32_t temp;
	
	//check that write is within flash address space
	temp = flashSSDConfig->P_FLASH_BASE + flashSSDConfig->P_FLASH_SIZE;
	if (address > temp)
	{
		return F_OUTOFRANGE;
	}
	
	//Wait for previous command to finish
	//NOTE: need to deal with volatile before porting to HW
	//NEED TO HANDLE ERROR SITUATION
	temp = flashSSDConfig->P_FLASH_BASE + FTFx_SSD_FSTAT_OFFSET;
	while(!REG_BIT_GET(temp,FFTx_CCIF));
	
	temp = (flashSSDConfig->P_FLASH_BASE) + FTFx_SSD_FSTAT_OFFSET;
	uint8_t Fstatus = REG_READ(temp);
	
	//Check ACCERR and FPVIOL - if violation, clear bit and return error generated from previous command
	if(GET_BIT(Fstatus,FTFx_ACCERR))
	{
		temp = flashSSDConfig->P_FLASH_BASE + FTFx_SSD_FSTAT_OFFSET;
		REG_BIT_SET(temp,FTFx_ACCERR);
		return F_ACCERR;
	}
	
	if(GET_BIT(Fstatus,FTFx_PVIOL))
	{
		temp = flashSSDConfig->P_FLASH_BASE + FTFx_SSD_FSTAT_OFFSET;
		REG_BIT_SET(temp,FTFx_PVIOL);
		return F_FPVIOL;
	}
	
	//Write program command in FCCOB CMD register
	temp = flashSSDConfig->P_FLASH_BASE + FTFx_SSD_FCCOB0_OFFSET;
	REG_WRITE(temp,CMD_PROGRAM_LONGWORD);
	
	//Write address to FCCOB address registers
	temp = flashSSDConfig->P_FLASH_BASE + FTFx_SSD_FCCOB3_OFFSET;
	REG_WRITE(temp,GET_BIT_0_7(address));
	temp = flashSSDConfig->P_FLASH_BASE + FTFx_SSD_FCCOB2_OFFSET;
	REG_WRITE(temp,GET_BIT_8_15(address));
	temp = flashSSDConfig->P_FLASH_BASE + FTFx_SSD_FCCOB1_OFFSET;
	REG_WRITE(temp,GET_BIT_16_23(address));
	
	//Write 32 bit data to FCCOB's first 4 8-bit data registers
	temp = flashSSDConfig->P_FLASH_BASE + FTFx_SSD_FCCOB4_OFFSET;
	REG_WRITE(temp,GET_BIT_0_7(data));
	temp = flashSSDConfig->P_FLASH_BASE + FTFx_SSD_FCCOB5_OFFSET;
	REG_WRITE(temp,GET_BIT_8_15(data));
	temp = flashSSDConfig->P_FLASH_BASE + FTFx_SSD_FCCOB6_OFFSET;
	REG_WRITE(temp,GET_BIT_16_23(data));
	temp = flashSSDConfig->P_FLASH_BASE + FTFx_SSD_FCCOB7_OFFSET;
	REG_WRITE(temp,GET_BIT_24_31(data));
	
	//Clear CCIF (write 0x80 to FSTAT)
	temp = flashSSDConfig->P_FLASH_BASE + FTFx_SSD_FSTAT_OFFSET;
	REG_BIT_SET(temp, FFTx_CCIF)
	
	return F_NO_ERROR;
	
}