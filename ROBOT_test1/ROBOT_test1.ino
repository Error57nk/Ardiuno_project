#include <SoftwareSerial.h>
#include <AFMotor.h>
#include <Servo.h>
#define trigPin 12 // define the pins of your sensor
#define echoPin 13 
AF_DCMotor motor3(3); // set up motors.
AF_DCMotor motor4(2);
Servo s;
int i=200,l;
int p=90;
int j=0;
void setup() {

Serial.begin (9600);
s.attach(9);
  pinMode(trigPin, OUTPUT);// set the trig pin to output (Send sound waves)
  pinMode(echoPin, INPUT);
motor3.setSpeed(i); //set the speed of the motors, between 0-255
motor4.setSpeed (i);
}


void loop() {
if(Serial.available()>0)
 {char letter = Serial.read();
 Serial.println (" redy to recive ");
Serial.println (" Turning !");
  switch(letter)
   {    case 'd': 

         { p=p+10;
         
           s.write(p);
            break;
         }

      case 'a':
      {p=p-10;
         
           s.write(p);
            break;Serial.println("trnig right");
      break;
      }
       
      case 'w':
      {motor3.setSpeed(i); //set the speed of the motors, between 0-255
          motor4.setSpeed(i);
          motor3.run(FORWARD);
       
         motor4.run(FORWARD);
         Serial.println("frwrd");
           break;
      }
       case 's':
      {   motor3.setSpeed(i); //set the speed of the motors, between 0-255
          motor4.setSpeed (i);
          motor3.run(BACKWARD);//if there's no obstacle ahead, Go Forward! 
          motor4.run(BACKWARD); 
          Serial.println("reverse");
            break;
      }
      case 'e':
      {
        motor3.run(RELEASE); //if there's no obstacle ahead, Go Forward! 
        motor4.run(RELEASE); Serial.println("stop");
        i=255;
          break;
      }
      case 'u':
      {
        p=90;
        s.write(p);
      }
           case 'y':
           { 
            for(j=0;j>5;j++)
            {
         long duration, distance; // start the scan
        digitalWrite(trigPin, LOW);  
        delayMicroseconds(2); // delays are required for a succesful sensor operation.
        digitalWrite(trigPin, HIGH);

        delayMicroseconds(10); //this delay is required as well!
        digitalWrite(trigPin, LOW);
        duration = pulseIn(echoPin, HIGH);
        distance = (duration/2) / 29.1;
 Serial.print ("Distance From Robot is " );
Serial.print (distance);
        if (distance < 20)
        {
          motor3.run(FORWARD);
       
         motor4.run(BACKWARD);
        }

        else
        {
          motor3.run(FORWARD);
       
          motor4.run(FORWARD);
        }
            }
        
           
 }}
}}
      

