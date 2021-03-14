#include <ThingSpeak.h>
#include<ESP8266WiFi.h>
WiFiClient client;
unsigned long myChannelNumber = 1324644; //Your Channel Number (Without Brackets)
const char * myWriteAPIKey = "DHWZG29PIF5RGYD2"; //Your Write API Key
const int FieldNumber1 = 1;

void setup() {
  Serial.begin(9600);
delay(10);
// Connect to WiFi network
WiFi.begin("Peaky","HarryPotter0709");
while((!(WiFi.status() == WL_CONNECTED))){
   delay(100);
    Serial.print("..");
    
 }
Serial.println("Connected");
ThingSpeak.begin(client);
  // put your setup code here, to run once:

}

void loop() {
  long temp = ThingSpeak.readLongField(myChannelNumber, FieldNumber1, myWriteAPIKey);
   int statusCode = ThingSpeak.getLastReadStatus();
  if (statusCode == 200)
  {
    Serial.println(temp);
    Serial.println("REE");
  }
  delay(500);
  
  // put your main code here, to run repeatedly:

}
