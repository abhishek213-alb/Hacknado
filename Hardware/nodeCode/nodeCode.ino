#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h> 
#include <SoftwareSerial.h>
#include <string.h>

int sensData;

void setup() {
  Serial.begin(115200);  
  //Initialize WiFi Connection
  WiFi.begin("1141", "WiFi@09876");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Waiting for Connection");
  }

}

void loop() {
  // Receive Data from Arduino
  sensData= Serial.read();
  // Physical Response from NodeMCU
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
  
  // Send Data to API
    if (WiFi.status() == WL_CONNECTED) {
    WiFiClient client;
    HTTPClient http; // Declare object of class HTTPClient
    http.begin(client, "http://cloudfunctions.net/addData");
    http.addHeader("Content-Type", "text/plain");
    String str= "sensorData_"+String(sensData);
    Serial.println(str);

    int httpCode = http.POST(str); // Send the request
    String payload = http.getString(); // Get the response payload
    Serial.println(httpCode); // Print HTTP return code
    Serial.println(payload); // Print request response payload
    http.end();
  } 
    else {
    Serial.println("Error in WiFi connection");
  }

}
