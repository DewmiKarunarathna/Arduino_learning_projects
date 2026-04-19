// Simple Car Test Code
// Tests: Forward, Backward, Left Turn, Right Turn, Stop

// Motor A (Left side) - Pins 4 & 5
int leftForward = 4;
int leftBackward = 5;

// Motor B (Right side) - Pins 6 & 7  
int rightForward = 6;
int rightBackward = 7;

void setup() {
  // Set all motor pins as outputs
  pinMode(leftForward, OUTPUT);
  pinMode(leftBackward, OUTPUT);
  pinMode(rightForward, OUTPUT);
  pinMode(rightBackward, OUTPUT);
  
  
  stopCar(); 
  delay(2000);
}

void loop() {
  
  // TEST 1: FORWARD 
  forward();
  delay(5000);
  
  //STOP
  stopCar();
  delay(2000);
  
  //TEST 2: BACKWARD
  backward();
  delay(5000);
  
  //STOP
  stopCar();
  delay(2000);
  
  //TEST 3: LEFT TURN
  leftTurn();
  delay(3000);
  
  //STOP
  stopCar();
  delay(2000);
  
  //TEST 4: RIGHT TURN
  rightTurn();
  delay(3000);
  
  //STOP
  stopCar();
  delay(2000);
  
  //TEST 5: FORWARD HALF SPEED
  forwardHalfSpeed();
  delay(4000);
  
  //STOP
  stopCar();
  delay(5000);
}

//FUNCTIONS

void forward() {
  digitalWrite(leftForward, HIGH);
  digitalWrite(leftBackward, LOW);
  digitalWrite(rightForward, HIGH);
  digitalWrite(rightBackward, LOW);
}

void backward() {
  digitalWrite(leftForward, LOW);
  digitalWrite(leftBackward, HIGH);
  digitalWrite(rightForward, LOW);
  digitalWrite(rightBackward, HIGH);
}


void leftTurn() {
  digitalWrite(leftForward, LOW);
  digitalWrite(leftBackward, LOW);    // Left wheels STOP
  digitalWrite(rightForward, HIGH);
  digitalWrite(rightBackward, LOW);   // Right wheels FORWARD
}


void rightTurn() {
  digitalWrite(leftForward, HIGH);
  digitalWrite(leftBackward, LOW);    // Left wheels FORWARD
  digitalWrite(rightForward, LOW);
  digitalWrite(rightBackward, LOW);   // Right wheels STOP
}

void stopCar() {
  digitalWrite(leftForward, LOW);
  digitalWrite(leftBackward, LOW);
  digitalWrite(rightForward, LOW);
  digitalWrite(rightBackward, LOW);
}

// Forward at HALF SPEED (using PWM)
void forwardHalfSpeed() {
  analogWrite(leftForward, 128);  // 128 = half of 255
  digitalWrite(leftBackward, LOW);
  analogWrite(rightForward, 128);
  digitalWrite(rightBackward, LOW);
}