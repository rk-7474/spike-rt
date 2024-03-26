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
}
