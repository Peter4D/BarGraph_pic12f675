/* 
 * File:   main.c
 * Author: Peter
 *
 * Created on 24. april 2019, 0:12
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <pic12f675.h>

#include <htc.h>

#include "hw_timer0.h"
#include "interrupt.h"

#define TIMER0_1S_CONST     (242u)
#define GPIO_PIN4_msk       (1 << 4)

#define GPIO_PIN_0_Val      (0u)
#define GPIO_PIN_1_Val      (1u)
#define GPIO_PIN_2_Val      (2u)
#define GPIO_PIN_3_Val      (3u)
#define GPIO_PIN_4_Val      (4u)
#define GPIO_PIN_5_Val      (5u)

typedef enum{
    GPIO_PIN_0_Msk  = (1 << GPIO_PIN_0_Val),
    GPIO_PIN_1_Msk  = (1 << GPIO_PIN_1_Val),
    GPIO_PIN_2_Msk  = (1 << GPIO_PIN_2_Val),
    GPIO_PIN_3_Msk  = (1 << GPIO_PIN_3_Val),
    GPIO_PIN_4_Msk  = (1 << GPIO_PIN_4_Val),
    GPIO_PIN_5_Msk  = (1 << GPIO_PIN_5_Val)
}GPIO_pin_msk_t;

typedef enum {
    GPIO_LOW,
    GPIO_HIGH,
    GPIO_TOGGLE        
}eGPIO_write_t;

__CONFIG(FOSC_INTRCIO & WDTE_OFF & PWRTE_OFF & MCLRE_ON & BOREN_ON & CP_OFF & CPD_OFF);



void gpio_init(GPIO_pin_msk_t pin_msk);
void gpio_write(GPIO_pin_msk_t pin_msk, eGPIO_write_t GPIO_write);

void delay_blk(uint16_t delay_cnt);

/*
 * GLOBAL VARIABLES:
 */
static uint8_t timer0_cnt = TIMER0_1S_CONST;

void gpio_init(GPIO_pin_msk_t pin_msk){
    TRISIO &= (~pin_msk);
    GPIO &= (~pin_msk);
}

void gpio_write(GPIO_pin_msk_t pin_msk, eGPIO_write_t GPIO_write)
{
    static uint8_t GPIO_state = 0x00;
    
    if(GPIO_write == GPIO_HIGH){
        GPIO_state |= (pin_msk);
    }else if(GPIO_write == GPIO_LOW){
        GPIO_state &= (~pin_msk);
    }else if(GPIO_write == GPIO_TOGGLE){
        GPIO_state ^= (pin_msk);
    }
    GPIO = GPIO_state;
}

void tmr0_sw_intHandler(void)
{
    // timer0_cnt--;
    // if(timer0_cnt == 0) {
    //     timer0_cnt = TIMER0_1S_CONST;
    //     gpio_write(GPIO_PIN_4_Msk, GPIO_TOGGLE); 
    // }
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
    
    gpio_init(GPIO_PIN_4_Msk);
//    intr_tmr0_en();
    hw_timer0_setup(TIMER0_PRSC_16);
    
    while(1)
    { 
       //gpio_write(GPIO_PIN_4_Msk, GPIO_TOGGLE);
       //delay_blk(20000);
       
        //GPIObits.GP4 = 0;
        //delay_blk(20000);
        //GPIObits.GP4 = 1;
        //delay_blk(10000); 
        //GPIObits.GP4 = !GPIObits.GP4; 
        
        if(hw_timer0_get_OF_bit()) {
            timer0_cnt--;
            if(timer0_cnt == 0) {
                timer0_cnt = TIMER0_1S_CONST;
                gpio_write(GPIO_PIN_4_Msk, GPIO_TOGGLE); 
            }
        }
        
    }
    return (EXIT_SUCCESS);
}

