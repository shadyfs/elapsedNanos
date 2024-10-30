#include "elapsed_nanos.h"

elapsedMicros microsTimer;  // Timer for microsecond measurement
unsigned long long totalElapsedNanos = 0;  // 64-bit accumulator
unsigned long long previousNanos = 0;           // Store the last reading 

void setup() {
    Serial.begin(9600);
    Serial.println("Starting nanosecond precision test...");
    Serial.print("Initial CPU Frequency: ");
    Serial.println(F_CPU_ACTUAL);
    microsTimer = 0;
    initNanosTimer();  // Initialize DWT-based nanos timer
}

void loop() {  
    unsigned long microsElapsed = microsTimer;
    unsigned long long nanosElapsed = elapsedNanos();
    totalElapsedNanos += (nanoElapsed - previousNanos);
    if (totalElapsedNanos >= 60000000000ULL){
      totalElapsedNanos += (nanoElapsed - previousNanos);
      microsTimer = 0; 
      ARM_DWT_CYCCNT = 0;  
      //    unsigned long convertedMicros = nanosElapsed / 1000;
      //    long long skew = (long long)microsElapsed - (long long)convertedMicros;
      //    Serial.print("Elapsed micros: ");
      //    Serial.println(microsElapsed);
      //
      //    Serial.print("Elapsed Nanos: ");
      //    Serial.println(nanosElapsed);
      //
      //    Serial.print("Converted micros (from nanos): ");
      //    Serial.println(convertedMicros);
      //
      //    Serial.print("Skew between micros and converted micros: ");
      //    Serial.println(skew); 
    }
}



//#include "elapsed_nanos.h"
//
//void setup() {
//    Serial.begin(9600);
//
//    initGptTimer();  // Initialize the GPT1 timer
//    Serial.println("GPT Timer Initialized...");
//}
//
//void loop() {
//    delay(1000);  // 1 second delay
//
//    unsigned long long nanosElapsed = elapsedGptNanos();
//    Serial.print("Elapsed nanos: ");
//    Serial.println(nanosElapsed);
//}
