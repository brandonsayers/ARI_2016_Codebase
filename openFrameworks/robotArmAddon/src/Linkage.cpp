#include "Linkage.h"

PD::Linkage::Linkage(){
}


PD::Linkage::~Linkage(){
}

//Creates a square linkage
void PD::Linkage::setup(float base, float newDepth, bool enableXray){
	height = base;
	width = base;
	depth = newDepth;
	color = ofColor::purple;

	link.set(width, height, depth);
	widget.setup(base / 4);
	if (enableXray) {
		showXray();
	} else {
		disableXray();
	}
}


//TODO: fix this so setting side color is done on change of color rather than every draw
void PD::Linkage::draw(){
	if (showWidget) {
		color.a = 150;
	}
	//set color of the links
	link.setSideColor(ofBoxPrimitive::SIDE_BACK, color);
	link.setSideColor(ofBoxPrimitive::SIDE_BOTTOM, color);
	link.setSideColor(ofBoxPrimitive::SIDE_FRONT, color);
	link.setSideColor(ofBoxPrimitive::SIDE_LEFT, color);
	link.setSideColor(ofBoxPrimitive::SIDE_RIGHT, color);
	link.setSideColor(ofBoxPrimitive::SIDE_TOP, color);

	if (showWidget) {
		ofPushMatrix();
			ofRotateX(180);
			widget.draw();
		ofPopMatrix();
	}
	ofTranslate(0, 0, depth / 2);
	link.draw();

}

void PD::Linkage::setColor(ofColor newColor){
	color = newColor;
}

void PD::Linkage::showXray(){
	showWidget = true;
}

void PD::Linkage::disableXray(){
	showWidget = false;
}
