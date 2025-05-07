#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>


const char* ssid = "Galaxy A52D2F7";
const char* password = "123456789"

ESP8226WebServer server (80);
String webpage;

void setup() 
{
  iSerial.begin(9600);
  delay (10);

  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(D6, OUTPUT);

//Connect to WiFi network
  Serial.println();
  Serial.print("Konfigurasi akses poin...");

//Mengatur WiFi 
WiFi.mode(WIFI_AP);
WiFi.begin(ssid, password);

//Cek Status Koneksi
  Serial.println("IP Address...");
  Serial.println(WiFi.softAPIP());

//Isi dari WebPage
  webpage+= "<h1> Web Control ESP8226</h1>";
  webpage+= "<h2> Fatur Sakti Arrafi</h2>";
  webpage+= "<p> LED1 :";
  webpage+= "<a href=\"LED1ON\"\"><button>ON</button></a>/a href=\"LED1OFF\"\"><button>OFF</button></a>";
  webpage+= "<a href=\"LED2ON\"\"><button>ON</button></a>/a href=\"LED2OFF\"\"><button>OFF</button></a>";
  webpage+= "<a href=\"LED3ON\"\"><button>ON</button></a>/a href=\"LED3OFF\"\"><button>OFF</button></a>";
//Membuat Tampilan Webpage
server.on("/",[]() 
{
  server.send(200, "text/html", webpage);
});

//Bagian ini untuk merespon perintah yang masuk

server.on("/LED1ON", []()
{
  server.send(200, "text/html", webpage);
  digitalWriter(D3, HIGH);
  delay(1000);
});
server.on("/LED2ON", []()
{
  server.send(200, "text/html", webpage);
  digitalWriter(D4, HIGH);
  delay(1000);
});
server.on("/LED3ON", []()
{
  server.send(200, "text/html", webpage);
  digitalWriter(D6, HIGH);
  delay(1000);
});

server.on("/LED1OFF", []()
{
  server.send(200, "text/html", webpage);
  digitalWriter(D3, LOW);
  delay(1000);
});
server.on("/LED2OFF", []()
{
  server.send(200, "text/html", webpage);
  digitalWriter(D4, LOW);
  delay(1000);
});
server.on("/LED3OFF", []()
{
  server.send(200, "text/html", webpage);
  digitalWriter(D6, LOW);
  delay(1000);
});


server.begin();
Serial.println("Webserver dijalankan");
}

void loop() 
{
  server.handleClient();
}
