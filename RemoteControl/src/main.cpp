/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Ben                                              */
/*    Created:      Fri Oct 08 2021                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// LFMotor              motor         1               
// LBMotor              motor         2               
// RFMotor              motor         3               
// RBMotor              motor         4               
// LiftBottom           motor         5               
// LiftTop              motor         6               
// Intake               motor         7               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

void StopAll(){
  LFMotor.stop();
  LBMotor.stop();
  RFMotor.stop();
  RBMotor.stop();
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  while(true){
    // Robot rotatation, horizontal axis
    int rotation = Controller1.Axis4.position(percent);
    if(rotation > 0){ // Rotate left
      LFMotor.spin(forward, rotation, pct);
      LBMotor.spin(forward, rotation, pct);
      RFMotor.spin(reverse, rotation, pct);
      RBMotor.spin(reverse, rotation, pct);
    }
    else if(rotation < 0){ // Rotate right
      LFMotor.spin(reverse, -rotation, pct);
      LBMotor.spin(reverse, -rotation, pct);
      RFMotor.spin(forward, -rotation, pct);
      RBMotor.spin(forward, -rotation, pct);
    }
    else{
      StopAll();
    }

    // Moving forwards/backwards, verticle axis
    int velocity = Controller1.Axis3.position(percent);
    if(velocity > 0){ // Move forward
      LFMotor.spin(forward, rotation, pct);
      LBMotor.spin(forward, rotation, pct);
      RFMotor.spin(forward, rotation, pct);
      RBMotor.spin(forward, rotation, pct);
    }
    else if(velocity < 0){ // Move backwards
      LFMotor.spin(reverse, -rotation, pct);
      LBMotor.spin(reverse, -rotation, pct);
      RFMotor.spin(reverse, -rotation, pct);
      RBMotor.spin(reverse, -rotation, pct);
    }
    else{
      StopAll();
    }

    // Bottom lift control
    if(Controller1.ButtonX.pressing()){
      LiftBottom.spin(forward);
    }
    else if(Controller1.ButtonB.pressing()){
      LiftBottom.spin(reverse);
    }
    else{
      LiftBottom.stop();
    }

    // Upper lift control
    if(Controller1.ButtonUp.pressing()){
      LiftTop.spin(forward);
    }
    else if(Controller1.ButtonDown.pressing()){
      LiftTop.spin(forward);
    }
    else{
      LiftTop.stop();
    }

    // Intake control
    if(Controller1.ButtonR2.pressing()){
      Intake.spin(forward);
    }
    else if(Controller1.ButtonR1.pressing()){
      Intake.spin(reverse);
    }
    else{
      Intake.stop();
    }
  }
}
