//
// Created by Administrator on 2024/3/11/011.
//

#ifndef LVGL_SIMULATOR_QT_SCREENWIDGET_H
#define LVGL_SIMULATOR_QT_SCREENWIDGET_H

#include <QWidget>

class ScreenWidget : public QWidget {
Q_OBJECT
protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
private slots:
    void lvglScreenUpdate();
public:
    explicit ScreenWidget(QWidget *parent = nullptr);
};


#endif //LVGL_SIMULATOR_QT_SCREENWIDGET_H
