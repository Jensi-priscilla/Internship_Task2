# Internship_Task2
# LCD Temperature Display using Arduino

This Arduino project uses a **TMP36 temperature sensor** to read temperature and displays the result on a **16x2 LCD**. The circuit is simulated using [Tinkercad](https://www.tinkercad.com/things/ch4UX2GBjT2-lcd-display-using-temperature).

## 🔗 Live Simulation

[Click here to open the Tinkercad simulation](https://www.tinkercad.com/things/ch4UX2GBjT2-lcd-display-using-temperature)

---

## 🛠️ Components Used

- Arduino UNO
- TMP36 Temperature Sensor
- 16x2 LCD Display
- 10k Potentiometer
- Breadboard
- Jumper Wires
- 220Ω Resistor (for LCD backlight)

---

## 🔌 Circuit Connections

### LCD to Arduino:
- RS → 12  
- E  → 11  
- D4 → 5  
- D5 → 4  
- D6 → 3  
- D7 → 2  
- VO → Middle pin of 10k potentiometer  
- VSS → GND  
- VDD → 5V  
- RW  → GND  
- LED+ → 5V via 220Ω resistor  
- LED- → GND  

### TMP36 to Arduino:
- Left pin → 5V  
- Middle pin → A0  
- Right pin → GND  

---

## 🧠 How It Works

The TMP36 outputs voltage based on temperature:
- 0.5V at 0°C
- 10 mV/°C

Arduino reads analog value, converts it to voltage, and then to °C.

---

## 📟 Arduino Code

```cpp
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);
  lcd.print("Temp Display");
  delay(2000);
  lcd.clear();
}

void loop() {
  int sensorValue = analogRead(A0);
  float voltage = sensorValue * (5.0 / 1023.0);
  float temperatureC = (voltage - 0.5) * 100;

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperatureC, 1);
  lcd.print((char)223);
  lcd.print("C");

  delay(1000);
}
