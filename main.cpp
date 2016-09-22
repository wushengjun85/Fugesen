#include <QtGui/QApplication>
#include "widget.h"
#include <QTextCodec>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
   // QApplication::setOverrideCursor(Qt::BlankCursor);//隐藏鼠标 光标
    
    return a.exec();
}
