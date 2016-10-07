#pragma once

#include "ofMain.h"
#include "XYZ_Widget.h"

namespace PD {
	class Linkage{
	public:
		Linkage();
		~Linkage();
		void setup(float,float,bool = false);
		void draw();
		void setColor(ofColor);
		void showXray();
		void disableXray();
		void setWidth(float);
		void setDepth(float);

		ofColor color;
		float height, width, depth;
		ofBoxPrimitive link;

		XYZ_Widget widget;
		bool showWidget;
		float rotation[3];
	
	};
}
