#include <QtWidgets/QtWidgets>
#include "mainwidget.h"

int main(int argc, char *argv[])
{
    // Creates an instance of QApplication
    QApplication a(argc, argv);

    MainWidget w = MainWidget();
    w.show(); // Show main window

    // run the application and return execs() return value/code
    return a.exec();
}