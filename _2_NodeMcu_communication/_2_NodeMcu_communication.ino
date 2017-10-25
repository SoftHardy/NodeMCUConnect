#include <ESP8266WiFi.h>

#include <ESP8266HTTPClient.h>

String  i;
String  new_var;
/*IPAddress staticIP162_7(192,168,1,7);
IPAddress gateway162_7(192,168,1,1);
IPAddress subnet162_7(255,255,255,0);
*/
WiFiServer server(80);

String  httpurl;
HTTPClient http;

void setup()
{
  i = "";

  new_var = "ON";

  Serial.begin(9600);

    WiFi.disconnect();
  delay(1000);
  Serial.println("Start Server");
   WiFi.begin("Pytron","pytron123");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(1000);
    Serial.println(">>");

  }
  Serial.println("Connected");
  //WiFi.config(staticIP162_7, gateway162_7, subnet162_7);
  Serial.println((WiFi.localIP()));
  server.begin();

}


void loop()
{

    WiFiClient client = server.available();
    if (!client) { return; }
    while(!client.available()){  delay(1); }
    Serial.println("CLIENT IP");
    Serial.println((client.remoteIP()));
    Serial.println("DONE");
    i = (client.readStringUntil('\r'));
    i.remove(0, 5);
    i.remove(i.length()-9,9);
    Serial.println("Before I");
    Serial.println(i);
    Serial.println("After I");
    if (i == "ROOF_ON") {
      httpurl = "http://";
      httpurl+="192.168.1.6";
      httpurl+="/";
      httpurl+="ROOF_ON";
      http.begin(httpurl);
      http.GET();
      http.end();
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("");
      client.println("</html>");
      client.stop();
      delay(1);

    } else if (i == "ROOF_OFF") {
      httpurl = "http://";
      httpurl+="192.168.1.6";
      httpurl+="/";
      httpurl+="ROOF_OFF";
      http.begin(httpurl);
      http.GET();
      http.end();
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("");
      client.println("</html>");
      client.stop();
      delay(1);
    } else if (i == "TUBE_ON") {
      httpurl = "http://";
      httpurl+="192.168.1.6";
      httpurl+="/";
      httpurl+="TUBE_ON";
      http.begin(httpurl);
      http.GET();
      http.end();
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("");
      client.println("</html>");
      client.stop();
      delay(1);
    } else if (i == "TUBE_OFF") {
      httpurl = "http://";
      httpurl+="192.168.1.6";
      httpurl+="/";
      httpurl+="TUBE_OFF";
      http.begin(httpurl);
      http.GET();
      http.end();
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("");
      client.println("</html>");
      client.stop();
      delay(1);
    } else if (i == "BALCONY_ON") {
      httpurl = "http://";
      httpurl+="192.168.1.6";
      httpurl+="/";
      httpurl+="BALCONY_ON";
      http.begin(httpurl);
      http.GET();
      http.end();
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("");
      client.println("</html>");
      client.stop();
      delay(1);
    } else if (i == "BALCONY_OFF") {
      httpurl = "http://";
      httpurl+="192.168.1.6";
      httpurl+="/";
      httpurl+="BALCONY_OFF";
      http.begin(httpurl);
      http.GET();
      http.end();
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("");
      client.println("</html>");
      client.stop();
      delay(1);
    } else if (i == "PLUG_ON") {
      httpurl = "http://";
      httpurl+="192.168.1.6";
      httpurl+="/";
      httpurl+="PLUG_ON";
      http.begin(httpurl);
      http.GET();
      http.end();
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("");
      client.println("</html>");
      client.stop();
      delay(1);
    } else if (i == "PLUG_OFF") {
      httpurl = "http://";
      httpurl+="192.168.1.6";
      httpurl+="/";
      httpurl+="PLUG_OFF";
      http.begin(httpurl);
      http.GET();
      http.end();
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("");
      client.println("</html>");
      client.stop();
      delay(1);
    } else if (i == "ALL_ON") {
      httpurl = "http://";
      httpurl+="192.168.1.6";
      httpurl+="/";
      httpurl+="ALL_ON";
      http.begin(httpurl);
      http.GET();
      http.end();
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("");
      client.println("</html>");
      client.stop();
      delay(1);
    } else if (i == "ALL_OFF") {
      httpurl = "http://";
      httpurl+="192.168.1.6";
      httpurl+="/";
      httpurl+="ALL_OFF";
      http.begin(httpurl);
      http.GET();
      http.end();
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("");
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("");
      client.println("</html>");
      client.stop();
      delay(1);
    }

}
