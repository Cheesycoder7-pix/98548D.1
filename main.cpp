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
// Drivetrain           drivetrain    11, 13, 18, 20, 15
// Controller1          controller                    
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
// function to run drive motors for specified distance in units defined by WHEEL_DIAM then stop the drive motors
// +dist = forward, -dist = reverse.

// Calling Functions



void autonomous(void) {
  Drivetrain.setDriveVelocity(45, pct);
  Drivetrain.setTurnVelocity(30, pct);
  Motor1.setVelocity(90, pct);
  Motor2.setVelocity(100, pct);
  Motor3.setVelocity(100, pct);
  Drivetrain.driveFor(fwd, 85, inches);
  Drivetrain.turnFor(-45, deg);
  Motor2.spin(fwd);
  Motor1.spin(fwd);
  Drivetrain.driveFor(fwd, 38.5+5, inches);
  Drivetrain.driveFor(reverse, 13, inches);
  wait(.5, seconds);
  Motor2.stop();
  Drivetrain.turnFor(80, deg);
  Drivetrain.driveFor(fwd, 45, inches);
  Motor3.setVelocity(60, pct);
  Motor2.setVelocity(60, pct);
  Motor2.spin(forward);
  Motor3.spin(reverse);
  wait(5, seconds);
  Drivetrain.driveFor(fwd, 1, inches);
  Drivetrain.driveFor(reverse, 1, inches);

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

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    if (Controller1.ButtonL1.pressing()) {
      Motor2.setVelocity(75, percent);
      Motor3.setVelocity(100, percent);
      Motor2.spin(forward);
      Motor3.spin(forward);
    }
    else if (Controller1.ButtonR1.pressing()) {
      Motor1.setVelocity(100, percent);
      Motor1.spin(forward);
      if (Distance.objectDistance(mm) < 127) {
        Motor2.setVelocity(100, percent);
        Motor2.spin(forward);
        wait(.3, sec);
        Motor2.stop();
      }
    }
    else if (Controller1.ButtonL2.pressing()) {
      Motor2.setVelocity(100, percent);
      Motor3.setVelocity(100, percent);
      Motor2.spin(forward);
      Motor3.spin(reverse);
    }
    else if (Controller1.ButtonR2.pressing()) {
      Motor1.setVelocity(100, percent);
      Motor2.setVelocity(100, percent);
      Motor1.spin(reverse);
      Motor2.spin(reverse);
    }
    else {
      Motor1.stop();
      Motor2.stop();
      Motor3.stop();
    }
    if (Controller1.ButtonA.pressing()) {
      DigitalOutA.set(true);
    }
    else{
      DigitalOutA.set(false);
    }
    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
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

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
