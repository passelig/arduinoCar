
#define leftReversePin 10
#define leftForwardPin 11
#define rightReversePin 8
#define rightForwardPin 9

void setup() {
  Serial.begin(9600);
  pinMode(leftReversePin, OUTPUT);
  pinMode(rightReversePin, OUTPUT);
  pinMode(leftForwardPin, OUTPUT);
  pinMode(rightForwardPin, OUTPUT);  
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