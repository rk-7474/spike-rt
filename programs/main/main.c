#include <kernel.h>
#include <kernel_cfg.h>
#include <t_syslog.h>
#include <stdio.h>
#include <serial/serial.h>
#include <spike/hub/system.h>
#include <spike/pup/motor.h>
#include <spike/hub/button.h>
#include <spike/hub/display.h>
#include "main.h"
#include "menu/menu.h"

void main_task(intptr_t exinf) {
  gyro_init();

  open_menu();
  

  // pbio_error_t err;
  // pup_motor_t *motor;
  
  // dly_tsk(3*1000*1000);


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
