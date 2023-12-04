#include <TinyWireM.h>
#include <TM1637Display.h>
const int CLK = 0;
const int DIO = 1;
TM1637Display display(CLK, DIO);
const int POT_PIN = 3 ;
void setup() {
  display.setBrightness(7);
}
void loop() {
  int potValue = analogRead(POT_PIN);
  display.showNumberDec(potValue );
  delay(100);
}
