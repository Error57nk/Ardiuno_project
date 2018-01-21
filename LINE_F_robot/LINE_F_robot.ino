//Line follower
#define LS 2      // left sensor at pin 2
#define RS 3      // right sensor at pin 3




void setup()
{  Serial.begin(9600);
  pinMode(LS, INPUT);   //taking sensor as INPUT data
  pinMode(RS, INPUT);
 
 
}

void loop()
{
  if(digitalRead(LS) && digitalRead(RS))     // Move Forward
  {
    Serial.println("forward");
  }
  
  if(!(digitalRead(LS)) && digitalRead(RS))     // Turn right
  {
     Serial.println("RIGHT TURN");
  }
  
  if(digitalRead(LS) && !(digitalRead(RS)))     // turn left
  {
     Serial.println("left turn");
  }
  
  if(!(digitalRead(LS)) && !(digitalRead(RS)))     // stop
  {
     Serial.println("STOP");
  }
}

