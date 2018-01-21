

#include <Wire.h>

void setup() {
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(9600);  // start serial for output
}

void loop() {
  while(Serial.available())
  while (Wire.available()) { // slave may send less than requested
    char c = Wire.read(); // receive a byte as character
   if(c == 'h')
   {
    Wire.beginTransmission(5);
    Wire.write('H');
    Serial.println("h send");
    Wire.endTransmission();
   }
   else if(c == 'l')
   {
    Wire.beginTransmission(5);
    Wire.write('L');
    Serial.println("l send!");
    Wire.endTransmission();
   }
  }

 
}
