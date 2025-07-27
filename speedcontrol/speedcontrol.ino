/*
*	Hello_World.ino
*
*	Author: Frank Häfele
*	Date:	01.12.2023
*
*	Object: Print Hello World on LCD Display
*/

#include <LCD-I2C.h>


LCD_I2C lcd(0x27, 16, 2); // Default address of most PCF8574 modules, change according

const int pressureSensorPin = A0;    // Analog pin for pressure sensor
const int motorControlPin = 9;       // PWM pin to control motor speed
const int pressureThreshold = 600;   // ADC units threshold for pressure increase
const int pressureChange = 20;       // ADC units change in pressure for speed increase
const int maxMotorSpeed = 500;       // Maximum PWM duty cycle for motor speed
const int motorSpeed1=100;
void setup() {
  pinMode(motorControlPin, OUTPUT);
  Serial.begin(9600);
    lcd.begin();
    lcd.display();
    lcd.backlight();
}

void loop() {
  // Read pressure sensor value
  int sensorValue = analogRead(pressureSensorPin);
  
  // Calculate motor speed adjustment based on pressure
  int motorSpeed = map(sensorValue, 0, 1023, 0, maxMotorSpeed);  // Maps 0-1023 to 0-maxMotorSpeed PWM range
  
  // Determine if pressure is above threshold and calculate speed increase
  if (sensorValue > pressureThreshold) {
    int pressureDifference = sensorValue - pressureThreshold;
    //int speedIncrease = (pressureDifference / pressureChange) * 50;  // 50 is the duty cycle increase per pressure change
    motorSpeed +=motorSpeed1 ;
  }

  // Ensure motorSpeed does not exceed maximum PWM duty cycle
  motorSpeed = constrain(motorSpeed, 0, maxMotorSpeed);

  // Control motor speed
  analogWrite(motorControlPin, motorSpeed);

  // Print sensor value and motor speed for debugging
  Serial.print("Pressure Sensor Value: ");
  Serial.print(sensorValue);
  Serial.print(", Motor Speed: ");
  Serial.println(motorSpeed);

  delay(100);  // Adjust delay as ne
}


