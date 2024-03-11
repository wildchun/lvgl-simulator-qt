//
// Created by Administrator on 2024/3/11/011.
//

#include "ScreenWidget.h"

#include "LvglScreen.h"

#include <QPainter>
#include <QDebug>
#include <QMouseEvent>

ScreenWidget::ScreenWidget(QWidget *parent) : QWidget(parent) {
    QObject::connect(LvglScreen::getInstance(), &LvglScreen::lvglScreenUpdate,
                     this, &ScreenWidget::lvglScreenUpdate,
                     Qt::QueuedConnection);
    //允许鼠标
    setMouseTracking(true);
    LvglScreen::getInstance()->start();
}

void ScreenWidget::paintEvent(QPaintEvent *event) {
    QWidget::paintEvent(event);
    QPainter painter(this);
    auto image = LvglScreen::getInstance()->getImage();
    painter.drawImage(0, 0, image);

    if (image.width() != width() || image.height() != height()) {
        setFixedSize(image.width(), image.height());
    }
}

void ScreenWidget::lvglScreenUpdate() {
    update();
}

void ScreenWidget::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        LvglScreen::getInstance()->mousePressState(true);
    }
    QWidget::mousePressEvent(event);
}

void ScreenWidget::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        LvglScreen::getInstance()->mousePressState(false);
    }
    QWidget::mouseReleaseEvent(event);
}

void ScreenWidget::mouseMoveEvent(QMouseEvent *event) {
    LvglScreen::getInstance()->mouseMoveEvent(event->x(), event->y());
    QWidget::mouseMoveEvent(event);
}



