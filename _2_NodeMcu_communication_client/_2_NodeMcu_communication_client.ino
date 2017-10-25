#include <ESP8266WiFi.h>

String  i;
IPAddress staticIP653_6(192,168,1,1);
IPAddress gateway653_6(192,168,1,1);
IPAddress subnet653_6(255,255,255,0);

WiFiServer server(80);

void setup()
{
  i = "";

  Serial.begin(9600);

  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(0, OUTPUT);
  pinMode(2, OUTPUT);
    WiFi.disconnect();
  delay(2000);
  Serial.println("Start Client");
   WiFi.begin("Pytron","pytron123");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(1000);
    Serial.println(">>");

  }
  Serial.println("Connected");
  WiFi.config(staticIP653_6, gateway653_6, subnet653_6);
  Serial.println((WiFi.localIP()));
  server.begin();

}


void loop()
{

    WiFiClient client = server.available();
    if (!client) { return; }
    while(!client.available()){  delay(1); }
    i = (client.readStringUntil('\r'));
    i.remove(0, 5);
    i.remove(i.length()-9,9);
    Serial.println("Before I");
    Serial.println(i);
    if (i == "ROOF_ON") {
      digitalWrite(5,HIGH);

    } else if (i == "ROOF_OFF") {
      digitalWrite(5,LOW);
    } else if (i == "TUBE_ON") {
      digitalWrite(4,HIGH);
    } else if (i == "TUBE_OFF") {
      digitalWrite(4,LOW);
    } else if (i == "BALCONY_ON") {
      digitalWrite(0,HIGH);
    } else if (i == "BALCONY_OFF") {
      digitalWrite(0,LOW);
    } else if (i == "PLUG_ON") {
      digitalWrite(2,HIGH);
    } else if (i == "PLUG_OFF") {
      digitalWrite(2,LOW);
    } else if (i == "ALL_ON") {
      digitalWrite(5,HIGH);
      digitalWrite(4,HIGH);
      digitalWrite(0,HIGH);
      digitalWrite(2,HIGH);
    } else if (i == "ALL_OFF") {
      digitalWrite(5,LOW);
      digitalWrite(4,LOW);
      digitalWrite(0,LOW);
      digitalWrite(2,LOW);
    }
    delay(3000);

}
