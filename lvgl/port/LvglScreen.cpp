//
// Created by Administrator on 2024/3/11/011.
//

#include "LvglScreen.h"
#include "lvgl.h"
#include "lv_port_disp.h"
#include "lv_port_indev.h"

#include <QDebug>
#include <QMouseEvent>
#include <QTimerEvent>

Q_GLOBAL_STATIC(LvglScreen, lvglScreen)

LvglScreen *LvglScreen::getInstance() {
    return lvglScreen();
}

LvglScreen::LvglScreen() = default;

void LvglScreen::setSize(int width, int height) {
    mImage = QImage(width, height, QImage::Format_RGB32);
    mImage.fill(Qt::white);
    qDebug() << "LvglScreen::setSize" << width << height;
}

void LvglScreen::drawArea(int x1, int y1, int x2, int y2, const uint8_t *px_map) {
    for (int y = y1; y <= y2; y++) {
        for (int x = x1; x <= x2; x++) {
            mImage.setPixel(x, y, qRgb(px_map[0], px_map[1], px_map[2]));
            px_map += 3;
        }
    }
    qDebug() << "LvglScreen::drawArea" << x1 << y1 << x2 << y2;
    emit lvglScreenUpdate();
}

#define RGB565_RED      0xf800        //1111 1000 0000 0000 | 0000 0000 1111 1000
#define RGB565_GREEN    0x07e0        //0000 0111 1110 0000 | 0000 0000 1111 1100
#define RGB565_BLUE     0x001f        //0000 0000 0001 1111 | 0000 0000 1111 1000

void LvglScreen::drawArea(const LvglArea *area, const uint8_t *px_map) {
    uint16_t *buf16 = (uint16_t *) px_map; /*Let's say it's a 16 bit (RGB565) display*/
    for (int32_t y = area->y1; y <= area->y2; y++) {
        for (int32_t x = area->x1; x <= area->x2; x++) {
            mImage.setPixel(x, y, qRgb(((*buf16) & RGB565_RED) >> 8, ((*buf16) & RGB565_GREEN) >> 3,
                                       ((*buf16) & RGB565_BLUE) << 3));
            buf16++;
        }
    }
    emit lvglScreenUpdate();
    qDebug() << "ScreenWidget::paintEvent";
}

const QImage &LvglScreen::getImage() const {
    return mImage;
}

void LvglScreen::start() {
    if (mLvglTickTimer != 0 || mLvglTimerHandlerTimer != 0) {
        return;
    }
    mLvglTickTimer = startTimer(1, Qt::PreciseTimer);
    mLvglTimerHandlerTimer = startTimer(20, Qt::PreciseTimer);
    lv_init();                  // lvgl初始化，如果这个没有初始化，那么下面的初始化会崩溃
    lv_port_disp_init();        // 显示器初始化
    lv_port_indev_init();       // 输入设备初始化


    // fill white
    lv_obj_t *obj1;
    obj1 = lv_obj_create(lv_scr_act());
    lv_obj_set_size(obj1, 100, 50);
    lv_obj_align(obj1, LV_ALIGN_CENTER, -60, -30);

    static lv_style_t style_shadow;
    lv_style_init(&style_shadow);
    lv_style_set_shadow_width(&style_shadow, 10);
    lv_style_set_shadow_spread(&style_shadow, 5);
    lv_style_set_shadow_color(&style_shadow, lv_palette_main(LV_PALETTE_BLUE));

    lv_obj_t *obj2;
    obj2 = lv_obj_create(lv_scr_act());
    lv_obj_add_style(obj2, &style_shadow, 0);
    lv_obj_align(obj2, LV_ALIGN_CENTER, 60, 30);


}

void LvglScreen::timerEvent(QTimerEvent *event) {
    if (event->timerId() == mLvglTickTimer) {
        lv_tick_inc(1);
    } else if (event->timerId() == mLvglTimerHandlerTimer) {
        lv_timer_handler();
    }
}

void LvglScreen::mousePressState(bool isPressed) {
    mIndevData.state = isPressed ? LV_INDEV_STATE_PRESSED : LV_INDEV_STATE_RELEASED;
}

void LvglScreen::mouseMoveEvent(int x, int y) {
    mIndevData.point.x = (lv_coord_t)x;
    mIndevData.point.y = (lv_coord_t)y;
}

void LvglScreen::getIndevData(lv_indev_data_t *data) {
    *data = mIndevData;
}







