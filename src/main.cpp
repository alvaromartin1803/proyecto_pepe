#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "Tu_SSID";
const char* password = "Tu_Contraseña";
const char* serverName = "http://192.168.x.x:5000/login"; // Cambia esto por la IP de tu servidor Flask

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(serverName);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");

    String httpRequestData = "username=usuario&password=contraseña";
    int httpResponseCode = http.POST(httpRequestData);

    if (httpResponseCode > 0) {
      String response = http.getString();
      Serial.println(httpResponseCode);
      Serial.println(response);
    } else {
      Serial.print("Error on sending POST: ");
      Serial.println(httpResponseCode);
    }
    http.end();
  }
  delay(10000); // Intervalo de 10 segundos entre solicitudes
}
