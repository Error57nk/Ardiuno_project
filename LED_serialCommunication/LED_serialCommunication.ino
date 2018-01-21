//nitesh kumar
//testing Serial communication  controlinng led with keyboard
int red = 13;
int green = 11;


void setup() 
  {
 
   pinMode(red, OUTPUT);
   digitalWrite(red,LOW); //led is off at start
   Serial.begin(9600);   //start the serial comunication at 9600 bit per second
   pinMode(green, OUTPUT); 
   digitalWrite(green,LOW); 
}

void loop() {
        if(Serial.available()>0)   //if somthing is recived than
             {
              char letter = Serial.read();     // read it
                      if(letter == '0')                                  // cheaking is o or not
                           {
                            digitalWrite(red,HIGH);
                            Serial.println("RED led is ON");
                           }
                      else if(letter == '1')
                           {
                            digitalWrite(red,LOW);
                            Serial.println("Red led is OFF");
                           }
                     else if(letter=='a')
                           {
                            digitalWrite(green,HIGH);
                            Serial.println("green led is ON restart it to make it oFF");
                           }
               }
           }
