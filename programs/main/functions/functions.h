#include <spike/pup/motor.h>

void setup_single_motor(pup_motor_t *motor, int power, int port);

void setup_motors(pup_motor_t *motor_a, pup_motor_t *motor_b, int power_a, int power_b);

void setup_motors_power(pup_motor_t *motor_a, pup_motor_t *motor_b, int power_a, int power_b);

void setup_motors_speed(pup_motor_t *motor_a, pup_motor_t *motor_b, int speed_a, int speed_b);

float get_distance(pup_motor_t *motor);

void brake_pair(pup_motor_t *motor_a, pup_motor_t *motor_b);

void move_dist(int power, float distance);

void move_time(int power, float time);

void turn_degrees(int power_a, int power_b, float target);

void turn_time(int power_a, int power_b, float time);

void rotate_top(char side, int angle, int speed);