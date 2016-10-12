#include "XYZ_Widget.h"

/**
* Constructor
*
* Sets default resolution to 16 for cylinder and sphere.
*/
PD::XYZ_Widget::XYZ_Widget(){
	axisResolution = 16; //default resolution
}

PD::XYZ_Widget::~XYZ_Widget() {
}

/**
* Setup function
*
* Sets the height and radius for the axis cylinders as well as colors (see AxisColor)
* @param width Screen width of display recieved from ofGetWidth() in ofApp::Setup()
* @see AxisColor
*/
void PD::XYZ_Widget::setup(float width){
	setAxisRadius(width / 4);
	setAxisHeight(width * 3);

	axisColor[X_AXIS_SIDE_COLOR] = ofColor::red;
	axisColor[X_AXIS_CAP_COLOR] = ofColor::darkRed;
	axisColor[Y_AXIS_SIDE_COLOR] = ofColor::green;
	axisColor[Y_AXIS_CAP_COLOR] = ofColor::darkGreen;
	axisColor[Z_AXIS_SIDE_COLOR] = ofColor::blue;
	axisColor[Z_AXIS_CAP_COLOR] = ofColor::darkBlue;
	sphereColor = ofColor::brown;

	//set dimensions
	xAxis.set(axisRadius, axisHeight);
	xAxis.setResolutionRadius(axisResolution);
	yAxis.set(axisRadius, axisHeight);
	yAxis.setResolutionRadius(axisResolution);
	zAxis.set(axisRadius, axisHeight);
	zAxis.setResolutionRadius(axisResolution);

	sphere.set(axisRadius*.8, axisResolution);
}

//TODO : Create multiple radius definitions
void PD::XYZ_Widget::setAxisRadius(int axisIndex, float radius){

}

//TODO : Create multiple height definitions 
void PD::XYZ_Widget::setAxisHeight(int axisIndex, float height){
}

/**
* Sets the radius for the ofCylinderPrimitive axis objects. This function gets called from setup()
* @param radius Type float
*/
void PD::XYZ_Widget::setAxisRadius(float radius){
	axisRadius = radius;
}

/**
* Sets the height for the ofCylinderPrimitive axis objects. This function gets called from setup()
* @param height Type float
*/
void PD::XYZ_Widget::setAxisHeight(float height){
	axisHeight = height;
}

/**
* Sets the color for the ofCylinderPrimitive axis objects. This function gets called from draw()
* @param axisIndex see #AxisColor
* @param color see ofColor for list of acceptable colors
*/
void PD::XYZ_Widget::setAxisColor(int axisIndex, ofColor color){
	axisColor[axisIndex] = color;
}

/**
* Sets the color for the ofSpherePrimitive sphere. This function gets called from draw()
* @param color see ofColor for list of acceptable colors
*/
void PD::XYZ_Widget::setSphereColor(ofColor color){
	sphereColor = color;
}

/**
* Sets the size (radially) of the ofSpherePrimitive. This function gets called from setup()
* @param size Sets the size (radially) of the sphere
*/
void PD::XYZ_Widget::setSphereSize(float size){
	sphereSize = size;
}

/**
* sets the resolution for the ofSpherePrimitive sphere objects. Increasing this number makes the sphere "smoother". This func		tion has yet to be implemented.
* @param resolution see #AxisColor
*/
void PD::XYZ_Widget::setSphereResolution(int resolution){
	sphereResolution = resolution;
}

/**
* Sets the resolution for the ofCylinderPrimitive axis objects. Increasing this number makes the cylinder "smoother". This function gets called from XYZ_Widget()
* @param resolution the number of vertexs for each cylinder face
*/
void PD::XYZ_Widget::setAxisResolution(int resolution) {
	axisResolution = resolution;
}

/**
* Sets the resolution for the ofCylinderPrimitive axis objects. Increasing this number makes the cylinder "smoother". This function gets called from XYZ_Widget()
* @param resolution the number of vertexs for each cylinder face
*/
void PD::XYZ_Widget::draw(){
	//set colors
	xAxis.setCylinderColor(axisColor[X_AXIS_SIDE_COLOR]);
	xAxis.setTopCapColor(axisColor[X_AXIS_CAP_COLOR]);
	yAxis.setCylinderColor(axisColor[Y_AXIS_SIDE_COLOR]);
	yAxis.setTopCapColor(axisColor[Y_AXIS_CAP_COLOR]);
	zAxis.setCylinderColor(axisColor[Z_AXIS_SIDE_COLOR]);
	zAxis.setTopCapColor(axisColor[Z_AXIS_CAP_COLOR]);

	ofPushMatrix();
		ofSetColor(sphereColor);
		sphere.draw();
	ofPopMatrix();

	ofPushMatrix();
		ofRotateZ(90);
		ofTranslate(0, -axisHeight / 2, 0);
		xAxis.draw();
	ofPopMatrix();

	ofPushMatrix();
		ofTranslate(0, -axisHeight / 2, 0);
		yAxis.draw();
	ofPopMatrix();

	ofPushMatrix();
		ofRotateX(90);
		ofTranslate(0, -axisHeight / 2, 0);
		zAxis.draw();
	ofPopMatrix();
}