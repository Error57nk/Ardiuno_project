void setup() {
 pinMode(13, OUTPUT);
 Serial.begin(9600);
  digitalWrite(13,LOW);

}

void loop() {
 if(Serial.available()>0)
 {char letter = Serial.read();
 if(letter == '1')
 {
  digitalWrite(13,HIGH);
 }
 if(letter == '2')
 {
  digitalWrite(13,LOW);
 }

 }}
