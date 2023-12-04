#include <IRremote.h>
const int irPin = 4; 
const int pin0 = 0;
const int pin1 = 1;  
const int pin2 = 2;
const int pin3 = 3;
boolean pin0state = false;
boolean pin1state = false;
boolean pin2state = false;
boolean pin3state = false;

void setup() { 
    pinMode(irPin, INPUT); 
    pinMode(pin0, OUTPUT);
    pinMode(pin1, OUTPUT); 
    pinMode(pin2, OUTPUT);
    pinMode(pin3, OUTPUT);
}
void loop() { 
    int key = getIrKey();
  
    if(key == 17843 ) {
        pin0state = !pin0state;
        if(pin0state == true)
        digitalWrite(pin0, HIGH);
        else 
        digitalWrite(pin0, LOW); 
        }
  
    if(key == 18098) {
        pin1state = !pin1state;
        if(pin1state == true)
        digitalWrite(pin1, HIGH);
        else
        digitalWrite(pin1, LOW);
    }
  
    if(key == 18353){ 
        pin2state = !pin2state;
        if(pin2state == true)
          digitalWrite(pin2, HIGH);
        else
          digitalWrite(pin2, LOW);
    }
  
    if(key == 17588) { 
        pin3state = !pin3state;
        if(pin3state == true)
          digitalWrite(pin3, HIGH);
        else
          digitalWrite(pin3, LOW);
     }
  
     if(key == 7388) {
       pin0state = false;
       pin1state = false;
       pin2state = false;
       pin3state = false;
       digitalWrite(pin3, LOW);
       digitalWrite(pin2, LOW);
       digitalWrite(pin0, LOW);
       digitalWrite(pin1, LOW);
    }
 }

int getIrKey(){
    int len = pulseIn(irPin,LOW); 
    int key, temp; 
    key = 0;
    if(len > 5000) {
        for(int i=1;i<=32;i++){
            temp = pulseIn(irPin,HIGH);
            if(temp > 1000)
            key = key + (1<<(i-17));
         }
     }
     if(key < 0 )
        key = -key;
     delay(250);
     return key;
     }
