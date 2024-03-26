#include <spike/hub/imu.h>
#include <pthread.h> 
#include <stdbool.h>

#define IMU_ERROR 500.0
#define DELTA_TIME 1000

static float imu_heading = 0.0;

void *gyro_thread() 
{ 
    float ang_speed_vec[3];

    int dt = DELTA_TIME / 1000;

    while (true) {
        hub_imu_get_angular_velocity(&ang_speed_vec);
        
        float rot_speed = ang_speed_vec[0];

        imu_heading += (rot_speed - IMU_ERROR) * dt;
    }

    return NULL; 
}

void gyro_init() {
    hub_imu_init();

    pthread_t thread_id; 
    pthread_create(&thread_id, NULL, gyro_thread, NULL); 
}

float gyro_heading() {
    return imu_heading;
}

void gyro_reset() {
    imu_heading = 0.0;
}