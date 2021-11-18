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
    // Debugging screen text to display axis values
    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1, 3);
    Brain.Screen.print(Controller1.Axis4.position(percent));
    Brain.Screen.setCursor(3, 3);
    Brain.Screen.print(Controller1.Axis3.position(percent));
    Brain.Screen.render();

    // Robot rotatation, horizontal axis
    int rotation = Controller1.Axis3.position(percent);
    int velocity = -Controller1.Axis4.position(percent);

    if(rotation > 0){ // Rotate left
      LFMotor.spin(reverse, rotation, pct);
      RFMotor.spin(fwd, rotation, pct);
      LBMotor.spin(reverse, rotation, pct);
      RBMotor.spin(fwd, rotation, pct);  
    }
    else if(rotation < 0){ // Rotate right
      LFMotor.spin(fwd, -rotation, pct);
      RFMotor.spin(reverse, -rotation, pct);
      LBMotor.spin(fwd, -rotation, pct);
      RBMotor.spin(reverse, -rotation, pct);
    }
    else if(velocity == 0){
      StopAll();
    }

    // Moving forwards/backwards, verticle axis
    if(velocity > 0){ // Move forward
      LFMotor.spin(forward, velocity, pct);
      LBMotor.spin(forward, velocity, pct);
      RFMotor.spin(forward, velocity, pct);
      RBMotor.spin(forward, velocity, pct);
    }
    else if(velocity < 0){ // Move backwards
      LFMotor.spin(reverse, -velocity, pct);
      LBMotor.spin(reverse, -velocity, pct);
      RFMotor.spin(reverse, -velocity, pct);
      RBMotor.spin(reverse, -velocity, pct);
    }
    else if(rotation == 0){
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
