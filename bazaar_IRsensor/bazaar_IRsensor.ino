#define IRsensor 1
#define LEDpin 1
#define outputPin 0

int sensorValue = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LEDpin, OUTPUT);
  pinMode(outputPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(IRsensor);
  if(sensorValue <80) {
    Serial.println(sensorValue);
    Serial.println("coin detected");
    digitalWrite(LEDpin, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(outputPin,HIGH);
    delay(250);  
    digitalWrite(LEDpin, LOW);    // turn the LED off by making the voltage LOW
    digitalWrite(outputPin,LOW);
    delay(50); 
  }
}
