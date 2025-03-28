#include "temperature.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    float temperature_value, converted_temperature;
    char input_scale, target_scale;

    while (1) {
        printf("Enter temperature value: ");
        if (scanf("%f", &temperature_value) != 1) {
            printf("Invalid temperature value. Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        printf("Choose input scale (F/C/K): ");
        if (scanf(" %c", &input_scale) != 1) {
            printf("Invalid input scale. Please enter F, C, or K.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }
        input_scale = toupper(input_scale); // Convert to uppercase for easier comparison

        printf("Choose target scale (F/C/K): ");
        if (scanf(" %c", &target_scale) != 1) {
            printf("Invalid target scale. Please enter F, C, or K.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }
        target_scale = toupper(target_scale); // Convert to uppercase for easier comparison

        if (input_scale != 'F' && input_scale != 'C' && input_scale != 'K') {
            printf("Invalid input scale. Please enter F, C, or K.\n");
            continue;
        }

        if (target_scale != 'F' && target_scale != 'C' && target_scale != 'K') {
            printf("Invalid target scale. Please enter F, C, or K.\n");
            continue;
        }

        if (input_scale == target_scale) {
            printf("Input and target scales are the same. No conversion needed.\n");
            converted_temperature = temperature_value;
        } else {
            if (input_scale == 'C') {
                if (target_scale == 'F') {
                    converted_temperature = celsius_to_fahrenheit(temperature_value);
                } else if (target_scale == 'K') {
                    converted_temperature = celsius_to_kelvin(temperature_value);
                }
            } else if (input_scale == 'F') {
                if (target_scale == 'C') {
                    converted_temperature = fahrenheit_to_celsius(temperature_value);
                } else if (target_scale == 'K') {
                    converted_temperature = fahrenheit_to_kelvin(temperature_value);
                }
            } else if (input_scale == 'K') {
                if (target_scale == 'C') {
                    converted_temperature = kelvin_to_celsius(temperature_value);
                } else if (target_scale == 'F') {
                    converted_temperature = kelvin_to_fahrenheit(temperature_value);
                }
            }
        }

        printf("Converted temperature: %.2f %c\n", converted_temperature, target_scale);

        float celsius_for_category;
        if (target_scale == 'C') {
            celsius_for_category = converted_temperature;
        } else {
            celsius_for_category = fahrenheit_to_celsius(converted_temperature); // Convert to Celsius for categorization
        }
        categorize_temperature(celsius_for_category);


        char continue_choice;
        printf("Convert another temperature? (y/n): ");
        if (scanf(" %c", &continue_choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }
        if (tolower(continue_choice) != 'y') {
            break;
        }
    }

    return 0;
}
