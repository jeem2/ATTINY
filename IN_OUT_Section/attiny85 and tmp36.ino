#include <TinyWireM.h>
#include  <TM1637Display.h>
#define TEMP_PIN3
const int CLK = 0; 
const int DIO = 1;
TM1637Display display(CLK,DIO);
const uint8_t celesuis[]=
{
SEG_A | SEG_B |  SEG_F | SEG_G,
SEG_A | SEG_D |  SEG_E | SEG_F 
};
void setup() {
  display.setBrightness(7);
}
void loop() {
  float temp = analogRead(TEMP_PIN);
  temp = temp * 500.0 / 1024.0;
  int displayTemp = int(temp * 10);
  displayTemp=ceil(displayTemp*0.01);
  display.showNumberDec(displayTemp,false,2,0);
  display.setSegments(celesuis,2,2);
  delay(1000);
}
