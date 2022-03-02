#ifndef _FUNCTIONS_HPP_
#define _FUNCTIONS_HPP_

void ImuTurnHeadingRight(double degree, double kp, double position);
void moveback (double distance, double kp);
void moveforward (double distance, double kp);
void ImuTurnleft(double degree, double kp);
void ImuTurnright(double degree, double kp);
void liftUp(double degree, double speed);
void liftDown(double degree, double speed);
void clawUp();
void clawDown();
void armUp();
void armDown();
void conveyerOn();
void conveyerOff();
//void matchAuto();
//void balance(double kp);
#endif
