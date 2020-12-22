#include "attitude.hpp"

MPU9250 imu_attitude(Wire, 0x68);
float orientation[3];

void setupAttitudeImu()
{
    int status = imu_attitude.begin();
    if (status < 0)
    {
        Serial.println("Attitude: IMU initialization unsuccessful");
        Serial.println("Attitude: Check IMU wiring or try cycling power");
        Serial.print("Attitude: Status ");
        Serial.println(status);
        while (1)
        {
        }
    }
    imu_attitude.setAccelRange(MPU9250::ACCEL_RANGE_8G);
    imu_attitude.setGyroRange(MPU9250::GYRO_RANGE_500DPS);
    imu_attitude.setDlpfBandwidth(MPU9250::DLPF_BANDWIDTH_20HZ);
    imu_attitude.setSrd(19);
}

float* getOrientation() {
    return orientation;
}

void AttitudeTask(void *pvParameters)
{
    setupAttitudeImu();
    for (;;)
    {
        imu_attitude.readSensor();
        getOrientation(orientation, imu_attitude.getAccelX_mss(), imu_attitude.getAccelY_mss(), imu_attitude.getAccelZ_mss(), imu_attitude.getGyroX_rads(), imu_attitude.getGyroY_rads(), imu_attitude.getGyroZ_rads(), imu_attitude.getMagX_uT(), imu_attitude.getMagY_uT(), imu_attitude.getMagZ_uT());
    }
}