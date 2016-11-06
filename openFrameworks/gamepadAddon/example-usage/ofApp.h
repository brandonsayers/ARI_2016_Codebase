#pragma once

#include "ofMain.h"
#include "ofxGamepad.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		Gamepad gamepad;
		bool wasConnected = true;

		ofxPanel gui;
		
};
