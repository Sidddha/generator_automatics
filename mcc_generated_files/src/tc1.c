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
<<<<<<< HEAD

volatile uint16_t counter = 0;

void TC1_DefaultCOMPAIsrCallback(void);
void (*TC1_COMPA_isr_cb)(void) = &TC1_DefaultCOMPAIsrCallback;
void TC1_DefaultCOMPBIsrCallback(void);
void (*TC1_COMPB_isr_cb)(void) = &TC1_DefaultCOMPBIsrCallback;
void TC1_DefaultOVFIsrCallback(void);
void (*TC1_OVF_isr_cb)(void) = &TC1_DefaultOVFIsrCallback;
void TC1_DefaultCAPTIsrCallback(void);
void (*TC1_CAPT_isr_cb)(void) = &TC1_DefaultCAPTIsrCallback;

void TC1_DefaultCOMPAIsrCallback(void)
=======
#include "../include/pin_manager.h"
volatile uint16_t captured_events = 0;
volatile uint16_t current_rpm = 0;

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
//    TC1_DisableInterrupt();
//    current_rpm = captured_events * 60;
//    captured_events = 0;
//    TC1_EnableInterrupt();
}

void TC1_COMPBIsrCallback(void)
>>>>>>> main
{
    //Add your ISR code here
}

<<<<<<< HEAD
void TC1_DefaultCOMPBIsrCallback(void)
{
    //Add your ISR code here
}

void TC1_DefaultOVFIsrCallback(void)
{
    TIFR1 = 1 << TOV1; /*Clear Overflow Interrupt Flag*/
    counter++;
    if (counter >= 50)
    {
        counter = 0;
    }
}

void TC1_DefaultCAPTIsrCallback(void)
{
    //Add your ISR code here
}

=======
void TC1_OVFIsrCallback(void)
{

}

void TC1_CAPTIsrCallback(void)
{
    captured_events++;
    if (TIFR1 & (1 << OCF1A))
    {
        current_rpm = captured_events * 60;
        captured_events = 0;
        TIFR1 |= (0 << OCF1A);
    }
}

>>>>>>> main
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
<<<<<<< HEAD
    OCR1A = 0x00;
=======
    OCR1A = 0xF424;
>>>>>>> main

    //Output Compare B
    OCR1B = 0x00;

    //Control Register A
<<<<<<< HEAD
    TCCR1A = 0xA2;

    //Control Register B
    TCCR1B = 0x1C;

    //Input Capture Register
    ICR1 = 0xF424;
=======
    TCCR1A = 0x00;

    //Control Register B
    TCCR1B = 0xCC;

    //Input Capture Register
    ICR1 = 0x00;
>>>>>>> main

    //Input Capture Register
    GTCCR = 0x00;

    //Interrupt Register
<<<<<<< HEAD
    TIMSK1 = 0x01;
=======
    TIMSK1 = 0x22;
>>>>>>> main

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