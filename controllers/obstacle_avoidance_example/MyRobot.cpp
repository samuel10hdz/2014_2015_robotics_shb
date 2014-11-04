/**
 * @file    main_template.cpp
 * @brief   A template for webots projects.
 *
 * @author  Samuel Hernandez Bermejo <100284298@alumnos.uc3m.es>
 * @date    2014-11-04
 */

#include "MyRobot.h"

//////////////////////////////////////////////

MyRobot::MyRobot() : DifferentialWheels()
{
    _time_step = 64;

    _left_speed = 0;
    _right_speed = 0;

    _mode = FORWARD;

    // Get and enable the compass device
    _my_compass = getCompass("compass");
    _my_compass->enable(_time_step);

    _distance_sensor[0] = getDistanceSensor("ds0");
    _distance_sensor[0]->enable(_time_step);
    _distance_sensor[1] = getDistanceSensor("ds1");
    _distance_sensor[1]->enable(_time_step);
    _distance_sensor[2] = getDistanceSensor("ds2");
    _distance_sensor[2]->enable(_time_step);
    _distance_sensor[3] = getDistanceSensor("ds3");
    _distance_sensor[3]->enable(_time_step);
    _distance_sensor[4] = getDistanceSensor("ds4");
    _distance_sensor[4]->enable(_time_step);
    _distance_sensor[5] = getDistanceSensor("ds5");
    _distance_sensor[5]->enable(_time_step);
    _distance_sensor[6] = getDistanceSensor("ds6");
    _distance_sensor[6]->enable(_time_step);
    _distance_sensor[7] = getDistanceSensor("ds7");
    _distance_sensor[7]->enable(_time_step);
    _distance_sensor[8] = getDistanceSensor("ds8");
    _distance_sensor[8]->enable(_time_step);
    _distance_sensor[9] = getDistanceSensor("ds9");
    _distance_sensor[9]->enable(_time_step);
    _distance_sensor[10] = getDistanceSensor("ds10");
    _distance_sensor[10]->enable(_time_step);
    _distance_sensor[11] = getDistanceSensor("ds11");
    _distance_sensor[11]->enable(_time_step);
    _distance_sensor[12] = getDistanceSensor("ds12");
    _distance_sensor[12]->enable(_time_step);
    _distance_sensor[13] = getDistanceSensor("ds13");
    _distance_sensor[13]->enable(_time_step);
    _distance_sensor[14] = getDistanceSensor("ds14");
    _distance_sensor[14]->enable(_time_step);
    _distance_sensor[15] = getDistanceSensor("ds15");
    _distance_sensor[15]->enable(_time_step);
}

//////////////////////////////////////////////

MyRobot::~MyRobot()
{
    _my_compass->disable();

    for (int i=0; i<NUM_DISTANCE_SENSOR; i++) {
        _distance_sensor[i]->disable();
    }
}

//////////////////////////////////////////////

void MyRobot::run()
{
    long combine_mode = 0;
    double compass_angle;
    double ir0_val = 0.0, ir1_val = 0.0, ir2_val = 0.0, ir3_val = 0.0, ir4_val = 0.0, ir6_val = 0.0;
    double ir7_val = 0.0, ir8_val = 0.0, ir9_val = 0.0, ir11_val = 0.0, ir12_val = 0.0, ir13_val = 0.0;
    double ir14_val = 0.0, ir15_val = 0.0;

    while (step(_time_step) != -1) {
        // Read the sensors
        const double *compass_val = _my_compass->getValues();

        // Convert compass bearing vector to angle, in degrees
        compass_angle = convert_bearing_to_degrees(compass_val);

        // Read the sensors
        ir0_val = _distance_sensor[0]->getValue();
        ir1_val = _distance_sensor[1]->getValue();
        ir2_val = _distance_sensor[2]->getValue();
        ir3_val = _distance_sensor[3]->getValue();
        ir4_val = _distance_sensor[4]->getValue();
        ir6_val = _distance_sensor[6]->getValue();
        ir7_val = _distance_sensor[7]->getValue();
        ir8_val = _distance_sensor[8]->getValue();
        ir9_val = _distance_sensor[9]->getValue();
        ir11_val = _distance_sensor[11]->getValue();
        ir12_val = _distance_sensor[12]->getValue();
        ir13_val = _distance_sensor[13]->getValue();
        ir14_val = _distance_sensor[14]->getValue();
        ir15_val = _distance_sensor[15]->getValue();

        if ((ir0_val < DISTANCE_LIMIT) && (ir1_val < DISTANCE_LIMIT) && (ir2_val < DISTANCE_LIMIT)&& (ir3_val < DISTANCE_LIMIT)) {
            if (compass_angle > (DESIRED_ANGLE + 2)) {
                cout << "TURN_LEFT_COMPASS" << endl;
                _mode = TURN_LEFT_COMPASS;

            }
            else
            {
                if ((ir14_val < DISTANCE_LIMIT) && (ir15_val < DISTANCE_LIMIT) && (ir13_val < DISTANCE_LIMIT) && (ir12_val < DISTANCE_LIMIT)) {
                    if (compass_angle < (DESIRED_ANGLE - 2)) {
                        cout << "TURN_RIGHT_COMPASS" << endl;
                        _mode = TURN_RIGHT_COMPASS;
                    }
                }
                else
                {
                    // Control logic of the robot
                    if (((ir0_val > DISTANCE_LIMIT) || (ir1_val > DISTANCE_LIMIT+150) || (ir2_val > DISTANCE_LIMIT) || (ir3_val > DISTANCE_LIMIT)) && ((ir6_val > DISTANCE_LIMIT) || (ir7_val > DISTANCE_LIMIT) || (ir8_val > DISTANCE_LIMIT) || (ir9_val > DISTANCE_LIMIT))){
                        cout << "TURN_RIGHT " << endl;
                        _mode = TURN_RIGHT;
                    }
                    else
                    {

                        if ((ir0_val > DISTANCE_LIMIT) || (ir1_val > DISTANCE_LIMIT) || (ir2_val > DISTANCE_LIMIT) || (ir3_val > DISTANCE_LIMIT)) {
                            cout << "OBSTACLE_AVOID_RIGHT" << endl;
                            _mode = OBSTACLE_AVOID_RIGHT;
                        }
                    }
                    if (((ir15_val > DISTANCE_LIMIT) || (ir14_val > DISTANCE_LIMIT) || (ir13_val > DISTANCE_LIMIT) || (ir12_val > DISTANCE_LIMIT)) && ((ir6_val > DISTANCE_LIMIT) || (ir7_val > DISTANCE_LIMIT) || (ir8_val > DISTANCE_LIMIT) || (ir9_val > DISTANCE_LIMIT))){
                        cout << "TURN_LEFT" << endl;
                        _mode = TURN_LEFT;
                    }
                    else
                    {

                        if ((ir15_val > DISTANCE_LIMIT) || (ir14_val > DISTANCE_LIMIT) || (ir13_val > DISTANCE_LIMIT) || (ir12_val > DISTANCE_LIMIT)) {
                            cout << "OBSTACLE_AVOID_LEFT" << endl;
                            _mode = OBSTACLE_AVOID_LEFT;
                        }
                    }
                }
            }
        }
        else
        {
           if ((ir7_val > DISTANCE_LIMIT) && (ir8_val > DISTANCE_LIMIT)){
                cout << "FORWARD" << endl;
                _mode = FORWARD;
            }
            else
            {
              if ((ir3_val > DISTANCE_LIMIT) || (ir4_val > DISTANCE_LIMIT)) {
                 if (combine_mode == 14){
                    cout << "OBSTACLE_AVOID_RIGHT AND FORWARD" << endl;
                    _mode = OBSTACLE_AVOID_RIGHT;
                    _mode = FORWARD;
                 }
                 else
                 {
                    cout << "OBSTACLE_AVOID_RIGHT" << endl;
                    _mode = OBSTACLE_AVOID_RIGHT;
                 }
              }
              if ((ir13_val > DISTANCE_LIMIT) && (ir14_val > DISTANCE_LIMIT) && (ir15_val > DISTANCE_LIMIT)){
                 if ((ir11_val > DISTANCE_LIMIT+700) || (ir12_val > DISTANCE_LIMIT+700)) {
                     cout << "OBSTACLE_AVOID_LEFT" << endl;
                     _mode = OBSTACLE_AVOID_LEFT;
                }
              
              cout << "OBSTACLE_RIGHT_NOW" << endl;
              combine_mode = combine_mode+1;
              _mode = OBSTACLE_RIGHT_NOW;
              }
            }
          }

        // Send actuators commands according to the mode
        switch (_mode){
            case STOP:
                _left_speed = 0;
                _right_speed = 0;
                break;
            case FORWARD:
                _left_speed = MAX_SPEED;
                _right_speed = MAX_SPEED;
                break;
            case TURN_LEFT:
                _left_speed = MAX_SPEED / 1.25;
                _right_speed = MAX_SPEED;
                break;
            case TURN_RIGHT:
                _left_speed = MAX_SPEED;
                _right_speed = MAX_SPEED / 1.25;
                break;
            case TURN_LEFT_COMPASS:
                _left_speed = MAX_SPEED - 15;
                _right_speed = MAX_SPEED;
                break;
            case TURN_RIGHT_COMPASS:
                _left_speed = MAX_SPEED;
                _right_speed = MAX_SPEED - 15;
                break;
            case OBSTACLE_AVOID_RIGHT:
                _left_speed = -MAX_SPEED / 20.0;
                _right_speed = -MAX_SPEED / 3.0;
                break;
            case OBSTACLE_AVOID_LEFT:
                _left_speed = -MAX_SPEED / 3.0;
                _right_speed = -MAX_SPEED / 20.0;
                break;
            case OBSTACLE_RIGHT_NOW:
                  _left_speed = MAX_SPEED;
                  _right_speed = MAX_SPEED / 50;                
                break;
            default:
                break;
        }

        // Set the motor speeds
        setSpeed(_left_speed, _right_speed);
    }
}

//////////////////////////////////////////////

// It converts radians to degrees
double MyRobot::convert_bearing_to_degrees(const double* in_vector)
{
    double rad = atan2(in_vector[0], in_vector[2]);
    double deg = rad * (180.0 / M_PI);

    return deg;
}

//////////////////////////////////////////////
