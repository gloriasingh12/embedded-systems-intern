// =================================================================
// PROJECT: Temperature Monitoring System (C++)
// DESCRIPTION: C++ implementation for LM35 Sensor Interfacing.
// =================================================================

#include <Arduino.h> // Industry standard for .cpp embedded files

const int sensorPin = A0; 

void setup() {
    Serial.begin(9600);
    Serial.println("--- System Initialized (C++ Mode) ---");
}

void loop() {
    // Reading raw data from A0
    int reading = analogRead(sensorPin);
    
    // Converting to voltage and then to Celsius
    float tempC = (reading * 5.0 / 1024.0) * 100.0;

    // Displaying Output
    Serial.print("Temperature: ");
    Serial.print(tempC);
    Serial.println(" C");

    delay(2000); // 2 Second interval
}
