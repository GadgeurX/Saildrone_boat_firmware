#include <Arduino.h>
#include "rubber.hpp"
#include "sail.hpp"
#include "wind.hpp"
#include "gps.hpp"
#include "attitude.hpp"

TaskHandle_t RubberTaskHandler;
TaskHandle_t SailTaskHandler;
TaskHandle_t WindTaskHandler;
TaskHandle_t GpsTaskHandler;
TaskHandle_t AttitudeTaskHandler;

void setup()
{
  xTaskCreate(RubberTask,
              "RubberTask",
              10000,
              NULL,
              0,
              &RubberTaskHandler);
  xTaskCreate(SailTask,
              "SailTask",
              10000,
              NULL,
              0,
              &SailTaskHandler);
  xTaskCreate(WindTask,
              "WindTask",
              10000,
              NULL,
              0,
              &WindTaskHandler);
  xTaskCreate(GpsTask,
              "GpsTask",
              10000,
              NULL,
              0,
              &GpsTaskHandler);
  xTaskCreate(AttitudeTask,
              "AttitudeTask",
              10000,
              NULL,
              0,
              &AttitudeTaskHandler);
}

void loop()
{
}