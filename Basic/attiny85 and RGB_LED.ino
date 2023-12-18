#define RED_PIN 0
#define GREEN_PIN 1
#define BLUE_PIN 2
void setup () {
  pinMode (RED_PIN, OUTPUT);
  pinMode (GREEN_PIN, OUTPUT);
  pinMode (BLUE_PIN, OUTPUT);
}
void loop () {
  digitalWrite (RED_PIN, 255);
  digitalWrite (GREEN_PIN, 0);
  digitalWrite (BLUE_PIN, 0);
  delay (1000);
  digitalWrite (RED_PIN, 0);
  digitalWrite (GREEN_PIN, 255);
  digitalWrite (BLUE_PIN, 0);
  delay (1000);
  digitalWrite (RED_PIN, 0);
  digitalWrite (GREEN_PIN, 0);
  digitalWrite (BLUE_PIN, 255);
  delay (1000);
}
