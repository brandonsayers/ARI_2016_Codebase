#include <Servo.h>
#include <RobotArm.h>

RobotArm arm(1,2,3,4,5);

void setup() {
}

void loop() {
  arm.updateJoint(RobotArm::BASE,125);
}
