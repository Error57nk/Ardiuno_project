#include <LiquidCrystal.h>
#include <dht.h>
dht DHT;

#define DHT11_PIN 7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int greenLed = 9;
int buzzer = 8;
int smokeA0 = A0;
// Your threshold value
int sensorThres = 300;

void setup() {

  pinMode(greenLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop() {
  int s = analogRead(smokeA0);
  int chk = DHT.read11(DHT11_PIN);
  int t = DHT.temperature;
  int h = DHT.humidity;
  if(DHT.temperature >= 0  )
  {
    Lcd_print(t,h,s);
  }
  delay(100);
}
void Lcd_print(int t,int h,int s)
{
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("T:");
    lcd.print(DHT.temperature);
    lcd.print("  H:");
    lcd.print(DHT.humidity);
    lcd.setCursor(0,1);
if(s > sensorThres || t >= 50){
  if( t >= 50)
  { lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("High Temperature");
  }
  if(s > sensorThres){
    lcd.setCursor(0,1);
    lcd.print("SMOKE DETECTED !!");
  }
    }
else{
     lcd.setCursor(0,1);
     lcd.print("ALL Good");
    }
}

