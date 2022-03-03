#include "main.h"
#include "functions.hpp"

/*void matchAuto(){
  Frontclaw.set_value(1);
   moveforward(2720, 0.2);
   delay(1000);
   ImuTurnright(40, 2.85);
   delay(500);
   moveforward(1420, 0.7);
   delay(750);
   Frontclaw.set_value(0);
   moveback(1420, 0.7);
   ImuTurnleft(40, 2.85);
   moveback(2720, 0.2);


}*/

/*void ImuTurnright(double degree, double kp){
  double power;
  double error;
  //while the robot's rotation does not meet the target
  inertial_sensor.tare_rotation();
  error = -degree + inertial_sensor.get_rotation();
  while(inertial_sensor.get_rotation()<= fabs(degree)){
    //the rest of the turn
    error = -degree + inertial_sensor.get_rotation();
    //0-127
    // 680*0.1 = 68
    //680*0.2 = 136
    power = error*kp;
    leftFrontMotor = -power;
    leftBackMotor = -power;
    rightFrontMotor = -power;
    rightBackMotor = -power;
  }
  leftFrontMotor=0;
  leftBackMotor=0;
  rightFrontMotor=0;
  rightBackMotor=0;
}
*/
void ImuTurnleft(double degree, double kp){
  double power;
  double error;
  //while the robot's rotation does not meet the target
  inertial_sensor.tare_rotation();
  error = -degree + inertial_sensor.get_rotation();
  while(inertial_sensor.get_rotation()>= degree){
    //the rest of the turn
    error = -degree + inertial_sensor.get_rotation();
    //0-127
    // 680*0.1 = 68
    //680*0.2 = 136
    power = error*kp;
    leftFrontMotor = -power;
    leftBackMotor = -power;
    rightFrontMotor = -power;
    rightBackMotor = -power;
  }
  leftFrontMotor=0;
  leftBackMotor=0;
  rightFrontMotor=0;
  rightBackMotor=0;
}



void moveback(double distance, double kp) {
  double power;
  double error;
  leftFrontMotor.tare_position();
  //while the robot's rotation does not meet the target
  error = -distance + leftFrontMotor.get_position();
  while(leftFrontMotor.get_position() >= (distance) || fabs(error) <= 5){
    //the rest of the turn
    error = -distance + leftFrontMotor.get_position();

    power = error * kp;
    leftFrontMotor= -power;
    leftBackMotor= -power;
    rightFrontMotor = power;
    rightBackMotor = power;
  }
  leftFrontMotor=0;
  leftBackMotor=0;
  rightFrontMotor=0;
  rightBackMotor=0;
}
void moveforward(double distance, double kp) {
  double power;
  double error;
  leftFrontMotor.tare_position();
  //while the robot's rotation does not meet the target
  error = -distance + leftFrontMotor.get_position();
  while(leftFrontMotor.get_position() <= fabs(distance) || fabs(error) <= 5){
    //the rest of the turn
    error = -distance + leftFrontMotor.get_position();

    power = error * kp;
    leftFrontMotor= -power;
    leftBackMotor= -power;
    rightFrontMotor = power;
    rightBackMotor = power;
  }
  leftFrontMotor=0;
  leftBackMotor=0;
  rightFrontMotor=0;
  rightBackMotor=0;
}



void liftUp(double degree, double speed) {

  ArmMotorLeft.move_absolute(-degree, -speed);
  ArmMotorRight.move_absolute(degree, speed);
}
void liftDown(double degree, double speed) {
  ArmMotorLeft.move_absolute(-degree, -speed);
  ArmMotorRight.move_absolute(degree, speed);
}

//void clawUp() {
  //Frontclaw.set_value(1);
//}
//void clawDown() {
  //Frontclaw.set_value(0);
//}
//void armUp() {
  //BackArm.move_absolute(2950, 150);
//}
//void armDown() {
  //BackArm.move_absolute(2420, 150);
//}
void conveyerOn() {
  Conveyor = 127;
}
void conveyerOff() {
  Conveyor = 0;
}
/*void balance(double kp){
  //22 degree
  double power;
  double error;
  //inertial_sensor.tare_pitch();
  error = inertial_sensor.get_pitch();

    while (fabs(error) >= 3) {
    error = inertial_sensor.get_pitch(); {

        power = error*kp;
        leftFrontMotor= power;
        leftBackMotor= power;
        rightFrontMotor= -power;
        rightBackMotor= -power;
      }
      if (error >= 1){
        power = fabs(error)*kp;
        leftFrontMotor= power;
        leftBackMotor= power;
        rightFrontMotor= -power;
        rightBackMotor= -power;
        }

     else if (-error >= 1) {
          power = fabs(error)*kp;
          leftFrontMotor= -power;
          leftBackMotor= -power;
          rightFrontMotor= power;
          rightBackMotor= power;
        }

      }

          leftFrontMotor= 0;
          leftBackMotor= 0;
          rightFrontMotor= 0;
          rightBackMotor= 0;
  }
}

void autonomoustwo();
//plan B
delay(500);
ImuTurnleft(-30, 5);
delay(500);
BackArm.move_absolute(2960, 150);
delay(1000);
moveback(-4000, 1.2);


//starting section;
Frontclaw.set_value(1);
delay(1500);
BackArm.move_absolute(2900, 150);
delay(1500);
moveback(-1400,0.234);
delay(1000);
BackArm.move_absolute(2000, 150);
delay(1500);
ImuTurn(30,5);
delay(500);
//transition to first mobile goal (yellow)
moveforward(315, 2.25);
delay(1500);
//56 is too much
ImuTurn(44.5,3);
delay(500);
moveforward(2450, 0.2);
delay(500);
liftUp(-50, 100);
delay(1000);
moveforward(155, 6.2);
delay(500);
Frontclaw.set_value(0);
delay(500);
//head to platform 1
//5.5 is too much
ImuTurn(20,6.5);
delay(1000);
liftUp(800, 100);
delay(500);

delay(1000);
moveforward(2500,0.3);
delay(1000);
liftUp(1600, 100);
delay(750);
moveforward(950,0.5);
delay(500);
ImuTurn(-35, 5.5);
delay(1000);
liftUp(1200, 100);
delay(500);
moveforward(500,5);
//let go of goal1
delay(500);
Frontclaw.set_value(1);
delay(500);
}


*/
void ImuTurnHeadingRight(double degree, double kp, double position){
  double power;
  double error;
  inertial_sensor.tare_rotation();
  error = degree - inertial_sensor.get_rotation();
  while((fabs(error)>1) && (inertial_sensor.get_heading())<= position){
    inertial_sensor.get_heading();
    error = degree - inertial_sensor.get_rotation();
    power = error*kp;
    leftFrontMotor = power;
    leftBackMotor = power;
    rightFrontMotor = power;
    rightBackMotor = power;
  }
  leftFrontMotor=0;
  leftBackMotor=0;
  rightFrontMotor=0;
  rightBackMotor=0;
}
