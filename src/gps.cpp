#include "gps.hpp"

float position[2];

float* getPosition() {
    return position;
}

void GpsTask(void * pvParameters) {
    Serial2.begin(9600);
    TinyGPS gps;
    for(;;) {
        if(Serial2.available()) {
            gps.encode(Serial2.read());
            gps.f_get_position(position, position + 1);
        }
    }
}