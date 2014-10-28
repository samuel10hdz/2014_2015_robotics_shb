/**
 * @file    wall_follower.cpp
 * @brief   A template for webots projects.
 *
 * @author  Samuel Hernandez <100284298@alumnos.uc3m.es>
 * @date    10-28-2014
 */

#include "MyRobot.h"

//Main program.//

int main(int argc, char **argv)
{
    MyRobot* my_robot = new MyRobot();

    my_robot->run();

    delete my_robot;

    return 0;
}
