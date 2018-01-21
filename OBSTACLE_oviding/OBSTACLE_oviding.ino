\\..................Nitesh nick..........\\
\\...any problem leave comment............\\
\\https://www.youtube.com/channel/UCeq4uLKgQu5Pu379Q96bYVg





#include <AFMotor.h> //import your motor shield library

#define trigPin 12 // define the pins of your sensor
#define echoPin 13 
AF_DCMotor motor1(1); // set up motors.
AF_DCMotor motor4(4);

void setup() {
  Serial.begin(9600); // begin serial communitication  
  Serial.println("Getting ready");
  pinMode(trigPin, OUTPUT);// set the trig pin to output (Send sound waves)
  pinMode(echoPin, INPUT);// set the echo pin to input (recieve sound waves)
  motor1.setSpeed(200); //set the speed of the motors, between 0-255
  motor4.setSpeed (200);  

}
 
void loop() {

   long duration, distance; // start the scan
   digitalWrite(trigPin, LOW);  
   delayMicroseconds(2); // delays are required for a succesful sensor operation.
   digitalWrite(trigPin, HIGH);

   delayMicroseconds(10); //this delay is required as well!
   digitalWrite(trigPin, LOW);
   duration = pulseIn(echoPin, HIGH);
   distance = (duration/2) / 29.1;// convert the distance to centimeters.
     if (distance < 25)/*if there's an obstacle 25 centimers, ahead, do the following: */ 
       {   
          Serial.println ("Somthing is in front" );
          Serial.print ("Distance From Robot is " );
          Serial.print ( distance);
          Serial.print ( " CM!");// print out the distance in centimeters.
          Serial.println (" The obstacle is near ");
          Serial.println (" aoiding the object");

          motor1.run(FORWARD);  // Turn as long as there's an obstacle ahead.
          motor4.run (BACKWARD);

       }
  else 
      {
          Serial.println ("No obstacle detected. going forward");
          delay (15);
          motor1.run(FORWARD); //if there's no obstacle ahead, Go Forward! 
          motor4.run(FORWARD);  
       }  
  
}
