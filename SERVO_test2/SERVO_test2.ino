#include <Servo.h> //libery File 
Servo servo1;      
void setup() 
{
 Serial.begin(9600);  
 servo1.attach(9);      // servo is at pin 9
}

void loop() 
{
  if(Serial.available()>0)       // if somthing is recived
    {
      char letter = Serial.read();     // store it in letter

        if(letter == '0')               //cheacking 
          {
            servo1.write(140);
          }
       
        else if(letter == '2')
         {
          servo1.write(40);

         }
       else if(letter == '1')
        {
        servo1.write(90);

        }
     }
}
