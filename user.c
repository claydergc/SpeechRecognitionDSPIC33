/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

/* Device header file */
#if defined(__XC16__)
    #include <xc.h>
#elif defined(__C30__)
    #if defined(__dsPIC33E__)
    	#include <p33Exxxx.h>
    #elif defined(__dsPIC33F__)
    	#include <p33Fxxxx.h>
    #endif
#endif

#include <stdint.h>          /* For uint16_t definition                       */
#include <stdbool.h>         /* For true/false definition                     */
#include <delay.h>
#include "user.h"            /* variables/params used by user.c               */



/******************************************************************************/
/* User Functions                                                             */
/******************************************************************************/

/* <Initialize variables in user.h and insert code for user algorithms.> */

void InitApp(void)
{
    /* TODO Initialize User Ports/Peripherals/Project here */
    /* Set port configuration */


    //TRISA = 0x0000;
    //PORTA = 0xFFFF;

    ANSELA = ANSELB = 0x0000;
    ANSELBbits.ANSB0 = 1; // Ensure AN0/RB0 is analog
    ANSELBbits.ANSB1 = 1; // Ensure AN1/RB1 is analog
    ANSELBbits.ANSB2 = 1; // Ensure AN2/RB2 is analog
    ANSELAbits.ANSA0 = 1; // Ensure AN5/RB5 is analog
    /* Initialize and enable ADC module */
    AD1CON1 = 0x000C; // Enable simultaneous sampling and auto-sample
    AD1CON2 = 0x0300; // Sample 4 channels
    AD1CON3 = 0x000F;
    AD1CON4 = 0x0000;
    AD1CSSH = 0x0000;
    AD1CSSL = 0x0000;
    AD1CHS0bits.CH0SA = 5; // Select AN5 for CH0 +ve input
    AD1CHS0bits.CH0NA = 0; // Select Vref- for CH0 -ve input
    AD1CHS123bits.CH123SA = 0; // Select AN0 for CH1 +ve input
    // Select AN1 for CH2 +ve input
    // Select AN2 for CH3 +ve input
    AD1CHS123bits.CH123NA = 0; // Select Vref- for CH1/CH2/CH3 -ve inputs
    AD1CON1bits.ADON = 1;
    /* Setup analog functionality and port direction */

    /* Initialize peripherals */
}

void initADC(void)
{
    ANSELA = 0x0000;
    ANSELAbits.ANSA0 = 1; // Ensure AN0/RA0 is analog

    /* Initialize and enable ADC module */
    
    //AD1CON1 = 0x0704; //Signed fractional
    AD1CON1 = 0x0404; //Unsigned integer

    AD1CON2 = 0x0000;
    AD1CON3 = 0x000F;
    AD1CON4 = 0x0000;
    AD1CHS123 = 0x0000;
    AD1CHS0 = 0x0000; //Select AN0
    AD1CSSH = 0x0000;
    AD1CSSL = 0x0000;
    AD1CON1bits.ADON = 1;
    __delay_us(20);
}

void __delay_us(unsigned int delay)
{
    int i;

    for (i = 0; i < delay; i++)
    {
        __asm__ volatile ("repeat #39");
        __asm__ volatile ("nop");
    }
}

void __delay_ms(unsigned int delay)
{
    int i;

    for (i = 0; i < 1000; i++)
        __delay_us(delay);
}