#include <Servo.h>
int trigPin = 6;
int echoPin = 7;
int servoPin = 5;
float distance;
float distanceToTheRight;
float distanceToTheLeft;
String turnDirection = "NOT SET";
int sensorToTheLeft =180;
int sensorToTheRight = 0;
int sensorStraitAhead = 90;

#define leftReversePin 11
#define leftForwardPin 10
#define rightReversePin 8
#define rightForwardPin 9

Servo servoMotor;

void setup()
{ 
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  Serial.begin(9600);
  servoMotor.attach(servoPin, 500, 2500);
  servoMotor.write(sensorStraitAhead);
  delay(3000);
}

void loop()
{
  distance = readDistance();
  Serial.println("Distance = " + String(distance));
 
  if (distance <= 30){
    stop();
    if (goLeftOrRight() == "LEFT"){
      turnLeft();
      delay(200);      
    } else if (goLeftOrRight() == "RIGHT") {
      turnRight();
      delay(200);      
    } 
  }else {
    driveForward ();     
  }
}

void driveForward (){
  digitalWrite(leftForwardPin, HIGH);
  digitalWrite(rightForwardPin, HIGH);
  digitalWrite(leftReversePin, LOW);
  digitalWrite(rightReversePin, LOW);
}

String goLeftOrRight(){
    servoMotor.write(sensorToTheLeft); 
    delay(500);
    distanceToTheLeft = readDistance();
    servoMotor.write(sensorToTheRight);
    delay(500); 
    distanceToTheRight= readDistance();
    delay(500);
    servoMotor.write(sensorStraitAhead); 
    delay(300);   
    Serial.println("distanceToTheLeft = " + String(distanceToTheLeft));
    Serial.println("distanceToTheRight = " + String(distanceToTheRight));
    if (distanceToTheLeft >  distanceToTheRight){
      return "LEFT";
    } else {
      return "RIGHT";     
    }
}

void turnRight (){
  Serial.println("Turning Right");
  digitalWrite(leftForwardPin, HIGH);
  digitalWrite(rightForwardPin, LOW);
  digitalWrite(leftReversePin, LOW);
  digitalWrite(rightReversePin, HIGH);
}

void turnLeft (){
  Serial.println("Turning Left");
  digitalWrite(leftForwardPin, LOW);
  digitalWrite(rightForwardPin, HIGH);
  digitalWrite(leftReversePin, HIGH);
  digitalWrite(rightReversePin, LOW);
}

void stop (){
  digitalWrite(leftForwardPin, LOW);
  digitalWrite(rightForwardPin, LOW);
  digitalWrite(leftReversePin, LOW);
  digitalWrite(rightReversePin, LOW);
}


float readDistance() {
  int pingTravelTime;
  digitalWrite(trigPin,LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  pingTravelTime = pulseIn(echoPin,HIGH);
  distance = ((pingTravelTime-200.)/60.)+1;
  return distance;
}