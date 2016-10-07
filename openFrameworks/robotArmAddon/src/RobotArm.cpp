#include "RobotArm.h"

PD::RobotArm::RobotArm(){
}


PD::RobotArm::~RobotArm(){
}

//example use with width of screen
void PD::RobotArm::setup(float width){
	base.setup(width * 2, width * 2, false);
	lowerArm.setup(width, width * 5, false);
	upperArm.setup(width, width * 2, false);
	foreArmTwist.setup(width*.8, width / 4, false);
	lowerWrist.setup(width, width*2.5, false);
	upperWrist.setup(width, width*1.75, false);

	upperArm.setColor(ofColor::lightBlue);
	lowerWrist.setColor(ofColor::orange);
	upperWrist.setColor(ofColor::orangeRed);

	baseJoint.setup(lowerArm.width, lowerArm.width *1.25, false);
	elbowJoint.setup(lowerArm.width*.6, lowerArm.width*1.1, false);
	wristJoint.setup(lowerWrist.width*.6, lowerWrist.width*1.1, false);

	baseJoint.setColor(ofColor::darkSlateGrey);
	elbowJoint.setColor(ofColor::darkSlateGrey);
	wristJoint.setColor(ofColor::darkSlateGrey);
}

void PD::RobotArm::draw(){
	//Draw base
	ofRotateY(jointAngles[JOINT::BASE]);
	base.draw();
	//Draw aesthetic joint
	ofPushMatrix();
		ofTranslate(0, base.height / 2, 0);
		ofRotateX(90);
		baseJoint.draw();
	ofPopMatrix();
	ofRotateY(90);
	ofPushMatrix();
		//Draw Lower Arm
		ofTranslate(0, lowerArm.width / 2 + base.height / 2, 0);
		ofRotateX(-90 + jointAngles[JOINT::SHOULDER]);
		lowerArm.draw();
		ofPushMatrix();
			//Draw Upper Arm
			ofTranslate(0, 0, lowerArm.depth / 2);
			ofPushMatrix();
				ofRotateZ(90);
				elbowJoint.draw();
			ofPopMatrix();
			ofRotateX(jointAngles[JOINT::ELBOW]);
			upperArm.draw();
			ofPushMatrix();
				//Draw lower forearm
				ofTranslate(0, 0, foreArmTwist.height / 2 + upperArm.depth / 2);
				ofRotateX(90);
				ofRotateY(jointAngles[JOINT::WRIST_1]);
				foreArmTwist.draw();
				ofPushMatrix();
					//Draw upper forearm
					ofTranslate(0, foreArmTwist.height / 2, 0);
					ofRotateX(-90);
					lowerWrist.draw();
					ofPushMatrix();
						//draw wrist
						ofTranslate(0, 0, foreArmTwist.height + upperWrist.height);
						//Draw Elbow joint aesthetic
						ofPushMatrix();
							ofRotateZ(90);
							wristJoint.draw();
						ofPopMatrix();
						ofRotateX(jointAngles[JOINT::WRIST_2]);
						upperWrist.draw();
					ofPopMatrix();
				ofPopMatrix();
			ofPopMatrix();
		ofPopMatrix();
	ofPopMatrix();
}

void PD::RobotArm::rotateJoint(int joint, float degree){
	switch (joint){
	case JOINT::BASE : 
		jointAngles[JOINT::BASE] = degree;
		break;
	case JOINT::SHOULDER :
		jointAngles[JOINT::SHOULDER] = degree;
		break;
	case JOINT::ELBOW : 
		jointAngles[JOINT::ELBOW] = degree;
		break;
	case JOINT::WRIST_1 :
		jointAngles[JOINT::WRIST_1] = degree;
		break;
	case JOINT::WRIST_2 :
		jointAngles[JOINT::WRIST_2] = degree;
		break;
	}
}

