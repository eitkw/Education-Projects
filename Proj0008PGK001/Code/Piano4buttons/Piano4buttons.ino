/*
   EIT (Electronic In Touch) Projects
   www.eitkw.com

   Youtube Project Link:
   https://www.youtube.com/watch?v=GcXmUjAJp-8

   Github Project Source Code Link:
   www.eitkw.com/GitHub

   Project Conponents Package Link:
   www.eitkw.com/EIT-PGK-001/
   - 1 x Arduino Uno
   - 1 x LM35
   - 3 x LEDs (Red - Yellow - Green)
   - 3 x Resistor 330 Ohm


   Project Name: Temperature level detector
   In this code we will simulate temperature level detector
   that this have three type of LEDs (GREEN|YELLOW|RED) indicator
   for the temperature level if it's green that mean it's safe if
   yellow that mean up normal level and red if its over heat and the alert
   will be raised using buzzer

   Proj0007PGK001
   Created March 27,2020 BY EIT EDUCATION GROUP
   Modified April 01,2020 BY EIT EDUCATION GROUP

*/

//Define Constant variables
#define LED_GREEN  2
#define LED_YELLOW 3
#define LED_RED    4
#define BUZZER     5

#define LM35 A0

#define LVL_SAFE      20
#define LVL_UP_NORMAL 30
#define LVL_OVER_HEAT 40

void setup() {
  //define the LEDs pins as output
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_RED, OUTPUT);
}

//greenLight is function switch green led
void greenLight() {
  digitalWrite(LED_GREEN, HIGH);// turn the LED on (HIGH is the voltage level)
  digitalWrite(LED_YELLOW, LOW);// turn the LED off by making the voltage LOW
  digitalWrite(LED_RED, LOW);   // turn the LED off by making the voltage LOW
}

//yellowLight is function switch yellow led
void yellowLight() {
  digitalWrite(LED_GREEN, LOW);  // turn the LED off by making the voltage LOW
  digitalWrite(LED_YELLOW, HIGH);// turn the LED on (HIGH is the voltage level)
  digitalWrite(LED_RED, LOW);    // turn the LED off by making the voltage LOW
}

//redLight is function switch red led
void redLight() {
  digitalWrite(LED_GREEN, LOW); // turn the LED off by making the voltage LOW
  digitalWrite(LED_YELLOW, LOW);// turn the LED off by making the voltage LOW
  digitalWrite(LED_RED, HIGH);  // turn the LED on (HIGH is the voltage level)
}

float getTemperature() {
  val = analogRead(tempPin);
  float mv = ( val / 1024.0) * 5000;
  float cel = mv / 10;
  return cel;
}

void loop() {
  //Call waterLevel function
  if (getTemperature() >= LVL_OVER_HEAT) {
    redLight(); //Call redLight to switch on red LED on and others off
  }
  else if (getTemperature() >= LVL_UP_NORMAL) {
    yellowLight();//Call yellowLight to switch on yellow LED on and others off
  }
  else if (getTemperature() >= LVL_SAFE) {
    greenLight();   //Call greenLight to switch on green ow LED on and others off
  }
  else {
    greenLight();   //Call greenLight to switch on green ow LED on and others off
  }
}
