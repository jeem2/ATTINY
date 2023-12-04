#define SERVO_PIN 0
int position;
void setServoPosition(int angle);
void setup() {
  pinMode(SERVO_PIN, OUTPUT);
}
void loop() {
  for (position = 0; position <= 180; position++) {
    setServoPosition(position); delay(15);
  }
  
  for (position = 180; position >= 0; position--) {
    setServoPosition(position); delay(15);
  }
}
void setServoPosition(int angle) {
  int pulseWidth = (angle * 11) + 500;
  digitalWrite(SERVO_PIN, HIGH);
  delayMicroseconds(pulseWidth);
  digitalWrite(SERVO_PIN, LOW);
  delay(20 - (pulseWidth / 1000));
}
