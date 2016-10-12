#pragma once
#include "Linkage.h"
#include "BaseLinkage.h"

namespace PD {
	class RobotArm {
	public:
		/**
		* Joint enumeration
		*/
		enum JOINT {
			BASE,		/**< Default: */
			SHOULDER,	/**< Default: */
			ELBOW,		/**< Default: */
			WRIST_1,	/**< Default: */
			WRIST_2,	/**< Default: */
		};

		RobotArm();
		~RobotArm();
		void setup(float);
		void draw();
		void rotateJoint(int, float);

		//TODO : rename linkages 
		PD::BaseLinkage base, foreArmTwist;						//Rotating linkages / joints
		PD::Linkage lowerArm, upperArm, lowerWrist, upperWrist;	//Linkages
		PD::BaseLinkage baseJoint, elbowJoint, wristJoint;		//Aesthetic joints

		float jointAngles[5];
	};
}