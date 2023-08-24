int trigPin = 13;
int echoPin = 12;


#define leftReversePin 16
#define leftForwardPin 17

#define rightReversePin 18
#define rightForwardPin 5

#define rightPWMSpeedPin 4
#define leftPWMSpeedPin 2

#define defaultSpeed 150
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

  delay(1000);
  analogWrite(leftPWMSpeedPin, defaultSpeed);
  analogWrite(rightPWMSpeedPin, defaultSpeed);
  driveForward();
}
void loop() {
  int distance = readDistance();
  Serial.println("Distance = " + String(distance));

  int deviation = abs(setPoint - distance);
  calculateAndSetPWMSpeed(deviation);

  if (distance > setPoint + 2) {
    driveForward();
  } else if (distance < setPoint - 2) {
    driveBackward();
  } else {
    stop();
  }
}

void calculateAndSetPWMSpeed(int deviation) {
  int speed = 120 + deviation * 10;
  if (speed > 255) {
    speed = 255;
  }
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