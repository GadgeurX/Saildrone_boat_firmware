#include "wind.hpp"

MPU9250 imu_wind(Wire, 0x69);
float direction;

void setupWindImu()
{
    int status = imu_wind.begin();
    if (status < 0)
    {
        Serial.println("Wind: IMU initialization unsuccessful");
        Serial.println("Wind: Check IMU wiring or try cycling power");
        Serial.print("Wind: Status ");
        Serial.println(status);
        while (1)
        {
        }
    }
    imu_wind.setAccelRange(MPU9250::ACCEL_RANGE_8G);
    imu_wind.setGyroRange(MPU9250::GYRO_RANGE_500DPS);
    imu_wind.setDlpfBandwidth(MPU9250::DLPF_BANDWIDTH_20HZ);
    imu_wind.setSrd(19);
}

float getWindDirection() {
    return direction;
}

void WindTask(void *pvParameters)
{
    setupWindImu();
    for (;;)
    {
        imu_wind.readSensor();
        direction = imu_wind.getMagX_uT();
    }
}