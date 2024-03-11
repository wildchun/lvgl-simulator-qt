//
// Created by Administrator on 2024/3/11/011.
//

#ifndef LVGL_SIMULATOR_QT_LVGLSCREENWRAPPER_H
#define LVGL_SIMULATOR_QT_LVGLSCREENWRAPPER_H



#ifdef __cplusplus
extern "C" {
#endif
#include "lv_conf.h"
#include "lvgl.h"
#include <stdint.h>
typedef struct {
    int32_t x1;
    int32_t y1;
    int32_t x2;
    int32_t y2;
} LvglArea;


void wrapper_setScreenSetSize(int width, int height);
void wrapper_drawArea(LvglArea *area, uint8_t *px_map);
void wrapper_getIndevData(lv_indev_data_t *data);

#ifdef __cplusplus
}
#endif


#endif //LVGL_SIMULATOR_QT_LVGLSCREENWRAPPER_H
