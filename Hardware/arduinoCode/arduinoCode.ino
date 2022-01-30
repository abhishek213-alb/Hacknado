#include <SoftwareSerial.h>
#include <string.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int sensorValue = 0;

void setup() {
  // Initialize LEDs as Output
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(6, OUTPUT);//Red
  pinMode(5, OUTPUT);//Yellow
  pinMode(4, OUTPUT);//White
  pinMode(3, OUTPUT);//Blue
  pinMode(2, OUTPUT);//Green
  Serial.begin(115200);
}

void loop() {
  // Initialize LED
  lcd.init();
  lcd.backlight();
  lcd.clear();
  
  //Potentiometer Data
  sensorValue = analogRead(A0);
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\n");

  //LEDs
  if (sensorValue < 140){
    digitalWrite(6, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);

    lcd.setCursor(0,0);
    lcd.print("Status:");
    lcd.setCursor(0,1);
    lcd.print("Red Alert!");
  }

    else if (sensorValue > 140 & sensorValue < 280){
    digitalWrite(6, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);

    lcd.setCursor(0,0);
    lcd.print("Status:");
    lcd.setCursor(0,1);
    lcd.print("Stay Cautious!");
  }

  else if (sensorValue > 280 & sensorValue < 420){
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);

    lcd.setCursor(0,0);
    lcd.print("Status:");
    lcd.setCursor(0,1);
    lcd.print("Average");
  }

  else if (sensorValue > 420 & sensorValue < 560){
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(2, LOW);

    lcd.setCursor(0,0);
    lcd.print("Status:");
    lcd.setCursor(0,1);
    lcd.print("Okay");
  }

  else if (sensorValue > 560 & sensorValue < 700){
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    digitalWrite(3, LOW);
    digitalWrite(2, HIGH);

    lcd.setCursor(0,0);
    lcd.print("Status:");
    lcd.setCursor(0,1);
    lcd.print("All good!");
  }
  
}
