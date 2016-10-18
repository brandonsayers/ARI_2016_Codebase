#include "BaseLinkage.h"


PD::BaseLinkage::BaseLinkage(){
	axisResolution = 16; //default resolution
}

PD::BaseLinkage::~BaseLinkage(){
}

void PD::BaseLinkage::setRadius(float newRadius){
	radius = newRadius;
}

void PD::BaseLinkage::setHeight(float newHeight){
	height = newHeight;
}

void PD::BaseLinkage::setResolution(int newResolution){
	axisResolution = newResolution;
	cylinder.setResolutionRadius(axisResolution);
}

void PD::BaseLinkage::setColor(ofColor newColor){
	color = newColor;
}

void PD::BaseLinkage::setup(float newRadius, float newHeight, bool turnXRayOn){
	setRadius(newRadius);
	setHeight(newHeight);

	cylinder.set(radius, height);
	cylinder.setResolutionRadius(axisResolution);
	cylinder.setResolutionHeight(1);
	color = ofColor::greenYellow;
	fColor = ofFloatColor(.75, 1, .2,.5);
	material.setDiffuseColor(fColor);
	material.setShininess(.01);
	widget.setup(newRadius/4);
	if (turnXRayOn) {
		showXray();
	} else {
		disableXray();
	}
}

void PD::BaseLinkage::draw(){
	//sets color of cylinder
	cylinder.setCylinderColor(color);
	cylinder.setTopCapColor(color);
	cylinder.setBottomCapColor(color);
	if (showWidget) {
		color.set(color.r, color.g, color.b, 200);
	}
	if (showWidget) {
		ofPushMatrix();
			ofRotateX(180);
			widget.draw();
		ofPopMatrix();
	}
	cylinder.draw();
}

void PD::BaseLinkage::showXray(){
	showWidget = true;
}

void PD::BaseLinkage::disableXray(){
	showWidget = false;
}
