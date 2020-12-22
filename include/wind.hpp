#ifndef _WIND_HPP_
#define _WIND_HPP_

#include <Arduino.h>
#include <MPU9250.h>
#include "imu_utils.hpp"

void WindTask(void * pvParameters);
float getWindDirection();

#endif