#include <Servo.h>
Servo SERVO_1;
Servo SERVO_2;

#define trigPin 8
#define echoPin 9

void setup() {
  Serial.begin(9600);
pinMode (8, OUTPUT);
  pinMode (9, INPUT);
  pinMode (13,OUTPUT);
  SERVO_1.attach(5);
  SERVO_2.attach (6);
}

void loop() {

if (Serial.available() > 0)
{
int data = Serial.read();
switch (data) {
case '1': 
SERVO_1.write (180);
SERVO_2.write (0);

break;
case '2' : 
 SERVO_1.write (0);
SERVO_2.write (180);

break;
case '3' :
 SERVO_1.write (180);
SERVO_2.write (180);
break;
case '4' : 
 SERVO_1.write (0);
SERVO_2.write (0);
break;

case '5':
 SERVO_1.write (95);
SERVO_2.write (95);
default : break;


}
}
}


