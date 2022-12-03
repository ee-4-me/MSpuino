// mspuino_pins.c
// Created: 09/15/2022
// Author: Logan Luedtke

#include "msp.h"
#include <stdbool.h>

#include "mspuino_pins.h"

struct MSP432_PIN _P1_0 = {
	.pin_type = NOT_SET,
	.gpio_port_odd = P1,
	.gpio_port_is_even = false,
	.gpio_pin = BIT0,
	.is_timer = false,
	.is_analog = false
};

struct MSP432_PIN _P1_1 = {
	.pin_type = NOT_SET,
	.gpio_port_odd = P1,
	.gpio_port_is_even = false,
	.gpio_pin = BIT1,
	.is_timer = false,
	.is_analog = false
};

struct MSP432_PIN _P1_2 = {
	.pin_type = NOT_SET,
	.gpio_port_odd = P1,
	.gpio_port_is_even = false,
	.gpio_pin = BIT2,
	.is_timer = false,
	.is_analog = false
};

struct MSP432_PIN _P1_3 = {
	.pin_type = NOT_SET,
	.gpio_port_odd = P1,
	.gpio_port_is_even = false,
	.gpio_pin = BIT3,
	.is_timer = false,
	.is_analog = false
};

struct MSP432_PIN _P1_4 = {
	.pin_type = NOT_SET,
	.gpio_port_odd = P1,
	.gpio_port_is_even = false,
	.gpio_pin = BIT4,
	.is_timer = false,
	.is_analog = false
};

struct MSP432_PIN _P1_5 = {
	.pin_type = NOT_SET,
	.gpio_port_odd = P1,
	.gpio_port_is_even = false,
	.gpio_pin = BIT5,
	.is_timer = false,
	.is_analog = false
};

struct MSP432_PIN _P1_6 = {
	.pin_type = NOT_SET,
	.gpio_port_odd = P1,
	.gpio_port_is_even = false,
	.gpio_pin = BIT6,
	.is_timer = false,
	.is_analog = false
};

struct MSP432_PIN _P1_7 = {
	.pin_type = NOT_SET,
	.gpio_port_odd = P1,
	.gpio_port_is_even = false,
	.gpio_pin = BIT7,
	.is_timer = false,
	.is_analog = false
};

struct MSP432_PIN _P2_0 = {
	.pin_type = NOT_SET,
	.gpio_port_even = P2,
	.gpio_port_is_even = true,
	.gpio_pin = BIT0,
	.is_timer = false,
	.is_analog = false
};

struct MSP432_PIN _P2_1 = {
	.pin_type = NOT_SET,
	.gpio_port_even = P2,
	.gpio_port_is_even = true,
	.gpio_pin = BIT1,
	.is_timer = false,
	.is_analog = false
};

struct MSP432_PIN _P2_2 = {
	.pin_type = NOT_SET,
	.gpio_port_even = P2,
	.gpio_port_is_even = true,
	.gpio_pin = BIT2,
	.is_timer = false,
	.is_analog = false
};

struct MSP432_PIN _P2_3 = {
	.pin_type = NOT_SET,
	.gpio_port_even = P2,
	.gpio_port_is_even = true,
	.gpio_pin = BIT3,
	.is_timer = false,
	.is_analog = false
};

struct MSP432_PIN _P2_4 = {
	.pin_type = NOT_SET,
	.gpio_port_even = P2,
	.gpio_port_is_even = true,
	.gpio_pin = BIT4,
	.is_timer = true,
	.is_analog = false,
	.A_timer = TIMER_A0,
	.timer_number = 1
};

struct MSP432_PIN _P2_5 = {
	.pin_type = NOT_SET,
	.gpio_port_even = P2,
	.gpio_port_is_even = true,
	.gpio_pin = BIT5,
	.is_timer = true,
	.is_analog = false,
	.A_timer = TIMER_A0,
	.timer_number = 2
};

struct MSP432_PIN _P2_6 = {
	.pin_type = NOT_SET,
	.gpio_port_even = P2,
	.gpio_port_is_even = true,
	.gpio_pin = BIT6,
	.is_timer = true,
	.is_analog = false,
	.A_timer = TIMER_A0,
	.timer_number = 3
};

struct MSP432_PIN _P2_7 = {
	.pin_type = NOT_SET,
	.gpio_port_even = P2,
	.gpio_port_is_even = true,
	.gpio_pin = BIT7,
	.is_timer = true,
	.is_analog = false,
	.A_timer = TIMER_A0,
	.timer_number = 4
};

struct MSP432_PIN _P3_0 = {
	.pin_type = NOT_SET,
	.gpio_port_odd = P3,
	.gpio_port_is_even = false,
	.gpio_pin = BIT0,
	.is_timer = false,
	.is_analog = false
};

struct MSP432_PIN _P3_1 = {
	.pin_type = NOT_SET,
	.gpio_port_odd = P3,
	.gpio_port_is_even = false,
	.gpio_pin = BIT1,
	.is_timer = false,
	.is_analog = false
};

struct MSP432_PIN _P3_2 = {
	.pin_type = NOT_SET,
	.gpio_port_odd = P3,
	.gpio_port_is_even = false,
	.gpio_pin = BIT2,
	.is_timer = false,
	.is_analog = false
};

struct MSP432_PIN _P3_3 = {
	.pin_type = NOT_SET,
	.gpio_port_odd = P3,
	.gpio_port_is_even = false,
	.gpio_pin = BIT3,
	.is_timer = false,
	.is_analog = false
};

struct MSP432_PIN _P3_4 = {
	.pin_type = NOT_SET,
	.gpio_port_odd = P3,
	.gpio_port_is_even = false,
	.gpio_pin = BIT4,
	.is_timer = false,
	.is_analog = false
};

struct MSP432_PIN _P3_5 = {
	.pin_type = NOT_SET,
	.gpio_port_odd = P3,
	.gpio_port_is_even = false,
	.gpio_pin = BIT5,
	.is_timer = false,
	.is_analog = false
};

struct MSP432_PIN _P3_6 = {
	.pin_type = NOT_SET,
	.gpio_port_odd = P3,
	.gpio_port_is_even = false,
	.gpio_pin = BIT6,
	.is_timer = false,
	.is_analog = false
};

struct MSP432_PIN _P3_7 = {
	.pin_type = NOT_SET,
	.gpio_port_odd = P3,
	.gpio_port_is_even = false,
	.gpio_pin = BIT7,
	.is_timer = false,
	.is_analog = false
};

struct MSP432_PIN _P4_0 = {
	.pin_type = NOT_SET,
	.gpio_port_even = P4,
	.gpio_port_is_even = true,
	.gpio_pin = BIT0,
	.is_timer = false,
	.is_analog = true,
	.analog_number = 13
};

struct MSP432_PIN _P4_1 = {
	.pin_type = NOT_SET,
	.gpio_port_even = P4,
	.gpio_port_is_even = true,
	.gpio_pin = BIT1,
	.is_timer = false,
	.is_analog = true,
	.analog_number = 12
};

struct MSP432_PIN _P4_2 = {
	.pin_type = NOT_SET,
	.gpio_port_even = P4,
	.gpio_port_is_even = true,
	.gpio_pin = BIT2,
	.is_timer = false,
	.is_analog = true,
	.analog_number = 11
};

struct MSP432_PIN _P4_3 = {
	.pin_type = NOT_SET,
	.gpio_port_even = P4,
	.gpio_port_is_even = true,
	.gpio_pin = BIT3,
	.is_timer = false,
	.is_analog = true,
	.analog_number = 10
};

struct MSP432_PIN _P4_4 = {
	.pin_type = NOT_SET,
	.gpio_port_even = P4,
	.gpio_port_is_even = true,
	.gpio_pin = BIT4,
	.is_timer = false,
	.is_analog = true,
	.analog_number = 9
};

struct MSP432_PIN _P4_5 = {
	.pin_type = NOT_SET,
	.gpio_port_even = P4,
	.gpio_port_is_even = true,
	.gpio_pin = BIT5,
	.is_timer = false,
	.is_analog = true,
	.analog_number = 8
};

struct MSP432_PIN _P4_6 = {
	.pin_type = NOT_SET,
	.gpio_port_even = P4,
	.gpio_port_is_even = true,
	.gpio_pin = BIT6,
	.is_timer = false,
	.is_analog = true,
	.analog_number = 7
};

struct MSP432_PIN _P4_7 = {
	.pin_type = NOT_SET,
	.gpio_port_even = P4,
	.gpio_port_is_even = true,
	.gpio_pin = BIT7,
	.is_timer = false,
	.is_analog = true,
	.analog_number = 6
};

struct MSP432_PIN _P5_0 = {
	.pin_type = NOT_SET,
	.gpio_port_odd = P5,
	.gpio_port_is_even = false,
	.gpio_pin = BIT0,
	.is_timer = false,
	.is_analog = true,
	.analog_number = 5
};

struct MSP432_PIN _P5_1 = {
	.pin_type = NOT_SET,
	.gpio_port_odd = P5,
	.gpio_port_is_even = false,
	.gpio_pin = BIT1,
	.is_timer = false,
	.is_analog = true,
	.analog_number = 4
};

struct MSP432_PIN _P5_2 = {
	.pin_type = NOT_SET,
	.gpio_port_odd = P5,
	.gpio_port_is_even = false,
	.gpio_pin = BIT2,
	.is_timer = false,
	.is_analog = true,
	.analog_number = 3
};

struct MSP432_PIN _P5_3 = {
	.pin_type = NOT_SET,
	.gpio_port_odd = P5,
	.gpio_port_is_even = false,
	.gpio_pin = BIT3,
	.is_timer = false,
	.is_analog = true,
	.analog_number = 2
};

struct MSP432_PIN _P5_4 = {
	.pin_type = NOT_SET,
	.gpio_port_odd = P5,
	.gpio_port_is_even = false,
	.gpio_pin = BIT4,
	.is_timer = false,
	.is_analog = true,
	.analog_number = 1
};

struct MSP432_PIN _P5_5 = {
	.pin_type = NOT_SET,
	.gpio_port_odd = P5,
	.gpio_port_is_even = false,
	.gpio_pin = BIT5,
	.is_timer = false,
	.is_analog = true,
	.analog_number = 0
};

struct MSP432_PIN _P5_6 = {
	.pin_type = NOT_SET,
	.gpio_port_odd = P5,
	.gpio_port_is_even = false,
	.gpio_pin = BIT6,
	.is_timer = true,
	.is_analog = false,
	.A_timer = TIMER_A2,
	.timer_number = 1
};

struct MSP432_PIN _P5_7 = {
	.pin_type = NOT_SET,
	.gpio_port_odd = P5,
	.gpio_port_is_even = false,
	.gpio_pin = BIT7,
	.is_timer = true,
	.is_analog = false,
	.A_timer = TIMER_A2,
	.timer_number = 2
};

struct MSP432_PIN _P6_0 = {
	.pin_type = NOT_SET,
	.gpio_port_even = P6,
	.gpio_port_is_even = true,
	.gpio_pin = BIT0,
	.is_timer = false,
	.is_analog = true,
	.analog_number = 15
};

struct MSP432_PIN _P6_1 = {
	.pin_type = NOT_SET,
	.gpio_port_even = P6,
	.gpio_port_is_even = true,
	.gpio_pin = BIT1,
	.is_timer = false,
	.is_analog = true,
	.analog_number = 14
};

struct MSP432_PIN _P6_2 = {
	.pin_type = NOT_SET,
	.gpio_port_even = P6,
	.gpio_port_is_even = true,
	.gpio_pin = BIT2,
	.is_timer = false,
	.is_analog = false
};

struct MSP432_PIN _P6_3 = {
	.pin_type = NOT_SET,
	.gpio_port_even = P6,
	.gpio_port_is_even = true,
	.gpio_pin = BIT3,
	.is_timer = false,
	.is_analog = false
};

struct MSP432_PIN _P6_4 = {
	.pin_type = NOT_SET,
	.gpio_port_even = P6,
	.gpio_port_is_even = true,
	.gpio_pin = BIT4,
	.is_timer = false,
	.is_analog = false
};

struct MSP432_PIN _P6_5 = {
	.pin_type = NOT_SET,
	.gpio_port_even = P6,
	.gpio_port_is_even = true,
	.gpio_pin = BIT5,
	.is_timer = false,
	.is_analog = false
};

struct MSP432_PIN _P6_6 = {
	.pin_type = NOT_SET,
	.gpio_port_even = P6,
	.gpio_port_is_even = true,
	.gpio_pin = BIT6,
	.is_timer = true,
	.is_analog = false,
	.A_timer = TIMER_A2,
	.timer_number = 3
};

struct MSP432_PIN _P6_7 = {
	.pin_type = NOT_SET,
	.gpio_port_even = P6,
	.gpio_port_is_even = true,
	.gpio_pin = BIT7,
	.is_timer = true,
	.is_analog = false,
	.A_timer = TIMER_A2,
	.timer_number = 4
};

struct MSP432_PIN _P7_0 = {
	.pin_type = NOT_SET,
	.gpio_port_odd = P7,
	.gpio_port_is_even = false,
	.gpio_pin = BIT0,
	.is_timer = false,
	.is_analog = false
};

struct MSP432_PIN _P7_1 = {
	.pin_type = NOT_SET,
	.gpio_port_odd = P7,
	.gpio_port_is_even = false,
	.gpio_pin = BIT1,
	.is_timer = false,
	.is_analog = false
};

struct MSP432_PIN _P7_2 = {
	.pin_type = NOT_SET,
	.gpio_port_odd = P7,
	.gpio_port_is_even = false,
	.gpio_pin = BIT2,
	.is_timer = false,
	.is_analog = false
};

struct MSP432_PIN _P7_3 = {
	.pin_type = NOT_SET,
	.gpio_port_odd = P7,
	.gpio_port_is_even = false,
	.gpio_pin = BIT3,
	.is_timer = true,
	.is_analog = false,
	.A_timer = TIMER_A0,
	.timer_number = 0
};

struct MSP432_PIN _P7_4 = {
	.pin_type = NOT_SET,
	.gpio_port_odd = P7,
	.gpio_port_is_even = false,
	.gpio_pin = BIT4,
	.is_timer = true,
	.is_analog = false,
	.A_timer = TIMER_A1,
	.timer_number = 4
};

struct MSP432_PIN _P7_5 = {
	.pin_type = NOT_SET,
	.gpio_port_odd = P7,
	.gpio_port_is_even = false,
	.gpio_pin = BIT5,
	.is_timer = true,
	.is_analog = false,
	.A_timer = TIMER_A1,
	.timer_number = 3
};

struct MSP432_PIN _P7_6 = {
	.pin_type = NOT_SET,
	.gpio_port_odd = P7,
	.gpio_port_is_even = false,
	.gpio_pin = BIT6,
	.is_timer = true,
	.is_analog = false,
	.A_timer = TIMER_A1,
	.timer_number = 2
};

struct MSP432_PIN _P7_7 = {
	.pin_type = NOT_SET,
	.gpio_port_odd = P7,
	.gpio_port_is_even = false,
	.gpio_pin = BIT7,
	.is_timer = true,
	.is_analog = false,
	.A_timer = TIMER_A1,
	.timer_number = 1
};

struct MSP432_PIN _P8_0 = {
	.pin_type = NOT_SET,
	.gpio_port_even = P8,
	.gpio_port_is_even = true,
	.gpio_pin = BIT0,
	.is_timer = true,
	.is_analog = false,
	.A_timer = TIMER_A1,
	.timer_number = 0
};

struct MSP432_PIN _P8_1 = {
	.pin_type = NOT_SET,
	.gpio_port_even = P8,
	.gpio_port_is_even = true,
	.gpio_pin = BIT1,
	.is_timer = true,
	.is_analog = false,
	.A_timer = TIMER_A2,
	.timer_number = 0
};

struct MSP432_PIN _P8_2 = {
	.pin_type = NOT_SET,
	.gpio_port_even = P8,
	.gpio_port_is_even = true,
	.gpio_pin = BIT2,
	.is_timer = true,
	.is_analog = true,
	.A_timer = TIMER_A3,
	.timer_number = 2,
	.analog_number = 23
};

struct MSP432_PIN _P8_3 = {
	.pin_type = NOT_SET,
	.gpio_port_even = P8,
	.gpio_port_is_even = true,
	.gpio_pin = BIT3,
	.is_timer = false,
	.is_analog = true,
	.analog_number = 22
};

struct MSP432_PIN _P8_4 = {
	.pin_type = NOT_SET,
	.gpio_port_even = P8,
	.gpio_port_is_even = true,
	.gpio_pin = BIT4,
	.is_timer = false,
	.is_analog = true,
	.analog_number = 21
};

struct MSP432_PIN _P8_5 = {
	.pin_type = NOT_SET,
	.gpio_port_even = P8,
	.gpio_port_is_even = true,
	.gpio_pin = BIT5,
	.is_timer = false,
	.is_analog = true,
	.analog_number = 20
};

struct MSP432_PIN _P8_6 = {
	.pin_type = NOT_SET,
	.gpio_port_even = P8,
	.gpio_port_is_even = true,
	.gpio_pin = BIT6,
	.is_timer = false,
	.is_analog = true,
	.analog_number = 19
};

struct MSP432_PIN _P8_7 = {
	.pin_type = NOT_SET,
	.gpio_port_even = P8,
	.gpio_port_is_even = true,
	.gpio_pin = BIT7,
	.is_timer = false,
	.is_analog = true,
	.analog_number = 18
};

struct MSP432_PIN _P9_0 = {
	.pin_type = NOT_SET,
	.gpio_port_odd = P9,
	.gpio_port_is_even = false,
	.gpio_pin = BIT0,
	.is_timer = false,
	.is_analog = true,
	.analog_number = 17
};

struct MSP432_PIN _P9_1 = {
	.pin_type = NOT_SET,
	.gpio_port_odd = P9,
	.gpio_port_is_even = false,
	.gpio_pin = BIT1,
	.is_timer = false,
	.is_analog = true,
	.analog_number = 16
};

struct MSP432_PIN _P9_2 = {
	.pin_type = NOT_SET,
	.gpio_port_odd = P9,
	.gpio_port_is_even = false,
	.gpio_pin = BIT2,
	.is_timer = true,
	.is_analog = false,
	.A_timer = TIMER_A3,
	.timer_number = 3
};

struct MSP432_PIN _P9_3 = {
	.pin_type = NOT_SET,
	.gpio_port_odd = P9,
	.gpio_port_is_even = false,
	.gpio_pin = BIT3,
	.is_timer = true,
	.is_analog = false,
	.A_timer = TIMER_A3,
	.timer_number = 4
};

struct MSP432_PIN _P9_4 = {
	.pin_type = NOT_SET,
	.gpio_port_odd = P9,
	.gpio_port_is_even = false,
	.gpio_pin = BIT4,
	.is_timer = false,
	.is_analog = false
};

struct MSP432_PIN _P9_5 = {
	.pin_type = NOT_SET,
	.gpio_port_odd = P9,
	.gpio_port_is_even = false,
	.gpio_pin = BIT5,
	.is_timer = false,
	.is_analog = false
};

struct MSP432_PIN _P9_6 = {
	.pin_type = NOT_SET,
	.gpio_port_odd = P9,
	.gpio_port_is_even = false,
	.gpio_pin = BIT6,
	.is_timer = false,
	.is_analog = false
};

struct MSP432_PIN _P9_7 = {
	.pin_type = NOT_SET,
	.gpio_port_odd = P9,
	.gpio_port_is_even = false,
	.gpio_pin = BIT7,
	.is_timer = false,
	.is_analog = false
};

struct MSP432_PIN _P10_0 = {
	.pin_type = NOT_SET,
	.gpio_port_even = P10,
	.gpio_port_is_even = true,
	.gpio_pin = BIT0,
	.is_timer = false,
	.is_analog = false
};

struct MSP432_PIN _P10_1 = {
	.pin_type = NOT_SET,
	.gpio_port_even = P10,
	.gpio_port_is_even = true,
	.gpio_pin = BIT1,
	.is_timer = false,
	.is_analog = false
};

struct MSP432_PIN _P10_2 = {
	.pin_type = NOT_SET,
	.gpio_port_even = P10,
	.gpio_port_is_even = true,
	.gpio_pin = BIT2,
	.is_timer = false,
	.is_analog = false
};

struct MSP432_PIN _P10_3 = {
	.pin_type = NOT_SET,
	.gpio_port_even = P10,
	.gpio_port_is_even = true,
	.gpio_pin = BIT3,
	.is_timer = false,
	.is_analog = false
};

struct MSP432_PIN _P10_4 = {
	.pin_type = NOT_SET,
	.gpio_port_even = P10,
	.gpio_port_is_even = true,
	.gpio_pin = BIT4,
	.is_timer = true,
	.is_analog = false,
	.A_timer = TIMER_A3,
	.timer_number = 0
};

struct MSP432_PIN _P10_5 = {
	.pin_type = NOT_SET,
	.gpio_port_even = P10,
	.gpio_port_is_even = true,
	.gpio_pin = BIT5,
	.is_timer = true,
	.is_analog = false,
	.A_timer = TIMER_A3,
	.timer_number = 1
};

struct MSP432_PIN *P1_0 = &_P1_0;
struct MSP432_PIN *P1_1 = &_P1_1;
struct MSP432_PIN *P1_2 = &_P1_2;
struct MSP432_PIN *P1_3 = &_P1_3;
struct MSP432_PIN *P1_4 = &_P1_4;
struct MSP432_PIN *P1_5 = &_P1_5;
struct MSP432_PIN *P1_6 = &_P1_6;
struct MSP432_PIN *P1_7 = &_P1_7;
struct MSP432_PIN *P2_0 = &_P2_0;
struct MSP432_PIN *P2_1 = &_P2_1;
struct MSP432_PIN *P2_2 = &_P2_2;
struct MSP432_PIN *P2_3 = &_P2_3;
struct MSP432_PIN *P2_4 = &_P2_4;
struct MSP432_PIN *P2_5 = &_P2_5;
struct MSP432_PIN *P2_6 = &_P2_6;
struct MSP432_PIN *P2_7 = &_P2_7;
struct MSP432_PIN *P3_0 = &_P3_0;
struct MSP432_PIN *P3_1 = &_P3_1;
struct MSP432_PIN *P3_2 = &_P3_2;
struct MSP432_PIN *P3_3 = &_P3_3;
struct MSP432_PIN *P3_4 = &_P3_4;
struct MSP432_PIN *P3_5 = &_P3_5;
struct MSP432_PIN *P3_6 = &_P3_6;
struct MSP432_PIN *P3_7 = &_P3_7;
struct MSP432_PIN *P4_0 = &_P4_0;
struct MSP432_PIN *P4_1 = &_P4_1;
struct MSP432_PIN *P4_2 = &_P4_2;
struct MSP432_PIN *P4_3 = &_P4_3;
struct MSP432_PIN *P4_4 = &_P4_4;
struct MSP432_PIN *P4_5 = &_P4_5;
struct MSP432_PIN *P4_6 = &_P4_6;
struct MSP432_PIN *P4_7 = &_P4_7;
struct MSP432_PIN *P5_0 = &_P5_0;
struct MSP432_PIN *P5_1 = &_P5_1;
struct MSP432_PIN *P5_2 = &_P5_2;
struct MSP432_PIN *P5_3 = &_P5_3;
struct MSP432_PIN *P5_4 = &_P5_4;
struct MSP432_PIN *P5_5 = &_P5_5;
struct MSP432_PIN *P5_6 = &_P5_6;
struct MSP432_PIN *P5_7 = &_P5_7;
struct MSP432_PIN *P6_0 = &_P6_0;
struct MSP432_PIN *P6_1 = &_P6_1;
struct MSP432_PIN *P6_2 = &_P6_2;
struct MSP432_PIN *P6_3 = &_P6_3;
struct MSP432_PIN *P6_4 = &_P6_4;
struct MSP432_PIN *P6_5 = &_P6_5;
struct MSP432_PIN *P6_6 = &_P6_6;
struct MSP432_PIN *P6_7 = &_P6_7;
struct MSP432_PIN *P7_0 = &_P7_0;
struct MSP432_PIN *P7_1 = &_P7_1;
struct MSP432_PIN *P7_2 = &_P7_2;
struct MSP432_PIN *P7_3 = &_P7_3;
struct MSP432_PIN *P7_4 = &_P7_4;
struct MSP432_PIN *P7_5 = &_P7_5;
struct MSP432_PIN *P7_6 = &_P7_6;
struct MSP432_PIN *P7_7 = &_P7_7;
struct MSP432_PIN *P8_0 = &_P8_0;
struct MSP432_PIN *P8_1 = &_P8_1;
struct MSP432_PIN *P8_2 = &_P8_2;
struct MSP432_PIN *P8_3 = &_P8_3;
struct MSP432_PIN *P8_4 = &_P8_4;
struct MSP432_PIN *P8_5 = &_P8_5;
struct MSP432_PIN *P8_6 = &_P8_6;
struct MSP432_PIN *P8_7 = &_P8_7;
struct MSP432_PIN *P9_0 = &_P9_0;
struct MSP432_PIN *P9_1 = &_P9_1;
struct MSP432_PIN *P9_2 = &_P9_2;
struct MSP432_PIN *P9_3 = &_P9_3;
struct MSP432_PIN *P9_4 = &_P9_4;
struct MSP432_PIN *P9_5 = &_P9_5;
struct MSP432_PIN *P9_6 = &_P9_6;
struct MSP432_PIN *P9_7 = &_P9_7;
struct MSP432_PIN *P10_0 = &_P10_0;
struct MSP432_PIN *P10_1 = &_P10_1;
struct MSP432_PIN *P10_2 = &_P10_2;
struct MSP432_PIN *P10_3 = &_P10_3;
struct MSP432_PIN *P10_4 = &_P10_4;
struct MSP432_PIN *P10_5 = &_P10_5;

struct MSP432_PIN *TA0_0 = &_P7_3;
struct MSP432_PIN *TA0_1 = &_P2_4;
struct MSP432_PIN *TA0_2 = &_P2_5;
struct MSP432_PIN *TA0_3 = &_P2_6;
struct MSP432_PIN *TA0_4 = &_P2_7;
struct MSP432_PIN *TA1_0 = &_P8_0;
struct MSP432_PIN *TA1_1 = &_P7_7;
struct MSP432_PIN *TA1_2 = &_P7_6;
struct MSP432_PIN *TA1_3 = &_P7_5;
struct MSP432_PIN *TA1_4 = &_P7_4;
struct MSP432_PIN *TA2_0 = &_P8_1;
struct MSP432_PIN *TA2_1 = &_P5_6;
struct MSP432_PIN *TA2_2 = &_P5_7;
struct MSP432_PIN *TA2_3 = &_P6_6;
struct MSP432_PIN *TA2_4 = &_P6_7;
struct MSP432_PIN *TA3_0 = &_P10_4;
struct MSP432_PIN *TA3_1 = &_P10_5;
struct MSP432_PIN *TA3_2 = &_P8_2;
struct MSP432_PIN *TA3_3 = &_P9_2;
struct MSP432_PIN *TA3_4 = &_P9_3;

struct MSP432_PIN *A0 = &_P5_5;
struct MSP432_PIN *A1 = &_P5_4;
struct MSP432_PIN *A2 = &_P5_3;
struct MSP432_PIN *A3 = &_P5_2;
struct MSP432_PIN *A4 = &_P5_1;
struct MSP432_PIN *A5 = &_P5_0;
struct MSP432_PIN *A6 = &_P4_7;
struct MSP432_PIN *A7 = &_P4_6;
struct MSP432_PIN *A8 = &_P4_5;
struct MSP432_PIN *A9 = &_P4_4;
struct MSP432_PIN *A10 = &_P4_3;
struct MSP432_PIN *A11 = &_P4_2;
struct MSP432_PIN *A12 = &_P4_1;
struct MSP432_PIN *A13 = &_P4_0;
struct MSP432_PIN *A14 = &_P6_1;
struct MSP432_PIN *A15 = &_P6_0;
struct MSP432_PIN *A16 = &_P9_1;
struct MSP432_PIN *A17 = &_P9_0;
struct MSP432_PIN *A18 = &_P8_7;
struct MSP432_PIN *A19 = &_P8_6;
struct MSP432_PIN *A20 = &_P8_5;
struct MSP432_PIN *A21 = &_P8_4;
struct MSP432_PIN *A22 = &_P8_3;
struct MSP432_PIN *A23 = &_P8_2;
