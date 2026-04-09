// =================================================================
// PROJECT: Speech Recognition Control System
// DESCRIPTION: Voice-commanded device control using Embedded Board.
// DELIVERABLE: System Architecture and Command Execution Code.
// =================================================================

#include <Arduino.h>
#include <SoftwareSerial.h>

// Pins for Voice Recognition Module (TX, RX)
SoftwareSerial voice(2, 3); 

const int relayPin = 8; // Connected to Light/Device
uint8_t records[7]; // Save voice command IDs
uint8_t buf[64];

void setup() {
    Serial.begin(9600);
    voice.begin(9600);
    
    pinMode(relayPin, OUTPUT);
    digitalWrite(relayPin, HIGH); // Default OFF (Active Low Relay)

    Serial.println("🎙️ Voice Recognition System Initializing...");
    
    // Commands trained in Module:
    // ID 1: "Light ON"
    // ID 2: "Light OFF"
}

void loop() {
    int ret = voice.read(buf); // Read incoming voice command
    
    if(ret > 0) {
        switch(buf[1]) {
            case 0x01: // Command ID 1 detected
                digitalWrite(relayPin, LOW); // Turn ON
                Serial.println("✅ Command Received: [LIGHT ON]");
                break;
                
            case 0x02: // Command ID 2 detected
                digitalWrite(relayPin, HIGH); // Turn OFF
                Serial.println("✅ Command Received: [LIGHT OFF]");
                break;

            default:
                Serial.println("❓ Unknown Voice Command.");
                break;
        }
    }
}
