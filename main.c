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
	FLASH_SSD_CONFIG flashSSDConfig = 
	{
	FTFx_REG_BASE,          /*! FTFx control register base */
    P_FLASH_BASE,           /*! Base address of PFlash block */
    P_FLASH_SIZE,           /*! Size of PFlash block */
	}
}

ferr_t fprogram( uint32_t *address, uint32_t data )
{
	if(!address)
	{
		return F_NULLPTR;
	}
}