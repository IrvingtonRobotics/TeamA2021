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
// LiftBottom           motor         4               
// LiftTop              motor         21              
// Intake               motor         7               
// Grabber              motor         5               
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

bool toggleGrabber = false;

float smoothen(float x){
    return (std::pow(2 * x - 1, 1./3.) + 1) / 2;
}

void tgl(){
  toggleGrabber = true;
}

void ntgl(){
  toggleGrabber = false;
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  Brain.Screen.render(true,false);
  std::string debuggerText = "";
  Controller1.ButtonX.pressed(tgl);
  Controller1.ButtonB.pressed(ntgl);
  while(true){
    // Debugging screen text to display axis values
    // Brain.Screen.clearScreen();
    // Brain.Screen.setCursor(1, 3);
    // Brain.Screen.print(Controller1.Axis4.position(percent));
    // Brain.Screen.setCursor(3, 3);
    // Brain.Screen.print(Controller1.Axis3.position(percent));
    // Brain.Screen.setCursor(5, 3);
    // Brain.Screen.print(debuggerText);
    // Brain.Screen.render();

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
      Intake.spin(forward, 20, pct);
    }
    else if(Controller1.ButtonR1.pressing() || Controller1.ButtonY.pressing()){
      Intake.spin(reverse, 20, pct);
    }
    else{
      Intake.stop();
    }

    // Grabber control
    if(Controller1.ButtonL1.pressing()){
      Grabber.spin(forward);
    }
    else if(Controller1.ButtonL2.pressing()){
      Grabber.spin(reverse);
    }
    else{
      if(toggleGrabber){
        Grabber.spin(reverse);      
      }
      else{
        Grabber.stop();
      }
    }

  }
}