/* 
 * File:   ntc.h
 * Author: Siddha
 *
 * Created on February 11, 2022, 5:03 PM
 */

#ifndef NTC_H
#define	NTC_H

#define DEFAULT_BCOEF        3950
#define DEFAULT_NOMINAL_RES 10000
#define DEFAULT_REFERENCE_RESISTANCE 10000
#define DEFAULT_ADC_RESOLUTION 1023
#define NOMINAL_TEMPERATURE 25.0

struct Thermistor {

    int pin; // Analog port to be connected to ntc thermistor.
    double referenceResistance; // Value of resistor connected to GND.
    double nominalResistance; // Nominal value of ntc thermistor.
    double nominalTemperature; // According to datasheet in Celsius.
    double bValue; // Beta coefficient according to datasheet.
    int adcResolution; 

};

typedef struct Thermistor * ntc_t;

/*-------------------------------------------------------------*/
/*		Function prototypes				                       */
/*-------------------------------------------------------------*/
//#ifdef	__cplusplus
//extern "C" {
//#endif
	/**
	 * @brief Creates a new ntc termistor instance
	 *
	 * variables. Also we set the tuning parameters
	 *
	 * @param ntc A pointer to a thermistor structure
	 * @param pin adc channel to convert
	 * @param referenceResistance value of resistor connected to gnd
	 * @param nominalResistance ntc thermistor nominal value
	 * @param nominalTemperature Temperature nominal resistance measured, usually 25 C
	 * @param bValue beta coefficient, refer to datasheet
	 * @param adcResolution Resolution of ad converter. 1023 for 10 bit adc
	 *
	 * @return returns a ntc thermistor controller handle
	 */
	ntc_t newThermistor(ntc_t ntc, int pin, double referenceResistance, double nominalResistance, double nominalTemperature, double bValue, int adcResolution);

    /**
      Reads a temperature in Celsius from the thermistor.

      @return temperature in degree Celsius
    */
    double readCelsius(ntc_t ntc);

    /**
      Reads a temperature in Kelvin from the thermistor.

      @return temperature in degree Kelvin
    */
    double readKelvin(ntc_t ntc);

    /**
      Reads a temperature in Fahrenheit from the thermistor.

      @return temperature in degree Fahrenheit
    */
    double readFahrenheit(ntc_t ntc);

    /**
      Resistance to Kelvin conversion:
      1/K = 1/K0 + ln(R/R0)/B;
      K = 1 / (1/K0 + ln(R/R0)/B);
      Where
      K0 - nominal temperature,
      R0 - nominal resistance at a nominal temperature,
      R - the input resistance,
      B - b-value of a thermistor.

      @param resistance - resistance value to convert
      @return temperature in degree Kelvin
    */
    double resistanceToKelvins(ntc_t ntc, double resistance);

    /**
      Calculates a resistance of the thermistor:
      Converts a value of the thermistor sensor into a resistance.
      R = R0 / (ADC / V - 1);
      Where
      R0 - nominal resistance at a nominal temperature,
      ADC - analog port resolution (1023, for Arduino)
      V - current voltage (analog port value).

      @return resistance of the thermistor sensor.
    */
    double readResistance(ntc_t ntc);

    /**
      Reads a voltage from the thermistor analog port.

      @return thermistor voltage in analog range (0...1023, for Arduino).
    */
    double readVoltage(ntc_t ntc);

    /**
      Celsius to Kelvin conversion:
      K = C + 273.15

      @param celsius - temperature in degree Celsius to convert
      @return temperature in degree Kelvin
    */
    double celsiusToKelvins(double celsius);

    /**
      Kelvin to Celsius conversion:
      C = K - 273.15

      @param kelvins - temperature in degree Kelvin to convert
      @return temperature in degree Celsius
    */
    double kelvinsToCelsius(double kelvins);

//    #ifdef	__cplusplus
//}
//#endif


#endif	/* NTC_H */

