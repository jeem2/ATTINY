#include <LiquidCrystal_I2C.h>
#include "RTClib.h"
#include <USI_TWI_Master.h>
#include <TinyWireM.h>
RTC_DS1307 rtc;
LiquidCrystal_I2C lcd(0x27,16,2);
char daysOfTheWeek[7][12] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

void setup () { 
  lcd.init();
  lcd.backlight();
  if (! rtc.begin()) {
    lcd.print("Couldn't find RTC");
    while (1); 
  }
  
  if (! rtc.isrunning()) {
    lcd.print("RTC is NOT running!");}
  rtc.adjust(DateTime(2023, 9, 28, 15, 52, 40));
}

void loop () { 
  DateTime now = rtc.now();
  lcd.setCursor(0, 0);
  lcd.print("TIME'S NOW ");
  lcd.setCursor(8, 1);
  lcd.print(now.hour());
  lcd.print(':'); 
  lcd.print(now.minute());
  lcd.print(':'); 
  lcd.print(now.second());
  lcd.print("  ");
  delay(1500);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("TODAY'S DATE");
  lcd.setCursor(3, 1);
  lcd.print(daysOfTheWeek[now.dayOfTheWeek()]);
  lcd.print(" ");
  lcd.print(now.day());
  lcd.print('/');
  lcd.print(now.month());
  lcd.print('/');
  lcd.print(now.year());
  lcd.print("  ");  
  delay(1500);
  lcd.clear();
}
