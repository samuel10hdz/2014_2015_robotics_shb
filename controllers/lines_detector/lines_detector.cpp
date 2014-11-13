/**
 * @file    lines_detector.cpp
 * @brief   A controller to detect yellow lines with the spherical camera.
 * @author  Samuel Hernandez Bermejo <100284298@alumnos.uc3m.es>
 * @date    13-11-2014
 */

#include "MyRobot.h"

int main(int argc, char **argv)
{
    MyRobot* my_robot = new MyRobot();

    my_robot->run();

    delete my_robot;

    return 0;
}
