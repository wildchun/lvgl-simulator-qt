//
// Created by Administrator on 2024/3/11/011.
//

#ifndef LVGL_SIMULATOR_QT_LVGLSCREEN_H
#define LVGL_SIMULATOR_QT_LVGLSCREEN_H

#include <QObject>
#include <QImage>
#include "lv_conf.h"
#include "lvgl.h"
#include "LvglScreenWrapper.h"

class LvglScreen : public QObject {
Q_OBJECT
protected:
    void timerEvent(QTimerEvent *event) override;
public:
    static LvglScreen *getInstance();

    LvglScreen();

    void setSize(int width, int height);
    void drawArea(int x1, int y1, int x2, int y2, const uint8_t *px_map);
    void drawArea(const LvglArea *area, const uint8_t *px_map);
    void getIndevData(lv_indev_data_t *data);
    const QImage &getImage() const;

    void start();

Q_SIGNALS:
    void lvglScreenUpdate();


public slots:
    void mousePressState(bool isPressed);
    void mouseMoveEvent(int x, int y);

private:
    QImage mImage;
    int mLvglTickTimer{0};
    int mLvglTimerHandlerTimer{0};
    lv_indev_data_t mIndevData;
};


#endif //LVGL_SIMULATOR_QT_LVGLSCREEN_H
