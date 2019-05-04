#include "hw_timer0.h"


void hw_timer0_setup(eTimer0_prsc_t prsc)
{

   /* write to separate bits of register seems NOT to work !
    you need to write whole regester at once !!
    */ 
//    OPTION_REGbits.PS0 = 1;
//    OPTION_REGbits.PS1 = 1;
//    OPTION_REGbits.PS2 = 1;
//    OPTION_REGbits.PS = 0;

    /* clear prescaler bits */
    //OPTION_REG &= (~prsc);
    OPTION_REG &= (~0x03);
    /* set prescaler bits*/
    //OPTION_REG |= (prsc);
    OPTION_REG |= (0x03);

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