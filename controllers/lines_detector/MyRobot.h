/**
 * @file    MyRobot.h
 * @brief   A controller to detect yellow lines with the spherical camera
 * @author  Samuel Hernandez Bermejo <100284298@alumnos.uc3m.es>
 * @date    13-11-2014
 */

#include <iostream>
#include <webots/DifferentialWheels.hpp>

using namespace std;
using namespace webots;

#define MAX_SPEED           100

class MyRobot : public DifferentialWheels {
private:
    int _time_step;

    Camera * _spherical_camera;

    double _left_speed, _right_speed;

public:

    /**
        * @brief Empty constructor of the class.
        * @param
        * @return
        */
    MyRobot();

    /**
        * @brief Destructor of the class.
        * @param
        * @return
        */
    ~MyRobot();

    /**
        * @brief User defined function for initializing and running the template class.
        * @param
        * @return
        */
    void run();
};
