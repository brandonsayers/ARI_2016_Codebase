#pragma once

#include "ofMain.h"
#include "RobotArm.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		ofxPanel gui;
		ofxButton showXYZ;

		ofLight keyLight, fillLight, rimLight;
		ofEasyCam cam;

		ofParameter<float> shoulderAngle, baseAngle;
		ofParameter<float> elbowAngle, foreArmTwistAngle;
		ofParameter<float> wristTiltAngle;
		ofxButton showXray;

		PD::RobotArm arm;
};
