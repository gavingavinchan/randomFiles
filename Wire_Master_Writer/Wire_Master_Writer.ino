// Wire Master Writer
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Writes data to an I2C/TWI slave device
// Refer to the "Wire Slave Receiver" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>

void setup() {
  Wire.begin(); // join i2c bus (address optional for master)
  blink(2);
}

byte x = 3;

void loop() {
  blink(x);
  delay(500);
  Wire.beginTransmission(8); // transmit to device #8
//  Wire.write("x is ");        // sends five bytes
  Wire.write(x);              // sends one byte
  Wire.endTransmission();    // stop transmitting

  blink(x);
//  x++;
  delay(1000);
}

void blink(int times) {
  for (int i=0;i<times;i++) {
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(500);                       // wait for a second
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    delay(500);    
  }
}
