#include "hw_timer0.h"


#define OPTION_REG_PRSC_Msk         (0x07u)

void hw_timer0_setup(eTimer0_prsc_t prsc)
{
    TMR0 = 0x00;
    OPTION_REG = 0;
    //OPTION_REGbits.T0CS = 1;
    /* clear prescaler bits */
    OPTION_REG &= (~OPTION_REG_PRSC_Msk);
    /* set prescaler bits*/
    OPTION_REG |= (prsc);
    //OPTION_REGbits.T0CS = 0;

    //OPTION_REG = 0x03; // this set prescaler to 16

}

uint8_t hw_timer0_get_OF_bit(void)
{
    if(INTCONbits.T0IF){
        INTCONbits.T0IF = 0;
        return 1;
    }else {
        return 0;
    }
}