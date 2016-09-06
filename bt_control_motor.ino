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
  Serial.print("motor ");
   Serial.print(value);
   Serial.println();
  switch (value) {
    
      //______________Motor 1______________
      
      case 1: // Motors Forward
      analogWrite(speedPinA, 255);//Sets speed variable via PWM 
      digitalWrite(dir1PinA, LOW);
      digitalWrite(dir2PinA, HIGH);
      analogWrite(speedPinB, 255);
      digitalWrite(dir1PinB, LOW);
      digitalWrite(dir2PinB, HIGH);
      Serial.println("Motors Forward"); // Prints out “Motor 1 Forward” on the serial monitor
      break;
      
      case 2: // Motors Reverse
      analogWrite(speedPinA, 0);
      digitalWrite(dir1PinA, HIGH);
      digitalWrite(dir2PinA, LOW);
      digitalWrite(dir1PinB, HIGH);
      digitalWrite(dir2PinB, LOW);
      Serial.println("Motors Reverse");
      break;
      
      case 3: // Motors Stop
      analogWrite(speedPinA, 255);
      digitalWrite(dir1PinA, LOW);
      digitalWrite(dir2PinA, LOW);
      digitalWrite(dir1PinB, LOW);
      digitalWrite(dir2PinB, LOW);
      Serial.println("Motors Stops");
      break;
      
      case 4: // Simulate Left Turn
      analogWrite(speedPinB, 255);
      digitalWrite(dir1PinA, LOW);
      digitalWrite(dir2PinA, HIGH);
      digitalWrite(dir1PinB, LOW);
      digitalWrite(dir2PinB, LOW);
      Serial.println("Simulate Left Turn");
      break;
      
      case 5: // Simulate Right Turn
      analogWrite(speedPinB, 0);
      digitalWrite(dir1PinA, LOW);
      digitalWrite(dir2PinA, LOW);
      digitalWrite(dir1PinB, LOW);
      digitalWrite(dir2PinB, HIGH);
      Serial.println("Simulate Right Turn");
      break;
      
      case 6: // Simulate Left Reverse
      analogWrite(speedPinB, 0);
      digitalWrite(dir1PinA, HIGH);
      digitalWrite(dir2PinA, LOW);
      digitalWrite(dir1PinB, LOW);
      digitalWrite(dir2PinB, LOW);
      Serial.println("Simulate Left Reverse");
      break;
      
      case 7: // Simulate RIGHT Reverse
      analogWrite(speedPinB, 0);
      digitalWrite(dir1PinA, LOW);
      digitalWrite(dir2PinA, LOW);
      digitalWrite(dir1PinB, HIGH);
      digitalWrite(dir2PinB, LOW);
      Serial.println("Simulate Right Reverse");
      break;
      
      default: break;
  }
}
