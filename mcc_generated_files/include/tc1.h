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

#ifndef TC1_H_INCLUDED
#define TC1_H_INCLUDED

#include "../utils/compiler.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief Initialize tc16 interface
 *
 * \return Initialization status.
 */
    
typedef void (*TC1_cb_t)(void);    

int8_t TC1_Initialize();
void TC1_SetOVFIsrCallback(TC1_cb_t cb);
void TC1_SetCOMPAIsrCallback(TC1_cb_t cb);
void TC1_SetCOMPBIsrCallback(TC1_cb_t cb);
void TC1_SetCAPTIsrCallback(TC1_cb_t cb);
void TC1_WriteTimer(uint16_t timerVal);
uint16_t TC1_ReadTimer(void);
void TC1_EnableInterrupt(void);
void TC1_DisableInterrupt(void);
void TC1_ClearOverflowInterruptFlag(void);
bool TC1_IsOverflowInterruptEnabled(void);

#ifdef __cplusplus
}
#endif

#endif /* TC1_H_INCLUDED */