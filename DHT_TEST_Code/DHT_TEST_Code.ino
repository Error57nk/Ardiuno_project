#include <dht.h>
#define DHT11_PIN D3
dht DHT;



void setup(){
  Serial.begin(115200);
}

void loop()
{
  int chk = DHT.read11(DHT11_PIN);
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);
  delay(1000);
}
