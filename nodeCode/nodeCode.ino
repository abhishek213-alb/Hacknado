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
  
}

void loop() {
  //Potentiometer Data
  sensorValue = analogRead(analogInPin);
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\n");
  delay(100);

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
}
