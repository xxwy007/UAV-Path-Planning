#include "view/arrShow.h"
#include "view/mapSelect.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    readXML();
    QApplication a(argc, argv);
	arrShow w;
    w.setWindowFlags(w.windowFlags() & ~Qt::WindowMaximizeButtonHint);
    w.setFixedSize(w.width(),w.height());
	w.show();
    return a.exec();
}
