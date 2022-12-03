// mspuino_util_functions.c
// Created: 11/30/2022
// Author: Logan Luedtke

#include "msp.h"

#include "mspuino_util_functions.h"

void initializeBoard (void) {
  stopWatchDog();
  powerSave();
}

void stopWatchDog (void) {
  WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer
}

// power save all pins by turning all pins to low outputs
void powerSave (void) {
  P1->SEL0 = 0; P1->SEL1 = 0; P1->DIR = 0xFF; P1->OUT = 0;
  P2->SEL0 = 0; P2->SEL1 = 0; P2->DIR = 0xFF; P2->OUT = 0;
  P3->SEL0 = 0; P3->SEL1 = 0; P3->DIR = 0xFF; P3->OUT = 0;
  P4->SEL0 = 0; P4->SEL1 = 0; P4->DIR = 0xFF; P4->OUT = 0;
  P5->SEL0 = 0; P5->SEL1 = 0; P5->DIR = 0xFF; P5->OUT = 0;
  P6->SEL0 = 0; P6->SEL1 = 0; P6->DIR = 0xFF; P6->OUT = 0;
  P7->SEL0 = 0; P7->SEL1 = 0; P7->DIR = 0xFF; P7->OUT = 0;
  P8->SEL0 = 0; P8->SEL1 = 0; P8->DIR = 0xFF; P8->OUT = 0;
  P9->SEL0 = 0; P9->SEL1 = 0; P9->DIR = 0xFF; P9->OUT = 0;
  P10->SEL0 = 0; P10->SEL1 = 0; P10->DIR = 0xFF; P10->OUT = 0;
}
