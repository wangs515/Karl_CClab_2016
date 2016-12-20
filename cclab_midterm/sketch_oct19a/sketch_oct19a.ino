/*
  Analog input, analog output, serial output

  Reads an analog input pin, maps the result to a range from 0 to 255
  and uses the result to set the pulsewidth modulation (PWM) of an output pin.
  Also prints the results to the serial monitor.

  The circuit:
   potentiometer connected to analog pin 0.
   Center pin of the potentiometer goes to the analog pin.
   side pins of the potentiometer go to +5V and ground
   LED connected from digital pin 9 to ground

  created 29 Dec. 2008
  modified 9 Apr 2012
  by Tom Igoe

  This example code is in the public domain.

*/

// These constants won't change.  They're used to give names
// to the pins used:
#include <Servo.h>
Servo myservo;
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = 9; // Analog output pin that the LED is attached to

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)
int pos = 0;
int val = 20;
int count = 0;


void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  myservo.attach(analogOutPin);
//  myservo.write(10);
  
}

void loop() {
//  long moveValue = random(180); 
//  if (Serial.available() > 0) {
////char incoming = Serial.read();
//
//String incoming = Serial.readStringUntil('\n');
//Serial.println(incoming);
//
//if (incoming=="MOVE"){
//  myservo.write(moveValue);
//  }else if (incoming=="move"){
//  myservo.write(10);
//  }
//  }

  while(!Serial.available()){  //wait until a byte was received
  analogWrite(9, Serial.read());//output received byte
  }
  delay(500);
  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  outputValue = map(sensorValue, 1023, 0, 0,180);
  if(millis()%2 <20){
  // map it to the range of the analog out:
  if(outputValue<90){
    count++;
    if(count ==1){
      myservo.write(180);}
//    else if(count==2){
//      myservo.write(60);}
//    else if(count==3){
//      myservo.write(90);}
//    else if(count==4){
//      myservo.write(120);}
//    else if(count==5){
//      myservo.write(150);}
    else if(count>1){
      myservo.write(0);
      count=0;}
  }
  }
  delay(100);
//  outputValue = map(sensorValue, 350, 0, 0, 180);
  // change the analog out value:
//  
//  if (outputValue > 50) {
//    for (int pos = 10; pos < 30; pos++) {
//      myservo.write(pos);
//      delay(15);
//    }
//  } else if (outputValue > 150) {
//    for (int pos = 30; pos < 70; pos++) {
//      myservo.write(pos);
//      delay(15);
//    }
//  }
//  // print the results to the serial monitor:

//  
//  Serial.print("sensor = ");
//  Serial.print(sensorValue);
//  Serial.print("\t output = ");
  Serial.print(outputValue);
//  Serial.print("\t count = ");
//  Serial.print(count);
  Serial.println();


  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(2);
}

void servoMove(int n) {
  switch(n)
  {
    case 1:
      myservo.write(30);
    break;
    case 2:
      myservo.write(60);
    break;
    case 3:
      myservo.write(90);
    break;
  }


  
}

