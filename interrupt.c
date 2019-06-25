#include "interrupt.h"

#include <stdint.h>
#include <pic12f675.h>

/* debug */
#include "GPIO_driver.h"

/* 1010 0000  [GIE|TMR0IE] */
#define INTCON_TMR0_SETUP_Msk      (0xA0)

// PIR PIE1

void intr_tmr0_en(void)
{
    INTCON = 0x00;
    // first clear bits that we will change
    INTCON &= (~INTCON_TMR0_SETUP_Msk);
    INTCON |= (INTCON_TMR0_SETUP_Msk);
}

void intr_adc_en(void) {
    INTCONbits.PEIE = 1;
    PIE1bits.ADIE = 1;
}


void interrupt pic_isr(void)
{
    // only process timer-triggered interrupts
    if(INTCONbits.TMR0IE && INTCONbits.TMR0IF) {
        //portValue++;
        tmr0_sw_intHandler();
        //tmr0_uart_intHandler();
        // #debug
        gpio_write(GPIO_PIN_2_Msk, GPIO_TOGGLE); 

        TMR0 = 155;
        INTCONbits.TMR0IF = 0;  // clear this interrupt condition
    }

    if(PIR1bits.ADIF == 1) {
        adc_sw_intHandler();
        PIR1bits.ADIF = 0; 
    }
}
