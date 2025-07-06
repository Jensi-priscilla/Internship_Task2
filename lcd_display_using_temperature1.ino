#include <LiquidCrystal.h>

// LCD pins: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);         // Initialize 16x2 LCD
  lcd.print("Temp Display"); // Show welcome text
  delay(2000);               // Show for 2 seconds
  lcd.clear();
}

void loop() {
  int sensorValue = analogRead(A0);        // Read TMP36 from A0
  float voltage = sensorValue * (5.0 / 1023.0); // Convert to voltage
  float temperatureC = (voltage - 0.5) * 100;   // TMP36 formula

  lcd.setCursor(0, 0);           // First row
  lcd.print("Temp: ");
  lcd.print(temperatureC, 1);    // Show 1 decimal place
  lcd.print((char)223);          // Degree symbol
  lcd.print("C");

  delay(1000); // Update every second
}
