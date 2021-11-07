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
// LFMotor              motor         2               
// LBMotor              motor         12              
// RFMotor              motor         10              
// RBMotor              motor         18              
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

void autonomous(){
  
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  Brain.Screen.render(true,false);
  while(true){
    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1, 3);
    Brain.Screen.print(Controller1.Axis4.position(percent));
    Brain.Screen.setCursor(3, 3);
    Brain.Screen.print(Controller1.Axis3.position(percent));
    Brain.Screen.render();

    // Robot rotatation, horizontal axis
    int rotation = Controller1.Axis4.position(percent);
    if(rotation > 0){ // Rotate left
      LFMotor.spin(reverse, 50, pct);
      RFMotor.spin(fwd, 50, pct);
      LBMotor.spin(reverse, 50, pct);
      RBMotor.spin(fwd, 50, pct);  
    }
    else if(rotation < 0){ // Rotate right
      LFMotor.spin(fwd, 50, pct);
      RFMotor.spin(reverse, 50, pct);
      LBMotor.spin(fwd, 50, pct);
      RBMotor.spin(reverse, 50, pct);
    }
    else{
      StopAll();
    }

    // Moving forwards/backwards, verticle axis
    int velocity = Controller1.Axis2.position(percent);
    if(velocity > 0){ // Move forward
      LFMotor.spin(forward, 50, pct);
      LBMotor.spin(forward, 50, pct);
      RFMotor.spin(forward, 50, pct);
      RBMotor.spin(forward, 50, pct);
    }
    else if(velocity < 0){ // Move backwards
      LFMotor.spin(reverse, 50, pct);
      LBMotor.spin(reverse, 50, pct);
      RFMotor.spin(reverse, 50, pct);
      RBMotor.spin(reverse, 50, pct);
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
