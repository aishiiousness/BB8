<p>/* The code was made by Tamás Imets for an Arduino UNO project<br>   This code controls the BB-8 Droid from the Star Wars: The Force Awakens,
   and works with Bluetooth RC Car application, using a HC-06 serial bluetooth module
   See more details at instructables.com/member/Imetomi
   Friday,  December 25, 2015
 */</p><p>#include <servo.h>
#include <softwareserial.h>
#include <afmotor.h>
int command = 0;  //incoming serial data</afmotor.h></softwareserial.h></servo.h></p><p>AF_DCMotor motor1(1, MOTOR12_64KHZ); //initialize motor1 that is connected to the M1 port, this motor moves forward and backward
AF_DCMotor motor2(2, MOTOR12_64KHZ); //motor2 is connected to M2 and this turns BB-8 left and right
AF_DCMotor motorhead(3); //this motor turns the head left or right</p><p>Servo head;
void setup() {
  Serial.begin(9600); // set up Serial library at 9600 bps - this is the speed the serial interface will work all
  head.attach(9); //attach servo to pin D9 or to servo2 on motor shield
  motor1.setSpeed(255); //set default speed
  motor2.setSpeed(255); //set default speed
  motorhead.setSpeed(1); //the motor should spin very slowly
  pinMode(13, OUTPUT); //connect here the blue LED
}</p><p>void loop() {
  if (Serial.available() > 0) { //if the Arduino detects incoming data
    // read the incoming byte:
    command = Serial.read();
  }
  switch (command) //set different cases of the "command" variable
  {
    case 'S': {
        motor1.run(RELEASE); // stopped
        motor2.run(RELEASE); // stopped
        command = '*';
      } break;</p><p>    case 'F': { //go forward
        motor2.run(RELEASE);
        motor1.run(FORWARD);
      } break;</p><p>    case 'B': { //go backward
        motor2.run(RELEASE);
        motor1.run(BACKWARD);
      } break;</p><p>    case 'R': { //spin right
        motor1.run(RELEASE);
        motor2.run(FORWARD);
      } break;</p><p>    case 'L': { //spin left
        motor1.run(RELEASE);
        motor2.run(BACKWARD);
      } break;</p><p>    case 'G': { //forward left
        motor1.run(FORWARD);
        motor2.run(BACKWARD);
      } break;</p><p>    case 'I': { //forward right
        motor1.run(FORWARD);
        motor2.run(FORWARD);
      } break;</p><p>    case 'H': { //backward left
        motor1.run(BACKWARD);
        motor2.run(BACKWARD);
      } break;</p><p>    case 'J': { //backward right
        motor1.run(BACKWARD);
        motor2.run(FORWARD);
      } break;</p><p>    case 'W': {
        digitalWrite(13, HIGH); //lights on
      } break;</p><p>    case 'w': {
        digitalWrite(13, LOW); //lights off
      } break;</p><p>    case 'U': {
        motor1.setSpeed(180); //set lower speed
      } break;</p><p>    case 'u': {
        motor1.setSpeed(255); //set max speed
      } break;</p><p>    case 'V': {
        motorhead.run(FORWARD); //turn head left
      } break;</p><p>    case 'v': {
        motorhead.run(RELEASE); //stop spinning
      } break;</p><p>    case 'X': {
        motorhead.run(BACKWARD); //turn head right
      } break;</p><p>    case 'x': {
        motorhead.run(RELEASE); //stop spinning
      } break;</p><p>    case '0': {
        head.write(95); //basic servo state
      } break;</p><p>    case '1': {
        head.write(50); //move servo
      } break;</p><p>    case '2': {
        head.write(60); //move servo
      } break;</p><p>    case '3': {
        head.write(70); //move servo
      } break;</p><p>    case '4': {
        head.write(80); //move servo
      } break;</p><p>    case '5': {
        head.write(90); //move servo
      } break;</p><p>    case '6': {
        head.write(95); //move servo
      } break;</p><p>    case '7': {
        head.write(110); //move servo
      } break;</p><p>    case '8': {
        head.write(120); //move servo
      } break;</p><p>    case '9': {
        head.write(130); //move servo
      } break;</p><p>    case 'q': {
        head.write(135); //move servo
      } break;
      //you can add more extra feautres by writing a case command (example: different lights, sound, etc...)
  }
}</p>

