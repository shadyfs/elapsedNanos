#include "elapsed_nanos.h"

void initNanosTimer() {
    ARM_DWT_CTRL |= ARM_DWT_CTRL_CYCCNTENA;  // Enable DWT cycle counting
    ARM_DWT_CYCCNT = 0;  // Reset the DWT counter
}

unsigned long updateTotalCycles() {
    unsigned long currentCycleCount = ARM_DWT_CYCCNT;  // Read DWT counter
    return currentCycleCount;
}

unsigned long long elapsedNanos() {
    unsigned long totalCycles = updateTotalCycles();
    return (totalCycles * 1000ULL) / 600;
}

//#include "elapsed_nanos.h"
//#include <Arduino.h>
//#include <imxrt.h>  // Teensy 4.x-specific hardware definitions
//
//void initGptTimer() {
//    // Enable GPT1 clock (Bus Clock ON)
//    CCM_CCGR1 |= CCM_CCGR1_GPT1_BUS(CCM_CCGR_ON);
//
//    // Disable the GPT1 timer before configuration
//    GPT1_CR = 0;          // Reset the control register
//    GPT1_SR = 0x3F;       // Clear any pending status flags
//
//    // Set GPT1 to use the 24 MHz ipg_clk directly (no prescaler)
//    GPT1_PR = 0;          // No prescaler (1 tick = 41.67 ns)
//
//    // Select the ipg_clk as the clock source for GPT1
//    GPT1_CR |= GPT_CR_CLKSRC(1);  // Use the Peripheral Clock (24 MHz)
//
//    // Enable the timer in free-running mode
//    GPT1_CR |= GPT_CR_EN;
//}
//
//unsigned long long elapsedGptNanos() {
//    // Read the current counter value from GPT1
//    noInterrupts();
//    unsigned long cycles = GPT1_CNT;
//    interrupts();
//
//    // Convert cycles to nanoseconds (41.67 ns per tick)
//    return (cycles * 41) / 24;
//}
