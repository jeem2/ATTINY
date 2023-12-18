#define MOTOR_ENABLE_PIN 4
#define MOTOR_INPUT1_PIN 3
#define MOTOR_INPUT2_PIN 5
void setup() {
  pinMode(MOTOR_ENABLE_PIN, OUTPUT);
  pinMode(MOTOR_INPUT1_PIN, OUTPUT);
  pinMode(MOTOR_INPUT2_PIN, OUTPUT); }
void loop() {
  digitalWrite(MOTOR_INPUT1_PIN, LOW);
  digitalWrite(MOTOR_INPUT2_PIN, HIGH);
  analogWrite(MOTOR_ENABLE_PIN, 128);
  delay(3000);
  analogWrite(MOTOR_ENABLE_PIN, 0);
  delay(1000);
  digitalWrite(MOTOR_INPUT1_PIN, HIGH);
  digitalWrite(MOTOR_INPUT2_PIN, LOW);
  analogWrite(MOTOR_ENABLE_PIN, 128);
  delay(3000);
}

