/*#include <QApplication>
#include <QWidget>

int main(int argc, char** argv) {
    QApplication app(argc, argv);

    QWidget widget;
    widget.setFixedSize(QSize(600, 400));
    widget.show();

    return QApplication::exec();
}*/
#include "window.h"

int main(int argc, char** argv) {
    QApplication app(argc, argv);


    Window window;
    window.show();

    return QApplication::exec();
}