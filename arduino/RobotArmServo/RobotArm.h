/*
  RobotArm.h - Library for 5DOF robot arm
  Created by Dustin Mendoza
  MIT License
*/

#ifndef __ROBOT_ARM_H__
#define __ROBOT_ARM_H__

//Although the below is commented, you must also include this in
//your main!
#include <Servo.h>
#include "Arduino.h"

class RobotArm{
  private:
    int servoPos[5];
    Servo jointServo[5];
  
  public:
    enum JOINT{
      BASE,
      SHOULDER,
      ELBOW,
      LOWER,
      UPPER
    };
    
    RobotArm(int basePin, int shoulderPin, int elbowPin, int lowerPin, int upperPin);
    void setPositions();
    void updateJoint(int joint, int newPosition);    
};

#endif
