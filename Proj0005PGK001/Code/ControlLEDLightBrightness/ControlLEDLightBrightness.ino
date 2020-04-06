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
   - 1 x LEDs (White)
   - 1 x LDR
   - 2 x Resistor 330 Ohm
   
   Project Name: Control LED light brightness 
   Controlling the light brightness level base on LDR (Light Dependency Resistor).
   This project consists of LDR (Light Dependency Resistor)
   Sensor and White LED.

   Proj0004PGK001
   Created March 27,2020 BY EIT EDUCATION GROUP
   Modified April 01,2020 BY EIT EDUCATION GROUP

*/

//Define Constant variables
#define LED_WHITE   3
#define LDR         A0
#define LIGHT_LEVEL 50//Persentage of the light level 50%

//Define varibles 
int sensorValue = 0; //To store the value of the sensor  
int persentageValue = 0; // value of the persentage of the light level

void setup() {
  //define the LEDs pins as output
  pinMode(LED_WHITE, OUTPUT);
}

//getLightLevel is function get the level of the light 
int getLightLevel() {
  //read the analog in value
  sensorValue = analogRead(analogInPin);
  //Convert the base value of LDR to be in persentage 
  persentageValue = map(sensorValue, 0, 1023, 0, 100);
  return persentageValue;//return the light level value
}

void loop() {
  //Call function getLightLevel() to get the persentage of ldr level then store it into local varibale ldrLevel
  int ldrLevel = getLightLevel();
  //Convert the persentage value of LDR to be in PWM (analog out)
  int pwmValue = map(ldrLevel, 0, 100, 0, 255);
  analogWrite(LED_WHITE,pwmValue);
}
