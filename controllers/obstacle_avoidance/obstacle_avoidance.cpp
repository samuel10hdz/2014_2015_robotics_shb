/**
 * @file    obstacle_avoidance.cpp
 * @brief   Controller that void the obstacle
 *
 * @author  Samuel Hernandez <100284298@alumnos.uc3m.es>
 * @date    11-11-2014
 */
#include "MyRobot.h"

int main(int argc, char **argv)
{
    MyRobot* my_robot = new MyRobot();

    my_robot->run();

    delete my_robot;

    return 0;
}
