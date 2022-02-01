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

#ifndef TC0_H_INCLUDED
#define TC0_H_INCLUDED

#include "../utils/compiler.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief Initialize TC0 interface
 *
 * \return Initialization status.
 */
    
typedef void (*TC0_cb_t)(void);    

int8_t TC0_Initialize();
void TC0_SetOVFIsrCallback(TC0_cb_t cb);
void TC0_SetCMPAIsrCallback(TC0_cb_t cb);
void TC0_SetCMPBIsrCallback(TC0_cb_t cb);
void TC0_EnableInterrupt(void);
void TC0_DisableInterrupt(void);
uint8_t TC0_ReadTimer(void);
void TC0_WriteTimer(uint8_t timerVal);
void TC0_ClearOverflowInterruptFlag(void);
bool TC0_IsOverflowInterruptEnabled(void);
//uint16_t rpmAverage(uint16_t value);

#ifdef __cplusplus
}
#endif

#endif /* TC0_H_INCLUDED */
