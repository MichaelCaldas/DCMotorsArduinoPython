/*

This code permit to control two DC motors interfacing with pyserial.

Below is shown the function of each pins to control the motors.

Function 	  Channel A 	Channel B
Direction 	  Digital 12 	Digital 13
Speed (PWM) 	  Digital 3 	Digital 11
Brake 	          Digital 9 	Digital 8
Current Sensing   Analog 0 	Analog 1

Below is shown each attributes to control the motors.

The pwmA and pwmB set the speed of the motors
The dirA and dirB set the motors
The breakA and breakB set the breaks of motors

*/

const int pwmA = 3;
const int pwmB = 11;
const int breakA = 9;
const int breakB = 8;
const int dirA = 12;
const int dirB = 13;
char action = '  ';

void setup(){
 //Configuring the Channel A. 
 pinMode(dirA, OUTPUT);
 pinMode(breakA, OUTPUT);
 
 //Configuring the Channel B.
 pinMode(dirB, OUTPUT);
 pinMode(breakB, OUTPUT);
 
 Serial.begin(9600);
 
}
void loop() {
  
 while (Serial.available()>0){  
  action = Serial.read();
 }
 
 if(action == 'f'){
  move_to_front();
 }
 else if(action == 'b'){
  move_to_back();
 }
 else if(action == 's'){
  stop_motors();
 }
  else if(action == 'r'){
  move_to_right();
 }
  else if(action == 'l'){
  move_to_left();
 }
 
}
 /* This method allows to set the direction to the front.*/
 void move_to_front(){
  //Configuring the motor A to operate with partial speed.
  digitalWrite(dirB, HIGH);
  digitalWrite(breakB, LOW);
  analogWrite(pwmB, 96);
 
 //Configuring the motor B to operate with partial speed.
  digitalWrite(dirA, HIGH);
  digitalWrite(breakA, LOW);
  analogWrite(pwmA, 96);
 
  delay(1000);
 }
 
 /*This method allows to set the direction to the back.*/
 void move_to_back(){
  //Configuring the motor A to operate with partial speed.
  digitalWrite(dirA, LOW);
  digitalWrite(breakA, LOW);
  analogWrite(pwmA, 96);
 
 //Configuring the motor B to operate with partial speed.
  digitalWrite(dirB, LOW);
  digitalWrite(breakB, LOW);
  analogWrite(pwmB, 96);
 
  delay(1000);
 }
 
 /*This method allows to set the direction to the right.*/
 void move_to_right(){
  //Configuring the motor A to operate with partial speed.
  digitalWrite(dirB, HIGH);
  digitalWrite(breakB, LOW);
  analogWrite(pwmB, 96);
 
 //Stop the motor A.
  digitalWrite(breakA, LOW);
  analogWrite(pwmA, 0);
 
  delay(1000);
 }
 
 /*This method allows to set the direction to the left.*/
 void move_to_left(){
  //Configuring the motor A to operate with partial speed.
  digitalWrite(dirA, HIGH);
  digitalWrite(breakA, LOW);
  analogWrite(pwmA, 96);
 
 //Stop the motor B.
  digitalWrite(breakB, HIGH);
  analogWrite(pwmB, 0);
 
  delay(1000);
 }
 
 /*This method allows to stop the motors.*/
 void stop_motors(){
  digitalWrite(breakA, HIGH);
  digitalWrite(breakB, HIGH); 
 }
  
