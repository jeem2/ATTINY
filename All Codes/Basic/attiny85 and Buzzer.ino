int speaker = 0;
void setup() {
  pinMode(speaker, OUTPUT);
}
void myTone(byte pin, uint16_t frequency, uint16_t duration) {
  unsigned long startTime = millis();
  unsigned long halfPeriod = 1000000L / frequency / 2;
  while (millis() - startTime < duration) {
    digitalWrite(pin, HIGH);
    delayMicroseconds(halfPeriod);
    digitalWrite(pin, LOW);
    delayMicroseconds(halfPeriod);
  }
}
void loop() {
  myTone(speaker, 440, 500);
  delay(1000);
  myTone(speaker, 900, 500);
  delay(1000);
  myTone(speaker, 600, 500);
  delay(1000);
}
