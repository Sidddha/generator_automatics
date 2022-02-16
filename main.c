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
#define F_CPU 8000000UL
#include "mcc_generated_files/mcc.h"
#include <stdlib.h>
#include "PID.h"
#include "ntc.h"
#include "lcdpcf8574/lcdpcf8574.h"
#include "i2chw/i2cmaster.h"
#include "pcf8574/pcf8574.h"

/* Controller parameters */
#define PID_KP  2.0f
#define PID_KI  0.5f
#define PID_KD  0.25f

#define PID_TAU 0.02f

#define PID_LIM_MIN uint16_t 125
#define PID_LIM_MAX uint16_t 250

#define PID_LIM_MIN_INT uint8_t 25
#define PID_LIM_MAX_INT uint8_t 50

#define SAMPLE_TIME_S 0.01f

/* Thermistor */
#define JACKET_SENSOR_PIN 0

/**
  How many readings are taken to determine a mean temperature.
  The more values, the longer a calibration is performed,
  but the readings will be more accurate.
*/
#define READINGS_NUMBER 10

/**
  Delay time between a temperature readings
  from the temperature sensor (ms).
*/
#define DELAY_TIME 10

/*
    Main application
*/

/* Variables definition */
uint16_t newValue = 0;
uint16_t avgRPM = 0;
uint16_t rpm = 0;
uint32_t now = 0;
int8_t currentTemperature = 0;

// Structure to store PID data and pointer to PID structure
struct pid_controller aceleratordata;
struct pid_controller flapdata;
pid_t aceleratorPid;
pid_t flapPid;

// Control loop input,output and setpoint variables
float input = 0, output = 0;
float setpoint = 1500;

// Control loop gains
float kp = 2.5, ki = 1.0, kd = 1.0;

// Thermistors 
struct  Thermistor jacket_sensor_data;
struct  Thermistor stator_sensor_data;
ntc_t jacket_sensor;
ntc_t stator_sensor;

/* Auxiliary functions */

int expAverage(int newVal) {
    float k = 0.1;  // gain 0.0-1.0
    static int filVal = 0;
    filVal += (newVal - filVal) * k;
    return filVal;
}

uint32_t MAP(uint32_t au32_IN, uint32_t au32_INmin, uint32_t au32_INmax, uint32_t au32_OUTmin, uint32_t au32_OUTmax)
{
    return ((((au32_IN - au32_INmin)*(au32_OUTmax - au32_OUTmin))/(au32_INmax - au32_INmin)) + au32_OUTmin);
}


int main(void)
{
    /* Initializes MCU, drivers and middleware */
    SYSTEM_Initialize();
    
    /* initialize I2C library */
    i2c_init();                             

    pcf8574_init();
    
    /* initialize lcd */
    lcd_init(LCD_DISP_ON);
    
    /* Initialize PID controller */
	aceleratorPid = pid_create(&aceleratordata, &input, &output, &setpoint, kp, ki, kd);
	pid_limits(aceleratorPid, 250, 500);
	pid_auto(aceleratorPid);
    
    flapPid = pid_create(&flapdata, &input, &output, &setpoint, kp, ki, kd);
	pid_limits(flapPid, 50, 350);
	pid_auto(flapPid);

    jacket_sensor = newThermistor(
            &jacket_sensor_data,
            JACKET_SENSOR_PIN,
            DEFAULT_REFERENCE_RESISTANCE,
            DEFAULT_NOMINAL_RES,
            NOMINAL_TEMPERATURE,
            DEFAULT_BCOEF,
            DEFAULT_ADC_RESOLUTION
    );
    
    while (1)
    {
        if (millis() - now >= 250)
        {
            rpm = capture * 60;
            now = millis();
        }
        avgRPM = expAverage(rpm);
        
        currentTemperature = readCelsius(jacket_sensor);

        // Check if need to compute PID
		if (pid_need_compute(aceleratorPid)) 
        {
            setpoint = MAP(ADC_GetConversion(7), 0, 1023, 0, 100);
			// Read process feedback
			input = currentTemperature;
			// Compute new PID output value
			pid_compute(aceleratorPid);
			//Change actuator value
		    OCR1A = output;
		}
    }
}
/**
    End of File
*/