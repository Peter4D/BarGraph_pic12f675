/* 
 * File:   hw_timer0.h
 * Author: Peter
 *
 * Created on 24. april 2019, 22:01
 */

#ifndef HW_TIMER0_H
#define	HW_TIMER0_H

#include <stdint.h>
#include <pic12f675.h>

#ifdef	__cplusplus
extern "C" {
#endif

    typedef enum
    {
        TIMER0_PRSC_2   = (uint8_t)0x00, 
        TIMER0_PRSC_4   = (uint8_t)0x01,
        TIMER0_PRSC_8   = (uint8_t)0x02,
        TIMER0_PRSC_16  = (uint8_t)0x03,
        TIMER0_PRSC_32  = (uint8_t)0x04,
        TIMER0_PRSC_64  = (uint8_t)0x05,
        TIMER0_PRSC_128 = (uint8_t)0x06,
        TIMER0_PRSC_256 = (uint8_t)0x07
    }eTimer0_prsc_t;
    
    void hw_timer0_setup(eTimer0_prsc_t prsc);
    uint8_t hw_timer0_get_OF_bit(void);



#ifdef	__cplusplus
}
#endif

#endif	/* HW_TIMER0_H */

