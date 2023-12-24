/*
Example for Arduino Uno R4 Minima with LCD Screen (I2C).
By: RoboticX Team
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Define I2C address and LCD parameters
const int I2C_ADDRESS = 0x27;  // I2C address of the LCD module
const int LCD_COLS = 20;       // Number of LCD columns
const int LCD_ROWS = 4;        // Number of LCD rows

// Create an LCD object
LiquidCrystal_I2C lcd(I2C_ADDRESS, LCD_COLS, LCD_ROWS);

void setup() {
  // Initialize Serial communication
  Serial.begin(9600);

  // Initialize I2C communication
  Wire.begin();

  // Initialize the LCD and clear the display
  lcd.init();
  lcd.clear();
  
  // Turn ON LCD Backlight
  lcd.backlight();

    // Display a welcome message on the LCD
  lcd.setCursor(0, 0);
  lcd.print("Arduino Uno R4");
  lcd.setCursor(0, 1);
  lcd.print("Elapsed Time =");
  lcd.print(0.0);
  lcd.print(" s");
  lcd.setCursor(0, 3);
  lcd.print("RoboticX");

}

void loop() {
  
  unsigned long startTime = millis(); // Get the start time

  // Perform a simple task, for example, a loop
  for (int i = 0; i < 10000; i++) {
    Serial.println(i);
  }

  unsigned long endTime = millis(); // Get the end time
  unsigned long elapsedTime = endTime - startTime; // Calculate the elapsed time
  Serial.println("Elapsed time (s) on Uno R4: ");
  Serial.println(elapsedTime/1000.0);
  lcd.setCursor(0, 1);
  lcd.print("Elapsed Time =");
  lcd.print(elapsedTime/1000.0);
  lcd.print(" s");
  lcd.println("Count from 0 to 10 k");
  delay(10000); // Delay for better readability
  lcd.clear();
}