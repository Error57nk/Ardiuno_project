#define trigPin 13
#define echoPin 12
#define trigPin2 7
#define echoPin2 6
char b;

void setup() {
 Serial.begin (9600);
 pinMode(trigPin, OUTPUT);//sonic F
  pinMode(echoPin, INPUT);

  pinMode(trigPin2, OUTPUT);//sonic2 F
  pinMode(echoPin2, INPUT);
}

void loop() {

  if(Serial.available()>0)
      {
        char a = Serial.read();
        switch(a) {
             case 'O':                               //AUTO mode OBSTACKEL
                    { 
                      while(b = 'O')
                            { 
                                  long duration, distance;
                                  long duration2, distance2;
                                  digitalWrite(trigPin, LOW);  // Added this line
                                  delayMicroseconds(21); // Added this line
                                  digitalWrite(trigPin, HIGH);
                                  delayMicroseconds(10); // Added this line
                                  digitalWrite(trigPin, LOW);
                                  duration = pulseIn(echoPin, HIGH);
                                  distance = (duration/2) / 29.1;


                                 digitalWrite(trigPin2, LOW);  // Added this line
                                  delayMicroseconds(21); // Added this line
                                  digitalWrite(trigPin2, HIGH);
                                  delayMicroseconds(10); // Added this line
                                  digitalWrite(trigPin2, LOW);
                                  duration2 = pulseIn(echoPin2, HIGH);
                                  distance2 = (duration2/2) / 29.1;

                                

                              if (distance2 < distance)     //KEY  9
                                               
                                               
                                               
                                               {
                                                digitalWrite(10,HIGH);
                                                Serial.print(distance2);
                                                Serial.println("your are in range d1");
                                                delay(1000);
                                                }


                                                
                             else
                                 {
                                   Serial.print(distance);      
                                   Serial.println("are in range d2");
                                   delay(1000);
                                   
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
               case 'F':                               //LEFT
                     {  
                                       
                            Serial.println("LEFT");
                            delay(20);
                            break;
                     }
                }



}}
