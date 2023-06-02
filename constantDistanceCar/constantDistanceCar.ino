// Motor connections
int enA = 3;
int in1 = 8;
int in2 = 9;

// Potentiometer pin
int potPin = A0;

void setup() {
  // Set the motor control pins as outputs
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
Serial.begin(9600);
  // Set the potentiometer pin as input
  pinMode(potPin, INPUT);
}

void loop() {
  // Read the potentiometer value
  int potValue = analogRead(potPin);

  // Map the potentiometer value to the motor speed range
  int motorSpeed = map(potValue, 0, 1023, 0, 255);

  // Set the motor speed and direction
  analogWrite(enA, motorSpeed);
Serial.println(String(motorSpeed));
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
}
