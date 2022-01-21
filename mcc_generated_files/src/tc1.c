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

#include "../include/tc1.h"

uint16_t captured_events = 0;
uint16_t current_rpm = 0;

void TC1_COMPAIsrCallback(void);
void (*TC1_COMPA_isr_cb)(void) = &TC1_COMPAIsrCallback;
void TC1_COMPBIsrCallback(void);
void (*TC1_COMPB_isr_cb)(void) = &TC1_COMPBIsrCallback;
void TC1_OVFIsrCallback(void);
void (*TC1_OVF_isr_cb)(void) = &TC1_OVFIsrCallback;
void TC1_CAPTIsrCallback(void);
void (*TC1_CAPT_isr_cb)(void) = &TC1_CAPTIsrCallback;

void TC1_COMPAIsrCallback(void)
{
    current_rpm = captured_events * 60;
    captured_events = 0;
}

void TC1_COMPBIsrCallback(void)
{
    //Add your ISR code here
}

void TC1_OVFIsrCallback(void)
{
    //Add your ISR code here
}

void TC1_CAPTIsrCallback(void)
{
    captured_events++;
}

void TC1_SetOVFIsrCallback(TC1_cb_t cb)
{
    TC1_OVF_isr_cb = cb;
}

void TC1_SetCOMPAIsrCallback(TC1_cb_t cb)
{
    TC1_COMPA_isr_cb = cb;
}

void TC1_SetCOMPBIsrCallback(TC1_cb_t cb)
{
    TC1_COMPB_isr_cb = cb;
}

void TC1_SetCAPTIsrCallback(TC1_cb_t cb)
{
    TC1_CAPT_isr_cb = cb;
}


ISR(TIMER1_COMPA_vect)
{
    if (TC1_COMPA_isr_cb != NULL)
        (*TC1_COMPA_isr_cb)();
    
    TIMSK1 = 1 << OCIE1A;
}

ISR(TIMER1_COMPB_vect)
{
    if (TC1_COMPB_isr_cb != NULL)
        (*TC1_COMPB_isr_cb)();
    
    TIMSK1 = 1 << OCIE1B;
}

ISR(TIMER1_OVF_vect)
{
    if (TC1_OVF_isr_cb != NULL)
        (*TC1_OVF_isr_cb)();
    
    TIMSK1 = 1 << TOIE1;
}

ISR(TIMER1_CAPT_vect)
{
    if (TC1_CAPT_isr_cb != NULL)
        (*TC1_CAPT_isr_cb)();
    
    TIMSK1 = 1 << ICIE1;
}


/**
 * \brief Initialize TC16 interface
 */
int8_t TC1_Initialize()
{
    //Output Compare A
    OCR1A = 0xF424;

    //Output Compare B
    OCR1B = 0x00;

    //Control Register A
    TCCR1A = 0x00;

    //Control Register B
    TCCR1B = 0xCC;

    //Input Capture Register
    ICR1 = 0x00;

    //Input Capture Register
    GTCCR = 0x00;

    //Interrupt Register
    TIMSK1 = 0x22;

    return 0;
}

void TC1_WriteTimer(uint16_t timerVal)
{
    TCNT1=timerVal;
}

uint16_t TC1_ReadTimer(void)
{
    uint16_t readVal;

    readVal = TCNT1;

    return readVal;
}

void TC1_EnableInterrupt(void)
{

        TIMSK1 = 1 << OCIE1A      /* Output Compare Channel A Interrupt: enabled */
                    | 1 << OCIE1B    /* Output Compare Channel B Interrupt: enabled */
                    | 1 << TOIE1      /* Timer Overflow Interrupt: enabled */
                    | 1 << ICIE1;    /* Input Capture Interrupt: enabled */
    
}

void TC1_DisableInterrupt(void)
{

        TIMSK1 = 0 << OCIE1A      /* Output Compare Channel A Interrupt: enabled */
                    | 0 << OCIE1B    /* Output Compare Channel B Interrupt: enabled */
                    | 0 << TOIE1      /* Timer Overflow Interrupt: enabled */
                    | 0 << ICIE1;    /* Input Capture Interrupt: enabled */
    
}

void TC1_ClearOverflowInterruptFlag(void)
{

        TIFR1 = 1 << TOV1; /*Clear Overflow Interrupt Flag*/

}
    
bool TC1_IsOverflowInterruptEnabled(void)
{

        return ((TIFR1 & (1 << TOIE1)) > 0);

}