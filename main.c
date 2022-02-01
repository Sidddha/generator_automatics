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
#define F_CPU 16000000UL
#include "mcc_generated_files/mcc.h"
#include <stdlib.h>
#include "PID.h"

/* Controller parameters */
#define PID_KP  2.0f
#define PID_KI  0.5f
#define PID_KD  0.25f

#define PID_TAU 0.02f

#define PID_LIM_MIN uint16_t 250
#define PID_LIM_MAX uint16_t 500

#define PID_LIM_MIN_INT uint8_t 25
#define PID_LIM_MAX_INT uint8_t 50

#define SAMPLE_TIME_S 0.01f

/*
    Main application
*/

/*
    Variables definition
 */

float k = 0.1;  // gain 0.0-1.0
uint16_t avgRPM = 0;
uint16_t rpm = 0;
uint32_t now = 0;

// Structure to strore PID data and pointer to PID structure
struct pid_controller ctrldata;
pid_t pid;

// Control loop input,output and setpoint variables
float input = 0, output = 0;
float setpoint = 1500;

// Control loop gains
float kp = 2.5, ki = 1.0, kd = 1.0;

int expAverage(int newVal) {
  static int filVal = 0;
  filVal += (newVal - filVal) * k;
  return filVal;
}

int main(void)
{
    /* Initializes MCU, drivers and middleware */
    SYSTEM_Initialize();
    
    /* Initialise PID controller */
	// Prepare PID controller for operation
	pid = pid_create(&ctrldata, &input, &output, &setpoint, kp, ki, kd);
	// Set controler output limits from 0 to 200
	pid_limits(pid, 250, 500);
	// Allow PID to compute and change output
	pid_auto(pid);

    while (1)
    {
        if (millis() - now >= 250)
        {
            rpm = capture * 240;
            now = millis();
        }
        avgRPM = expAverage(rpm);
        // Check if need to compute PID
		if (pid_need_compute(pid)) 
        {
			// Read process feedback
			input = avgRPM;
			// Compute new PID output value
			pid_compute(pid);
			//Change actuator value
		    OCR1A = output;
		}
    }
}
/**
    End of File
*/