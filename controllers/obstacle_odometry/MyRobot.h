/**
* @file MyRobot.h
* @brief Controller that void the obstacle with odometry.
* @author Samuel Hernandez Bermejo <100284298@alumnos.uc3m.es>
* @date 2014-11-11
*/

#include <iostream>
#include <cmath>
#include <webots/DifferentialWheels.hpp>

using namespace webots;
using namespace std;

#define MAX_SPEED 80

class MyRobot : public DifferentialWheels {
private:
    double _left_encoder, _right_encoder;
    double _left_speed, _right_speed;
    double _distance, goal_distance, goal_angle;
    Compass* _my_compass;
    int _time_step, _status;
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
* @brief User defined function for initializing and running the template class.
* @param
* @return */ 
    void run();
    /**
* @brief Function for converting bearing vector from compass to angle (in degrees).
* @param const double* in_vector
* @return deg*/
    double convert_bearing_to_degrees(const double* in_vector);
};
