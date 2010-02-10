#include <QtGui/QApplication>
#include "simpoi_window.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SimpoiWindow w;
    w.show();

    return a.exec();
}
