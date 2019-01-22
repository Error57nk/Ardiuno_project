#include <ESP8266WiFi.h>
 
const char* ssid = "******"; // SSID i.e. Service Set Identifier is the name of your WIFI
const char* password = "*******"; // Your Wifi password, in case you have open network comment the whole statement.
#define blue D0  //embeded led(Data + power)
#define red D1
#define green D2 
// relay pin are as
#define int1 D3
#define int2 D5
#define int3 D6
#define int4 D7
#define nt D8   //music key

int n=0;
WiFiServer server(80); // Creates a server that listens for incoming connections on the specified port, here in this case port is 80.
 
void setup() {
  Serial.begin(115200);
  delay(10);
  pinMode(blue, OUTPUT);  // Night light
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(nt, OUTPUT);
                          //initialising the board pin
  digitalWrite(blue,LOW); 
  digitalWrite(green,LOW);
  digitalWrite(red,LOW);
                        //defining the relay pin
  pinMode(int1, OUTPUT); 
  pinMode(int2, OUTPUT);
  pinMode(int3, OUTPUT);
  pinMode(int4, OUTPUT);

  digitalWrite(int1,HIGH); 
  digitalWrite(int2,HIGH);
  digitalWrite(int3,HIGH); 
  digitalWrite(int4,HIGH);
  
  
 
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(red,HIGH);
    digitalWrite(green,LOW);
    delay(500);
    Serial.print(".");
  }
  digitalWrite(red,LOW);
  digitalWrite(green,HIGH);
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Start the server
  server.begin();

  Serial.println("Server started");
 
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP()); //Gets the WiFi shield's IP address and Print the IP address of serial monitor
  Serial.println("/");
 
}
 
void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
   
    return;
  }
  
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
 
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
 
  // Match the request
      
      
      
 
  if (request.indexOf("/Relay1On") != -1)  {
    digitalWrite(int1,HIGH);
    delay(1);
    light();
    }
  if (request.indexOf("/Relay1Off") != -1)  {
    digitalWrite(int1, LOW);
    delay(1);
    lightOFF();
  }


  if (request.indexOf("/Relay2On") != -1)  {
    digitalWrite(int2, HIGH);
    delay(1);
    light();

  }
  if (request.indexOf("/Relay2Off") != -1)  {
    digitalWrite(int2, LOW);
    delay(1);
    lightOFF();
  }


  if (request.indexOf("/Relay3Off") != -1)  {
    digitalWrite(int3,LOW);
    delay(1);
    lightOFF();
  }
  if (request.indexOf("/Relay3On") != -1)  {
    digitalWrite(int3, HIGH);
    delay(1);
    light();
  }

  if (request.indexOf("/Relay4Off") != -1)  {
    digitalWrite(int4,LOW);
    delay(1);
    lightOFF();
  }
  if (request.indexOf("/Relay4On") != -1)  {
    digitalWrite(int4, HIGH);

      delay(1);
      light();
  }
  if (request.indexOf("/blue") != -1)  {
    digitalWrite(blue, HIGH);
    

      
      delay(1);
  }
  if (request.indexOf("/green") != -1)  {
    digitalWrite(green, HIGH);

      
      delay(1);
  }
  if (request.indexOf("/red") != -1)  {
    digitalWrite(red, HIGH);

      
      delay(1);
  }
  
  if (request.indexOf("/test") != -1)  {
    light();
    delay(1);
  }
  if (request.indexOf("/nlon") != -1)  {

    if(n==0){
      digitalWrite(nt, LOW);
      light();
      n=1;
    }
    else
    {
      digitalWrite(nt, HIGH);
      lightOFF();
      n=0;
    }
    delay(1);
  }
  
  }    

void lightOFF()
{
      digitalWrite(red,HIGH);
      delay(50);
      digitalWrite(red,LOW);
      delay(50);
      digitalWrite(green,HIGH);
      delay(50);
      digitalWrite(green,LOW);
      delay(50);
      digitalWrite(blue,HIGH);
      delay(50);
      digitalWrite(blue,LOW);
      delay(50);
      digitalWrite(green,HIGH);
      delay(2000);
      digitalWrite(green,LOW);
      
}

void light()
{
      digitalWrite(red,HIGH);
      delay(50);
      digitalWrite(red,LOW);
      delay(50);
      digitalWrite(green,HIGH);
      delay(50);
      digitalWrite(green,LOW);
      delay(50);
      digitalWrite(blue,HIGH);
      delay(50);
      digitalWrite(blue,LOW);
      delay(50); 
      digitalWrite(red,HIGH);
      delay(2000);
      digitalWrite(red,LOW);
}
 

 
 
