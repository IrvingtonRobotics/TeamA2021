using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor LFMotor;
extern motor LBMotor;
extern motor RFMotor;
extern motor RBMotor;
extern motor LiftBottom;
extern motor LiftTop;
extern motor Intake;
extern motor Grabber;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );