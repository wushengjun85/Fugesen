#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"work.h"

#include"timesetup.h"
#include"findlook.h"
#include"signalcan.h"


#include "posix_qextserialport.h"
#include <QTimer>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    
private slots:
    void on_pushButton_timesetup_clicked();//设置按钮
    void on_ptn_back_clicked();//返回按钮

    void diplaytime();

    void on_pushButton_timesetup_2_clicked();

    void on_pushButton_timesetup_3_clicked();

    void xiaoshiji();

    void gzmslot();//故障码

    void on_pushButton_clicked();


    void readMyCom(); //读取串口 槽函数

    void on_pushButton_2_clicked();

private:
    Ui::Widget *ui;
    Work work;
    Timesetup timeObj;
    FindLook  findlook;

    //线程
    SignalCan *mycan;

    QTimer *timer_xiaoshiji;

    QTimer *timergzm;




    Posix_QextSerialPort *myCom;    //串口
    QTimer *readTimer;    //定时器

protected:
    void paintEvent(QPaintEvent *event);
};

#endif // WIDGET_H
