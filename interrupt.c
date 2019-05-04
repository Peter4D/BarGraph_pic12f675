#include "interrupt.h"

#include <stdint.h>
#include <pic12f675.h>

/* 1010 0000  [GIE|TMR0IE] */
#define INTCON_TMR0_SETUP_Msk      (0xA0)

void intr_tmr0_en(void)
{
    // firt clear bits that we will change
    INTCON &= (~INTCON_TMR0_SETUP_Msk);
    INTCON |= (INTCON_TMR0_SETUP_Msk);
}


void interrupt pic_isr(void)
{
    // only process timer-triggered interrupts
    if(INTCONbits.TMR0IE && INTCONbits.TMR0IF) {
        //portValue++;
        tmr0_sw_intHandler();
        INTCONbits.TMR0IF = 0;  // clear this interrupt condition
    }
}
