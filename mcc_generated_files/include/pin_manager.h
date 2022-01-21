/**
  @Company
    Microchip Technology Inc.

  @Description
    This Source file provides APIs.
    Generation Information :
    Driver Version    :   1.0.0
*/
/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PINS_H_INCLUDED
#define PINS_H_INCLUDED

#include <avr/io.h>
#include "port.h"

//get/set PWM0 aliases
#define PWM0_SetHigh() do { PORTD |= 0x20; } while(0)
#define PWM0_SetLow() do { PORTD &= ~0x20; } while(0)
#define PWM0_Toggle() do { PIND |= 0x20; } while(0)
#define PWM0_GetValue() (PIND & (0x1 << 5))
#define PWM0_SetDigitalInput() do { DDRD &= ~0x20; } while(0)
#define PWM0_SetDigitalOutput() do { DDRD |= 0x20; } while(0)
#define PWM0_SetPullUp() do { PORTD |= 0x20; } while(0)
#define PWM0_ResetPullUp() do { PORTD &= ~0x20; } while(0)
#define PWM0_SetInverted() do { PORTD_PIN5CTRL  |= PORT_INVEN_bm; } while(0)
#define PWM0_ResetInverted() do { PORTD_PIN5CTRL  &= ~PORT_INVEN_bm; } while(0)

//get/set PC4_SDA aliases
#define PC4_SDA_SetHigh() do { PORTC |= 0x10; } while(0)
#define PC4_SDA_SetLow() do { PORTC &= ~0x10; } while(0)
#define PC4_SDA_Toggle() do { PINC |= 0x10; } while(0)
#define PC4_SDA_GetValue() (PINC & (0x1 << 4))
#define PC4_SDA_SetDigitalInput() do { DDRC &= ~0x10; } while(0)
#define PC4_SDA_SetDigitalOutput() do { DDRC |= 0x10; } while(0)
#define PC4_SDA_SetPullUp() do { PORTC |= 0x10; } while(0)
#define PC4_SDA_ResetPullUp() do { PORTC &= ~0x10; } while(0)
#define PC4_SDA_SetInverted() do { PORTC_PIN4CTRL  |= PORT_INVEN_bm; } while(0)
#define PC4_SDA_ResetInverted() do { PORTC_PIN4CTRL  &= ~PORT_INVEN_bm; } while(0)

//get/set PWM1 aliases
#define PWM1_SetHigh() do { PORTD |= 0x40; } while(0)
#define PWM1_SetLow() do { PORTD &= ~0x40; } while(0)
#define PWM1_Toggle() do { PIND |= 0x40; } while(0)
#define PWM1_GetValue() (PIND & (0x1 << 6))
#define PWM1_SetDigitalInput() do { DDRD &= ~0x40; } while(0)
#define PWM1_SetDigitalOutput() do { DDRD |= 0x40; } while(0)
#define PWM1_SetPullUp() do { PORTD |= 0x40; } while(0)
#define PWM1_ResetPullUp() do { PORTD &= ~0x40; } while(0)
#define PWM1_SetInverted() do { PORTD_PIN6CTRL  |= PORT_INVEN_bm; } while(0)
#define PWM1_ResetInverted() do { PORTD_PIN6CTRL  &= ~PORT_INVEN_bm; } while(0)

//get/set PC5_SCL aliases
#define PC5_SCL_SetHigh() do { PORTC |= 0x20; } while(0)
#define PC5_SCL_SetLow() do { PORTC &= ~0x20; } while(0)
#define PC5_SCL_Toggle() do { PINC |= 0x20; } while(0)
#define PC5_SCL_GetValue() (PINC & (0x1 << 5))
#define PC5_SCL_SetDigitalInput() do { DDRC &= ~0x20; } while(0)
#define PC5_SCL_SetDigitalOutput() do { DDRC |= 0x20; } while(0)
#define PC5_SCL_SetPullUp() do { PORTC |= 0x20; } while(0)
#define PC5_SCL_ResetPullUp() do { PORTC &= ~0x20; } while(0)
#define PC5_SCL_SetInverted() do { PORTC_PIN5CTRL  |= PORT_INVEN_bm; } while(0)
#define PC5_SCL_ResetInverted() do { PORTC_PIN5CTRL  &= ~PORT_INVEN_bm; } while(0)

//get/set NTC0 aliases
#define NTC0_SetHigh() do { PORTC |= 0x1; } while(0)
#define NTC0_SetLow() do { PORTC &= ~0x1; } while(0)
#define NTC0_Toggle() do { PINC |= 0x1; } while(0)
#define NTC0_GetValue() (PINC & (0x1 << 0))
#define NTC0_SetDigitalInput() do { DDRC &= ~0x1; } while(0)
#define NTC0_SetDigitalOutput() do { DDRC |= 0x1; } while(0)
#define NTC0_SetPullUp() do { PORTC |= 0x1; } while(0)
#define NTC0_ResetPullUp() do { PORTC &= ~0x1; } while(0)
#define NTC0_SetInverted() do { PORTC_PIN0CTRL  |= PORT_INVEN_bm; } while(0)
#define NTC0_ResetInverted() do { PORTC_PIN0CTRL  &= ~PORT_INVEN_bm; } while(0)

//get/set FREQ_CAPTURE aliases
#define FREQ_CAPTURE_SetHigh() do { PORTB |= 0x1; } while(0)
#define FREQ_CAPTURE_SetLow() do { PORTB &= ~0x1; } while(0)
#define FREQ_CAPTURE_Toggle() do { PINB |= 0x1; } while(0)
#define FREQ_CAPTURE_GetValue() (PINB & (0x1 << 0))
#define FREQ_CAPTURE_SetDigitalInput() do { DDRB &= ~0x1; } while(0)
#define FREQ_CAPTURE_SetDigitalOutput() do { DDRB |= 0x1; } while(0)
#define FREQ_CAPTURE_SetPullUp() do { PORTB |= 0x1; } while(0)
#define FREQ_CAPTURE_ResetPullUp() do { PORTB &= ~0x1; } while(0)
#define FREQ_CAPTURE_SetInverted() do { PORTB_PIN0CTRL  |= PORT_INVEN_bm; } while(0)
#define FREQ_CAPTURE_ResetInverted() do { PORTB_PIN0CTRL  &= ~PORT_INVEN_bm; } while(0)

//get/set IO_PC1 aliases
#define IO_PC1_SetHigh() do { PORTC |= 0x2; } while(0)
#define IO_PC1_SetLow() do { PORTC &= ~0x2; } while(0)
#define IO_PC1_Toggle() do { PINC |= 0x2; } while(0)
#define IO_PC1_GetValue() (PINC & (0x1 << 1))
#define IO_PC1_SetDigitalInput() do { DDRC &= ~0x2; } while(0)
#define IO_PC1_SetDigitalOutput() do { DDRC |= 0x2; } while(0)
#define IO_PC1_SetPullUp() do { PORTC |= 0x2; } while(0)
#define IO_PC1_ResetPullUp() do { PORTC &= ~0x2; } while(0)
#define IO_PC1_SetInverted() do { PORTC_PIN1CTRL  |= PORT_INVEN_bm; } while(0)
#define IO_PC1_ResetInverted() do { PORTC_PIN1CTRL  &= ~PORT_INVEN_bm; } while(0)

void PIN_MANAGER_Initialize();
#endif /* PINS_H_INCLUDED */
