#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "XYZ_Widget.h"

namespace PD {
	class BaseLinkage{
	public:
		BaseLinkage();
		~BaseLinkage();
		void setRadius(float); //TODO: Document this
		void setHeight(float); //TODO: Document this
		void setResolution(int); //TODO: Document this
		void setColor(ofColor); //TODO: Document this
		void setup(float, float, bool = true); //default show gizmo
		void draw();
		void showXray(); //Turn on alpha to show widget
		void disableXray();

		float radius, height;
		int axisResolution;
		ofColor color;			//TODO: change to ofSetColor
		ofFloatColor fColor;
		ofMaterial material;
		ofCylinderPrimitive cylinder;

		bool showWidget; //TODO: implement opacity changing
		XYZ_Widget widget;

	};
}
