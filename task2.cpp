// =================================================================
// PROJECT: Temperature Monitoring System
// DELIVERABLE: Correct Code for LM35/DHT Sensor
// =================================================================

const int sensorPin = A0; // LM35 Output connect to A0

void setup() {
  Serial.begin(9600); 
  Serial.println("🌡️ System Started...");
}

void loop() {
  // Reading analog data
  int rawValue = analogRead(sensorPin);
  
  // Convert to voltage (assuming 5V)
  float voltage = (rawValue / 1024.0) * 5000; 
  
  // Convert to Celsius (10mV = 1 degree)
  float tempC = voltage / 10.0;

  // Print to Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(tempC);
  Serial.println(" C");

  delay(2000); // 2 second gap
}
