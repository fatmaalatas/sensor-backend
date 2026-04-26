#include <WiFi.h>
#include <HTTPClient.h>
#include <WiFiClientSecure.h>
#include <DHT.h>

// --- KONFİG ---
#define DHTPIN 15
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

const char* ssid = "Wokwi-GUEST";
const char* password = "";

const char* serverName = "https://sensor-backend-production-28d9.up.railway.app/api/sensor/data";

void setup() {
  Serial.begin(115200);
  dht.begin();

  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi...");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi Connected!");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {

    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();

    if (isnan(temperature) || isnan(humidity)) {
      Serial.println("Sensor error!");
      delay(2000);
      return;
    }

    String jsonPayload = "{\"temperature\": " + String(temperature) + ", \"humidity\": " + String(humidity) + "}";

    WiFiClientSecure client;
    client.setInsecure(); // SSL bypass

    HTTPClient http;

    Serial.println("Sending data...");
    Serial.println(jsonPayload);

    if (http.begin(client, serverName)) {

      http.addHeader("Content-Type", "application/json");
      http.addHeader("ngrok-skip-browser-warning", "1");

      int httpResponseCode = http.POST(jsonPayload);

      if (httpResponseCode > 0) {
        Serial.print("SUCCESS! Code: ");
        Serial.println(httpResponseCode);

        String response = http.getString();
        Serial.println("Response:");
        Serial.println(response);

      } else {
        Serial.print("ERROR! Code: ");
        Serial.println(httpResponseCode);
        Serial.println(http.errorToString(httpResponseCode));
      }

      http.end();
    } else {
      Serial.println("Connection failed!");
    }
  }

  delay(5000);
}