// Motor 1
int dir1PinA = 8;
int dir2PinA = 9;
int speedPinA = 12; // Needs to be a PWM pin to be able to control motor speed

// Motor 2
int dir1PinB = 10;
int dir2PinB = 11;
int speedPinB = 13; // Needs to be a PWM pin to be able to control motor speed

void initMotors() {
  // define motor controller pins
  pinMode(dir1PinA,OUTPUT);
  pinMode(dir2PinA,OUTPUT);
  pinMode(speedPinA,OUTPUT);
  pinMode(dir1PinB,OUTPUT);
  pinMode(dir2PinB,OUTPUT);
  pinMode(speedPinB,OUTPUT);
}

void btControlMotor(String cmd) {
  int speed; // Local variable
  int value = (cmd.substring(2,cmd.length())).toInt();
  switch (value) {
    
      //______________Motor 1______________
      
      case '1': // Motor 1 Forward
      analogWrite(speedPinA, 255);//Sets speed variable via PWM 
      digitalWrite(dir1PinA, LOW);
      digitalWrite(dir2PinA, HIGH);
      Serial.println("Motor 1 Forward"); // Prints out “Motor 1 Forward” on the serial monitor
      break;
      
      case '2': // Motor 1 Stop (Freespin)
      analogWrite(speedPinA, 0);
      digitalWrite(dir1PinA, LOW);
      digitalWrite(dir2PinA, HIGH);
      Serial.println("Motor 1 Stop");
      break;
      
      case '3': // Motor 1 Reverse
      analogWrite(speedPinA, 255);
      digitalWrite(dir1PinA, HIGH);
      digitalWrite(dir2PinA, LOW);
      Serial.println("Motor 1 Reverse");
      break;
      
      //______________Motor 2______________
      
      case '4': // Motor 2 Forward
      analogWrite(speedPinB, 255);
      digitalWrite(dir1PinB, LOW);
      digitalWrite(dir2PinB, HIGH);
      Serial.println("Motor 2 Forward");
      break;
      
      case '5': // Motor 1 Stop (Freespin)
      analogWrite(speedPinB, 0);
      digitalWrite(dir1PinB, LOW);
      digitalWrite(dir2PinB, HIGH);
      Serial.println("Motor 2 Stop");
      break;
      
      case '6': // Motor 2 Reverse
      analogWrite(speedPinB, 255);
      digitalWrite(dir1PinB, HIGH);
      digitalWrite(dir2PinB, LOW);
      Serial.println("Motor 2 Reverse");
      break;
      
      default: break;
  }
}
