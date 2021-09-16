/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       PraneetJoshi                                              */
/*    Created:      Fri Aug 27 2021                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
 
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LFmotor              motor         6               
// RFmotor              motor         1               
// LBmotor              motor         12              
// RBmotor              motor         18              
// Controller1          controller                    
// PotentiometerA       pot           A               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();


LFmotor.setVelocity(100, velocityUnits::pct);
RFmotor.setVelocity(100, velocityUnits::pct);
LBmotor.setVelocity(100, velocityUnits::pct);
RBmotor.setVelocity(100, velocityUnits::pct);

  // move forward

  LFmotor.spin(fwd, 100, pct);
  RFmotor.spin(fwd, 100, pct);
  LBmotor.spin(fwd,100, pct);
  RBmotor.spin(fwd, 100, pct);


  // move backward

  LFmotor.spin(reverse, 100, pct);
  RFmotor.spin(reverse, 100, pct);
  LBmotor.spin(reverse,100, pct);
  RBmotor.spin(reverse, 100, pct);

  task::sleep(5000);
  

  // move left

  LFmotor.spin(reverse, 100, pct);
  RFmotor.spin(fwd, 100, pct);
  LBmotor.spin(reverse, 100, pct);
  RBmotor.spin(fwd, 100, pct);           

  task::sleep(5000);

  // move right

  LFmotor.spin(fwd, 100, pct);
  RFmotor.spin(reverse, 100, pct);
  LBmotor.spin(fwd, 100, pct);
  RBmotor.spin(reverse, 100, pct);

  task::sleep(5000);

  //  stop

  LFmotor.stop();
  RFmotor.stop();
  LBmotor.stop();
  RBmotor.stop();

  
  
  
}
