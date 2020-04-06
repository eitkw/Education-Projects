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
   - 1 x Resistor 330 Ohm
   - 1 x Resistor 10  KOhm

   Project Name: SOS Light Flashing
   In this code we will simulate SOS Light flashing,
   This project consists of while LED and button to start flashing.

   Proj0001PGK001
   Created March 27,2020 BY EIT EDUCATION GROUP
   Modified April 01,2020 BY EIT EDUCATION GROUP

*/

//Define Constant variables
#define LED_WHITE   2
#define BUTTON      3

int buttonState = 0;

//Display flashing Morse code for alphabet "S"
void Morse_S_code() {
  digitalWrite(LED_WHITE, HIGH);// turn the LED on by making the voltage HIGH
  delay(250);
  digitalWrite(LED_WHITE, LOW); // turn the LED off by making the voltage LOW
  delay(250);
  digitalWrite(LED_WHITE, HIGH);// turn the LED on by making the voltage HIGH
  delay(250);
  digitalWrite(LED_WHITE, LOW); // turn the LED off by making the voltage LOW
  delay(250);
  digitalWrite(LED_WHITE, HIGH);// turn the LED on by making the voltage HIGH
  delay(250);
  digitalWrite(LED_WHITE, LOW); // turn the LED off by making the voltage LOW
  delay(250);
}

//Display flashing Morse code for alphabet "O"
void Morse_O_code() {
  digitalWrite(LED_WHITE, HIGH);// turn the LED on by making the voltage HIGH
  delay(750);
  digitalWrite(LED_WHITE, LOW); // turn the LED off by making the voltage LOW
  delay(250);
  digitalWrite(LED_WHITE, HIGH);// turn the LED on by making the voltage HIGH
  delay(750);
  digitalWrite(LED_WHITE, LOW); // turn the LED off by making the voltage LOW
  delay(250);
  digitalWrite(LED_WHITE, HIGH);// turn the LED on by making the voltage HIGH
  delay(750);
  digitalWrite(LED_WHITE, LOW); // turn the LED off by making the voltage LOW
  delay(250);
}

void setup() {
  //define the LEDs pins as output
  pinMode(LED_WHITE, OUTPUT);
  //Define the push button as input
  pinMode(BUTTON, INPUT);
}

void loop() {

  //Read the state of the push button pressed or not
  buttonState = digitalRead(BUTTON);

  //check if the pushbutton is pressed. If it is, the buttonState is HIGH
  if (buttonState == HIGH) {
    while (1) {
      Morse_S_code();//S Morse code light
      Morse_O_code();//O Morse code light
      Morse_S_code();//S Morse code light
      delay(1000);   //Delay 1 second between words
    }
  }
}
