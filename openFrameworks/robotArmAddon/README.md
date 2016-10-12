# robotArm addon

## usage

An example is provided in the example folder. To change the default settings for the arm you can use the following functions:

```c++
//in header file define the arm
	PD::RobotArm arm;
```

```c++
//in ofApp.cpp
void ofApp::setup(){
	// code
	float width = ofGetWidth() * .12;
	arm.setup(width);	//this will create an arm with some default sizes

	//The following are some of the functions you can use to change the various dimensions
	//for the base, foreArmTwist, and aesthetic joints (baseJoint, elbowJoint, wristJoint) you can use the following
	arm.base.setHeight(<float>);
	arm.foreArmTwist.setRadius(<float>);

	//for the other linkages: lowerArm, upperArm, lowerWrist, upperWrist
	arm.lowerArm.setDepth(<float>);
	arm.upperArm.setWidth(<float>);
	//etc

}
```

![Demo Arm Usage](./demoUsage.JPG "Demo Arm Usage")













