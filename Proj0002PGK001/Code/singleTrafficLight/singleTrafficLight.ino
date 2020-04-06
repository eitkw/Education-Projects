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
   - 3 x LEDs (Red - Yellow - Green)
   - 3 x Resistor 330 Ohm
   
   Project Name: Single Traffic  Light
   In this code we will simulate single traffic light
   have three type of LEDs (GREEN|YELLOW|RED)

   Proj0002PGK001
   Created March 27,2020 BY EIT EDUCATION GROUP
   Modified April 01,2020 BY EIT EDUCATION GROUP

*/

//Define Constant variables
#define LED_GREEN1  2
#define LED_YELLOW1 3
#define LED_RED1    4

//Define Delay for each color in trafflic light in ms (1000ms = 1sec)
#define DELAY_GREEN1  2000
#define DELAY_YELLOW1 1000
#define DELAY_RED1    4000

void setup() {
  //define the LEDs pins as output
  pinMode(LED_GREEN1, OUTPUT);
  pinMode(LED_YELLOW1, OUTPUT);
  pinMode(LED_RED1, OUTPUT);
}

//greenLight1 is function switch green led
void greenLight1() {
  digitalWrite(LED_GREEN1, HIGH);// turn the LED on (HIGH is the voltage level)
  digitalWrite(LED_YELLOW1, LOW);// turn the LED off by making the voltage LOW
  digitalWrite(LED_RED1, LOW);   // turn the LED off by making the voltage LOW
  delay(DELAY_GREEN1);           // wait for a 2 second as its on definition
}

//yellowLight1 is function switch yellow led
void yellowLight1() {
  digitalWrite(LED_GREEN1, LOW);  // turn the LED off by making the voltage LOW
  digitalWrite(LED_YELLOW1, HIGH);// turn the LED on (HIGH is the voltage level)
  digitalWrite(LED_RED1, LOW);    // turn the LED off by making the voltage LOW
  delay(LED_YELLOW1);             // wait for a 1 second as its on definition
}

//redLight is function switch red led
void redLight1() {
  digitalWrite(LED_GREEN1, LOW); // turn the LED off by making the voltage LOW
  digitalWrite(LED_YELLOW1, LOW);// turn the LED off by making the voltage LOW
  digitalWrite(LED_RED1, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(LED_RED1);               // wait for a 4 second as its on definition
}

void loop() {
  greenLight1(); //Call greenLight1 to switch on green LED on and others off
  yellowLight1();//Call yellowLight1 to switch on yellow LED on and others off
  redLight1();   //Call redLight1 to switch on red ow LED on and others off
}
