// Includes the Servo library
#include <Servo.h>

//Defines Tig and Echo pins of the Ultrasonic Sensors
const int trigPin = A5; //read only, use less memory compare to "int"
const int echoPin = A4;

//Variables for the duration and the distance
long duration; //travelled time
float distance;
float soundSpeed = 0.0343;

//creates a servo object for controlling the servo
Servo servo1;

void setup() { 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  servo1.attach(13,455,2600); // parameter => (pin, min pulse width, max pulse width)

  Serial.begin(9600);
  
}

void loop() {
  // default servo angle for lid close
  servo1.write(180);

  // detect object distance
  detectDistance();

  // remain the lid open while object distance is less than 10 cm
  while (distance < 10){
    servo1.write(120); // servo angle for lid open
    detectDistance(); // detect the kbject distance again
  }
}

void detectDistance() {

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH); //return value of time which is high
  distance = duration * soundSpeed / 2;  //in microsec
}
