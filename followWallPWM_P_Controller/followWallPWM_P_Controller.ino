int trigPin = 8;
int echoPin = 9;

#define leftReversePin 12
#define leftForwardPin 13
#define rightReversePin 10
#define rightForwardPin 11
#define rightPWMSpeedPin 5
#define leftPWMSpeedPin 6
#define defaultSpeed 190
#define setPoint 30

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(leftReversePin, OUTPUT);
  pinMode(rightReversePin, OUTPUT);

  pinMode(leftForwardPin, OUTPUT);
  pinMode(rightForwardPin, OUTPUT);

  pinMode(rightPWMSpeedPin, OUTPUT);
  pinMode(leftPWMSpeedPin, OUTPUT);

  analogWrite(leftPWMSpeedPin, defaultSpeed);
  analogWrite(rightPWMSpeedPin, defaultSpeed);
  
  delay(1000);
  driveForward();
}


void loop() {
  int distance = readDistance();
  Serial.println("Distance = " + String(distance));

  int deviation = setPoint - distance;
  calculateAndSetPWMSpeed(deviation);
   
}

void calculateAndSetPWMSpeed(int deviation) {
  int rightSpeed = defaultSpeed + deviation * 10;   
  rightSpeed = constrainSpeedBetween110and255(rightSpeed) ;
  
  int leftSpeed = defaultSpeed - deviation * 10;
  leftSpeed = constrainSpeedBetween110and255(leftSpeed) ;

  analogWrite(leftPWMSpeedPin, leftSpeed);
  analogWrite(rightPWMSpeedPin, rightSpeed);

  Serial.println("Deviation: " + String(deviation));
  Serial.println("RightSpeed : " + String(rightSpeed));  
  Serial.println("LeftSpeed : " + String(leftSpeed));  
}

int constrainSpeedBetween110and255(int speed){
  if (speed > 255) {
    speed = 255;
  }
  if (speed < 110) {
    speed = 110;
  }  
  return speed;
}


void driveBackward() {
  digitalWrite(leftForwardPin, LOW);
  digitalWrite(rightForwardPin, LOW);
  digitalWrite(leftReversePin, HIGH);
  digitalWrite(rightReversePin, HIGH);
}

void driveForward() {
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

void stop() {
  digitalWrite(leftForwardPin, LOW);
  digitalWrite(rightForwardPin, LOW);
  digitalWrite(leftReversePin, LOW);
  digitalWrite(rightReversePin, LOW);
}

float readDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  float pingTravelTime = pulseIn(echoPin, HIGH);
  int distance = ((pingTravelTime - 200.) / 60.) + 1;
  return distance;
}