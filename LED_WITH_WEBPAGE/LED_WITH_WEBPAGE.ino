
#include<ESP8266WiFi.h>
String client_request;
WiFiServer server(80);//CREATE WEB SERVER
int led=D0;
void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  WiFi.disconnect();
  Serial.println("Start");
  WiFi.begin("Peaky", "HarryPotter0709");

  while ((!(WiFi.status() == WL_CONNECTED)))
  {
    delay(300);
    Serial.print("..");

  }
  Serial.println("connected");
  // Serial.print("Host name: ");
  //Serial.println(WiFi.hostname());
  // put your setup code here, to run once:
  Serial.print(" ip: ");
  Serial.println(WiFi.localIP().toString());
  //Serial.print("Gateway IP: ");
  //Serial.println((WiFi.gatewayIP().toString().c_str()));
  server.begin();
}

void loop() {
  WiFiClient client = server.available(); // CREATING A CLIENT
  if (!client)
  {
    return;
  }
  while (!client.available())
  {
    delay(1);
  }
  Serial.println("Working");
  client_request = (client.readStringUntil('\r'));
  client.flush();
  client_request.remove(0, 5);
  client_request.remove(client_request.length() - 9, 9);
  client_request.remove(client_request.length() - 11, 11);
  Serial.println(client_request);
   if(client_request=="LED=ON")
  {
    digitalWrite(led,HIGH);
  }
  else if(client_request=="LED=OFF")
  {
    digitalWrite(led,LOW);
  }

  //HTML CODE FOR CREATING wEBPAGE

  client.flush();
  client.println("HTTP/1.1 200 OK");
  client.println("content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE html>");
  client.println("<html>");
  client.println("<head >");
  client.println("<center>");
  client.println("<link rel='stylesheet' href='https://maxcdn.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css'>");
  client.println("<h1 >welcome</h1>");
  client.println("<h4 class = 'text-muted'> led</h4>");
  client.println("  </center>");
  client.println("</head>");
  client.println("<body class = 'bg-success' >");
  client.println("<center>");
   client.println("<a href=");
  client.println("LED=OFF");
  client.println("><button type='button' class='btn btn-primary'>");
  client.println("OFF");
  client.println("</button></a>");
   client.println("<a href=");
  client.println("LED=ON");
   client.println("><button type='button' class='btn btn-primary'>");
  client.println("on");
  client.println("</button></a>");

 client.println("  </center>");
  client.println("</body>");
  client.println("</html>");
  client.stop();
  delay(1);


}
