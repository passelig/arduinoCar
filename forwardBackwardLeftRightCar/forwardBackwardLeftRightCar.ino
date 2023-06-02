


#define leftReversePin 12
#define leftForwardPin 13
#define leftSpeedPin 5

#define rightReversePin 10
#define rightForwardPin 11
#define rightSpeedPin 6
#define speed 170

void setup() {
  Serial.begin(9600);
  pinMode(leftSpeedPin, OUTPUT);
  pinMode(rightSpeedPin, OUTPUT);  
  pinMode(leftReversePin, OUTPUT);
  pinMode(rightReversePin, OUTPUT);
  pinMode(leftForwardPin, OUTPUT);
  pinMode(rightForwardPin, OUTPUT);  
  analogWrite(leftSpeedPin, speed);
  analogWrite(rightSpeedPin, speed);
  delay(1000);  
}
void loop() {
  driveForward ();
  delay(1000);

  driveReverse();
  delay(1000);

  turnRight();
  delay(1000); 
  
  turnLeft(); 
  delay(1000);      
 
  stop();
  delay(1000);  
}


void driveForward () {
  digitalWrite(leftForwardPin, HIGH);
  digitalWrite(rightForwardPin, HIGH);
  digitalWrite(leftReversePin, LOW);
  digitalWrite(rightReversePin, LOW);
}  

void driveReverse() {
  digitalWrite(leftForwardPin, LOW);
  digitalWrite(rightForwardPin, LOW);
  digitalWrite(leftReversePin, HIGH);
  digitalWrite(rightReversePin, HIGH);
}

void turnRight(){
  digitalWrite(leftForwardPin, HIGH);
  digitalWrite(rightForwardPin, LOW);
  digitalWrite(leftReversePin, LOW);
  digitalWrite(rightReversePin, HIGH);
}

void turnLeft () {
  digitalWrite(leftForwardPin, LOW);
  digitalWrite(rightForwardPin, HIGH);
  digitalWrite(leftReversePin, HIGH);
  digitalWrite(rightReversePin, LOW);
}

 void stop(){
  digitalWrite(leftForwardPin, LOW);
  digitalWrite(rightForwardPin, LOW);
  digitalWrite(leftReversePin, LOW);
  digitalWrite(rightReversePin, LOW);
 }