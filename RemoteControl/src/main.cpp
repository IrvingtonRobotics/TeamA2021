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
// LFMotor              motor         9               
// LBMotor              motor         10              
// RFMotor              motor         1               
// RBMotor              motor         2               
// LiftR                motor         8               
// Intake               motor         7               
// Grabber              motor         5               
// LiftL                motor         3               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include <cmath>
#include <bits/stdc++.h>
using namespace vex;


void StopAll(){
  LFMotor.stop();
  LBMotor.stop();
  RFMotor.stop();
  RBMotor.stop();
}


float smoothen(float x){
    return (std::pow(2 * x - 1, 1./3.) + 1) / 2;
}

bool grabMode = false;
int revGrabCount = 0;
const int revGrabMaxCount = 20;
void toggleGrabber(){
  if(grabMode){
    revGrabCount = revGrabMaxCount;
  }
  grabMode = !grabMode;
}

bool intakeMode = false;
void toggleIntake(){
  intakeMode = !intakeMode;
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  Brain.Screen.render(true,false);
  std::string debuggerText = "";
  Controller1.ButtonX.pressed(toggleGrabber);
  Controller1.ButtonY.pressed(toggleIntake); 
  while(true){

    // Robot rotatation, horizontal axis
    int rotation = - pow(Controller1.Axis3.position(percent), 2) / 120;
    int velocity = - pow(Controller1.Axis4.position(percent), 2) / 120;
    if(Controller1.Axis3.position(percent) < 0){
      rotation *= -1;
    }
    if(Controller1.Axis4.position(percent) < 0){
      velocity *= -1;
    }

    if(rotation > 0){ // Rotate left
      debuggerText = "rotating left";
      LFMotor.spin(reverse, rotation, pct);
      RFMotor.spin(fwd, rotation, pct);
      LBMotor.spin(reverse, rotation, pct);
      RBMotor.spin(fwd, rotation, pct);  
    }
    else if(rotation < 0){ // Rotate right
    debuggerText = "rotating right";
      LFMotor.spin(fwd, -rotation, pct);
      RFMotor.spin(reverse, -rotation, pct);
      LBMotor.spin(fwd, -rotation, pct);
      RBMotor.spin(reverse, -rotation, pct);
    }
    else if(velocity == 0){
      debuggerText = "";
      StopAll();
    }

    // Moving forwards/backwards, verticle axis
    if(velocity > 0){ // Move forward
      debuggerText = "moving forward";
      LFMotor.spin(forward, velocity, pct);
      LBMotor.spin(forward, velocity, pct);
      RFMotor.spin(forward, velocity, pct);
      RBMotor.spin(forward, velocity, pct);
    }
    else if(velocity < 0){ // Move backwards
      debuggerText = "moving backwards";
      LFMotor.spin(reverse, -velocity, pct);
      LBMotor.spin(reverse, -velocity, pct);
      RFMotor.spin(reverse, -velocity, pct);
      RBMotor.spin(reverse, -velocity, pct);
    }
    else if(rotation == 0){
      debuggerText = "";
      StopAll();
    }

    // Lift control
    if(Controller1.ButtonUp.pressing()){
      LiftL.spin(reverse, 20, pct);
      LiftR.spin(reverse, 20, pct);
    }
    else if(Controller1.ButtonDown.pressing()){
      LiftL.spin(forward, 20, pct);
      LiftR.spin(forward, 20, pct);
    }
    else{
      LiftL.stop();
      LiftL.setStopping(hold);
      
      LiftR.stop();
      LiftR.setStopping(hold);
    }

    // Intake control
    if(Controller1.ButtonR2.pressing()){
      Intake.spin(reverse, 20, pct);
    }
    else if(Controller1.ButtonR1.pressing()){
      Intake.spin(forward, 20, pct);
    }
    else{
      if(intakeMode){
        Intake.spin(reverse, 20, pct);
      }
      else{
        Intake.stop();
      }
    }

    if(revGrabCount > 0){
      revGrabCount--;
    }
    // Grabber control
    if(Controller1.ButtonL1.pressing() || revGrabCount > 0){
      Grabber.spin(forward);
    }
    else if(Controller1.ButtonL2.pressing()){
      Grabber.spin(reverse);
    }
    else{
      if(grabMode){
        Grabber.spin(reverse);      
      }
      else{
        Grabber.stop();
      }
    }

  }
}