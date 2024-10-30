#ifndef ELAPSED_NANOS_H
#define ELAPSED_NANOS_H

#include <Arduino.h>

// Function to initialize DWT cycle counter
void initNanosTimer();

// Function to get elapsed time in nanoseconds
unsigned long long elapsedNanos();

#endif  // ELAPSED_NANOS_H\

//#ifndef GPT_TIMER_H
//#define GPT_TIMER_H
//
//#include <Arduino.h>
//
//void initGptTimer();  // Initialize GPT1 Timer
//unsigned long long elapsedGptNanos();  // Return elapsed nanoseconds
//
//#endif  // GPT_TIMER_H
