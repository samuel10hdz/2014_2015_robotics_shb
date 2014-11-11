/**
* @file obstacle_odometry.cpp
* @brief Controller that void the obstacle with odometry.
* @author Samuel Hernandez Bermejo <100284298@alumnos.uc3m.es>
* @date 2014-11-11
*/

#include "MyRobot.h"

//Main program
int main(int argc, char **argv)
{
    MyRobot* my_robot = new MyRobot();
    my_robot->run();
    delete my_robot;
    return 0;
}
