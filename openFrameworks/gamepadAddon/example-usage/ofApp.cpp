#include "ofApp.h"

void ofApp::setup(){
	gui.setup();
}

void ofApp::update(){
	if (!gamepad.Refresh()) {	//gamepad disconnected
		if (wasConnected) {		//print error message once
			wasConnected = false;
			std::cout << "Please connect Xbox 360 controller." << std::endl;
		}
	}
	else {
		if (!wasConnected) {	//confirm connected controller
			wasConnected = true;
			std::cout << "Controller connected on port " << gamepad.GetPort() << std::endl;
		}

		//do stuff with gamepad data
		std::cout << "Left thumb stick: (" << gamepad.leftStickX << ", " << gamepad.leftStickY << ")   Right thumb stick : (" << gamepad.rightStickX << ", " << gamepad.rightStickY << ")" << std::endl;
		std::cout << "Left analog trigger: " << gamepad.leftTrigger << "   Right analog trigger: " << gamepad.rightTrigger << std::endl;
		if (gamepad.IsPressed(XINPUT_GAMEPAD_A)) std::cout << "(A) button pressed" << std::endl;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofDrawCircle(ofGetWidth() / 2, ofGetHeight() / 2, gamepad.leftStickY*300);
	gui.draw();
}