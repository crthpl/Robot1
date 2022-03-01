/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// Motor11              motor         11              
// Motor3               motor         3               
// Drivetrain           drivetrain    12, 2           
// Motor1               motor         1               
// Motor13              motor         13              
// Motor4               motor         4               
// Distance5            distance      5               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
#define HANDSPEED 15
void usercontrol(void) {
  // User control code here, inside the loop
  Motor13.spin(forward);
  Motor3.spin(forward);
  for (;;) {
    if (Controller1.ButtonL1.pressing()) {
      Brain.Screen.clearLine();
      Brain.Screen.print("L1");
      Motor13.setVelocity(HANDSPEED, percent);
    } else if (Controller1.ButtonL2.pressing()) {
      Brain.Screen.clearLine();
      Brain.Screen.print("L2");
      Motor13.setVelocity(-HANDSPEED, percent);
    } else {
      Motor13.setVelocity(0, percent);
    }
    if (Controller1.ButtonR1.pressing()) {
      Brain.Screen.clearLine();
      Brain.Screen.print("R1");
      Motor3.setVelocity(HANDSPEED, percent);
    } else if (Controller1.ButtonR2.pressing()) {
      Brain.Screen.clearLine();
      Brain.Screen.print("R2");
      Motor3.setVelocity(-HANDSPEED, percent);
    } else {
      Motor3.setVelocity(0, percent);
    }
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();
  usercontrol();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
