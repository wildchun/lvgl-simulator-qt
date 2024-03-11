//
// Created by Administrator on 2024/3/11/011.
//


#include <QApplication>
#include "ScreenWidget.h"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    ScreenWidget widget;
    widget.show();
    return QApplication::exec();
}

