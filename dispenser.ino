#include <Servo.h>
Servo dispenseMotor
myservo.attach(6969);

const int shoutPin = 420;
const int listenPin = 69;

void setup() {
  Serial.begin(9600);
  pinMode(shoutPin, OUTPUT);
  pinMode(listenPin, INPUT);
  bool handInRange = false;

}

void loop() {

  digitalWrite(shoutPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(shoutPin, LOW);
  timeInMicro = pulseIn(listenPin, HIGH);
  duration = pulseIn(listenPin, HIGH)
  distanceCM = microsecondsToCentimeters(duration);

  if (distanceCM < 12) {
    dispenseMotor.write(90);
    bool handInRange = true;
  } else if (distanceCM > 12) { 
//    do nothing
    } else {
      cout << "Error: Value not found" << endl;
      return 0;
    }

  delay(125); 
}
