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
const int pressuresensorpin=A0;
const int motorpin=9;
int initialdutycycle=200;
int highpressuredutycycle=500;
//const float pressureMin=0.2;
//const float pressureMax=4.7;
//const float pressureMin_kPa=0;
//const float pressureMax_kPa=50;
int sensorvalue=0;
float sensorvoltage=0.0;
float pressure_kPa=0.0;

void setup() {
    pinMode(pressuresensorpin,INPUT);
    pinMode(motorpin,OUTPUT);
    Serial.println(9600);
    lcd.begin();
    lcd.display();
    lcd.backlight();
}

void loop()
{
  analogWrite(motorpin,initialdutycycle);
  
    
    lcd.setCursor(0, 0); // Or setting the cursor in the desired position.
    lcd.print("welcome");
    delay(500);
    lcd.clear();
    //read analog voltage from the pressure sensor
    int sensorvalue=analogRead(pressuresensorpin);
    float sensorvoltage=sensorvalue*(5.0/1023.0);//convert analog read to voltage(0_5)
    pressure_kPa=((sensorvoltage/5.0)-0.5)/0.2;//Convert voltage to pressure in kPa
    lcd.setCursor(0,1);
    lcd.print(pressure_kPa,1);
    
    Serial.println(pressure_kPa);
    delay(1000);
    if(pressure_kPa>65){
      analogWrite(motorpin,initialdutycycle);
    }else{
      analogWrite(motorpin,highpressuredutycycle);
    }
delay(500);

    }




