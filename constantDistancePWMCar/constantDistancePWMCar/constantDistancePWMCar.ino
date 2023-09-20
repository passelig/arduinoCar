int trigPin = 8;
int echoPin = 9;

#define leftReversePin 12
#define leftForwardPin 13
#define rightReversePin 10
#define rightForwardPin 11
#define rightPWMSpeedPin 5
#define leftPWMSpeedPin 6

#define defaultSpeed 150
#define setPoint 30
int distance = setPoint;

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

  delay(1000);
  analogWrite(leftPWMSpeedPin, defaultSpeed);
  analogWrite(rightPWMSpeedPin, defaultSpeed);
  driveForward();
}
void loop() {
  distance = readDistance();
  Serial.println("Distance = " + String(distance));
  if (distance > setPoint + 2) {
    calculateAndSetPWMSpeed(); // hvor mye pådrag/gass?
    driveForward();
  } else if (distance < setPoint - 2) {
    calculateAndSetPWMSpeed(); // hvor mye pådrag/gass?
    driveBackward();
  } else {
    stop();
  }
}

void calculateAndSetPWMSpeed() {
  int deviation = abs(setPoint - distance); // deviation (avvik) i centimeter
  int speed = deviation * 10; 
  speed = constrain(speed,80,255); // ved speed < 80 går ikke motorene
  analogWrite(leftPWMSpeedPin, speed);
  analogWrite(rightPWMSpeedPin, speed);
  Serial.println("Deviation: " + String(deviation) + " , Speed : " + String(speed));
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