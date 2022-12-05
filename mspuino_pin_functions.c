// msp432_hal_pin_functions.c
// Created: 09/16/2022
// Author: Logan Luedtke

#include "msp.h"
#include <stdbool.h>
#include <math.h>
#include <stdio.h>

#include "mspuino_pin_functions.h"
#include "mspuino_pins.h"

static void calculateTimerVals (int clockFreq, double freq, double duty, int *ID, int *EX0, int *CCR0, int *CCRN);
static bool pinTypeCheck(enum MSP432_PIN_TYPE pin_type, enum MSP432_PIN_TYPE allowed_types[], uint8_t num_allowed_types);

/**
* @brief Configure correct registers to set opperation mode of an MSP pin
*
* @note Additional logic is in place in this function to ensure that the particular pin
*   can be implemented as the requested pin type - i.e. - Only some pins are connected
*   to the ADC hardware and thus not every pin can be an analog input pin
*
* @param pin Target pin
* @param pin_type Requested pin configuration type - i.e. - digital output, analog input etc.
*
* @return void
*****************************************************************************/
void pinMode (struct MSP432_PIN *pin, enum MSP432_PIN_TYPE pin_type) {
  pin->pin_type = pin_type; // set pin type

  switch (pin_type) {

    // Note about how digital input works: when a digital input pin is not connected to any circuitry, 
    //   it's voltage will be "floating". This can make it so that digital read will return 0 or 1 when
    //   a digital input pin is disconnected from circuitry, and may be undesireable.
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

    // Note about how pullup works: when a digital input pullup pin is not connected to any circuitry, 
    //   it's voltage will be "pulled" up to 3.3[V].
    // Configuring this way ensures the pin is at a known value when disconnected.
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

    // Note about how pulldown works: when a digital input pulldown pin is not connected to any circuitry, 
    //   it's voltage will be "pulled" down to 0[V].
    // Configuring this way ensures the pin is at a known value when disconnected.
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

/**
* @brief Read the digital voltage on a pin
*
* @note All pins can have digital read called on them regardless of pin type
*
* @param pin Target pin
*
* @return boolean : 0 for ~0[V], 1 for ~3.3[V]
*
* @warning The value of digitalRead may be undefined for pin voltages in between 
*            the range of 0[V] and 3.3[V]. (more likley undefined between 1[V] and 2.5[V])
*****************************************************************************/
bool digitalRead (struct MSP432_PIN *pin) {
  // no type check happening here as any pin can be read

  if (pin->gpio_port_is_even) {
    return (pin->gpio_port_even->IN & pin->gpio_pin);
  } else {
    return (pin->gpio_port_odd->IN & pin->gpio_pin);
  }
}

/**
* @brief Set the digital voltage on a pin
*
* @note All pins have the ability to have digital write called on them, however, if a pin was previously
*         configured as an input pin, outputting a voltage may damage your MSP or external circuitry.
*         A check is in place to prevent setting an output if the pinmode was not set as output previously
*
* @param pin Target pin
* @param val boolean : 0 for 0[V], 1 for 3.3[V]
*
* @return void
*****************************************************************************/
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

/**
* @brief Create a pwm output signal on an analog output pin
*
* @note Not all pins have the ability to have pwm output.
*       Output frequency is 500[Hz] which is consistent with Arduino
*
* @param pin Target pin
* @param pwm uint8_t : 0 for always off, 255 for always on, inbetween 0 and 255 for inbetween on/off
*
* @return void
*****************************************************************************/
void analogWrite (struct MSP432_PIN *pin, uint8_t pwm) {
  if (pwm > 255) pwm = 255; // bound pwm
  analogWrite_f_d(pin, 500.0, (double)(pwm / 255.0)); // pin type check is happening in this function
}

/**
* @brief Create a pwm output signal on an analog output pin at specific frequency and duty cycle
*
* @note Not all pins have the ability to have pwm output
*
* @param pin Target pin
* @param freq double : output frequency of the pin. Function will accept values less than 0, but will 
*               result in pin being completely off (or completely on? need to test)
* @param duty double : duty cycle : range from 0.0 to 1.0. 0.0 for always off, 1.0 for always on. 
                Function will bound duty between 0.0 and 1.0
*
* @return void
*****************************************************************************/
void analogWrite_f_d (struct MSP432_PIN *pin, double freq, double duty) {
  enum MSP432_PIN_TYPE allowed_types[] = {ANALOG_OUTPUT};
  if (pinTypeCheck(pin->pin_type, allowed_types, 1)) return; // exit

  int ID = 0; // variables which will be set by calculateTimerVals() function
  int EX0 = 0;
  int CCR0 = 0;
  int CCRN = 1; // larger than CCR 0 so that pin doesn't change if an error were to happen in calculateTimerVals()
  int clock_freq = 12000000;
  calculateTimerVals(clock_freq, freq, duty, &ID, &EX0, &CCR0, &CCRN); // calculate register values

  pin->A_timer->CTL &= ~(0b11 << 6); // reset ID can change
  pin->A_timer->CTL |= (0b10 << 8) | // SMCLK
                (ID << 6) | // clock divider
                (0b01 << 4); // up mode
  pin->A_timer->EX0 = EX0; // clock divider multiple
  pin->A_timer->CCR[0] = CCR0; // count up to value to get frequency
  pin->A_timer->CCR[pin->timer_number] = CCRN; // divide count up value by this value to get duty cycle
  pin->A_timer->CCTL[pin->timer_number] |= (0b111 << 5); // "reset-set" mode
}

/**
* @brief Read analog voltage on a pin
*
* @note Not all pins have the ability to have analog read.
*
* @param pin Target pin
*
* @return uint32_t ADC val : This function will linearly turn the analog voltage on the pin to a digital
*           number. 0[V] is mapped to a uint of 0, 3.3[V] and above is mapped to a uint of 2^14 - 1, 16383.
*           Voltage can be determined by taking (double)(analogRead(pin) * 3.3 / 16383.0)
*
* @warning If this function is interrupted and another analog read is called, unexpected behavior
*            may occur because pins share the same global ADC hardware
*****************************************************************************/
uint32_t analogRead (struct MSP432_PIN *pin) {
  enum MSP432_PIN_TYPE allowed_types[] = {ANALOG_INPUT};
  if (pinTypeCheck(pin->pin_type, allowed_types, 1)) return 0; // exit

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


/**
* @brief Calculates the register values for PWM output
*
* @param pin Target pin
* @param freq double : output frequency of the pin
* @param duty double : duty cycle of the pin
* @param *ID int : clock divider register
* @param *EX0 int : clock divider register
* @param *CCR0 int : register to set frequency
* @param *CCRN int : register to set duty
*
* @return void
*****************************************************************************/
static void calculateTimerVals (int clockFreq, double freq, double duty, int *ID, int *EX0, int *CCR0, int *CCRN) {
  if (freq <= 0) return; // can't divide by 0, and can't have negative frequency I think???
  if (duty < 0.0) duty = 0.0; // bound duty
  if (duty > 1.0) duty = 1.0; // bound duty

  double Tcm = 1 / freq; // from equatio
  int id, ex0; // temp variables for pointers
  for (id = 1; id <= 8; id *= 2) { // multiply by two from 1 to 8: 1, 2, 4, 8
    for (ex0 = 1; ex0 <= 8; ex0++) { // increment from 1 to 8: 1, 2, 3, 4, 5, 6, 7, 8
      double TA = ((Tcm * clockFreq) / (id * ex0)) - 1; // from equation: TA = ((T * TCLK) / N) - 1
      if (TA < 65535) { // use the first value that fits, this works because N goes from min to max in for loop
        *ID = (id >> 1);
        if (id == 8) *ID = 3; // convert ID int number to register value
        *EX0 = ex0 - 1; // minus one is how to convert for EX0 int to register value
        *CCR0 = (int)round(TA); // the integer part of TA (in case of a machine precision error)
        *CCRN = round(*CCR0 * duty); // the correct multiplication for CCRN in up mode
        return;
      }
    }
  }
}

/**
* @brief determines if a pin's type is contained within an array of allowed pin types
*
* @param pin_type Target pin's type
* @param allowed_types[] : array of allowed pin types
* @param num_allowed_tupes uint8_t : number of items in allowed_types array
*
* @return boolean : 0, pin passes check. 1, pin fails check
*****************************************************************************/
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
