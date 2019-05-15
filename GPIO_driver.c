
#include "htc.h"
#include "GPIO_driver.h"




void gpio_init(GPIO_pin_msk_t pin_msk){

    TRISIO &= (~pin_msk);
    GPIO &= (~pin_msk);
}

void gpio_write(GPIO_pin_msk_t pin_msk, eGPIO_write_t GPIO_write)
{
    static uint8_t GPIO_state = 0x00;
    
    if(GPIO_write == GPIO_HIGH){
        GPIO_state |= (pin_msk);
        //GPIO |= (pin_msk); // this for some to me unknown reason not work 
    }else if(GPIO_write == GPIO_LOW){
        GPIO_state &= (~pin_msk);
        //GPIO &= (~pin_msk);
    }else if(GPIO_write == GPIO_TOGGLE){
        GPIO_state ^= (pin_msk);
        //GPIO ^= (pin_msk);
    }
    GPIO = GPIO_state;
}