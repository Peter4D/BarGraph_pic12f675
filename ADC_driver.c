#include <pic12f675.h>

#include "ADC_driver.h"


#define ADC_ANSEL_ADCS_Pos              (4u)
#define ADC_ANSEL_ADCS_F64_Msk          (0x06u)

#define ADC_ANSEL_ANS_CH2_Pos           (2u)
#define ADC_ANSEL_ANS_CH2_Msk           (0x01u)


#define ADC_ADCON0_ADON_Msk           (0x01u)
#define ADC_ADCON0_ADGO_Msk           (0x04u)


void ADC_drv_init(void) {
    gpio_init(GPIO_PIN_2_Msk, GPIO_INPUT);
    
    ADCON0 = 0x00;
    /* select AN2 channel */
    ADCON0bits.CHS1 = 1;
    ADCON0bits.CHS0 = 0;
}

void ADC_drv_read(void) {

}

void ADC_set_AN_intput2digital(void){
    ANSEL = 0x00;
}


void adc_sw_intHandler(void){
    
}