/******************************************************************************
 * Module: PWM Driver
 *
 * File Name: pwm.h
 *
 * Description: header file for the pwm driver
 *
 * Author: Abdelhamid Tarek
 *
 *******************************************************************************/

#ifndef PWM_H_
#define PWM_H_
#include "std_types.h"
/*******************************************************************************
 *                      DEFINITIONS                                  *
 *******************************************************************************/
#define PWM_PORT_ID      PORTB_ID
#define PWM_PIN_ID       PIN3_ID
#define PWM_TIMER0_MAXIMUM_VALUE  255


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void PWM_Timer0_Start(uint8 duty_cycle);


#endif /* PWM_H_ */
