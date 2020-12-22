#ifndef _ATTITUDE_HPP_
#define _ATTITUDE_HPP_

#include <Arduino.h>
#include <MPU9250.h>
#include "imu_utils.hpp"

void AttitudeTask(void * pvParameters);
float* getOrientation();

#endif