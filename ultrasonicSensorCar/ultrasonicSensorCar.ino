//#include <Servo.h>
int trigPin = 12;
int echoPin = 13;
float distance;
//int pos = 45;

//Servo servo_9;

void setup()
{ 
   pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  Serial.begin(115200);
  
  //servo_9.attach(9, 500, 2500);
  //servo_9.write(pos);
  
}

void loop()
{
  delay(500);
  digitalWrite(trigPin,LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  int pingTravelTime = pulseIn(echoPin,HIGH);
  
  distance = ((pingTravelTime-200.)/60.)+1;
  Serial.println("Distance = " + String(distance));
  
}