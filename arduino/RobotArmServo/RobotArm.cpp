#include "Arduino.h"
#include "RobotArm.h"

RobotArm::RobotArm(int basePin, int shoulderPin, int elbowPin, int lowerPin, int upperPin){
  jointServo[BASE].attach(basePin);
  jointServo[SHOULDER].attach(shoulderPin);
  jointServo[ELBOW].attach(elbowPin);
  jointServo[LOWER].attach(lowerPin);
  jointServo[UPPER].attach(upperPin);
}

/* Moves servos to desired positions 
 *
 * Examples
 *
 *   arm.setPositions();
 *   ==> each servo moves to associated servoPos
 */
void RobotArm::setPositions(){
  jointServo[BASE].write(servoPos[BASE]);
  jointServo[SHOULDER].write(servoPos[SHOULDER]);
  jointServo[ELBOW].write(servoPos[ELBOW]);
  jointServo[LOWER].write(servoPos[LOWER]);
  jointServo[UPPER].write(servoPos[UPPER]);
}

/* Sets the desired position for the specific servo
 *
 * int joint - the joint to be moved (See RobotArm.h for enum of joints
 * int newPos - the new servo position for the joint from 0-255
 *
 * Examples
 *
 * arm.updateJointPosition(RobotArm::BASE, 135)
 */
void RobotArm::updateJoint(int joint, int newPosition){
  servoPos[joint] = newPosition;
}    


