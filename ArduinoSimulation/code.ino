#include<LiquidCrystal.h>
LiquidCrystal lcd(12, 10, 8, 7, 6, 5);
int value=0;
int baselineTemp = 0;

int celsius = 0;

int fahrenheit = 0;

void setup()
{
  lcd.begin(16,2);
  pinMode(A0, INPUT);
  Serial.begin(9600);

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(A1, INPUT);
}

void loop()
{
  
  //temperature monitoring section
  
 
  // set threshold temperature to activate LEDs
  baselineTemp = 5;
  // measure temperature in Celsius
  celsius = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);
  // convert to Fahrenheit
  fahrenheit = ((celsius * 9) / 5 + 32);
  Serial.print(celsius);
  Serial.print(" C, ");
  lcd.setCursor(0,0);
  lcd.print(celsius);
  Serial.print(fahrenheit);
  Serial.println(" F");
  if (celsius < baselineTemp) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  if (celsius >= baselineTemp && celsius < baselineTemp + 5) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
  if (celsius >= baselineTemp + 6 && celsius < baselineTemp + 10) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }
  if (celsius >= baselineTemp + 11 && celsius < baselineTemp + 20) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  if (celsius >= baselineTemp + 21) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  
  
  // photoresistor section
  
  
  value=analogRead(A1);
  lcd.setCursor(1,1);
  lcd.print(value);
  if(value<100)
  {
  	digitalWrite(11, HIGH);
    Serial.println("Light ON");
    Serial.println(value);
  }
  else
  {
  digitalWrite(11, LOW);
  Serial.println("Light OFF");
  Serial.println(value);
  }
  
  
  delay(1000); // Wait for 1000 millisecond(s)
}