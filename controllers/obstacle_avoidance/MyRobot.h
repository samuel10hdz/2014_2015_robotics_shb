/**
 * @file    MyRobot.h
 * @brief   Controller that void the obstacle
 *
 * @author  Samuel Hernandez <100284298@alumnos.uc3m.es>
 * @date    11-11-2014
 */


#include <iostream>
#include <webots/DifferentialWheels.hpp>

using namespace std;
using namespace webots;

#define NUM_DISTANCE_SENSOR 16
#define DISTANCE_LIMIT      100
#define MAX_SPEED           80

class MyRobot : public DifferentialWheels {
private:
    int _time_step;

    DistanceSensor * _distance_sensor[NUM_DISTANCE_SENSOR];
    double _left_speed, _right_speed;

    enum Mode {
        STOP,
        FORWARD,
        TURN_LEFT,
        TURN_RIGHT,
        OBSTACLE_AVOID,
        TURN_RIGHT_NOW
    };

    Mode _mode;

public:
    /**
        * @brief Empty constructor of the class.
        * @param
        * @return */
    MyRobot();

    /**
         * @brief Destructor of the class.
         * @param
         * @return */
    ~MyRobot();

    /**
        * @brief User defined function for the control.
        * @param
        * @return */
    void run();
};
