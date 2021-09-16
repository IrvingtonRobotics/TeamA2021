using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor LFmotor;
extern motor RFmotor;
extern motor LBmotor;
extern motor RBmotor;
extern controller Controller1;
extern pot PotentiometerA;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );