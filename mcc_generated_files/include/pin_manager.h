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

//get/set PD5 aliases
#define PD5_SetHigh() do { PORTD |= 0x20; } while(0)
#define PD5_SetLow() do { PORTD &= ~0x20; } while(0)
#define PD5_Toggle() do { PIND |= 0x20; } while(0)
#define PD5_GetValue() (PIND & (0x1 << 5))
#define PD5_SetDigitalInput() do { DDRD &= ~0x20; } while(0)
#define PD5_SetDigitalOutput() do { DDRD |= 0x20; } while(0)
#define PD5_SetPullUp() do { PORTD |= 0x20; } while(0)
#define PD5_ResetPullUp() do { PORTD &= ~0x20; } while(0)
#define PD5_SetInverted() do { PORTD_PIN5CTRL  |= PORT_INVEN_bm; } while(0)
#define PD5_ResetInverted() do { PORTD_PIN5CTRL  &= ~PORT_INVEN_bm; } while(0)

<<<<<<< HEAD
//get/set PB2 aliases
#define PB2_SetHigh() do { PORTB |= 0x4; } while(0)
#define PB2_SetLow() do { PORTB &= ~0x4; } while(0)
#define PB2_Toggle() do { PINB |= 0x4; } while(0)
#define PB2_GetValue() (PINB & (0x1 << 2))
#define PB2_SetDigitalInput() do { DDRB &= ~0x4; } while(0)
#define PB2_SetDigitalOutput() do { DDRB |= 0x4; } while(0)
#define PB2_SetPullUp() do { PORTB |= 0x4; } while(0)
#define PB2_ResetPullUp() do { PORTB &= ~0x4; } while(0)
#define PB2_SetInverted() do { PORTB_PIN2CTRL  |= PORT_INVEN_bm; } while(0)
#define PB2_ResetInverted() do { PORTB_PIN2CTRL  &= ~PORT_INVEN_bm; } while(0)

//get/set PB1 aliases
#define PB1_SetHigh() do { PORTB |= 0x2; } while(0)
#define PB1_SetLow() do { PORTB &= ~0x2; } while(0)
#define PB1_Toggle() do { PINB |= 0x2; } while(0)
#define PB1_GetValue() (PINB & (0x1 << 1))
#define PB1_SetDigitalInput() do { DDRB &= ~0x2; } while(0)
#define PB1_SetDigitalOutput() do { DDRB |= 0x2; } while(0)
#define PB1_SetPullUp() do { PORTB |= 0x2; } while(0)
#define PB1_ResetPullUp() do { PORTB &= ~0x2; } while(0)
#define PB1_SetInverted() do { PORTB_PIN1CTRL  |= PORT_INVEN_bm; } while(0)
#define PB1_ResetInverted() do { PORTB_PIN1CTRL  &= ~PORT_INVEN_bm; } while(0)

//get/set PB0 aliases
#define PB0_SetHigh() do { PORTB |= 0x1; } while(0)
#define PB0_SetLow() do { PORTB &= ~0x1; } while(0)
#define PB0_Toggle() do { PINB |= 0x1; } while(0)
#define PB0_GetValue() (PINB & (0x1 << 0))
#define PB0_SetDigitalInput() do { DDRB &= ~0x1; } while(0)
#define PB0_SetDigitalOutput() do { DDRB |= 0x1; } while(0)
#define PB0_SetPullUp() do { PORTB |= 0x1; } while(0)
#define PB0_ResetPullUp() do { PORTB &= ~0x1; } while(0)
#define PB0_SetInverted() do { PORTB_PIN0CTRL  |= PORT_INVEN_bm; } while(0)
#define PB0_ResetInverted() do { PORTB_PIN0CTRL  &= ~PORT_INVEN_bm; } while(0)
=======
//get/set PD6 aliases
#define PD6_SetHigh() do { PORTD |= 0x40; } while(0)
#define PD6_SetLow() do { PORTD &= ~0x40; } while(0)
#define PD6_Toggle() do { PIND |= 0x40; } while(0)
#define PD6_GetValue() (PIND & (0x1 << 6))
#define PD6_SetDigitalInput() do { DDRD &= ~0x40; } while(0)
#define PD6_SetDigitalOutput() do { DDRD |= 0x40; } while(0)
#define PD6_SetPullUp() do { PORTD |= 0x40; } while(0)
#define PD6_ResetPullUp() do { PORTD &= ~0x40; } while(0)
#define PD6_SetInverted() do { PORTD_PIN6CTRL  |= PORT_INVEN_bm; } while(0)
#define PD6_ResetInverted() do { PORTD_PIN6CTRL  &= ~PORT_INVEN_bm; } while(0)
>>>>>>> main

void PIN_MANAGER_Initialize();
#endif /* PINS_H_INCLUDED */
