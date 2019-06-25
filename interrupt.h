/* 
 * File:   interrupt.h
 * Author: Peter
 *
 * Created on 03. maj 2019, 21:46
 */

#ifndef INTERRUPT_H
#define	INTERRUPT_H

#ifdef	__cplusplus
extern "C" {
#endif


void intr_tmr0_en(void);

/* this function must be provided by user1 Otherwise compile error will occur */
extern void tmr0_sw_intHandler(void);
extern void adc_sw_intHandler(void);
extern void tmr0_uart_intHandler(void);


#ifdef	__cplusplus
}
#endif

#endif	/* INTERRUPT_H */

