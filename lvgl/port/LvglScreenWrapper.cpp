//
// Created by Administrator on 2024/3/11/011.
//

#include "LvglScreenWrapper.h"

#include "LvglScreen.h"

#ifdef __cplusplus
extern "C" {
#endif
void wrapper_setScreenSetSize(int width, int height) {
    LvglScreen::getInstance()->setSize(width, height);
}
#ifdef __cplusplus
}

void wrapper_drawArea(LvglArea *area, uint8_t *px_map) {
    LvglScreen::getInstance()->drawArea(area, px_map);
}

void wrapper_getIndevData(lv_indev_data_t *data) {
    LvglScreen::getInstance()->getIndevData(data);
}

#endif
