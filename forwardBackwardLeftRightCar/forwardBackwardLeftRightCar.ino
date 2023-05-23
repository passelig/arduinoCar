
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
  delay(1000);    
  //driveForward
  digitalWrite(leftForwardPin, HIGH);
  digitalWrite(rightForwardPin, HIGH);
  digitalWrite(leftReversePin, LOW);
  digitalWrite(rightReversePin, LOW);
  delay(1000);
  //driveReverse
  digitalWrite(leftForwardPin, LOW);
  digitalWrite(rightForwardPin, LOW);
  digitalWrite(leftReversePin, HIGH);
  digitalWrite(rightReversePin, HIGH);
  delay(1000);  
  //turnRight
  digitalWrite(leftForwardPin, HIGH);
  digitalWrite(rightForwardPin, LOW);
  digitalWrite(leftReversePin, LOW);
  digitalWrite(rightReversePin, HIGH);
  delay(1000);
  //turnLeft 
  digitalWrite(leftForwardPin, LOW);
  digitalWrite(rightForwardPin, HIGH);
  digitalWrite(leftReversePin, HIGH);
  digitalWrite(rightReversePin, LOW);
  delay(1000);  
  //stop      
  digitalWrite(leftForwardPin, LOW);
  digitalWrite(rightForwardPin, LOW);
  digitalWrite(leftReversePin, LOW);
  digitalWrite(rightReversePin, LOW);
  delay(1000);  
}
