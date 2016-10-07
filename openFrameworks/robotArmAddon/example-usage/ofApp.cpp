#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	gui.setup();

	keyLight.setup();
	fillLight.setup();
	rimLight.setup();

	float width = ofGetWidth() * .12;
	arm.setup(width);

	gui.add(baseAngle.set("Rotate Base", 0, -360, 360));
	gui.add(shoulderAngle.set("Shoulder Angle: ", 30, -90, 90));
	gui.add(elbowAngle.set("Elbow Angle", 60, -90, 90));
	gui.add(foreArmTwistAngle.set("ForeArm Twist", 180, 0, 360));
	gui.add(wristTiltAngle.set("Wrist Tilt", -45, -90, 90));

	fillLight.setPosition(250, 200, 250);
	fillLight.setAttenuation(1, .001, 0);
	keyLight.setAttenuation(1, .0025, 0);
}

//--------------------------------------------------------------
void ofApp::update(){
	arm.rotateJoint(PD::RobotArm::JOINT::BASE, baseAngle);
	arm.rotateJoint(PD::RobotArm::JOINT::SHOULDER, shoulderAngle);
	arm.rotateJoint(PD::RobotArm::JOINT::ELBOW, elbowAngle);
	arm.rotateJoint(PD::RobotArm::JOINT::WRIST_1, foreArmTwistAngle);
	arm.rotateJoint(PD::RobotArm::JOINT::WRIST_2, wristTiltAngle);
}

//--------------------------------------------------------------
void ofApp::draw(){
	//Setup for 3D
	ofEnableDepthTest();
	keyLight.enable();
	fillLight.enable();
	rimLight.enable();

	//Start of drawing
	cam.begin();

	ofPushMatrix();
		arm.draw();
	ofPopMatrix();

	cam.end();
	//End of drawing

	//Setup for 2D GUI
	rimLight.disable();
	fillLight.disable();
	keyLight.disable();
	ofDisableDepthTest();
	
	//The following is needed if we have any shading in the main view
	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);
	gui.draw();
}