/*
  pwm.cpp
  Tauno Erik
  06.11.2022

 ESP32 PWM example. LEDS fadin and out. 3 LEDS connected to 3 different LED channels.
*/
#include <Arduino.h>

// Pins
const int LED_R_0 = 16;    // GPIO16
const int LED_G_0 = 17;    // GPIO17
const int LED_B_0 = 18;    // GPIO18

// PWM
const int FREQ = 5000;     // HZ
const int CH_0 = 0;
const int CH_1 = 1;
const int CH_2 = 2;
const int RESOLUTION = 8;  // bits

void setup() {
  Serial.begin(115200);
  Serial.println("Begins!");

  // Configure LED PWM functionalitites
  ledcSetup(CH_0, FREQ, RESOLUTION);
  ledcSetup(CH_1, FREQ, RESOLUTION);
  ledcSetup(CH_2, FREQ, RESOLUTION);

  // Attach the channel to the GPIO to be controlled
  ledcAttachPin(LED_R_0, CH_0);
  ledcAttachPin(LED_G_0, CH_1);
  ledcAttachPin(LED_B_0, CH_2);
}

void loop() {
  // increase the LED brightness
  for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){   
    // changing the LED brightness with PWM
    ledcWrite(CH_0, dutyCycle);
    delay(15);
  }

  // decrease the LED brightness
  for(int dutyCycle = 255; dutyCycle >= 0; dutyCycle--){
    // changing the LED brightness with PWM
    ledcWrite(CH_0, dutyCycle);
    delay(15);
  }

  // increase the LED brightness
  for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){   
    // changing the LED brightness with PWM
    ledcWrite(CH_1, dutyCycle);
    delay(15);
  }

  // decrease the LED brightness
  for(int dutyCycle = 255; dutyCycle >= 0; dutyCycle--){
    // changing the LED brightness with PWM
    ledcWrite(CH_1, dutyCycle);
    delay(15);
  }

  // increase the LED brightness
  for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){   
    // changing the LED brightness with PWM
    ledcWrite(CH_2, dutyCycle);
    delay(15);
  }

  // decrease the LED brightness
  for(int dutyCycle = 255; dutyCycle >= 0; dutyCycle--){
    // changing the LED brightness with PWM
    ledcWrite(CH_2, dutyCycle);
    delay(15);
  }

  ledcWrite(CH_0, 50);
  ledcWrite(CH_1, 100);
  ledcWrite(CH_2, 200);
  delay(2000);
}