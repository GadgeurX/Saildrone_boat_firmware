#ifndef IMU_UTILS_HPP_
#define IMU_UTILS_HPP_

#include <Arduino.h>

void getOrientation(float* orentation, float ax, float ay, float az, float gx, float gy, float gz, float mx, float my, float mz);

#endif