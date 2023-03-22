//#include <Servo.h>
int trigPin = 6;
int echoPin = 7;
int pingTravelTime;
float distance;
//int pos = 45;

//Servo servo_9;

void setup()
{ 
   pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  Serial.begin(9600);
  
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
  pingTravelTime = pulseIn(echoPin,HIGH);
  
  distance = ((pingTravelTime-200.)/60.)+1;
  Serial.println("  Distance = " + String(distance));
  //Serial.print();
  //if ((distance <= 50) && (distance >=10)){
    //pos = map( distance, 50,10,45,135);
    //Serial.print(" postion = ");
    //Serial.print(pos);
    //servo_9.write(pos);    
  //}
    
  //Serial.println();
}