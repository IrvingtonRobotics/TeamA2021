using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor LFMotor;
extern motor LBMotor;
extern motor RFMotor;
extern motor RBMotor;
extern motor LiftR;
extern motor Intake;
extern motor Grabber;
extern motor LiftL;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );