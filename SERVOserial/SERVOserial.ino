#include <Servo.h> 
Servo servo1;
void setup() {
  
    servo1.attach(9);
    Serial.begin(9600);
     servo1.write(110);
}
int i=110;
void loop() {

  if(Serial.available()>0)
 {char letter = Serial.read();
   if(letter == '1')
   {
   
    i=i+5;
    if(i<=180)
      { 
      Serial.println(i);
      servo1.write(i);
      }
   else
     {
    i=180;}
     }
    if(letter == '2')
   {  i=i-5;
      if(i>=0)
        {
         Serial.println(i);
         servo1.write(i);
        }
     else
       {
        i=0;
        }
   }
   }
}
