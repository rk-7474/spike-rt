#include <serial/serial.h>
#include <spike/pup/motor.h>

#define MOTOR_MOVE_A PBIO_PORT_ID_A
#define MOTOR_MOVE_B PBIO_PORT_ID_B
#define MOTOR_TOP_LEFT PBIO_PORT_ID_C
#define MOTOR_TOP_RIGHT PBIO_PORT_ID_D

#define WHEEL_CIRCONFERENCE 50

void setup_single_motor(pup_motor_t *motor, int power, int port) {
    motor = pup_motor_get_device(port);

    if(motor == NULL) {
        hub_system_shutdown();
    }
    
    pup_motor_setup(motor, power > 0 ? PUP_DIRECTION_CLOCKWISE : PUP_DIRECTION_COUNTERCLOCKWISE, true);
    
    if(motor == NULL) {
        hub_system_shutdown();
    }
}

void setup_motors(pup_motor_t *motor_a, pup_motor_t *motor_b, int power_a, int power_b) {
    setup_single_motor(motor_a, power_a, MOTOR_MOVE_A);
    setup_single_motor(motor_b, power_b, MOTOR_MOVE_B);
}

void setup_motors_power(pup_motor_t *motor_a, pup_motor_t *motor_b, int power_a, int power_b) {
    pbio_error_t err1, err2;

    setup_motors(motor_a, motor_b, power_a, power_b);
    
    err1 = pup_motor_set_power(motor_a, power_a < 0 ? power_a * -1 : power_a);
    err2 = pup_motor_set_power(motor_b, power_a < 0 ? power_b * -1 : power_b);

    if (err1 != PBIO_SUCCESS && err2 != PBIO_SUCCESS) {
        hub_system_shutdown();
    }
}

void setup_motors_speed(pup_motor_t *motor_a, pup_motor_t *motor_b, int speed_a, int speed_b) {
    pbio_error_t err1, err2;

    setup_motors(motor_a, motor_b, speed_a, speed_b);

    err1 = pup_motor_set_speed(motor_a, speed_a < 0 ? speed_a * -1 : speed_a);
    err2 = pup_motor_set_speed(motor_b, speed_b < 0 ? speed_b * -1 : speed_b);

    if (err1 != PBIO_SUCCESS && err2 != PBIO_SUCCESS) {
        hub_system_shutdown();
    }
}

float get_distance(pup_motor_t *motor) {
    int32_t degree_distance = pup_motor_get_count(motor);

    float distance = degree_distance * WHEEL_CIRCONFERENCE / 360.0;

    return distance;
}

void brake_pair(pup_motor_t *motor_a, pup_motor_t *motor_b) {
    pup_motor_brake(motor_a);
    pup_motor_brake(motor_b);
}

void move_dist(int power, float distance) {
    pup_motor_t *motor_a, *motor_b;

    setup_motors_power(motor_a, motor_b, power, power);

    while (get_distance(motor_a) < distance) dly_tsk(1000);

    brake_pair(motor_a, motor_b);
}

void move_time(int power, float time) {
    pup_motor_t *motor_a, *motor_b;

    setup_motors_power(motor_a, motor_b, power, power);

    int elapsed = 0;

    do {
        dly_tsk(1000);
        elapsed += 1;
    } while (elapsed < time);

    brake_pair(motor_a, motor_b);
}

void turn_degrees(int power_a, int power_b, float target) {
    pup_motor_t *motor_a, *motor_b;

    setup_motors_power(motor_a, motor_b, power_a, power_b);

    float start_angle = gyro_heading();

    do dly_tsk(1000); 
    while ((start_angle < target && gyro_heading() < target) || (start_angle > target && gyro_heading() > target));

    brake_pair(motor_a, motor_b);
}

void turn_time(int power_a, int power_b, float time) {
    pup_motor_t *motor_a, *motor_b;

    setup_motors_power(motor_a, motor_b, power_a, power_b);

    int elapsed = 0;

    do {
        dly_tsk(1000);
        elapsed += 1;
    } while (elapsed < time);

    brake_pair(motor_a, motor_b);
}


void rotate_top(char side, int angle, int speed) {
    pup_motor_t *motor;

    setup_single_motor(motor, speed, side == 'R' ? MOTOR_TOP_RIGHT : MOTOR_TOP_LEFT);

    float time = (angle / speed) * 1000; 

    int elapsed = 0;

    do {
        dly_tsk(1000);
        elapsed += 1;
    } while (elapsed < time);

    pup_motor_brake(motor);
}
