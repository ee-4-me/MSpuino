// mspuino_pins.h
// Created: 09/15/2022
// Author: Logan Luedtke

#ifndef MSPUINO_PINS_H_
#define MSPUINO_PINS_H_

#include "msp.h"
#include <stdint.h>
#include <stdbool.h>

enum MSP432_PIN_TYPE {
  NOT_SET,
  ANALOG_INPUT,
  ANALOG_OUTPUT,  
  DIGITAL_INPUT,
  DIGITAL_INPUT_PULLUP,
  DIGITAL_INPUT_PULLDOWN,
  DIGITAL_OUTPUT
};

struct MSP432_PIN {
  enum MSP432_PIN_TYPE pin_type;

  DIO_PORT_Odd_Interruptable_Type* gpio_port_odd;
  DIO_PORT_Even_Interruptable_Type* gpio_port_even;

  bool gpio_port_is_even; // best way I have in C to keep track of even or odd types

  uint8_t gpio_pin;

  bool is_timer;
  bool is_analog;

  Timer_A_Type* A_timer;
  uint8_t timer_number;
  uint8_t analog_number;
};

extern struct MSP432_PIN *P1_0;
extern struct MSP432_PIN *P1_1;
extern struct MSP432_PIN *P1_2;
extern struct MSP432_PIN *P1_3;
extern struct MSP432_PIN *P1_4;
extern struct MSP432_PIN *P1_5;
extern struct MSP432_PIN *P1_6;
extern struct MSP432_PIN *P1_7;
extern struct MSP432_PIN *P2_0;
extern struct MSP432_PIN *P2_1;
extern struct MSP432_PIN *P2_2;
extern struct MSP432_PIN *P2_3;
extern struct MSP432_PIN *P2_4;
extern struct MSP432_PIN *P2_5;
extern struct MSP432_PIN *P2_6;
extern struct MSP432_PIN *P2_7;
extern struct MSP432_PIN *P3_0;
extern struct MSP432_PIN *P3_1;
extern struct MSP432_PIN *P3_2;
extern struct MSP432_PIN *P3_3;
extern struct MSP432_PIN *P3_4;
extern struct MSP432_PIN *P3_5;
extern struct MSP432_PIN *P3_6;
extern struct MSP432_PIN *P3_7;
extern struct MSP432_PIN *P4_0;
extern struct MSP432_PIN *P4_1;
extern struct MSP432_PIN *P4_2;
extern struct MSP432_PIN *P4_3;
extern struct MSP432_PIN *P4_4;
extern struct MSP432_PIN *P4_5;
extern struct MSP432_PIN *P4_6;
extern struct MSP432_PIN *P4_7;
extern struct MSP432_PIN *P5_0;
extern struct MSP432_PIN *P5_1;
extern struct MSP432_PIN *P5_2;
extern struct MSP432_PIN *P5_3;
extern struct MSP432_PIN *P5_4;
extern struct MSP432_PIN *P5_5;
extern struct MSP432_PIN *P5_6;
extern struct MSP432_PIN *P5_7;
extern struct MSP432_PIN *P6_0;
extern struct MSP432_PIN *P6_1;
extern struct MSP432_PIN *P6_2;
extern struct MSP432_PIN *P6_3;
extern struct MSP432_PIN *P6_4;
extern struct MSP432_PIN *P6_5;
extern struct MSP432_PIN *P6_6;
extern struct MSP432_PIN *P6_7;
extern struct MSP432_PIN *P7_0;
extern struct MSP432_PIN *P7_1;
extern struct MSP432_PIN *P7_2;
extern struct MSP432_PIN *P7_3;
extern struct MSP432_PIN *P7_4;
extern struct MSP432_PIN *P7_5;
extern struct MSP432_PIN *P7_6;
extern struct MSP432_PIN *P7_7;
extern struct MSP432_PIN *P8_0;
extern struct MSP432_PIN *P8_1;
extern struct MSP432_PIN *P8_2;
extern struct MSP432_PIN *P8_3;
extern struct MSP432_PIN *P8_4;
extern struct MSP432_PIN *P8_5;
extern struct MSP432_PIN *P8_6;
extern struct MSP432_PIN *P8_7;
extern struct MSP432_PIN *P9_0;
extern struct MSP432_PIN *P9_1;
extern struct MSP432_PIN *P9_2;
extern struct MSP432_PIN *P9_3;
extern struct MSP432_PIN *P9_4;
extern struct MSP432_PIN *P9_5;
extern struct MSP432_PIN *P9_6;
extern struct MSP432_PIN *P9_7;
extern struct MSP432_PIN *P10_0;
extern struct MSP432_PIN *P10_1;
extern struct MSP432_PIN *P10_2;
extern struct MSP432_PIN *P10_3;
extern struct MSP432_PIN *P10_4;
extern struct MSP432_PIN *P10_5;

// timer pin pointers for ease of use
extern struct MSP432_PIN *TA0_0;
extern struct MSP432_PIN *TA0_1;
extern struct MSP432_PIN *TA0_2;
extern struct MSP432_PIN *TA0_3;
extern struct MSP432_PIN *TA0_4;
extern struct MSP432_PIN *TA1_0;
extern struct MSP432_PIN *TA1_1;
extern struct MSP432_PIN *TA1_2;
extern struct MSP432_PIN *TA1_3;
extern struct MSP432_PIN *TA1_4;
extern struct MSP432_PIN *TA2_0;
extern struct MSP432_PIN *TA2_1;
extern struct MSP432_PIN *TA2_2;
extern struct MSP432_PIN *TA2_3;
extern struct MSP432_PIN *TA2_4;
extern struct MSP432_PIN *TA3_0;
extern struct MSP432_PIN *TA3_1;
extern struct MSP432_PIN *TA3_2;
extern struct MSP432_PIN *TA3_3;
extern struct MSP432_PIN *TA3_4;

// analog input pins for ease of use
extern struct MSP432_PIN *A0;
extern struct MSP432_PIN *A1;
extern struct MSP432_PIN *A2;
extern struct MSP432_PIN *A3;
extern struct MSP432_PIN *A4;
extern struct MSP432_PIN *A5;
extern struct MSP432_PIN *A6;
extern struct MSP432_PIN *A7;
extern struct MSP432_PIN *A8;
extern struct MSP432_PIN *A9;
extern struct MSP432_PIN *A10;
extern struct MSP432_PIN *A11;
extern struct MSP432_PIN *A12;
extern struct MSP432_PIN *A13;
extern struct MSP432_PIN *A14;
extern struct MSP432_PIN *A15;
extern struct MSP432_PIN *A16;
extern struct MSP432_PIN *A17;
extern struct MSP432_PIN *A18;
extern struct MSP432_PIN *A19;
extern struct MSP432_PIN *A20;
extern struct MSP432_PIN *A21;
extern struct MSP432_PIN *A22;
extern struct MSP432_PIN *A23;

#endif // MSPUINO_PINS_H_
