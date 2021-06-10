// Storage Library
#include <EEPROM.h>

#include <Servo.h>
Servo dispenseMotor;
const int servoPin = 3;

#include <Ultrasonic.h>
const int shoutPin = 9;
const int listenPin = 8;
Ultrasonic ultrasonic(shoutPin, listenPin, 6900UL);

const int resetPin = 12;
int currentErrors = EEPROM.read(0);
bool handInRange = false;


// Startup Sequence
void setup() {
  Serial.begin(9600);
  digitalWrite(resetPin, HIGH);
  pinMode(resetPin, OUTPUT);
  delay(200);
  Serial.print("Errors: ");
  Serial.println(currentErrors);

  if (currentErrors == 5) {
// Wait 20 seconds before starting up after errors
    Serial.println("Repeated crashes, resetting in 20s");
    delay(20000);
    int newErrors = 0;
    EEPROM.write(0, newErrors);
    digitalWrite(resetPin, LOW);
  } 
  else {
  dispenseMotor.attach(servoPin);
  } 
}

// Looping Process
void loop() {
  int cm = ultrasonic.read();
  Serial.print(cm); 
  Serial.println("cm");
  
  if (cm < 25) { 
    dispenseMotor.write(90);
    bool handInRange = true; 
    delay(200);
  }
  else if (cm > 25) { 
    bool handInRange = false;  
  }
  else {
      Serial.println("Error: Value not found, check connection");
      int newErrors = currentErrors + 1;
      EEPROM.write(0, newErrors);
      digitalWrite(resetPin, LOW);
    }
    
while (handInRange = true) { 
  int cm = ultrasonic.read();
  Serial.print(cm); 
  Serial.println("cm");
  if (cm > 25) { 
    dispenseMotor.write(0);
    delay(1000);
    bool handInRange = false; 
    break;
  }
  else { 
    break;
    }
    delay(150);
  }
return;
}
