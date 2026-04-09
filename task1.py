// =================================================================
// PROJECT: Real-time Temperature Monitoring System
// DESCRIPTION: Reading data from LM35/DHT11 and displaying on LCD.
// DELIVERABLE: Circuit Logic, Code, and Serial Output.
// =================================================================

/* --- CIRCUIT DESIGN (Logical Connection) ---
1. Sensor (LM35) VCC -> 5V
2. Sensor (LM35) GND -> GND
3. Sensor (LM35) Vout -> Analog Pin A0
4. 16x2 LCD -> Connected to pins (12, 11, 5, 4, 3, 2)
*/

#include <LiquidCrystal.h>

// Initialize the LCD interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int sensorPin = A0; // LM35 connected to A0

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Temp Monitor");
  delay(1000);
  lcd.clear();
  print("⚙️ System Initialized...");
}

void loop() {
  // Reading analog voltage
  int reading = analogRead(sensorPin);
  
  // Convert analog reading to voltage
  float voltage = reading * (5.0 / 1024.0);
  
  // Convert voltage to Temperature in Celsius (LM35: 10mV per degree)
  float tempC = voltage * 100;

  // 1. Output to Serial Monitor
  Serial.print("Current Temp: ");
  Serial.print(tempC);
  Serial.println(" C");

  // 2. Output to LCD Display
  lcd.setCursor(0, 0);
  lcd.print("Temperature:");
  lcd.setCursor(0, 1);
  lcd.print(tempC);
  lcd.print(" C");

  delay(2000); // Wait for 2 seconds before next reading
}
