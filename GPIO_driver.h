/* 
 * File:   GPIO_driver.h
 * Author: Peter
 *
 * Created on 24. april 2019, 23:56
 */

#ifndef GPIO_DRIVER_H
#define	GPIO_DRIVER_H

#include <stdint.h>

#ifdef	__cplusplus
extern "C" {
#endif


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

typedef enum {
    GPIO_INPUT,
    GPIO_OUTPUT,
    GPIO_PULL
}eGPIO_mode_t;


void gpio_init(GPIO_pin_msk_t pin_msk, eGPIO_mode_t mode);
void gpio_write(GPIO_pin_msk_t pin_msk, eGPIO_write_t GPIO_write);



#ifdef	__cplusplus
}
#endif

#endif	/* GPIO_DRIVER_H */

