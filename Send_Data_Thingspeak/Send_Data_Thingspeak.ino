#include <ESP8266WiFi.h>;
#include <WiFiClient.h>;
#include <ThingSpeak.h>;
int val;
#include<dht.h>
dht DHT;
int DHT_pin = D1;
WiFiClient client;
unsigned long myChannelNumber = 1324644; //Your Channel Number (Without Brackets)
const char * myWriteAPIKey = "DHWZG29PIF5RGYD2"; //Your Write API Key
void setup()
{
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
}

void loop()
{
  int chk = DHT.read11(DHT_pin);
 // val = DHT.temperature;
val = random(1,10);
 //Print on Serial Monitor
delay(100);
ThingSpeak.writeField(myChannelNumber, 1,val, myWriteAPIKey); //Update in ThingSpeak
delay(100);
Serial.println(val);

}
