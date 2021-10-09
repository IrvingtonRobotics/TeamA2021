#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor LFMotor = motor(PORT1, ratio18_1, false);
motor LBMotor = motor(PORT2, ratio18_1, false);
motor RFMotor = motor(PORT3, ratio18_1, false);
motor RBMotor = motor(PORT4, ratio18_1, false);
motor LiftBottom = motor(PORT5, ratio18_1, false);
motor LiftTop = motor(PORT6, ratio18_1, false);
motor Intake = motor(PORT7, ratio18_1, false);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}