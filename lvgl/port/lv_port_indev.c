/**
 * @file lv_port_indev_templ.c
 *
 */

/*Copy this file as "lv_port_indev.c" and set this value to "1" to enable content*/
#if 1

#include "lv_port_indev.h"
#include "LvglScreenWrapper.h"

static void mouse_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data);

static lv_indev_drv_t indev_drv;
static lv_indev_t *indev_mouse;

void lv_port_indev_init(void) {


    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = mouse_read;
    indev_mouse = lv_indev_drv_register(&indev_drv);

    lv_obj_t *mouse_cursor = lv_img_create(lv_scr_act());
    lv_img_set_src(mouse_cursor, LV_SYMBOL_HOME);
    lv_indev_set_cursor(indev_mouse, mouse_cursor);

}

/*Will be called by the library to read the mouse*/
static void mouse_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data) {
    wrapper_getIndevData(data);
}

#else /*Enable this file at the top*/

/*This dummy typedef exists purely to silence -Wpedantic.*/
typedef int keep_pedantic_happy;
#endif
