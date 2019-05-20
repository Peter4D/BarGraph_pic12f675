/* 
 * File:   main.c
 * Author: Peter
 *
 * Created on 24. april 2019, 0:12
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
//#include <pic12f675.h>

#include <htc.h>

#include "GPIO_driver.h"

#include "hw_timer0.h"
#include "interrupt.h"

#define TIMER0_1S_CONST         (242u)
#define TIMER0_0_5S_CONST       (121u)


__CONFIG(FOSC_INTRCIO & WDTE_OFF & PWRTE_OFF & MCLRE_ON & BOREN_ON & CP_OFF & CPD_OFF);


void delay_blk(uint16_t delay_cnt);


void tmr0_sw_intHandler(void)
{
    static uint8_t timer0_cnt = 0;
    timer0_cnt--;
    if(timer0_cnt == 0) {
        //timer0_cnt = TIMER0_1S_CONST;
        timer0_cnt = TIMER0_0_5S_CONST;
        gpio_write(GPIO_PIN_4_Msk, GPIO_TOGGLE); 
    }
}


void delay_blk(uint16_t delay_cnt)
{
    while(delay_cnt){
        delay_cnt--;
    }
}

/*
 * 
 */
int main(int argc, char** argv) {
    
    static uint8_t gpio_state = (1<<4);
    
    gpio_init(GPIO_PIN_4_Msk, GPIO_OUTPUT);
    intr_tmr0_en();
    hw_timer0_setup(TIMER0_PRSC_8);
    
    while(1)
    { 
       //gpio_write(GPIO_PIN_4_Msk, GPIO_TOGGLE);
       //delay_blk(20000);
       
        //GPIObits.GP4 = 0;
        //delay_blk(20000);
        //GPIObits.GP4 = 1;
        //delay_blk(10000); 
        //GPIObits.GP4 = !GPIObits.GP4; 
        
        // if(hw_timer0_get_OF_bit()) {
        //     timer0_cnt--;
        //     if(timer0_cnt == 0) {
        //         timer0_cnt = TIMER0_1S_CONST;
        //         gpio_write(GPIO_PIN_4_Msk, GPIO_TOGGLE); 
        //     }
        // }
        
    }
    return (EXIT_SUCCESS);
}

