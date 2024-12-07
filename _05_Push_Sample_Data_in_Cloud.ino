
 #include <WiFi.h>
#include <HTTPClient.h>
#define WIFI_SSID "</>"
#define WIFI_PASSWORD "0980980981"
float Temperature = 25.5;
float Humidity = 67;
int value = 100;
const char *serverUrl = "https://console.thingzmate.com/api/v1/device-types/xiaomi/devices/xiaomi/uplink"; // Replace with your server endpoint
String AuthorizationToken = "Bearer 10f1b0282482124cd7d5e6befecceddb";
void setup() {
  Serial.begin(115200);
  delay(4000); // Delay to let serial settle

  // Connect to WiFi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("Connected to WiFi");
}

void loop() {
  HTTPClient http;
  http.begin(serverUrl);
  http.addHeader("Content-Type", "application/json");
http.addHeader("Authorization", AuthorizationToken); //Authorization token
  // Create JSON payload
  String payload = "{\"temperature\":" + String(Temperature) +",\"humidity\":" + String(Humidity) +",\"Raw_Value\":" + String(value) +  "}";
  
  // Send POST request
  int httpResponseCode = http.POST(payload);

  if (httpResponseCode > 0) {
    String response = http.getString();
    Serial.println("HTTP Response code: " + String(httpResponseCode));
    Serial.println(response);
  } else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }

  http.end(); // Free resources
  delay(10000); // Wait for 1 minute before sending next request
}