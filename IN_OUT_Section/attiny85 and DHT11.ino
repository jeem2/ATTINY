#include <USI_TWI_Master.h>
#include <TinyWireM.h>
#include <LiquidCrystal_I2C.h>
#include <TinyDHT.h>
#define DHTTYPE DHT11
#define TEMPTYPE 0
#define DHTPIN 1
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  TinyWireM.begin();
  dht.begin();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Temp:");
  lcd.setCursor(0,1);
  lcd.print("Humidity:");
}
void loop() {
  int8_t h = dht.readHumidity();
  int16_t t = dht.readTemperature(TEMPTYPE);
  lcd.setCursor(10,0);
  lcd.print(t);
  lcd.print("  C");
  lcd.setCursor(10,1);
  lcd.print(h);
  lcd.print("%");
  delay(2000);
}
