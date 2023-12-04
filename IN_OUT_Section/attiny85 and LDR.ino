#include <TinyWireM.h>
#include <TM1637Display.h>
const int CLK = 0;
const int DIO = 1;
TM1637Display display(CLK, DIO);
int analogPin = 3;
void setup() {
  display.setBrightness(5);
}
void loop() {
  int ldrValue = analogRead(analogPin);
  display.showNumberDec(ldrValue);
  delay(10);
}
