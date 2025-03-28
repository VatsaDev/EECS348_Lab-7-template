#include "temperature.h"
#include <stdio.h>

/**
 * @brief Convert temperature in Celsius to Fahrenheit
 *
 * @param celsius
 * @return float
 */
float celsius_to_fahrenheit(float celsius) {
    return (9.0/5.0) * celsius + 32.0;
}

/**
 * @brief Convert temperature in Fahrenheit to Celsius
 *
 * @param fahrenheit
 * @return float
 */
float fahrenheit_to_celsius(float fahrenheit) {
    return (5.0/9.0) * (fahrenheit - 32.0);
}

/**
 * @brief Convert temperature in Celsius to Kelvin
 *
 * @param celsius
 * @return float
 */
float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

/**
 * @brief Convert temperature in Kelvin to Celsius
 *
 * @param kelvin
 * @return float
 */
float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

/**
 * @brief Convert temperature in Fahrenheit to Kelvin
 *
 * @param fahrenheit
 * @return float
 */
float fahrenheit_to_kelvin(float fahrenheit) {
    return celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit));
}

/**
 * @brief Convert temperature in Kelvin to Fahrenheit
 *
 * @param kelvin
 * @return float
 */
float kelvin_to_fahrenheit(float kelvin) {
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
}

/**
 * @brief Categorizes temperature in Celsius and prints category and advisory.
 *
 * @param celsius
 */
void categorize_temperature(float celsius) {
    printf("Category: ");
    if (celsius < 0) {
        printf("Freezing\n");
        printf("Advisory: Watch out for ice. Stay warm.\n");
    } else if (celsius < 10) {
        printf("Cold\n");
        printf("Advisory: Wear a jacket.\n");
    } else if (celsius < 25) {
        printf("Comfortable\n");
        printf("Advisory: Enjoy the weather!\n");
    } else if (celsius < 35) {
        printf("Hot\n");
        printf("Advisory: Stay hydrated.\n");
    } else {
        printf("Extreme Heat\n");
        printf("Advisory: Stay indoors and seek cool environments.\n");
    }
}
