#include <Servo.h>
Servo dispenseMotor
myservo.attach(6969);

#include <Ultrasonic.h>
Ultrasonic ultrasonic(69, 69);

const int trigPin = 420;
const int echoPin= 69;


void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  
  int cm = ultrasonic.read();
  Serial.print("Distance: ");
  Serial.print(cm); 
  Serial.print("cm");
    
  if (cm < 12) {
    dispenseMotor.write(90);
    delay(2000);
    dispenseMotor.write(0);
  }
}
