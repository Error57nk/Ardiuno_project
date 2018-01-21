#include <Wire.h>
#include <NewPing.h>
#define trigPin 13
#define echoPin 12
#define LS 2      // left sensor
#define RS 3      // right sensor
char b,c;



void setup() {
   
  Serial.begin (9600);
  Wire.begin();
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
  pinMode(trigPin, OUTPUT);//sonic F
  pinMode(echoPin, INPUT);
   pinMode(9, OUTPUT);
   pinMode(8, OUTPUT); 
   pinMode(7, OUTPUT);
}




void loop() {
 if(Serial.available()>0)
      {
        char a = Serial.read();
        if(a == 'M')
          { 
          Serial.println("MANUAL");
          digitalWrite(9, HIGH);
          delay(1120);
            
          }
        else
        {
          digitalWrite(9, LOW);
        }   
            switch(a) 
               {
                 case 'T':                             //FORWARD
                         {
                            Wire.beginTransmission(8); // transmit to device #8
                          
                            Wire.write('1');              // sends one byte
                            Wire.endTransmission();              
                            Serial.println("FORWARD");
                            delay(20);
                            break;
                         }
                case 'H':                                //RIGHT
                        {  
                            Wire.beginTransmission(8); // transmit to device #8
                         
                            Wire.write('6');              // sends one byte
                            Wire.endTransmission();              
                            Serial.println("RIGHT");
                            delay(20);
                            digitalWrite(8, LOW); 
                            break;
                       }

                case 'F':                               //LEFT
                     {  
                           Wire.beginTransmission(8); // transmit to device #8
                           
                            Wire.write('7');              // sends one byte
                            Wire.endTransmission();              
                            Serial.println("LEFT");
                            delay(20);
                            digitalWrite(8, LOW); 
                            break;
                     }

               case 'O':                               //AUTO mode OBSTACKEL
                    { 
                      while(b = 'O')
                            { 
                                  long duration, distance;
                                  digitalWrite(trigPin, LOW);  // Added this line
                                  delayMicroseconds(21); // Added this line
                                  digitalWrite(trigPin, HIGH);
                                  delayMicroseconds(10); // Added this line
                                  digitalWrite(trigPin, LOW);
                                  duration = pulseIn(echoPin, HIGH);
                                  distance = (duration/2) / 29.1;

                              if (distance < 13)     //KEY  9
                                               
                                               
                                               
                                               {
                                                 Wire.beginTransmission(8); // transmit to device #8
                                                 Wire.write('4');              // sends one byte
                                                Wire.endTransmission();              
                                                Serial.println("TURNING");
                                                delay(220);
                                                Serial.print(distance);
                                                Serial.println("OBSTACAL");
                                                
                                                }


                                                
                             else
                                 {
                                   Wire.beginTransmission(8); // transmit to device #8
                                   Wire.write('1');              // sends one byte
                                   Wire.endTransmission();
                                   Serial.print(distance);              
                                   Serial.println("NO OBSTACKEL");
                                   delay(220);
                              
                                 }
                            if(Serial.available()>0)
                             {
                               char b = Serial.read();
                                  if(b == 'M')             //break function
                                     {Serial.println("stop transmissino");
                                      break;}
                             }
                         }
                    }
                 case 'S':                                       //STOP
                         {
                            Wire.beginTransmission(8); // transmit to device #8
                      
                            Wire.write('8');              // sends one byte
                            Wire.endTransmission();              
                            Serial.println("STOP");
                            digitalWrite(8, HIGH); 
                            delay(20);
                            break;
                         }
                 case 'R':                                      //SPEED  'SLOW'
                         {
                            Wire.beginTransmission(8); // transmit to device #8
                         
                            Wire.write('5');              // sends one byte
                            Wire.endTransmission();              
                            Serial.println("SLOW SPD");
                            delay(20);
                            break;
                         }
                case 'Y':                                    //SPEED  'MIDUM'
                         {
                            digitalWrite(8, LOW);   // turn the LED on (HIGH is the voltage level)
                            Serial.println("OFF"); 
                            break;
                         }
                case 'U':                                   //SPEED  'MAX'
                         {
                            digitalWrite(8, HIGH);   // turn the LED on (HIGH is the voltage level)
                            Serial.println("ON");             // wait for a second
                           
                            break;
                         }
               case 'G':                                 //BACK
                         {
                             Wire.beginTransmission(8); // transmit to device #8
                            
                            Wire.write('2');              // sends one byte
                            Wire.endTransmission();              
                            Serial.println("BACK");
                            delay(20);
                            break;
                         }
               case 'L':                                 //AUTO   LINEFOLLOWER
                         {
                            while(c = 'L')
                            { 
                                    if(digitalRead(LS) && digitalRead(RS))     // Move Forward
                                             {
                                                Wire.beginTransmission(8); // transmit to device #8
                                                Wire.write('1');              // sends one byte
                                                Wire.endTransmission();
                                                Serial.println("forward line");              
                                                delay(220);
                                               
                                             }
  
                                  if(!(digitalRead(LS)) && digitalRead(RS))     // Turn right
                                            {
                                                Wire.beginTransmission(8); // transmit to device #8
                                                Wire.write('4');              // sends one byte
                                                Wire.endTransmission();
                                                Serial.println("Right line");              
                                                delay(220); 
                                                
                                             }
  
                                 if(digitalRead(LS) && !(digitalRead(RS)))     // turn left
                                            {
                                                Wire.beginTransmission(8); // transmit to device #8
                                                Wire.write('3');              // sends one byte
                                                Wire.endTransmission();
                                                Serial.println("LEFT line");              
                                                delay(220);
                                              
                                            }
  
                                if(!(digitalRead(LS)) && !(digitalRead(RS)))     // stop
                                            {
                                                Wire.beginTransmission(8); // transmit to device #8
                                                Wire.write('8');              // sends one byte
                                                Wire.endTransmission();
                                                Serial.println("stop line ");              
                                                delay(220);
                                                
                                            }

                              
                            

                             if(Serial.available()>0)
                             {
                               char c = Serial.read();
                                  if(c == 'M')             //break function
                                             {       
                                              Serial.println("stop transmissino");
                                              break;
                                              }
                             }
                      }                   
                   }
              


     }
   }
 }




