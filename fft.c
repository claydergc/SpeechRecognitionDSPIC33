/**********************************************************************
* � 2005 Microchip Technology Inc.
*
* FileName:        twiddleFactors.c
* Dependencies:    Header (.h) files if applicable, see below
* Processor:       dsPIC30Fxxxx
* Compiler:        MPLAB� C30 v1.33.00 or higher
* IDE:             MPLAB� IDE v7.20.01 or later
* Dev. Board Used: dsPICDEM 1.1 Development Board
* Hardware Dependencies: None
*
* SOFTWARE LICENSE AGREEMENT:
* Microchip Technology Inc. (�Microchip�) licenses this software to you
* solely for use with Microchip dsPIC� digital signal controller
* products. The software is owned by Microchip and is protected under
* applicable copyright laws.  All rights reserved.
*
* SOFTWARE IS PROVIDED �AS IS.�  MICROCHIP EXPRESSLY DISCLAIMS ANY
* WARRANTY OF ANY KIND, WHETHER EXPRESS OR IMPLIED, INCLUDING BUT NOT
* LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
* PARTICULAR PURPOSE, OR NON-INFRINGEMENT. IN NO EVENT SHALL MICROCHIP
* BE LIABLE FOR ANY INCIDENTAL, SPECIAL, INDIRECT OR CONSEQUENTIAL
* DAMAGES, LOST PROFITS OR LOST DATA, HARM TO YOUR EQUIPMENT, COST OF
* PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY OR SERVICES, ANY CLAIMS
* BY THIRD PARTIES (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF),
* ANY CLAIMS FOR INDEMNITY OR CONTRIBUTION, OR OTHER SIMILAR COSTS.
*
* REVISION HISTORY:
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Author            Date      Comments on this revision
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* HV               09/30/05  First release of source file
*
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*
* ADDITIONAL NOTES:
*
*
**********************************************************************/

#include <dsp.h>
#include "fft.h"

#ifdef FFTTWIDCOEFFS_IN_PROGMEM

#if (FFT_BLOCK_LENGTH == 64)
        const fractcomplex twiddleFactors[] __attribute__ ((space(auto_psv), aligned (FFT_BLOCK_LENGTH*2)))=
        {
        0x7FFF, 0x0000, 0x7F62, 0xF374, 0x7D8A, 0xE707, 0x7A7D, 0xDAD8,
        0x7642, 0xCF04, 0x70E3, 0xC3A9, 0x6A6E, 0xB8E3, 0x62F2, 0xAECC,
        0x5A82, 0xA57E, 0x5134, 0x9D0E, 0x471D, 0x9592, 0x3C57, 0x8F1D,
        0x30FC, 0x89BE, 0x2528, 0x8583, 0x18F9, 0x8276, 0x0C8C, 0x809E,
        0x0000, 0x8000, 0xF374, 0x809E, 0xE707, 0x8276, 0xDAD8, 0x8583,
        0xCF04, 0x89BE, 0xC3A9, 0x8F1D, 0xB8E3, 0x9592, 0xAECC, 0x9D0E,
        0xA57D, 0xA57D, 0x9D0E, 0xAECC, 0x9592, 0xB8E3, 0x8F1D, 0xC3A9,
        0x89BE, 0xCF04, 0x8583, 0xDAD8, 0x8276, 0xE707, 0x809E, 0xF374
        } ;
#endif
#if (FFT_BLOCK_LENGTH == 128)
        const fractcomplex twiddleFactors[] __attribute__ ((space(auto_psv), aligned (FFT_BLOCK_LENGTH*2)))=
        {
        0x7FFF, 0x0000, 0x7FD9, 0xF9B8, 0x7F62, 0xF374, 0x7E9D, 0xED38,
        0x7D8A, 0xE707, 0x7C2A, 0xE0E6, 0x7A7D, 0xDAD8, 0x7885, 0xD4E1,
        0x7642, 0xCF04, 0x73B6, 0xC946, 0x70E3, 0xC3A9, 0x6DCA, 0xBE32,
        0x6A6E, 0xB8E3, 0x66D0, 0xB3C0, 0x62F2, 0xAECC, 0x5ED7, 0xAA0A,
        0x5A82, 0xA57E, 0x55F6, 0xA129, 0x5134, 0x9D0E, 0x4C40, 0x9930,
        0x471D, 0x9592, 0x41CE, 0x9236, 0x3C57, 0x8F1D, 0x36BA, 0x8C4A,
        0x30FC, 0x89BE, 0x2B1F, 0x877B, 0x2528, 0x8583, 0x1F1A, 0x83D6,
        0x18F9, 0x8276, 0x12C8, 0x8163, 0x0C8C, 0x809E, 0x0648, 0x8027,
        0x0000, 0x8000, 0xF9B8, 0x8027, 0xF374, 0x809E, 0xED38, 0x8163,
        0xE707, 0x8276, 0xE0E6, 0x83D6, 0xDAD8, 0x8583, 0xD4E1, 0x877C,
        0xCF04, 0x89BE, 0xC946, 0x8C4A, 0xC3A9, 0x8F1D, 0xBE32, 0x9236,
        0xB8E3, 0x9592, 0xB3C0, 0x9931, 0xAECC, 0x9D0E, 0xAA0A, 0xA129,
        0xA57E, 0xA57E, 0xA129, 0xAA0A, 0x9D0E, 0xAECC, 0x9931, 0xB3C0,
        0x9592, 0xB8E3, 0x9236, 0xBE32, 0x8F1D, 0xC3A9, 0x8C4A, 0xC946,
        0x89BE, 0xCF04, 0x877C, 0xD4E1, 0x8583, 0xDAD8, 0x83D6, 0xE0E6,
        0x8276, 0xE707, 0x8163, 0xED38, 0x809E, 0xF374, 0x8027, 0xF9B8
        } ;
#endif
#if (FFT_BLOCK_LENGTH == 256)
        const fractcomplex twiddleFactors[] __attribute__ ((space(auto_psv), aligned (FFT_BLOCK_LENGTH*2))) =
        {
        0x7FFF, 0x0000, 0x7FF6, 0xFCDC, 0x7FD9, 0xF9B8, 0x7FA7, 0xF695,
        0x7F62, 0xF374, 0x7F0A, 0xF055, 0x7E9D, 0xED38, 0x7E1E, 0xEA1E,
        0x7D8A, 0xE707, 0x7CE4, 0xE3F4, 0x7C2A, 0xE0E6, 0x7B5D, 0xDDDC,
        0x7A7D, 0xDAD8, 0x798A, 0xD7D9, 0x7884, 0xD4E1, 0x776C, 0xD1EF,
        0x7642, 0xCF04, 0x7505, 0xCC21, 0x73B6, 0xC946, 0x7255, 0xC673,
        0x70E3, 0xC3A9, 0x6F5F, 0xC0E9, 0x6DCA, 0xBE32, 0x6C24, 0xBB85,
        0x6A6E, 0xB8E3, 0x68A7, 0xB64C, 0x66CF, 0xB3C0, 0x64E8, 0xB140,
        0x62F2, 0xAECC, 0x60EC, 0xAC65, 0x5ED7, 0xAA0A, 0x5CB4, 0xA7BD,
        0x5A82, 0xA57E, 0x5843, 0xA34C, 0x55F6, 0xA129, 0x539B, 0x9F14,
        0x5134, 0x9D0E, 0x4EC0, 0x9B18, 0x4C40, 0x9931, 0x49B4, 0x9759,
        0x471D, 0x9592, 0x447B, 0x93DC, 0x41CE, 0x9236, 0x3F17, 0x90A1,
        0x3C57, 0x8F1D, 0x398D, 0x8DAB, 0x36BA, 0x8C4A, 0x33DF, 0x8AFB,
        0x30FC, 0x89BE, 0x2E11, 0x8894, 0x2B1F, 0x877C, 0x2827, 0x8676,
        0x2528, 0x8583, 0x2224, 0x84A3, 0x1F1A, 0x83D6, 0x1C0B, 0x831C,
        0x18F9, 0x8276, 0x15E2, 0x81E3, 0x12C8, 0x8163, 0x0FAB, 0x80F7,
        0x0C8C, 0x809E, 0x096B, 0x8059, 0x0648, 0x8028, 0x0324, 0x800A,
        0x7FFF, 0x0000, 0x7FF6, 0xFCDC, 0x7FD9, 0xF9B8, 0x7FA7, 0xF695,
        0x7F62, 0xF374, 0x7F0A, 0xF055, 0x7E9D, 0xED38, 0x7E1E, 0xEA1E,
        0x7D8A, 0xE707, 0x7CE4, 0xE3F4, 0x7C2A, 0xE0E6, 0x7B5D, 0xDDDC,
        0x7A7D, 0xDAD8, 0x798A, 0xD7D9, 0x7884, 0xD4E1, 0x776C, 0xD1EF,
        0x7642, 0xCF04, 0x7505, 0xCC21, 0x73B6, 0xC946, 0x7255, 0xC673,
        0x70E3, 0xC3A9, 0x6F5F, 0xC0E9, 0x6DCA, 0xBE32, 0x6C24, 0xBB85,
        0x6A6E, 0xB8E3, 0x68A7, 0xB64C, 0x66CF, 0xB3C0, 0x64E8, 0xB140,
        0x62F2, 0xAECC, 0x60EC, 0xAC65, 0x5ED7, 0xAA0A, 0x5CB4, 0xA7BD,
        0x5A82, 0xA57E, 0x5843, 0xA34C, 0x55F6, 0xA129, 0x539B, 0x9F14,
        0x5134, 0x9D0E, 0x4EC0, 0x9B18, 0x4C40, 0x9931, 0x49B4, 0x9759,
        0x471D, 0x9592, 0x447B, 0x93DC, 0x41CE, 0x9236, 0x3F17, 0x90A1,
        0x3C57, 0x8F1D, 0x398D, 0x8DAB, 0x36BA, 0x8C4A, 0x33DF, 0x8AFB,
        0x30FC, 0x89BE, 0x2E11, 0x8894, 0x2B1F, 0x877C, 0x2827, 0x8676,
        0x2528, 0x8583, 0x2224, 0x84A3, 0x1F1A, 0x83D6, 0x1C0B, 0x831C,
        0x18F9, 0x8276, 0x15E2, 0x81E3, 0x12C8, 0x8163, 0x0FAB, 0x80F7,
        0x0C8C, 0x809E, 0x096B, 0x8059, 0x0648, 0x8028, 0x0324, 0x800A,
        0x0000, 0x8000, 0xFCDC, 0x800A, 0xF9B8, 0x8028, 0xF695, 0x8059,
        0xF374, 0x809E, 0xF055, 0x80F7, 0xED38, 0x8163, 0xEA1E, 0x81E3,
        0xE707, 0x8276, 0xE3F5, 0x831C, 0xE0E6, 0x83D6, 0xDDDC, 0x84A3,
        0xDAD8, 0x8583, 0xD7D9, 0x8676, 0xD4E1, 0x877C, 0xD1EF, 0x8894,
        0xCF04, 0x89BE, 0xCC21, 0x8AFB, 0xC946, 0x8C4A, 0xC673, 0x8DAB,
        0xC3A9, 0x8F1D, 0xC0E9, 0x90A1, 0xBE32, 0x9236, 0xBB85, 0x93DC,
        0xB8E3, 0x9593, 0xB64C, 0x975A, 0xB3C0, 0x9931, 0xB140, 0x9B18,
        0xAECC, 0x9D0E, 0xAC65, 0x9F14, 0xAA0A, 0xA129, 0xA7BD, 0xA34C,
        0xA57E, 0xA57E, 0xA34C, 0xA7BD, 0xA129, 0xAA0A, 0x9F14, 0xAC65,
        0x9D0E, 0xAECC, 0x9B18, 0xB140, 0x9931, 0xB3C0, 0x975A, 0xB64C,
        0x9593, 0xB8E3, 0x93DC, 0xBB85, 0x9236, 0xBE32, 0x90A1, 0xC0E9,
        0x8F1D, 0xC3A9, 0x8DAB, 0xC673, 0x8C4A, 0xC946, 0x8AFB, 0xCC21,
        0x89BF, 0xCF04, 0x8894, 0xD1EF, 0x877C, 0xD4E1, 0x8676, 0xD7D9,
        0x8583, 0xDAD8, 0x84A3, 0xDDDC, 0x83D6, 0xE0E6, 0x831C, 0xE3F5,
        0x8276, 0xE707, 0x81E3, 0xEA1E, 0x8163, 0xED38, 0x80F7, 0xF055,
        0x809E, 0xF374, 0x8059, 0xF695, 0x8028, 0xF9B8, 0x800A, 0xFCDC
        } ;
#endif
#if (FFT_BLOCK_LENGTH == 512 )
        const fractcomplex twiddleFactors[] __attribute__ ((space(auto_psv), aligned (FFT_BLOCK_LENGTH*2*2))) =
        {
        0x7FFF, 0x0000, 0x7FFE, 0xFE6E, 0x7FF6, 0xFCDC, 0x7FEA, 0xFB4A,
        0x7FD9, 0xF9B8, 0x7FC2, 0xF827, 0x7FA7, 0xF695, 0x7F87, 0xF505,
        0x7F62, 0xF374, 0x7F38, 0xF1E4, 0x7F0A, 0xF055, 0x7ED6, 0xEEC6,
        0x7E9D, 0xED38, 0x7E60, 0xEBAB, 0x7E1E, 0xEA1E, 0x7DD6, 0xE892,
        0x7D8A, 0xE707, 0x7D3A, 0xE57D, 0x7CE4, 0xE3F4, 0x7C89, 0xE26D,
        0x7C2A, 0xE0E6, 0x7BC6, 0xDF61, 0x7B5D, 0xDDDC, 0x7AEF, 0xDC59,
        0x7A7D, 0xDAD8, 0x7A06, 0xD958, 0x798A, 0xD7D9, 0x790A, 0xD65C,
        0x7885, 0xD4E1, 0x77FB, 0xD367, 0x776C, 0xD1EF, 0x76D9, 0xD079,
        0x7642, 0xCF04, 0x75A6, 0xCD92, 0x7505, 0xCC21, 0x7460, 0xCAB2,
        0x73B6, 0xC946, 0x7308, 0xC7DB, 0x7255, 0xC673, 0x719E, 0xC50D,
        0x70E3, 0xC3A9, 0x7023, 0xC248, 0x6F5F, 0xC0E9, 0x6E97, 0xBF8C,
        0x6DCA, 0xBE32, 0x6CF9, 0xBCDA, 0x6C24, 0xBB85, 0x6B4B, 0xBA33,
        0x6A6E, 0xB8E3, 0x698C, 0xB796, 0x68A7, 0xB64C, 0x67BD, 0xB505,
        0x66D0, 0xB3C0, 0x65DE, 0xB27F, 0x64E9, 0xB140, 0x63EF, 0xB005,
        0x62F2, 0xAECC, 0x61F1, 0xAD97, 0x60EC, 0xAC65, 0x5FE4, 0xAB36,
        0x5ED8, 0xAA0A, 0x5DC8, 0xA8E2, 0x5CB4, 0xA7BD, 0x5B9D, 0xA69C,
        0x5A83, 0xA57E, 0x5964, 0xA463, 0x5843, 0xA34C, 0x571E, 0xA238,
        0x55F6, 0xA128, 0x54CA, 0xA01C, 0x539B, 0x9F14, 0x5269, 0x9E0F,
        0x5134, 0x9D0E, 0x4FFB, 0x9C11, 0x4EC0, 0x9B17, 0x4D81, 0x9A22,
        0x4C40, 0x9930, 0x4AFB, 0x9843, 0x49B4, 0x9759, 0x486A, 0x9674,
        0x471D, 0x9592, 0x45CD, 0x94B5, 0x447B, 0x93DC, 0x4326, 0x9307,
        0x41CE, 0x9236, 0x4074, 0x9169, 0x3F17, 0x90A1, 0x3DB8, 0x8FDD,
        0x3C57, 0x8F1D, 0x3AF3, 0x8E62, 0x398D, 0x8DAB, 0x3825, 0x8CF8,
        0x36BA, 0x8C4A, 0x354E, 0x8BA0, 0x33DF, 0x8AFB, 0x326E, 0x8A5A,
        0x30FC, 0x89BE, 0x2F87, 0x8927, 0x2E11, 0x8894, 0x2C99, 0x8805,
        0x2B1F, 0x877B, 0x29A4, 0x86F6, 0x2827, 0x8676, 0x26A8, 0x85FA,
        0x2528, 0x8583, 0x23A7, 0x8511, 0x2224, 0x84A3, 0x209F, 0x843A,
        0x1F1A, 0x83D6, 0x1D93, 0x8377, 0x1C0C, 0x831C, 0x1A83, 0x82C6,
        0x18F9, 0x8276, 0x176E, 0x822A, 0x15E2, 0x81E2, 0x1455, 0x81A0,
        0x12C8, 0x8163, 0x113A, 0x812A, 0x0FAB, 0x80F6, 0x0E1C, 0x80C8,
        0x0C8C, 0x809E, 0x0AFB, 0x8079, 0x096B, 0x8059, 0x07D9, 0x803E,
        0x0648, 0x8027, 0x04B6, 0x8016, 0x0324, 0x800A, 0x0192, 0x8002,
        0x0000, 0x8000, 0xFE6E, 0x8002, 0xFCDC, 0x800A, 0xFB4A, 0x8016,
        0xF9B8, 0x8027, 0xF827, 0x803E, 0xF695, 0x8059, 0xF505, 0x8079,
        0xF374, 0x809E, 0xF1E4, 0x80C8, 0xF055, 0x80F6, 0xEEC6, 0x812A,
        0xED38, 0x8163, 0xEBAB, 0x81A0, 0xEA1E, 0x81E2, 0xE892, 0x822A,
        0xE707, 0x8276, 0xE57D, 0x82C6, 0xE3F4, 0x831C, 0xE26D, 0x8377,
        0xE0E6, 0x83D6, 0xDF61, 0x843A, 0xDDDC, 0x84A3, 0xDC59, 0x8511,
        0xDAD8, 0x8583, 0xD958, 0x85FA, 0xD7D9, 0x8676, 0xD65C, 0x86F6,
        0xD4E1, 0x877B, 0xD367, 0x8805, 0xD1EF, 0x8894, 0xD079, 0x8927,
        0xCF04, 0x89BE, 0xCD92, 0x8A5A, 0xCC21, 0x8AFB, 0xCAB2, 0x8BA0,
        0xC946, 0x8C4A, 0xC7DB, 0x8CF8, 0xC673, 0x8DAB, 0xC50D, 0x8E62,
        0xC3A9, 0x8F1D, 0xC248, 0x8FDD, 0xC0E9, 0x90A1, 0xBF8C, 0x9169,
        0xBE32, 0x9236, 0xBCDA, 0x9307, 0xBB85, 0x93DC, 0xBA33, 0x94B5,
        0xB8E3, 0x9592, 0xB796, 0x9674, 0xB64C, 0x9759, 0xB505, 0x9843,
        0xB3C0, 0x9930, 0xB27F, 0x9A22, 0xB140, 0x9B17, 0xB005, 0x9C11,
        0xAECC, 0x9D0E, 0xAD97, 0x9E0F, 0xAC65, 0x9F14, 0xAB36, 0xA01C,
        0xAA0A, 0xA128, 0xA8E2, 0xA238, 0xA7BD, 0xA34C, 0xA69C, 0xA463,
        0xA57D, 0xA57D, 0xA463, 0xA69C, 0xA34C, 0xA7BD, 0xA238, 0xA8E2,
        0xA128, 0xAA0A, 0xA01C, 0xAB36, 0x9F14, 0xAC65, 0x9E0F, 0xAD97,
        0x9D0E, 0xAECC, 0x9C11, 0xB005, 0x9B17, 0xB140, 0x9A22, 0xB27F,
        0x9930, 0xB3C0, 0x9843, 0xB504, 0x9759, 0xB64C, 0x9674, 0xB796,
        0x9592, 0xB8E3, 0x94B5, 0xBA33, 0x93DC, 0xBB85, 0x9307, 0xBCDA,
        0x9236, 0xBE32, 0x9169, 0xBF8C, 0x90A1, 0xC0E9, 0x8FDD, 0xC248,
        0x8F1D, 0xC3A9, 0x8E62, 0xC50D, 0x8DAB, 0xC673, 0x8CF8, 0xC7DB,
        0x8C4A, 0xC946, 0x8BA0, 0xCAB2, 0x8AFB, 0xCC21, 0x8A5A, 0xCD92,
        0x89BE, 0xCF04, 0x8927, 0xD079, 0x8894, 0xD1EF, 0x8805, 0xD367,
        0x877B, 0xD4E1, 0x86F6, 0xD65C, 0x8676, 0xD7D9, 0x85FA, 0xD958,
        0x8583, 0xDAD8, 0x8510, 0xDC59, 0x84A3, 0xDDDC, 0x843A, 0xDF61,
        0x83D6, 0xE0E6, 0x8377, 0xE26D, 0x831C, 0xE3F4, 0x82C6, 0xE57D,
        0x8275, 0xE707, 0x8229, 0xE892, 0x81E2, 0xEA1E, 0x81A0, 0xEBAB,
        0x8163, 0xED38, 0x812A, 0xEEC6, 0x80F6, 0xF055, 0x80C8, 0xF1E4,
        0x809E, 0xF374, 0x8079, 0xF505, 0x8059, 0xF695, 0x803E, 0xF827,
        0x8027, 0xF9B8, 0x8016, 0xFB4A, 0x800A, 0xFCDC, 0x8002, 0xFE6E
        } ;
#endif

fractcomplex sigCmpx[FFT_BLOCK_LENGTH] __attribute__ ((section (".ydata, data, ymemory"), aligned (FFT_BLOCK_LENGTH * 2 *2))) =
{
0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
0x8001, 0x8001, 0x8001, 0x8001, 0x8001,
0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
0x8001, 0x8001, 0x8001, 0x8001, 0x8001,
0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
0x8001, 0x8001, 0x8001, 0x8001, 0x8001,
0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
0x8001, 0x8001, 0x8001, 0x8001, 0x8001,
0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
0x8001, 0x8001, 0x8001, 0x8001, 0x8001,
0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
0x8001, 0x8001, 0x8001, 0x8001, 0x8001,
0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
0x8001, 0x8001, 0x8001, 0x8001, 0x8001,
0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
0x8001, 0x8001, 0x8001, 0x8001, 0x8001,
0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
0x8001, 0x8001, 0x8001, 0x8001, 0x8001,
0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
0x8001, 0x8001, 0x8001, 0x8001, 0x8001,
0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
0x8001, 0x8001, 0x8001, 0x8001, 0x8001,
0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
0x8001, 0x8001, 0x8001, 0x8001, 0x8001,
0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
0x8001, 0x8001, 0x8001, 0x8001, 0x8001,
0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
0x8001, 0x8001, 0x8001, 0x8001, 0x8001,
0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
0x8001, 0x8001, 0x8001, 0x8001, 0x8001,
0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
0x8001, 0x8001, 0x8001, 0x8001, 0x8001,
0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
0x8001, 0x8001, 0x8001, 0x8001, 0x8001,
0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
0x8001, 0x8001, 0x8001, 0x8001, 0x8001,
0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
0x8001, 0x8001, 0x8001, 0x8001, 0x8001,
0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
0x8001, 0x8001, 0x8001, 0x8001, 0x8001,
0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
0x8001, 0x8001, 0x8001, 0x8001, 0x8001,
0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
0x8001, 0x8001, 0x8001, 0x8001, 0x8001,
0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
0x8001, 0x8001, 0x8001, 0x8001, 0x8001,
0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
0x8001, 0x8001, 0x8001, 0x8001, 0x8001,
0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF,
0x8001, 0x8001, 0x8001, 0x8001, 0x8001,
0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x7FFF, 0x8001,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
0x0000, 0x0000, 0x0000, 0x0000
};

const fractional hmFactors1[] __attribute__ ((space(auto_psv)))=
{
 	0x0,0x39F3,0x73E5,0x59B4,0x294D,0x0
};

const fractional hmFactors2[] __attribute__ ((space(auto_psv)))=
{
 	0x0,0x264B,0x56B2,0x7A11,0x51A3,0x2935,0xC7
};

const fractional hmFactors3[] __attribute__ ((space(auto_psv)))=
{
 	0x5EE,0x2E5C,0x56CA,0x7F38,0x5EE1,0x3D1C,0x1B57,0x0
};

const fractional hmFactors4[] __attribute__ ((space(auto_psv)))=
{
 	0x0,0x211E,0x42E3,0x64A8,0x7AA0,0x5E6C,0x4237,0x2602,0x9CD
};

const fractional hmFactors5[] __attribute__ ((space(auto_psv)))=
{
 	0x55F,0x2193,0x3DC8,0x59FD,0x7632,0x70A0,0x5911,0x4181,0x29F2,0x1263,
	0x0
};

const fractional hmFactors6[] __attribute__ ((space(auto_psv)))=
{
 	0x0,0xF5F,0x26EE,0x3E7E,0x560D,0x6D9C,0x7BAD,0x67FF,0x5451,0x40A3,
	0x2CF6,0x1948,0x59A
};

const fractional hmFactors7[] __attribute__ ((space(auto_psv)))=
{
 	0x452,0x1800,0x2BAE,0x3F5C,0x5309,0x66B7,0x7A65,0x743D,0x63CD,0x535D,
	0x42ED,0x327E,0x220E,0x119E,0x12E
};

const fractional hmFactors8[] __attribute__ ((space(auto_psv)))=
{
 	0x0,0xBC2,0x1C32,0x2CA2,0x3D12,0x4D81,0x5DF1,0x6E61,0x7ED1,0x7340,
	0x6586,0x57CB,0x4A10,0x3C56,0x2E9B,0x20E0,0x1325,0x56B
};

const fractional hmFactors9[] __attribute__ ((space(auto_psv)))=
{
 	0x0,0xCBF,0x1A79,0x2834,0x35EF,0x43A9,0x5164,0x5F1F,0x6CDA,0x7A94,
	0x790E,0x6D96,0x621E,0x56A6,0x4B2F,0x3FB7,0x343F,0x28C7,0x1D50,0x11D8,
	0x660,0x0
};

const fractional hmFactors10[] __attribute__ ((space(auto_psv)))=
{
 	0x0,0x6F1,0x1269,0x1DE1,0x2959,0x34D0,0x4048,0x4BC0,0x5738,0x62AF,
	0x6E27,0x799F,0x7BBE,0x722A,0x6896,0x5F02,0x556E,0x4BD9,0x4245,0x38B1,
	0x2F1D,0x2589,0x1BF5,0x1261,0x8CD,0x0
};

const fractional hmFactors11[] __attribute__ ((space(auto_psv)))=
{
 	0x441,0xDD5,0x1769,0x20FD,0x2A91,0x3426,0x3DBA,0x474E,0x50E2,0x5A76,
	0x640A,0x6D9E,0x7732,0x7F58,0x7758,0x6F58,0x6758,0x5F57,0x5757,0x4F57,
	0x4757,0x3F57,0x3756,0x2F56,0x2756,0x1F56,0x1756,0xF56,0x755,0x0
};

const fractional hmFactors12[] __attribute__ ((space(auto_psv)))=
{
 	0xA7,0x8A7,0x10A7,0x18A7,0x20A8,0x28A8,0x30A8,0x38A8,0x40A8,0x48A9,
	0x50A9,0x58A9,0x60A9,0x68A9,0x70A9,0x78AA,0x7F70,0x78C1,0x7213,0x6B64,
	0x64B5,0x5E06,0x5757,0x50A9,0x49FA,0x434B,0x3C9C,0x35EE,0x2F3F,0x2890,
	0x21E1,0x1B32,0x1484,0xDD5,0x726,0x77
};

const fractional hmFactors13[] __attribute__ ((space(auto_psv)))=
{
 	0x8F,0x73E,0xDEC,0x149B,0x1B4A,0x21F9,0x28A8,0x2F56,0x3605,0x3CB4,
	0x4363,0x4A11,0x50C0,0x576F,0x5E1E,0x64CD,0x6B7B,0x722A,0x78D9,0x7F88,
	0x7ACE,0x7539,0x6FA4,0x6A0F,0x647A,0x5EE5,0x5950,0x53BB,0x4E26,0x4891,
	0x42FC,0x3D67,0x37D2,0x323D,0x2CA8,0x2713,0x217E,0x1BE9,0x1654,0x10BF,
	0xB2A,0x595,0x0
};

#endif
