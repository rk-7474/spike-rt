#include <spike/hub/button.h>
#include <spike/hub/display.h>

#include "menu.h"

void open_menu() {
    int selected_mission = 0;
    int max_missions = 5;

    while (!hub_button_is_pressed(HUB_BUTTON_BT)) {
        
        if (hub_button_is_pressed(HUB_BUTTON_RIGHT)) {
            while (hub_button_is_pressed(HUB_BUTTON_RIGHT)) dly_tsk(1000);
            selected_mission++;

            if (selected_mission > max_missions) selected_mission = 0;
        }

        if (hub_button_is_pressed(HUB_BUTTON_RIGHT)) {
            while (hub_button_is_pressed(HUB_BUTTON_RIGHT)) dly_tsk(1000);
            selected_mission--;

            if (selected_mission < 0) selected_mission = max_missions;
        }

        if (hub_button_is_pressed(HUB_BUTTON_CENTER)) {
            while (hub_button_is_pressed(HUB_BUTTON_CENTER)) dly_tsk(1000);

            switch (selected_mission+1) {
                case 1:
                    m1();
                    break;
            }
        }

        hub_display_number(selected_mission);

    }
}