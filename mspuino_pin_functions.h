// mspuino_pin_functions.h
// Created: 09/16/2022
// Author: Logan Luedtke

#ifndef MSPUINO_PIN_FUNCTIONS_H_
#define MSPUINO_PIN_FUNCTIONS_H_

#include "mspuino_pins.h"
#include <stdbool.h>

#define HIGH 1
#define LOW 0

void pinMode (struct MSP432_PIN *pin, enum MSP432_PIN_TYPE pin_type);

uint32_t analogRead (struct MSP432_PIN *pin);
void analogWrite (struct MSP432_PIN *pin, double freq, float duty);
void analogWriteToggle (struct MSP432_PIN *pin, bool val);

bool digitalRead (struct MSP432_PIN *pin);
void digitalWrite (struct MSP432_PIN *pin, bool val);

void powerSave (void);

#endif // MSPUINO_PIN_FUNCTIONS_H_
