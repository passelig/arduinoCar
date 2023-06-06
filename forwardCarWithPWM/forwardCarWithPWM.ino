
#define leftReversePin 12
#define leftForwardPin 13
#define rightReversePin 10
#define rightForwardPin 11
#define rightPWMSpeedPin 5
#define leftPWMSpeedPin 6
#define deafaultSpeed 150

void setup() {
  Serial.begin(9600);
  pinMode(leftReversePin, OUTPUT);
  pinMode(rightReversePin, OUTPUT);

  pinMode(leftForwardPin, OUTPUT);
  pinMode(rightForwardPin, OUTPUT);

  pinMode(rightPWMSpeedPin, OUTPUT);
  pinMode(leftPWMSpeedPin, OUTPUT);

  // drive forward
  digitalWrite(leftForwardPin, HIGH);
  digitalWrite(rightForwardPin, HIGH);
  digitalWrite(leftReversePin, LOW);
  digitalWrite(rightReversePin, LOW);
}
void loop() {
  // Accelerate  
  for (int i = 12; i <= 25; i++) {
    int speed = i * 10;
    analogWrite(leftPWMSpeedPin, speed);
    analogWrite(rightPWMSpeedPin, speed);
    Serial.println(String(speed));
    delay(1000);
  }
  
}
