#pragma once


#include "ofMain.h"
//#include "ofxGui.h"

namespace PD {
	
	/// XYZ_Widget class. XYZ graphical widget that shows translation axis'.
	///
	/// \brief Graphical widget for visualization of axis translation
	///
	/// This is a longer description of the class. This longer description is
	/// formatted using the Markdown syntax (see below) and can span on multiple
	/// lines.
	///
	/// Separate the paragraphs by leaving a blank line between them.
	///
	/// \author Dustin <dmendoza@alaska.edu>, University of Alaska Anchorage
	/// \date September 22, 2016
	class XYZ_Widget {

	public:
		/**
		* Axis Enumeration.
		*/
		enum Axis {
			AXIS_X, /**< 1 */ 
			AXIS_Y, /**< 2 */
			AXIS_Z	/**< 3 */
		};

		/**
		* Axis Color Enumeration.
		*/
		enum AxisColor {
			X_AXIS_SIDE_COLOR,	/**< Default: Red */
			X_AXIS_CAP_COLOR,	/**< Default: Dark Red */
			Y_AXIS_SIDE_COLOR,	/**< Default: Green */
			Y_AXIS_CAP_COLOR,	/**< Default: Dark Green */
			Z_AXIS_SIDE_COLOR,	/**< Default: Blue */
			Z_AXIS_CAP_COLOR,	/**< Default: Dark Blue */
		};

		XYZ_Widget();
		~XYZ_Widget();

		void setup(float width);
		void setAxisRadius(int axisIndex, float radius);
		void setAxisHeight(int axisIndex, float height);
		void setAxisRadius(float radius);
		void setAxisHeight(float height);
		void setAxisResolution(int resolution);
		void setAxisColor(int axisIndex, ofColor color);
		void setSphereColor(ofColor color);
		void setSphereSize(float size);
		void setSphereResolution(int resolution);
		void draw();

		ofColor axisColor[6];
		float axisRadius, axisHeight;
		int axisResolution;
		ofCylinderPrimitive xAxis, yAxis, zAxis;

		ofColor sphereColor;
		float sphereSize;
		int sphereResolution;
		ofSpherePrimitive sphere;
	};
}