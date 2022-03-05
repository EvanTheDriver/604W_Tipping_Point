#include "main.h"
#include "functions.hpp"
using namespace pros;
Controller master(E_CONTROLLER_MASTER);
//Imu inertial_sensor(15);-
 Motor leftFrontMotor(4);
 Motor rightFrontMotor(1);
 Motor leftBackMotor(20);
 Motor rightBackMotor(10);
 Motor ArmMotorRight(16);
 Motor ArmMotorLeft (15);
 Motor BackArm (17);
 Motor Conveyor (19);
//ADIDigitalIn button(1);
ADIDigitalOut Frontclaw(1);
 Imu inertial_sensor(3);
//ADIGyro gyro(3); ++++++++++-
/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
 pros::lcd::initialize();
  inertial_sensor.reset();
  delay(2000);
}
/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}
//for auto selector
/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {
  inertial_sensor.tare_rotation();
inertial_sensor.tare_pitch();
}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
 void autonomous(){
//set a if loop to do match auto or coding skills here.
//do like if 1 then match and 0 then Code
//use disable
  //pros::lcd::print(1,"Heading: [%0.0f]", inertial_sensor.get_heading());
  Frontclaw.set_value(1);
   delay(500);
   moveforward(2720, 0.2);
   delay(1000);
   ImuTurnHeadingRight(40, 2.85, 20);
   delay(500);
   moveforward(1405, 0.5);
   delay(500);
   Frontclaw.set_value(0);
   delay(500);
   moveforward(2663, 1.2);
   delay(500);
   liftUp(1600, 127);
   delay(2000);
   ImuTurnleft(-31, 5);
   delay(1000);
   moveforward(510, 0.7);
   delay(500);
   ImuTurnHeadingRight(21,5.5,37);
   delay(1000);
   liftDown(1153, 127);
   delay(500);
   Frontclaw.set_value(1);
   delay(500);
   moveback(-797,1.4);
   delay(500);
   ImuTurnleft(-80, 2.8);
   liftDown(0, 127);
   delay(1000);
   moveforward(1800, 1);
   delay(500);
   Frontclaw.set_value(0);
   delay(500);
   BackArm.move_absolute(2960, 150);
   delay(500);
   moveback(-8000, 0.69);
   delay(500);
   moveforward(800,0.5);
   delay(500);
   ImuTurnleft(-50, 3.5);
   delay(500);
   liftUp(1600, 127);
   delay(1000);
   /*ImuTurnleft(20, 5);
   delay(500);
   moveforward(1300, 3);
   delay(500);
   liftDown(1150, 127);
   delay(500);
   Frontclaw.set_value(1);
   delay(500);
   moveback(-1000, 1.2);


  /* Frontclaw.set_value(1);
    moveforward(2720, 0.2);
    delay(250);
    //ImuTurnright(40, 2.85);
    delay(500);
    moveforward(1420, 0.9);
    delay(500);
    Frontclaw.set_value(0);
    delay(250);
    moveback(-1420, 0.7);
    delay(250);
    ImuTurnleft(-40, 6);
    delay(500);
    moveback(-2720, 0.2);*/
    //ImuTurnHeadingRight (90, 1.2, 90);
    //example above
    //match auto
  /*  Frontclaw.set_value(1);
    delay(250);
    moveforward(2750,0.8);
    delay(500);
    Frontclaw.set_value(0);
    delay(500);
    liftUp(1200, 127);
    moveback(-2000,2);
    delay(1000);
    moveback(500,2.4);
    delay(500);
    liftUp(600,127);
    delay(1000);
    ImuTurnleft(-85,4.5);
    delay(750);
    moveforward(150,2.6);
    BackArm.move_absolute(2960, 150);
    delay(3000);
    moveback(-1500,1.2);
    delay(500);
    conveyerOn();
    delay(1000);
    conveyerOff();
    BackArm.move_absolute(2420, 150);
    delay(1000);
    moveback(-1000,3);*/
}
  /*




 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */

void opcontrol() {
 ArmMotorLeft.tare_position();
 ArmMotorRight.tare_position();
int armState=0;
int cState=0;

	while (true) {
    double leftY = master.get_analog(ANALOG_LEFT_Y);
		double leftX = master.get_analog(ANALOG_LEFT_X);
		leftFrontMotor = leftY + leftX;
		rightFrontMotor = -leftY + leftX;
		leftBackMotor = leftY + leftX;
		rightBackMotor = -leftY + leftX;
    /*int leftY = master.get_analog(ANALOG_LEFT_Y);
    int rightY = master.get_analog(ANALOG_RIGHT_Y);
    rightBackMotor= -rightY;
    rightFrontMotor = -rightY;
    leftBackMotor = leftY;
    leftFrontMotor= leftY;*/
    /*int rightY = master.get_analog(ANALOG_RIGHT_Y);
		int leftX = master.get_analog(ANALOG_LEFT_X);
		leftFrontMotor = rightY + leftX;
		rightFrontMotor = -rightY + leftX;
		leftBackMotor = rightY + leftX;
		rightBackMotor = -rightY + leftX;*/

    pros::lcd::print(1,"Heading: [%0.0f]", inertial_sensor.get_heading());

    /*lcd::print (4, "%f", leftBackDrive.get_position());
		lcd::print (5,"%f", rightBackDrive.get_position());*/

    /*if (master.get_digital_new_press(ANALOG_RIGHT_Y)==1){
      ArmMotorRight.move_absolute(1150, 127);
      ArmMotorLeft.move_absolute(-1150,-127);
      //armState = 1;
  }

  else if(master.get_digital(DIGITAL_R2)==1 ) {
    ArmMotorRight.move_absolute(10, -100);
    ArmMotorLeft.move_absolute(-10, 100);
  }
  */

ArmMotorRight = master.get_analog(ANALOG_RIGHT_Y);


ArmMotorLeft = -master.get_analog(ANALOG_RIGHT_Y);
/*  else {
    if(armState == 1){
      ArmMotorRight.move_absolute(1600, 127);
      ArmMotorLeft.move_absolute(-1600,-127);
    }

    else if(armState == 0 && button.get_value() == 1){
      ArmMotorRight = 0;
      ArmMotorLeft = 0;
    }
  }*/

    if (master.get_digital_new_press(DIGITAL_L2)==1){
      armState = 2;
    }

    if (master.get_digital_new_press(DIGITAL_L1)==1){
      armState = 3;
    }

      if(armState == 2){
        BackArm.move_absolute(2950, 150);
      }

      else if (armState == 3){
        BackArm.move_absolute(2420, 150);
      }


    if(master.get_digital_new_press(DIGITAL_R1) == 1){
        Frontclaw.set_value(1);
    }
    else if (master.get_digital(DIGITAL_R2) == 1){
        Frontclaw.set_value(0);
    }
    if(master.get_digital_new_press(DIGITAL_Y)==1){
      if(cState==1){
        cState=0;
        Conveyor=0;
      }
      else if(cState==0){
        cState=1;
        Conveyor=120;
      }
    }
		pros::delay(20);
    if(master.get_digital(DIGITAL_DOWN) == 1){
      void autonomous();
    }
  }
}
