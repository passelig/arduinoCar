
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
  // drive forward    
  digitalWrite(leftForwardPin, HIGH);
  digitalWrite(rightForwardPin, HIGH);
  digitalWrite(leftReversePin, LOW);
  digitalWrite(rightReversePin, LOW);
}
