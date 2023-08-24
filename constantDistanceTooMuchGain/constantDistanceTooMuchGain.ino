int trigPin = 8;
int echoPin = 9;

#define leftReversePin 12
#define leftForwardPin 13
#define rightReversePin 10
#define rightForwardPin 11

#define desiredDistance 30
#define acceptableError 1

int issuedStop = desiredDistance;       // For plotting values to the serial plotter - used for debugging
int issuedForward = desiredDistance*2;  // For plotting values to the serial plotter
int issuedReverse = 0;                  // For plotting values to the serial plotter

int previousDistance = desiredDistance; // Used for ignoring crazy distance readings
int issuedCommand = issuedStop;         // For plotting values to the serial plotter

void setup() {
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);

  pinMode(leftReversePin, OUTPUT);
  pinMode(rightReversePin, OUTPUT);

  pinMode(leftForwardPin, OUTPUT);
  pinMode(rightForwardPin, OUTPUT);

  delay(1000);
}
void loop() {
  int distance = readDistance();
  if (distance > desiredDistance*2){  // Used for ignoring crazy distance readings
    distance = previousDistance;
  }
  
  if (distance > desiredDistance + acceptableError) {
    issuedCommand = driveForward();
  } else if (distance < desiredDistance - acceptableError){
    issuedCommand = driveBackward();
  } else {
    issuedCommand = stop();
  }

  Serial.println(String(distance) + " " +String(issuedCommand) + " " +"60"); // For plotting values to the serial plotter
  previousDistance = distance;  // Store current reading if next one is crazy
}


int driveBackward() {
  digitalWrite(leftForwardPin, LOW);
  digitalWrite(rightForwardPin, LOW);
  digitalWrite(leftReversePin, HIGH);
  digitalWrite(rightReversePin, HIGH);
  return issuedReverse;
}

int driveForward() {
    digitalWrite(leftForwardPin, HIGH);
    digitalWrite(rightForwardPin, HIGH);
    digitalWrite(leftReversePin, LOW);
    digitalWrite(rightReversePin, LOW);
    return issuedForward;
  }

int stop() {
    digitalWrite(leftForwardPin, LOW);
    digitalWrite(rightForwardPin, LOW);
    digitalWrite(leftReversePin, LOW);
    digitalWrite(rightReversePin, LOW);
    return issuedStop;
  }

float readDistance() {
  digitalWrite(trigPin,LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  float pingTravelTime = pulseIn(echoPin,HIGH);
  int distance = ((pingTravelTime-200.)/60.)+1;
  return distance;
}