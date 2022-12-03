// msp432_hal_pin_functions.c
// Created: 09/16/2022
// Author: Logan Luedtke

#include "msp.h"
#include <stdbool.h>
#include <math.h>
#include <stdio.h>

#include "mspuino_pin_functions.h"
#include "mspuino_pins.h"

static void calculateTimerVals (int clockFreq, double freq, float duty, int *ID, int *EX0, int *CCR0, int *CCRN);
static bool pinTypeCheck(enum MSP432_PIN_TYPE pin_type, enum MSP432_PIN_TYPE allowed_types[], uint8_t num_allowed_types);

// two port types on msp, even and odd, have to duplicate everything for even and odd case
void pinMode (struct MSP432_PIN *pin, enum MSP432_PIN_TYPE pin_type) {
  pin->pin_type = pin_type; // set pin type for checking later

  switch (pin_type) {

    case DIGITAL_INPUT:

      // digital input setup
      if (pin->gpio_port_is_even) {
        pin->gpio_port_even->SEL0 &= ~pin->gpio_pin;
        pin->gpio_port_even->SEL1 &= ~pin->gpio_pin;
        pin->gpio_port_even->REN &= ~pin->gpio_pin; // disable pullup/pulldown
        pin->gpio_port_even->DIR &= ~pin->gpio_pin; // make input
        pin->gpio_port_even->OUT &= ~pin->gpio_pin;        
      } else {
        pin->gpio_port_odd->SEL0 &= ~pin->gpio_pin;
        pin->gpio_port_odd->SEL1 &= ~pin->gpio_pin;
        pin->gpio_port_odd->REN &= ~pin->gpio_pin; // disable pullup/pulldown
        pin->gpio_port_odd->DIR &= ~pin->gpio_pin; // make input
        pin->gpio_port_odd->OUT &= ~pin->gpio_pin;        
      }
      break;

    case DIGITAL_INPUT_PULLUP:

      // digital input pullup setup
      if (pin->gpio_port_is_even) {
        pin->gpio_port_even->SEL0 &= ~pin->gpio_pin;
        pin->gpio_port_even->SEL1 &= ~pin->gpio_pin;
        pin->gpio_port_even->REN |= pin->gpio_pin; // enable pullup/pulldown
        pin->gpio_port_even->DIR &= ~pin->gpio_pin; // make input
        pin->gpio_port_even->OUT |= pin->gpio_pin; // enable pullup
      } else {
        pin->gpio_port_odd->SEL0 &= ~pin->gpio_pin;
        pin->gpio_port_odd->SEL1 &= ~pin->gpio_pin;
        pin->gpio_port_odd->REN |= pin->gpio_pin; // enable pullup/pulldown
        pin->gpio_port_odd->DIR &= ~pin->gpio_pin; // make input
        pin->gpio_port_odd->OUT |= pin->gpio_pin; // enable pullup
      }
      break;

    case DIGITAL_INPUT_PULLDOWN:

      // digital input pulldown setup
      if (pin->gpio_port_is_even) {
        pin->gpio_port_even->SEL0 &= ~pin->gpio_pin;
        pin->gpio_port_even->SEL1 &= ~pin->gpio_pin;
        pin->gpio_port_even->REN |= pin->gpio_pin; // enable pullup/pulldown
        pin->gpio_port_even->DIR &= ~pin->gpio_pin; // make input
        pin->gpio_port_even->OUT &= ~pin->gpio_pin; // enable pulldown
      } else {
        pin->gpio_port_odd->SEL0 &= ~pin->gpio_pin;
        pin->gpio_port_odd->SEL1 &= ~pin->gpio_pin;
        pin->gpio_port_odd->REN |= pin->gpio_pin; // enable pullup/pulldown
        pin->gpio_port_odd->DIR &= ~pin->gpio_pin; // make input
        pin->gpio_port_odd->OUT &= ~pin->gpio_pin; // enable pulldown
      }
      break;

    case DIGITAL_OUTPUT:

      // digital output setup
      if (pin->gpio_port_is_even) {
        pin->gpio_port_even->SEL0 &= ~pin->gpio_pin;
        pin->gpio_port_even->SEL1 &= ~pin->gpio_pin;
        pin->gpio_port_even->REN &= ~pin->gpio_pin;
        pin->gpio_port_even->DIR |= pin->gpio_pin; // make output
        pin->gpio_port_even->OUT &= ~pin->gpio_pin; // make low by default
      } else {
        pin->gpio_port_odd->SEL0 &= ~pin->gpio_pin;
        pin->gpio_port_odd->SEL1 &= ~pin->gpio_pin;
        pin->gpio_port_odd->REN &= ~pin->gpio_pin;
        pin->gpio_port_odd->DIR |= pin->gpio_pin; // make output
        pin->gpio_port_odd->OUT &= ~pin->gpio_pin; // make low by default
      }
      break;

    case ANALOG_INPUT:
      if (!pin->is_analog) {
        // give error, pin is not an analog pin so it can not be an analog input pin
        printf("Error: Pin is not an analog input pin. Setting to digital input\n");
        pinMode(pin, DIGITAL_INPUT); // make pin be a digital input to hopefully not damage pin
        return;
      }

      // analog input setup
      if (pin->gpio_port_is_even) {
        pin->gpio_port_even->SEL0 |= pin->gpio_pin;
        pin->gpio_port_even->SEL1 |= pin->gpio_pin;
        pin->gpio_port_even->REN &= ~pin->gpio_pin;
        pin->gpio_port_even->DIR &= ~pin->gpio_pin;
        pin->gpio_port_even->OUT &= ~pin->gpio_pin;
      } else {
        pin->gpio_port_odd->SEL0 |= pin->gpio_pin;
        pin->gpio_port_odd->SEL1 |= pin->gpio_pin;
        pin->gpio_port_odd->REN &= ~pin->gpio_pin;
        pin->gpio_port_odd->DIR &= ~pin->gpio_pin;
        pin->gpio_port_odd->OUT &= ~pin->gpio_pin;
      }

      break;

    case ANALOG_OUTPUT:
      if (!pin->is_timer) {
        // give error, pin is not a timer pin so it can not be an analog output pin
        printf("Error: Pin is not an analog output pin. Setting to digital output driving ground\n");
        pinMode(pin, DIGITAL_OUTPUT); // make pin be a digital output to hopefully not damage pin
        return;
      }

      // analog output setup
      if (pin->gpio_port_is_even) {
        pin->gpio_port_even->SEL0 |= pin->gpio_pin;
        pin->gpio_port_even->SEL1 &= ~pin->gpio_pin;
        pin->gpio_port_even->REN &= ~pin->gpio_pin;
        pin->gpio_port_even->DIR |= pin->gpio_pin;
        pin->gpio_port_even->OUT |= pin->gpio_pin;
      } else {
        pin->gpio_port_odd->SEL0 |= pin->gpio_pin;
        pin->gpio_port_odd->SEL1 &= ~pin->gpio_pin;
        pin->gpio_port_odd->REN &= ~pin->gpio_pin;
        pin->gpio_port_odd->DIR |= pin->gpio_pin;
        pin->gpio_port_odd->OUT |= pin->gpio_pin;
      }
      break;

    default:
      // error
      break;
  }
}

bool digitalRead (struct MSP432_PIN *pin) {
  // no type check happening here as any pin can be read

  if (pin->gpio_port_is_even) {
    return (pin->gpio_port_even->IN & pin->gpio_pin);
  } else {
    return (pin->gpio_port_odd->IN & pin->gpio_pin);
  }
}

void digitalWrite (struct MSP432_PIN *pin, bool val) {
  enum MSP432_PIN_TYPE allowed_types[] = {DIGITAL_OUTPUT};
  if (pinTypeCheck(pin->pin_type, allowed_types, 1)) return; // exit

  if (pin->gpio_port_is_even) {
    if (val) {
      pin->gpio_port_even->OUT |= pin->gpio_pin;
    } else {
      pin->gpio_port_even->OUT &= ~pin->gpio_pin;
    }
  } else {
    if (val) {
      pin->gpio_port_odd->OUT |= pin->gpio_pin;
    } else {
      pin->gpio_port_odd->OUT &= ~pin->gpio_pin;
    }
  }
}

void analogWrite (struct MSP432_PIN *pin, double freq, float duty) {
  enum MSP432_PIN_TYPE allowed_types[] = {ANALOG_OUTPUT};
  if (pinTypeCheck(pin->pin_type, allowed_types, 1)) return; // exit

  int ID = 0; // variables which will be set by calculateTimerVals() function
  int EX0 = 0;
  int CCR0 = 0;
  int CCRN = 0;
  int clock_freq = 12000000;
  calculateTimerVals(clock_freq, freq, duty, &ID, &EX0, &CCR0, &CCRN); // calculate register values

  pin->A_timer->CTL &= ~(0b11 << 6); // reset ID can change
  pin->A_timer->CTL |= (0b10 << 8) | // SMCLK
                (ID << 6) | // clock divider
                (0b01 << 4); // up mode
  pin->A_timer->EX0 = EX0; // clock divider multiple
  pin->A_timer->CCR[0] = CCR0; // count up to value to get frequency
  pin->A_timer->CCR[pin->timer_number] = CCRN; // divide count up value by this value to get duty cycle
  pin->A_timer->CCTL[pin->timer_number] |= (0b111 << 5); // reset set mode
}

void analogWriteToggle (struct MSP432_PIN *pin, bool val) {
  enum MSP432_PIN_TYPE allowed_types[] = {ANALOG_OUTPUT};
  if (pinTypeCheck(pin->pin_type, allowed_types, 1)) return; // exit

  if (val) { // turn on timer output
    // connect timer pin
    if (pin->gpio_port_is_even) {
      pin->gpio_port_even->SEL0 |= pin->gpio_pin;
      pin->gpio_port_even->OUT |= pin->gpio_pin;
    } else {
      pin->gpio_port_odd->SEL0 |= pin->gpio_pin;
      pin->gpio_port_odd->OUT |= pin->gpio_pin;
    }

    pin->A_timer->CTL |= (0b01 << 4);
  } else { // turn off timer output
    pin->A_timer->CTL &= ~(0b11 << 4);

    // disconnect timer pin
    if (pin->gpio_port_is_even) {
      pin->gpio_port_even->SEL0 &= ~pin->gpio_pin;
      pin->gpio_port_even->OUT &= ~pin->gpio_pin;
    } else {
      pin->gpio_port_odd->SEL0 &= ~pin->gpio_pin;
      pin->gpio_port_odd->OUT &= ~pin->gpio_pin;
    }
  }
}

// if analog read was called in an interrupt while in this analog read, bad things would happen
// need to have some sort of interrupt protection 
uint32_t analogRead (struct MSP432_PIN *pin) {
  printf("f\n");

  ADC14->CTL0 = (1 << 26) | // source sample and hold
                (0b00 << 17) | // single channel single conversion
                (0b0101 << 12) | // sample and hold time = 96
                (0b0101 << 8) | // sample and hold time = 96
                (0 << 7) | // do not enable multiple conversion
                (1 << 4); // turn on

  ADC14->CTL1 = (pin->analog_number << 16) | // start with mem register (analog number)
                (0b11 << 4); // 14 bits of ADC

  ADC14->MCTL[pin->analog_number] = (pin->analog_number); // store result of analog pin in memory register that is the same as the analog pin

  ADC14->CTL0 |= (1 << 1); // enable conversion, cannot make changes now... 
  ADC14->CTL0 |= (1 << 0); // start single conversion
  
  while (!ADC14->IFGR0) {
    // do nothing while waiting for conversion to finish
  }

  ADC14->CTL0 &= ~(1 << 0); // stop conversions

  return ADC14->MEM[pin->analog_number];
}


// static helper functions


// calculates the dividers and and CCR numbers for analog output
static void calculateTimerVals (int clockFreq, double freq, float duty, int *ID, int *EX0, int *CCR0, int *CCRN) {
  if (freq == 0) return; // nothing to do
  double Tcm = 1 / freq; // from equation
  int id, ex0; // temp variables for pointers
  for (id = 1; id <= 8; id *= 2) { // multiply by two from 1 to 8: 1, 2, 4, 8
    for (ex0 = 1; ex0 <= 8; ex0++) { // increment from 1 to 8: 1, 2, 3, 4, 5, 6, 7, 8
      double TA = ((Tcm * clockFreq) / (id * ex0)) - 1; // from equation: TA = ((T * TCLK) / N) - 1
      if (TA < 65535) { // use the first value that fits, this works because N goes from min to max in for loop
        *ID = (id >> 1);
        if (id == 8) *ID = 3; // convert ID int number to register value
        *EX0 = ex0 - 1; // minus one is how to convert for EX0 int to register value
        *CCR0 = (int)round(TA); // the integer part of TA (in case of a machine precision error)
        *CCRN = round(*CCR0 * duty); // the correct multiplication for CCRN in up
        return;
      }
    }
  }
}

// checks if the type of the pin is in the allowed type of pins for the function calls
static bool pinTypeCheck (enum MSP432_PIN_TYPE pin_type, enum MSP432_PIN_TYPE allowed_types[], uint8_t num_allowed_types) {
  uint8_t i;
  for (i = 0; i < num_allowed_types; i++) {
    if (pin_type == allowed_types[i]) {
      return false;
    }
  }
  printf("Error: pin mode not set for the operation");
  return true;
}
