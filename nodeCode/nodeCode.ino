#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h> 
#include <SoftwareSerial.h>
#include <string.h>

const int analogInPin = A0;
int sensorValue = 0;

void setup() {
  // Initialize LEDs as Output
  pinMode(BUILTIN_LED, OUTPUT);
  pinMode(5, OUTPUT);//Red
  pinMode(4, OUTPUT);//Yellow
  pinMode(0, OUTPUT);//White
  pinMode(2, OUTPUT);//Blue
  pinMode(14, OUTPUT);//Green
  Serial.begin(115200);

  //Initialize WiFi Connection
  WiFi.begin("1141", "WiFi@09876");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Waiting for connection");
  }
}

void loop() {
  //Potentiometer Data
  sensorValue = analogRead(analogInPin);
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\n");
  delay(500);

  //LEDs
  if (sensorValue < 205){
    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(0, LOW);
    digitalWrite(2, LOW);
    digitalWrite(14, LOW);
  }

    else if (sensorValue > 205 & sensorValue < 410){
    digitalWrite(5, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(0, LOW);
    digitalWrite(2, LOW);
    digitalWrite(14, LOW);
  }

  else if (sensorValue > 410 & sensorValue < 615){
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    digitalWrite(0, HIGH);
    digitalWrite(2, LOW);
    digitalWrite(14, LOW);
  }

  else if (sensorValue > 615 & sensorValue < 820){
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    digitalWrite(0, LOW);
    digitalWrite(2, HIGH);
    digitalWrite(14, LOW);
  }

  else if (sensorValue > 820 & sensorValue < 1024){
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    digitalWrite(0, LOW);
    digitalWrite(2, LOW);
    digitalWrite(14, HIGH);
  }

  // Send Data to API
    if (WiFi.status() == WL_CONNECTED) {
    WiFiClient client;
    HTTPClient http; //Declare object of class HTTPClient
    http.begin(client, "http://cloudfunctions.net/addData");
    String str= "sensorData_"+String(sensorValue);
    
    int httpCode = http.POST(str); //Send the request
    String payload = http.getString(); //Get the response payload
    Serial.println(httpCode); //Print HTTP return code
    Serial.println(payload); //Print request response payload
    http.end();
  } 
    else {
    Serial.println("Error in WiFi connection");
  }
}
