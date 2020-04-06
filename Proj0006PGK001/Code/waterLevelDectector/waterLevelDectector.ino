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
   - 1 x Water Level Sensor
   - 3 x LEDs (Red - Yellow - Green)
   - 3 x Resistor 330 Ohm


   Project Name: water level detector
   In this code we will simulate water level detector
   that this have three type of LEDs (GREEN|YELLOW|RED) indicator
   for the water level if it's green that mean it's full if
   yellow that mean medium level and red if its empty and the alert
   will be raised using buzzer

   Proj0006PGK001
   Created March 27,2020 BY EIT EDUCATION GROUP
   Modified April 01,2020 BY EIT EDUCATION GROUP

*/

//Define Constant variables
#define LED_GREEN  2
#define LED_YELLOW 3
#define LED_RED    4
#define BUZZER     5

#define SENSOR_WATER A0

#define WATER_FULL   80
#define WATER_MEDUIM 40
#define WATER_EMPTY  0

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

int waterLevel() {
  int sensorValue = analogRead(SENSOR_WATER);
  int persentage = map(sensorValue, 0, 1023, 0, 100);
  return persentage;
}

void loop() {
  //Call waterLevel function 
  if (waterLevel() >= WATER_FULL) {
    greenLight(); //Call greenLight to switch on green LED on and others off
  }
  else if (waterLevel() >= WATER_MEDUIM) {
    yellowLight();//Call yellowLight to switch on yellow LED on and others off
  }
  else if (waterLevel() >= WATER_EMPTY) {
    redLight();   //Call redLight to switch on red ow LED on and others off
  }
}
