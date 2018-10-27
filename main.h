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

/*  Device address locations taken from KSDK_1.3.0 device driver examples
*	Provided by NXP
*/
    /* Flash Status Register (FSTAT)*/
    #define FTFx_SSD_FSTAT_OFFSET               0x00000000U
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
    F_ACCERR = -2, /* attempt to read while program in progress */
    F_FPVIOL = -1, /* attempt to program a protected flash area */
    F_NO_ERROR = 0 /* success */
} ferr_t;





///////////////////////////////////////////////////////////////////
// Function Prototypes
///////////////////////////////////////////////////////////////////

ferr_t fprogram( uint32_t *address, uint32_t data );

#endif // __MAIN__