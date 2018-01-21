int b = 0;    // how bright the LED is
int f =2;    // how many points to fade the LED by


void setup() {
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);

}

void loop() {
  analogWrite(9, b);
  b=b+f;
  delay(10);

  analogWrite(10, b);
  b=b+f;
  delay(11);

  analogWrite(11, b);
  b=b+f;
  delay(12);

  analogWrite(12, b);
  b=b+f;
  delay(13);

  analogWrite(13, b);
  b=b+f;
  delay(14);
}
