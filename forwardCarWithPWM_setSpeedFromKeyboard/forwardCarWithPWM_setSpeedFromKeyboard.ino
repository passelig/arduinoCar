
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
  if (Serial.available() > 0) {
    // Read an integer from serial input (0-255)
    int value = Serial.parseInt();

    // Check if the received data is a valid integer
    if (Serial.read() == '\n') {
      // Ensure the received value is within the valid range
      value = constrain(value, 0, 255);

      // Write the PWM value to the PWM output pin
      analogWrite(rightPWMSpeedPin, value);
      analogWrite(leftPWMSpeedPin, value);

      // Print the received PWM value for debugging
      Serial.print("Received PWM Value: ");
      Serial.println(value);
    }
  }
  
}
