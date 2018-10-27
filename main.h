/******************************************************************************************
* Copyright (C) 2018 by Victor Kronberg
*
* Redistribution, modification or use of this software in source or binary forms is 
* permitted as long as files maintain this copyright. Laura Gong and the University
* of Colorado are not liable for any misuse of this material.
*
*******************************************************************************************
/**
* @file main.h
* @brief An abstraction for the write to flash function
*
* This header file provides an abstraction of the write command
*
* @author: Victor Kronberg
* @date October 27 2018
* @version 1.0
* 
* @compiler: GNU GCC
*
*/

#ifndef __MAIN__
#define __MAIN__

#include <stdint.h>

/*  Device address locations taken from KSDK_1.3.0 C90TFS device driver examples and features header
*	Provided by NXP
*/
	/* Longword size */
	#define FTFx_LONGWORD_SIZE					0x0004U     /* 4 bytes */
	/* Flash memory module register base address */
	#define FTFx_REG_BASE             0x40020000
	#define P_FLASH_BASE              0x00000000
	/* @brief P-Flash start address. */
    #define FSL_FEATURE_FLASH_PFLASH_START_ADDRESS (0x00000000)
    /* @brief P-Flash block count. */
    #define FSL_FEATURE_FLASH_PFLASH_BLOCK_COUNT (1)
    /* @brief P-Flash block size. */
    #define FSL_FEATURE_FLASH_PFLASH_BLOCK_SIZE (131072)
    /* @brief P-Flash sector size. */
    #define FSL_FEATURE_FLASH_PFLASH_BLOCK_SECTOR_SIZE (1024)
    /* @brief P-Flash write unit size. */
    #define FSL_FEATURE_FLASH_PFLASH_BLOCK_WRITE_UNIT_SIZE (4)
	
	// Program Flash block information
	#define P_FLASH_SIZE            (FSL_FEATURE_FLASH_PFLASH_BLOCK_SIZE * FSL_FEATURE_FLASH_PFLASH_BLOCK_COUNT)
	#define P_BLOCK_NUM             FSL_FEATURE_FLASH_PFLASH_BLOCK_COUNT
	#define P_SECTOR_SIZE           FSL_FEATURE_FLASH_PFLASH_BLOCK_SECTOR_SIZE
	
    /* Flash Status Register (FSTAT)*/
    #define FTFx_SSD_FSTAT_OFFSET               0x00000000U
	#define FFTx_CCIF							0x0080U
	#define FTFx_ACCERR							0x0020U
	#define FTFx_PVIOL							0x0010U
    /* Flash configuration register (FCNFG)*/
    #define FTFx_SSD_FCNFG_OFFSET               0x00000001U
    /* Flash security register (FSEC) */
    #define FTFx_SSD_FSEC_OFFSET                0x00000002U
    /* Flash Option Register (FOPT) */
    #define FTFx_SSD_FOPT_OFFSET                0x00000003U
    /* Flash common command object registers (FCCOB0-B) */
    #define FTFx_SSD_FCCOB0_OFFSET              0x00000007U
    #define FTFx_SSD_FCCOB1_OFFSET              0x00000006U
    #define FTFx_SSD_FCCOB2_OFFSET              0x00000005U
    #define FTFx_SSD_FCCOB3_OFFSET              0x00000004U
    #define FTFx_SSD_FCCOB4_OFFSET              0x0000000BU
    #define FTFx_SSD_FCCOB5_OFFSET              0x0000000AU
    #define FTFx_SSD_FCCOB6_OFFSET              0x00000009U
    #define FTFx_SSD_FCCOB7_OFFSET              0x00000008U
    #define FTFx_SSD_FCCOB8_OFFSET              0x0000000FU
    #define FTFx_SSD_FCCOB9_OFFSET              0x0000000EU
    #define FTFx_SSD_FCCOBA_OFFSET              0x0000000DU
    #define FTFx_SSD_FCCOBB_OFFSET              0x0000000CU
	#define CMD_PROGRAM_LONGWORD				0x0006U
    /* P-Flash protection registers (FPROT0-3) */
    #define FTFx_SSD_FPROT0_OFFSET              0x00000013U
    #define FTFx_SSD_FPROT1_OFFSET              0x00000012U
    #define FTFx_SSD_FPROT2_OFFSET              0x00000011U
    #define FTFx_SSD_FPROT3_OFFSET              0x00000010U
    /* D-Flash protection registers (FDPROT) */
    #define FTFx_SSD_FDPROT_OFFSET              0x00000017U
    /* EERAM Protection Register (FEPROT)  */
    #define FTFx_SSD_FEPROT_OFFSET              0x00000016U
    /* P-Flash Flash Access Controller XAC regisers (XACCH0-3, XACCL0-3) */
    #define FTFx_SSD_XACCH0_OFFSET              0x0000001BU
    #define FTFx_SSD_XACCH1_OFFSET              0x0000001AU
    #define FTFx_SSD_XACCH2_OFFSET              0x00000019U
    #define FTFx_SSD_XACCH3_OFFSET              0x00000018U
    #define FTFx_SSD_XACCL0_OFFSET              0x0000001FU
    #define FTFx_SSD_XACCL1_OFFSET              0x0000001EU
    #define FTFx_SSD_XACCL2_OFFSET              0x0000001DU
    #define FTFx_SSD_XACCL3_OFFSET              0x0000001CU
    /* P-Flash Flash Access Controller SAC regisers (SACCH0-3, SACCL0-3) */
    #define FTFx_SSD_SACCH0_OFFSET              0x00000023U
    #define FTFx_SSD_SACCH1_OFFSET              0x00000022U
    #define FTFx_SSD_SACCH2_OFFSET              0x00000021U
    #define FTFx_SSD_SACCH3_OFFSET              0x00000020U
    #define FTFx_SSD_SACCL0_OFFSET              0x00000027U
    #define FTFx_SSD_SACCL1_OFFSET              0x00000026U
    #define FTFx_SSD_SACCL2_OFFSET              0x00000025U
    #define FTFx_SSD_SACCL3_OFFSET              0x00000024U

    /* P-Flash Access Segment Size register (FACSS) */
    #define FTFx_SSD_FACSS_OFFSET               0x00000028U
    /* P-Flash Access Segment Number register (FACSN) */
    #define FTFx_SSD_FACSN_OFFSET               0x0000002BU

typedef enum {
    /* add error codes here as needed */
	F_OUTOFRANGE = -4;	/*Attempt to write outside of memory range */
	F_NULLPTR = -3, 	/* Null address pointer passed */
    F_ACCERR = -2, 		/* attempt to read while program in progress */
    F_FPVIOL = -1, 		/* attempt to program a protected flash area */
    F_NO_ERROR = 0 		/* success */
} ferr_t;

/*-------------- Read/Write/Set/Clear Operation Macros -----------------*/
/*	Adapted from NXP's KSDK_1.3.0 C90TFS driver examples 
*/
#define REG_BIT_SET(address, mask)      (*(uint8_t*)(address) |= (mask))
#define REG_BIT_CLEAR(address, mask)    (*(uint8_t*)(address) &= ~(mask))
#define REG_BIT_GET(address, mask)      (*(uint8_t *)(address) & (uint8_t)(mask))
#define REG_WRITE(address, value)       (*(uint8_t*)(address) = (value))
#define REG_READ(address)               ((*(uint8_t*)(address)))

#define GET_BIT(value,mask)				((uint8_t)(value) & (uint8_t)(mask))

#define GET_BIT_0_7(value)              ((uint8_t)((value) & 0xFFU))
#define GET_BIT_8_15(value)             ((uint8_t)(((value)>>8) & 0xFFU))
#define GET_BIT_16_23(value)            ((uint8_t)(((value)>>16) & 0xFFU))
#define GET_BIT_24_31(value)            ((uint8_t)((value)>>24))

/*---------------- Flash SSD Configuration Structure -------------------*/
/*! @brief Flash SSD Configuration Structure
*	Taken from NXP's KSDK_1.3.0 C90TFS Device driver examples
*
* The structure includes the static parameters for  C90TFS/FTFx  which are
* device-dependent. The user should correctly initialize the fields including
* ftfxRegBase, PFlashBlockBase, PFlashBlockSize, DFlashBlockBase, EERAMBlockBase,
* DebugEnable and CallBack before passing the structure to SSD functions.
* The rest of parameters such as DFlashBlockSize, and EEEBlockSize will be
* initialized in FlashInit() automatically. The pointer to CallBack has to be
* initialized either for null callback or a valid call back function.
*
*/
typedef struct _ssd_config
{
    uint32_t      ftfxRegBase;        /*!< The  register  base address of  C90TFS/FTFx */
    uint32_t      PFlashBase;         /*!< The base address of P-Flash memory */
    uint32_t      PFlashSize;         /*!< The size in byte of P-Flash memory */
	
} FLASH_SSD_CONFIG, *PFLASH_SSD_CONFIG;


///////////////////////////////////////////////////////////////////
// Function Prototypes
///////////////////////////////////////////////////////////////////

ferr_t fprogram( uint32_t *address, uint32_t data );

#endif // __MAIN__