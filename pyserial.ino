//--------------------------------------
// Aurduino-Python Serial Communication
//--------------------------------------

#include <Servo.h>
Servo servo;
void setup()
{
  Serial.begin(9600); Serial.setTimeout(1);
  pinMode(9, OUTPUT); pinMode(5, OUTPUT); pinMode(3, OUTPUT);
  servo.attach(5);
  
}
//--------------------------------------------------------------
void loop()
{
  char controlSignal;
  while(!Serial.available());
  
  controlSignal = Serial.read();
  if(controlSignal == 'R') digitalWrite(9, !digitalRead(9));
  if(controlSignal == 'G'){
    servo.write(90);
  }
  if(controlSignal == 'B') digitalWrite(3, !digitalRead(3));
  if(controlSignal == 'S'){
    digitalWrite(3, LOW);
    digitalWrite(9, LOW);
    servo.write(0);
  }
}
