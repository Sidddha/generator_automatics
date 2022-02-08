/**
 * Copyright (c) 2014 panStamp <contact@panstamp.com>
 * 
 * This file is part of the panStamp project.
 * 
 * panStamp  is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * any later version.
 * 
 * panStamp is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with panStamp; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 
 * USA
 * 
 * Author: Daniel Berenguer
 * Creation date: 11/05/2014
 *
 * This library simplifies the use of NTC thermistors by using Steinhart
 * simplified formula.
 * http://en.wikipedia.org/wiki/Steinhart%E2%80%93Hart_equation
 *
 * Based on procedure explained by Adafruit:
 * https://learn.adafruit.com/thermistor/using-a-thermistor
 *
 * This library works only with the following circuit topology
 *
 * Vcc---NTC---ADC---SERIES_RESISTOR---GND
 */

#include "thermistor.h"
#include <math.h>

 
// Temperature for nominal resistance (almost always 25 C)
#define TEMPERATURENOMINAL 25
// Number of ADC samples
#define NUMSAMPLES         5 
#define ADC_RESOLUTION 1023
#define VERBOSE_SENSOR_ENABLED 1
/**
 * THERMISTOR
 * 
 * Class constructor
 *
 * @param adcPin Analog pin where the thermistor is connected
 * @param nomRes Nominal resistance at 25 degrees Celsius
 * @param bCoef beta coefficient of the thermistor
 * @param serialRes Value of the serial resistor
 */
THERMISTOR::THERMISTOR(uint8_t adcPin, uint16_t nomRes, uint16_t bCoef, uint16_t serialRes) 
{
  analogPin = adcPin;
  nominalResistance = nomRes;
  bCoefficient = bCoef;
  serialResistance = serialRes;
}

/**
 * read
 *
 * Read temperature from thermistor
 *
 * @return temperature in 0.1 ºC
 */
int THERMISTOR::read(void)
{
  uint8_t i = 0;
  float average = 0;

  // take N samples in a row, with a slight delay
  for (i; i< NUMSAMPLES; i++)
  {
    average += ADC_GetConversion(analogPin);
  }
  average /= NUMSAMPLES;
 
  // convert the value to resistance
  average = ADC_RESOLUTION / average - 1;
  average = serialResistance * average;

 
  float steinhart;
  steinhart = average / nominalResistance;     // (R/Ro)
  steinhart = log(steinhart);                  // ln(R/Ro)
//  #endif
  steinhart /= bCoefficient;                   // 1/B * ln(R/Ro)
  steinhart += 1.0 / (TEMPERATURENOMINAL + 273.15); // + (1/To)
  steinhart = 1.0 / steinhart;                 // Invert
  steinhart -= 273.15;                         // convert to C
  return (int)(steinhart * 10);
}

