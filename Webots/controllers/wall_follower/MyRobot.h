/**
 * @file    MyRobot.h
 * @brief   A template for webots projects.
 *
 * @author  Samuel Hernandez <100284298@alumnos.uc3m.es>
 * @date    10-28-2014
 */

#include <iostream>

#include <webots/DifferentialWheels.hpp>

using namespace std;
using namespace webots;

#define NUM_DISTANCE_SENSOR 3
#define DISTANCE_LIMIT      50
#define MAX_SPEED           100

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
            WALL_FOLLOWER
        };

        Mode _mode;

    public:
        // You may need to define your private methods or variables, like
        //  Constructors, helper functions, etc.

        /**
         * @brief Empty constructor of the class.
         */
        MyRobot();
        
        /**
         * @brief Destructor of the class.
         */
        ~MyRobot();

        /**
         * @brief User defined function for initializing and running the template class.
         */
        void run();
};
