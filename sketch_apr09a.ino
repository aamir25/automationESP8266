#include <ESP8266WiFi.h>

const char* ssid = "Faraz";
const char* password = "12345678";

int ledpin=2;    // D4 in ModeMcu
WiFiServer server(80);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(10);
  pinMode(ledpin,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(0,OUTPUT);
  
  digitalWrite(ledpin,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(0,HIGH);
  
  //connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin (ssid,password);

  while (WiFi.status()!=WL_CONNECTED)
  {  delay(500);
     Serial.print(".");
  }


  Serial.println("");
  Serial.println("WiFi connected");
  // Start the server
  server.begin();
  Serial.println("Server started");

  //Print the IP Address

  Serial.print("Use this url to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
}

void loop() {
  // put your main code here, to run repeatedly:
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client)
  { 
    return;
  }
  //Wait until the client sends some data

  Serial.println("new client");
  while (!client.available())
  {
    delay(1);
  }

  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
  //Match the request

  int value=LOW;

  // PIN 5  ON
  if ((request.indexOf(" /LED?value=1&pin=4") == -1) && (request.indexOf(" /LED?value=1&pin=2") == -1) && (request.indexOf(" /LED?value=1&pin=0") == -1) && (request.indexOf(" /LED?value=0&pin=5") == -1) && (request.indexOf(" /LED?value=0&pin=4") == -1) && (request.indexOf(" /LED?value=0&pin=0") == -1) && (request.indexOf(" /LED?value=0&pin=2") == -1))
  {
    digitalWrite(5, 0);
  }
  
  // PIN 4  ON
  if ((request.indexOf(" /LED?value=1&pin=5") == -1) && (request.indexOf(" /LED?value=1&pin=2") == -1) && (request.indexOf(" /LED?value=1&pin=0") == -1) && (request.indexOf(" /LED?value=0&pin=5") == -1) && (request.indexOf(" /LED?value=0&pin=4") == -1) && (request.indexOf(" /LED?value=0&pin=0") == -1) && (request.indexOf(" /LED?value=0&pin=2") == -1))
  {
    digitalWrite(4, 0);
  }

  // PIN 0  ON
  if ((request.indexOf(" /LED?value=1&pin=5") == -1) && (request.indexOf(" /LED?value=1&pin=2") == -1) && (request.indexOf(" /LED?value=1&pin=4") == -1) && (request.indexOf(" /LED?value=0&pin=5") == -1) && (request.indexOf(" /LED?value=0&pin=4") == -1) && (request.indexOf(" /LED?value=0&pin=0") == -1) && (request.indexOf(" /LED?value=0&pin=2") == -1))
  {
    digitalWrite(0, 0);
  }

  // PIN 2  ON
  if ((request.indexOf(" /LED?value=1&pin=5") == -1) && (request.indexOf(" /LED?value=1&pin=4") == -1) && (request.indexOf(" /LED?value=1&pin=0") == -1) && (request.indexOf(" /LED?value=0&pin=5") == -1) && (request.indexOf(" /LED?value=0&pin=4") == -1) && (request.indexOf(" /LED?value=0&pin=0") == -1) && (request.indexOf(" /LED?value=0&pin=2") == -1))
  {
    digitalWrite(2, 0);
  }

  // PIN 5  OFF
  if ((request.indexOf(" /LED?value=0&pin=4") == -1) && (request.indexOf(" /LED?value=0&pin=2") == -1) && (request.indexOf(" /LED?value=0&pin=0") == -1) && (request.indexOf(" /LED?value=1&pin=5") == -1) && (request.indexOf(" /LED?value=1&pin=4") == -1) && (request.indexOf(" /LED?value=1&pin=0") == -1) && (request.indexOf(" /LED?value=1&pin=2") == -1))
  {
    digitalWrite(5, 1);
  }

  // PIN 4  OFF
  if ((request.indexOf(" /LED?value=0&pin=5") == -1) && (request.indexOf(" /LED?value=0&pin=2") == -1) && (request.indexOf(" /LED?value=0&pin=0") == -1) && (request.indexOf(" /LED?value=1&pin=5") == -1) && (request.indexOf(" /LED?value=1&pin=4") == -1) && (request.indexOf(" /LED?value=1&pin=0") == -1) && (request.indexOf(" /LED?value=1&pin=2") == -1))
  {
    digitalWrite(4, 1);
  }

  // PIN 0  OFF
  if ((request.indexOf(" /LED?value=0&pin=4") == -1) && (request.indexOf(" /LED?value=0&pin=2") == -1) && (request.indexOf(" /LED?value=0&pin=5") == -1) && (request.indexOf(" /LED?value=1&pin=5") == -1) && (request.indexOf(" /LED?value=1&pin=4") == -1) && (request.indexOf(" /LED?value=1&pin=0") == -1) && (request.indexOf(" /LED?value=1&pin=2") == -1))
  {
    digitalWrite(0, 1);
  }

  // PIN 2  OFF
  if ((request.indexOf(" /LED?value=0&pin=4") == -1) && (request.indexOf(" /LED?value=0&pin=5") == -1) && (request.indexOf(" /LED?value=0&pin=0") == -1) && (request.indexOf(" /LED?value=1&pin=5") == -1) && (request.indexOf(" /LED?value=1&pin=4") == -1) && (request.indexOf(" /LED?value=1&pin=0") == -1) && (request.indexOf(" /LED?value=1&pin=2") == -1))
  {
    digitalWrite(2, 1);
  }

//  if ((request.indexOf(" /LED?value=0&pin=4") == -1) && (request.indexOf(" /LED?value=0&pin=5") == -1) && (request.indexOf(" /LED?value=0&pin=0") == -1) && (request.indexOf(" /LED?value=0&pin=2") == -1) && (request.indexOf(" /LED?value=1&pin=5") == -1) && (request.indexOf(" /LED?value=1&pin=4") == -1) && (request.indexOf(" /LED?value=1&pin=0") == -1) && (request.indexOf(" /LED?value=1&pin=2") == -1))
//  {
//    client.println("HTTP/1.1 200 OK");
//    client.println("Content-Type: application/json");
//    client.println("");
//    client.println(String("{\"light1\": ") + gpio.read(2) + ", \"light2\": " + gpio.read(5) + ", \"light3\": " + gpio.read(4) + ", \"light4\": " + gpio.read(0) + "}");
//  }
//  if (request.indexOf(" /LED=ON")!=-1)
//  {
//    digitalWrite(ledpin,0);
//    value=HIGH ;
//  }
//  
//  if (request.indexOf(" /LED=OFF")!=-1)
//  {
//    digitalWrite(ledpin,1);
//    value=HIGH ;
//  }
  
  // Set ledpin according to the request
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("");// do not forget this one
  client.println("Success");
//  client.println("<!DOCTYPE HTML>");
//  client.println("<html>");
//  client.println("<title>switch</title>");
//
//  client.print("Led pin is now: ");
//
//  if (value==HIGH)
//  {
//    client.print("OFF");
//
//  }
//  else
//  {
//    client.print("ON");
//  }
//
//
//  client.println("<br><br>");
//  client.println("<a href=\"/LED=OFF\"\"><button>Turn <b>ON</b></button></a>");
//  client.println("<a href=\"/LED=ON\"\"><button>Turn <b>OFF</b></button></a></br>");
//  client.println("</html>");

  delay(1);

  Serial.println("Client disconnected");
  Serial.println("");
}
