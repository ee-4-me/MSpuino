# MSpuino
## A library that provides the easy-to-use Arduino functions to the MSP432 Launchpad


Note: This library is a work in progress, and is not complete at the moment.

Things to be done yet:

- Code functionality
  - Interrupt protection on analog read function
  - Additional testing on analog read pins (just got that working :) )
  - Adding pin functions for more analog write variants to define duty and frequency, and the og arduino 0-255 function for analog write
  - Adopting more arduino behaviors for edge cases (like what happens when calling analog read on a pin that is not connected to ADC for example)
- Library housekeeping
  - Adding examples to this readme :)
  - Re-organizing the files in this library?
  - Creating a guide for how to download and setup this library in Code Composer Studio
  - Ensuring that this library can be downloaded and used
