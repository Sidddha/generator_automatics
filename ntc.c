
#include <math.h>
#include "ntc.h"
#include "mcc_generated_files/include/adc.h"

ntc_t newThermistor(ntc_t ntc, int pin, double referenceResistance,double nominalResistance,double nominalTemperature, double bValue, int adcResolution)
{
	ntc->pin = pin;
	ntc->referenceResistance = referenceResistance;
	ntc->nominalResistance = nominalResistance;
	ntc->nominalTemperature = nominalTemperature;
    ntc->bValue = bValue;
    ntc->adcResolution = adcResolution;    
	return ntc;
}

/**
	Reads and returns a temperature in Celsius.
	Reads the temperature in Kelvin,
	converts in Celsius and return it.

	@return temperature in Celsius.
*/
double readCelsius(ntc_t ntc) {
	return kelvinsToCelsius(readKelvin(ntc));
}

/**
	Returns a temperature in Kelvin.
	Reads the thermistor resistance,
	converts in Kelvin and return it.

	@return temperature in Kelvin.
*/
double readKelvin(ntc_t ntc) {
	return resistanceToKelvins(ntc, readResistance(ntc));
}

double resistanceToKelvins(ntc_t ntc, double resistance) {
	double inverseKelvin = 1.0 / ntc->nominalTemperature +
		log(resistance / ntc->nominalResistance) / ntc->bValue;
	return (1.0 / inverseKelvin);
}

double readResistance(ntc_t ntc) {
	return ntc->referenceResistance / (ntc->adcResolution / readVoltage(ntc) - 1);
}

double readVoltage(ntc_t ntc) {
	return ADC_GetConversion(ntc->pin);
}

double celsiusToKelvins(double celsius) {
	return (celsius + 273.15);
}

double kelvinsToCelsius(double kelvins) {
	return (kelvins - 273.15);
}

