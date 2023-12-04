#include <TinyWireM.h> 
#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>
SoftwareSerial mySerial(0, 1);
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int relayPin = 4;

void setup() {
  mySerial.begin(9600);
  TinyWireM.begin();
  lcd.init();
  lcd.backlight();
  pinMode(relayPin, OUTPUT);
}

void loop() {
  if (mySerial.available()) {
    char incoming = mySerial.read();
    if (incoming == '1') {
      lcd.clear();
      digitalWrite(relayPin, HIGH);
      lcd.setCursor(0, 0);
      lcd.print("LED: ON");
    }
      
    else if (incoming == '0') {
      lcd.clear();
      digitalWrite(relayPin, LOW);
      lcd.setCursor(0,0);  
      lcd.print("LED: OFF");
    }
  }
}
