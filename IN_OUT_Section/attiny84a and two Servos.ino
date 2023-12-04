#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
Servo servo1;
Servo servo2;
int pot1 = A1; 
int pot2 = A2;
void setup(){
  lcd.init();
  lcd.backlight();
  servo1.attach(7);
  servo2.attach(8);
}
void loop(){
  int val1 = analogRead(pot1);
  int val2 = analogRead(pot2);
  val1 = map(val1, 0, 1023, 0, 180);
  val2 = map(val2, 0, 1023, 0, 180);
  servo1.write(val1);
  servo2.write(val2);
  delay(15);
  lcd.setCursor(0,0);
  lcd.print("Angle1:");
  lcd.setCursor(10,0);  
  lcd.print(val1);
  lcd.setCursor(0,1);
  lcd.print("Angle2:");
  lcd.setCursor(10,1);  
  lcd.print(val2);
}
