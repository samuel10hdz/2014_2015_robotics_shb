/**
* @file MyRobot.cpp
* @brief Controller that void the obstacle with odometry.
* @author Samuel Hernandez Bermejo <100284298@alumnos.uc3m.es>
* @date 2014-11-11
*/

#include "MyRobot.h"
//////////////////////////////////////////////
MyRobot::MyRobot() : DifferentialWheels()
{
    //Initial values

    _time_step = 64;

    goal_distance = 0;
    goal_angle = 0;
    _distance = 0;
    _status=0;
    _left_speed = 0;
    _right_speed = 0;
    _left_encoder = 0;
    _right_encoder = 0;
    enableEncoders(_time_step);

    // Get and enable the compass device
    _my_compass = getCompass("compass");
    _my_compass->enable(_time_step);
}
//////////////////////////////////////////////
MyRobot::~MyRobot()
{
    disableEncoders();
    _my_compass->disable();
}
//////////////////////////////////////////////
void MyRobot::run()
{
    double compass_angle;
    while (step(_time_step) != -1)
    {
        //Status
        switch (_status)
        {
        //Inilial turn left(avoiding obstacle)
        case 0:
            goal_angle=0;
            goal_distance=0;
            break;
            //Go straight
        case 1:
            goal_distance=5.5;
            goal_angle=0;
            break;
            //Turn right to go straight
        case 2:
            goal_angle=45;
            goal_distance=0;
            break;
            //Go straight by the left side of the obstacle
        case 3:
            goal_distance=13.5;
            goal_angle=45;
            break;
        default:
            goal_distance=0;
            goal_angle=0;
            break;
        }
        // Read the sensors
        const double *compass_val = _my_compass->getValues();

        //Read the value of the encoders
        _left_encoder = getLeftEncoder();
        _right_encoder = getRightEncoder();
        cout << "encoder left: " << _left_encoder << endl;
        cout << "encoder right: "<< _right_encoder << endl;

        // Convert compass bearing vector to angle, in degrees
        compass_angle = convert_bearing_to_degrees(compass_val);

        //Convert the value of the right encoder to meters
        _distance = _right_encoder/60.59;
        if (_status<4)
        {
            if ((compass_angle>goal_angle)&&(_status==0))
            {
                _left_speed = 0;
                _right_speed = 10;
            }
            else if ((compass_angle<goal_angle)&&(_status==2))
            {
                _left_speed = 10;
                _right_speed = 0;
            }
            else if (_distance < goal_distance)
            {
                //we turn to go straight because one wheel is faster than the other
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
            //reseting values
            else
            {
                _left_speed = 0;
                _right_speed = 0;
                setEncoders(0,0);
                _distance = 0;
                _status ++;
            }
        }
        //Setting speeds
        setSpeed(_left_speed, _right_speed);
    }
}
//////////////////////////////////////////////
double MyRobot::convert_bearing_to_degrees(const double* in_vector)
{
    double rad = atan2(in_vector[0], in_vector[2]);
    double deg = rad * (180.0 / M_PI);
    return deg;
}
//////////////////////////////////////////////
