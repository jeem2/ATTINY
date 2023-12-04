#include <TinyWireM.h>
#include <TM1637Display.h>

const int CLK = 0;
const int DIO = 1;
TM1637Display display(CLK, DIO);

const int BUTTON_PIN_INC = 2;
const int BUTTON_PIN_RESET = 4;

int counter = 0;
int buttonStateInc = 0;
int buttonStateReset = 0;

void setup() {
  display.setBrightness(7);
  pinMode(BUTTON_PIN_INC, INPUT_PULLUP);
  pinMode(BUTTON_PIN_RESET, INPUT_PULLUP);
}

void loop() {
  buttonStateInc = digitalRead(BUTTON_PIN_INC);
  buttonStateReset = digitalRead(BUTTON_PIN_RESET);

  if (buttonStateInc == LOW) {
    counter++;
    display.showNumberDec(counter);
    delay(250);
  }

  if (buttonStateReset == LOW) {
    counter = 0;
    display.showNumberDec(counter);
    delay(250);
  }
}
