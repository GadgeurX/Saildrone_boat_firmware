#ifndef _GPS_HPP_
#define _GPS_HPP_

#include <Arduino.h>
#include "TinyGPS.h"

void GpsTask(void * pvParameters);
float* getPosition();

#endif