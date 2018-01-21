//Led PATTERN
//nitesh kumar

void setup() {
  
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
    
}

// the loop function runs over and over again forever
void loop() {
  
 digitalWrite(9, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(110);              // wait for a second
  digitalWrite(9, LOW);    // turn the LED off by making the voltage LOW
  delay(10);              // wait for a second

  digitalWrite(10, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(111);              // wait for a second
  digitalWrite(10, LOW);    // turn the LED off by making the voltage LOW
  delay(10);              // wait for a second

  digitalWrite(11, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(112);              // wait for a second
  digitalWrite(11, LOW);    // turn the LED off by making the voltage LOW
  delay(10);              // wait for a second

  digitalWrite(12, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(113);              // wait for a second
  digitalWrite(12, LOW);    // turn the LED off by making the voltage LOW
  delay(10);               //wait for a second

  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(114);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(10);              // wait for a second
}
