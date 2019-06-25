#ifndef ADC_DRIVER_H
#define ADC_DRIVER_H

/* dependencies */
#include "GPIO_driver.h"


void ADC_drv_init(void);

void ADC_drv_read(void);

void ADC_set_AN_intput2digital(void);



#endif /* ADC_DRIVER_H */
