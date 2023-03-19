#include <IRremote.h>
#define keyForward 24
#define keyReverse 82
#define keyLeft 8
#define keyRight 90
#define IR_RECEIVE_PIN 3
#define leftReversePin 11
#define leftForwardPin 10
#define rightReversePin 8
#define rightForwardPin 9

int receivedCommand;
void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN);
  pinMode(leftReversePin, OUTPUT);
  pinMode(rightReversePin, OUTPUT);
  pinMode(leftForwardPin, OUTPUT);
  pinMode(rightForwardPin, OUTPUT);  
}
void loop() {
  if (IrReceiver.decode()) {
    IrReceiver.resume();
    receivedCommand = IrReceiver.decodedIRData.command;
    Serial.println(receivedCommand);
  }
  if (receivedCommand == keyForward){
    driveForward ();
  } else if (receivedCommand == keyReverse){
    driveReverse ();
  } else if (receivedCommand == keyLeft){
    turnLeft ();
  } else if (receivedCommand == keyRight){
    turnRight ();
  } else{
    stop();
  } 
  delay(200);
  receivedCommand = 0;
}

void driveForward (){
  digitalWrite(leftForwardPin, HIGH);
  digitalWrite(rightForwardPin, HIGH);
  digitalWrite(leftReversePin, LOW);
  digitalWrite(rightReversePin, LOW);
}

void driveReverse (){
  digitalWrite(leftForwardPin, LOW);
  digitalWrite(rightForwardPin, LOW);
  digitalWrite(leftReversePin, HIGH);
  digitalWrite(rightReversePin, HIGH);
}

void turnRight (){
  digitalWrite(leftForwardPin, HIGH);
  digitalWrite(rightForwardPin, LOW);
  digitalWrite(leftReversePin, LOW);
  digitalWrite(rightReversePin, HIGH);
}

void turnLeft (){
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