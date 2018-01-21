#include <Wire.h>
#include <AFMotor.h>
#include <Servo.h> 
AF_DCMotor motor1(1,MOTOR12_64KHZ); // set up motors.
AF_DCMotor motor4(4,MOTOR12_8KHZ);
Servo myservo; 
void setup() {
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600); 
  myservo.attach(9);
   motor1.setSpeed(200);
   motor4.setSpeed(200);
   motor1.run(RELEASE);
   motor4.run(RELEASE);// start serial for output
}

void loop() {
  delay(100);
}


void receiveEvent(int howMany) {
  while (1 < Wire.available()) { // loop through all but the last
    char c = Wire.read(); // receive byte as a character
    Serial.print(c);         // print the character
  }
  int x = Wire.read();    // receive byte as an integer
  Serial.println(x); 
   switch(x) 
               {
                 case '1':                             //FORWARD
                         {
                           
                            motor4.run(FORWARD);
                            motor1.run(FORWARD);      
                            Serial.println("MOVING FORWARD");
                          
                            break;
                         }
                case '2':                                //BACKWARD
                        {   
                            motor4.run(BACKWARD);
                            motor1.run(BACKWARD); 
                            Serial.println("GOING BACK");
                            
                            break;
                       }

                case '3':                               //LEFT
                     {      
                            motor4.run(BACKWARD);
                            motor1.run(FORWARD);          
                            Serial.println("TURNING LEFT");
                           
                            break;
                     }

             case '4':                             //right turn
                         {
                            
                            motor4.run(FORWARD);
                            motor1.run(BACKWARD);      
                            Serial.println("TURNING RIGHT");
                          
                            break;
                         }


             case '5':                             //LOOK RIGHT
                         {
                           
                             myservo.write(50); 
                             delay(600);
                             myservo.write(115);
                            break;
                         }


           case '6':                             //right
                         {
                             
                           
                           motor4.run(FORWARD);
                            motor1.run(BACKWARD);  
                             delay(16000);  
                             delay(16000);
                             motor1.run(RELEASE);  
                             motor4.run(RELEASE);
                                
                            Serial.println("STOP");
                                    
                            Serial.println("TURNING LEFT");
                            break;
                         }

          case '7':                             // //LEFT
                         {
                             
                            
                            motor4.run(BACKWARD);
                            motor1.run(FORWARD);  
                             delay(16000);  
                             delay(16000);
                             motor1.run(RELEASE);  
                             motor4.run(RELEASE);
                                
                            Serial.println("STOP");
                                    
                            Serial.println("TURNING LEFT");
                            break;
                         } 
           case '8':                             //stop
                         {
                             
                            motor4.run(RELEASE);
                            motor1.run(RELEASE);      
                            Serial.println("STOP");
                          
                            break;
                         }                                                      
                     

               }}
