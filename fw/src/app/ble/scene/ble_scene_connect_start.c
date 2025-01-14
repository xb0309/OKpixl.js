#include "ble_scene.h"
#include "app_ble.h"
#include "ble_main.h"
#include "ble_status_view.h"

#include "mini_app_launcher.h"
#include "mini_app_registry.h"


void ble_scene_connect_status_view_event_cb(ble_status_view_event_t event, ble_status_view_t *p_view){
    ble_disable();
    mini_app_launcher_kill(mini_app_launcher(), MINI_APP_ID_BLE);
}


void ble_scene_connect_start_on_enter(void *user_data) {
    app_ble_t *app = user_data;

    ble_init();
    ble_get_addr_str(ble_status_view_get_ble_addr(app->p_ble_view));
    ble_status_view_set_event_cb(app->p_ble_view, ble_scene_connect_status_view_event_cb);
    mui_view_dispatcher_switch_to_view(app->p_view_dispatcher, BLE_VIEW_ID_MAIN);
}

void ble_scene_connect_start_on_exit(void *user_data) {

    app_ble_t *app = user_data;
    
}