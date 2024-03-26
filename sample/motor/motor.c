#include <kernel.h>
#include <kernel_cfg.h>
#include <t_syslog.h>
#include <stdio.h>
// #include <serial/serial.h>
#include <serial2/serial.h>
#include <spike/hub/system.h>
#include <spike/pup/motor.h>
#include <spike/hub/button.h>
#include <spike/hub/bluetooth.h>
#include <spike/hub/display.h>
#include <spike/hub/imu.h>
#include <stdlib.h>
#include "motor.h"
#include <t_stdlib.h>

static inline hub_button_t hub_buttons_pressed(hub_button_t buttons)
{
  hub_button_t pressed;
  hub_button_is_pressed(&pressed);
  return pressed & buttons;
}


void main_task(intptr_t exinf) {
  int selected_mission = 0;
  int max_missions = 5;

  hub_imu_init();

  // serial_opn_por(SIO_BLUETOOTH_PORTID);
  
  while (!hub_buttons_pressed(HUB_BUTTON_BT)) {
    if (hub_buttons_pressed(HUB_BUTTON_RIGHT)) {
      while (hub_buttons_pressed(HUB_BUTTON_RIGHT)) dly_tsk(1000);
      selected_mission++;

      if (selected_mission > max_missions - 1) selected_mission = 0;
    }
    if (hub_buttons_pressed(HUB_BUTTON_LEFT)) {
      while (hub_buttons_pressed(HUB_BUTTON_LEFT)) dly_tsk(1000);
      selected_mission--;

      if (selected_mission < 0) selected_mission = max_missions - 1;
    }
    if (hub_buttons_pressed(HUB_BUTTON_CENTER)) {
      while (hub_buttons_pressed(HUB_BUTTON_CENTER)) dly_tsk(1000);
      switch(selected_mission) {
        case 1:
          // m1(); 
          break;
      }
    }
    float acc[3];
    hub_imu_get_acceleration(acc);

    float vel[3];
    hub_imu_get_angular_velocity(vel);

    syslog(LOG_NOTICE, "Acceleration: %f, %f, %f", acc[0], acc[1], acc[2]);
    syslog(LOG_NOTICE, "Velocity: %f, %f, %f\n", vel[0], vel[1], vel[2]);

    hub_display_char(selected_mission+1+'0');

    dly_tsk(3*1000*1000);
  }

  // pbio_error_t err;
  // pup_motor_t *motor;
  
  // dly_tsk(3*1000*1000);

  // syslog(LOG_NOTICE, "Set Up Motor\n");

  // motor = pup_motor_get_device(PBIO_PORT_ID_A);
  // if(motor == NULL) {
  //   hub_system_shutdown();
  // }
  
  // bool reset_count = true;
  // err = pup_motor_setup(motor, PUP_DIRECTION_CLOCKWISE, reset_count);
  // if(motor == NULL) {
  //   hub_system_shutdown();
  // }
  
  // err = pup_motor_set_speed(motor, 300);
  // if (err != PBIO_SUCCESS) {
  //   hub_system_shutdown();
  // }
  // dly_tsk(3*1000*1000);

  // hub_system_shutdown();
}