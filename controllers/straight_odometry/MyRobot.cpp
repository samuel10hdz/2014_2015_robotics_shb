/**
* @file MyRobot.cpp
* @brief Controller that go straight.
* @author Samuel Hernandez Bermejo <100284298@alumnos.uc3m.es>
* @date 2014-11-11
*/

#include "MyRobot.h"
//////////////////////////////////////////////
MyRobot::MyRobot() : DifferentialWheels()
{
    _time_step = 64;
    goal_distance = 17;
    enableEncoders(_time_step);
    _left_speed = 0;
    _right_speed = 0;
    _distance = 0;
}
//////////////////////////////////////////////
MyRobot::~MyRobot()
{
    disableEncoders();
}
//////////////////////////////////////////////
void MyRobot::run()
{
    while (step(_time_step) != -1)
    {
        //Read the value of the encoders
        _left_encoder = getLeftEncoder();
        _right_encoder = getRightEncoder();
        //Convert the value of the right encoder to meters
        _distance = _right_encoder/60.59;
        if (_distance < goal_distance)
        {
            if(_left_encoder > _right_encoder)
            {
                _left_speed = MAX_SPEED-10;
                _right_speed = MAX_SPEED;
            }
            else
            {
                _left_speed = MAX_SPEED;
                _right_speed = MAX_SPEED-10;
            }
        }
        //stop
        else
        {
            _left_speed = 0;
            _right_speed = 0;
        }
        setSpeed(_left_speed, _right_speed);
    }
}
