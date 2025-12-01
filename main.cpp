#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Apply dark theme stylesheet
    a.setStyleSheet(
        "QMainWindow, QWidget {"
        "    background-color: #2d2d2d;"
        "    color: #ffffff;"
        "}"
        "QMenuBar {"
        "    background-color: #3d3d3d;"
        "    color: #ffffff;"
        "}"
        "QMenuBar::item {"
        "    background-color: #3d3d3d;"
        "    color: #ffffff;"
        "}"
        "QMenuBar::item:selected {"
        "    background-color: #505050;"
        "}"
        "QMenu {"
        "    background-color: #3d3d3d;"
        "    color: #ffffff;"
        "    border: 1px solid #505050;"
        "}"
        "QMenu::item:selected {"
        "    background-color: #505050;"
        "}"
        "QStatusBar {"
        "    background-color: #3d3d3d;"
        "    color: #ffffff;"
        "}"
    );

    MainWindow w;
    w.show();
    return a.exec();
}
