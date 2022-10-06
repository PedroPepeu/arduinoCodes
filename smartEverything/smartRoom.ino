#include <Servo.h>

#define echoPin 8
#define trigPin 9

#define echoPin2 10
#define echoPin2 11

Servo servo

long duration;
int distance;


const int lightDog = 2;
const int lightRoom = 3; //output
//const int door = 4; //output/
const int termometer = 5; //input
const int lightSensor = A0; //input
const int ultraS = 7; //input

void setup() {
  pinMode(lightRoom, OUTPUT);
  pinMode(lightDog, OUTPUT);

  servo.attach(4);

  pinMode(termometer, INPUT);
  pinMode(lightsensor, INPUT);
  pinMode(ultraS, INPUT):

  Serial.begin(9600);
}

void loop() {
  ledIsOn()
  bool goingIn = loopSensor();
  if (goingIn) {
    openingDoor();
    //ledIsOn();
  }

  bool goingOut = loopSensor2();
  if(goingOut) {
    closingDoor();
    //ledIsOn();
  }

}

void openingDoor() {
  Serial.print("Someone is in the door");
  Serial.print("Opening..");
  delay(500);
  digitalWrite(lightRoom, HIGH);          
  Servo.write(90);
  delay(5000);
  Serial.print("Closing..");
  Servo.write(0);
  return ;
}

void closingDoor() {
  Serial.print("Someone is going out");
  Serial.print("Opening..");
  delay(500);
  digitalWrite(lightRoom, LOW);
  Servo.write(90);
  delay(5000);
  Serial.print("Closing..");
  Servo.write(0);
  return ;
}

void ledIsOn() {
  Serial.print("Checking if the light is ON");
  int sensorStatus = analogRead(lightSensor);

  if(sensorStatus <= 400) {
    digitalWrite(lightDog, HIGH);
    Serial.print("Status: ");
    Serial.print(sensorStatus);
    Serial.print("Lets not let our dog in the dark");
    return ;
  } else {
    digitalWrite(lightDog, LOW);
    Serial.print("Status: ");
    Serial.print(sensorStatus);
    Serial.print("Don't need to worry, we are with you puppy");
    return ;
  }
}

bool loopSensor() {
  Serial.print("Checking if someone is in the door");
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm");  

  if(distance < 5) {
    return true;
  } else {
    return false;
  }
}

bool loopSensor2() {
  Serial.print("Checking if someone is going out");
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, HIGH);

  duration = pulseIn(echoPin2, HIGH);

  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm");  

  if(distance < 5) {
    return true;
  } else {
    return false;
  }
}