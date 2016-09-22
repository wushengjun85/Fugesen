#include "timesetuptrue.h"
#include "ui_timesetuptrue.h"


QString lsdate;
QString timeStr;


TimesetupTrue::TimesetupTrue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TimesetupTrue)
{
    ui->setupUi(this);

    TimesetupTrue::move(0,0);//回到原来主窗口的位置
    setWindowFlags(windowFlags()|Qt::FramelessWindowHint|Qt::WindowTitleHint);//删除 最小化、最大化、关闭按钮

    QTimer *tm_set = new QTimer(this);
   // connect(tm, SIGNAL(timeout()), this, SLOT(funsetuptime()));  //连接信号槽，定时器超时触发窗体更新
    //connect(ui->dateEdit,SIGNAL(dateChanged(QDate)),this,SLOT(funsetuptime()));


    connect(tm_set, SIGNAL(timeout()), this, SLOT(update()));  //连接信号槽，定时器超时触发窗体更新
    tm_set->start(500);

}

TimesetupTrue::~TimesetupTrue()
{
    delete ui;
}

void TimesetupTrue::on_pushButton_clicked()//返回上一界面按钮
{

// system("hwclock --hctosys");

//    QString  str1 = "date -s 06/18/2011";
//         system(str1.toLatin1().data());

//       QString  str2 = "date -s 11:06:00";
//         system(str2.toLatin1().data());


//         //强制写入到CMOS
//         system("hwclock -w");

    this->close();
}


void TimesetupTrue::paintEvent(QPaintEvent *)
{
   // QTime time = QTime::currentTime();   //获取当前的时间
    QPainter painter(this);
    QPixmap pix;
    pix.load("./imagejy/beijingtu.bmp");
    painter.drawPixmap(0,0,1024,600,pix);


    /**************************************************************************************************************/
    //显示时间 。2016.7.12
        QString timeStr1= QTime::currentTime().toString();     //绘制当前的时间
        QString dateStr1 = QDate::currentDate().toString("yyyy-MM-dd");

        ui->lcdNumber_4->display(dateStr1);//dateStr1
        ui->lcdNumber_3->display(timeStr1);
    /**************************************************************************************************************/



}

void TimesetupTrue::on_dateEdit_dateChanged(const QDate &date)
{
    lsdate = date.toString("yyyy-MM-dd");//QString "yyyy-MM-dd"
    ui->lcdNumber->display(lsdate);

}

void TimesetupTrue::on_timeEdit_timeChanged(const QTime &timed)
{
     timeStr= timed.toString();     //绘制当前的时间 QString
     ui->lcdNumber_2->display(timeStr);
}


void TimesetupTrue::on_pushButton_2_clicked()//设置
{
    QString str2 = """";
         str2 += "date -s ";
         str2 += lsdate;
         str2 += """";

         system(str2.toLatin1().data());//str1.toLatin1().data()

         QString str1 = """";
              str1 += "date -s ";
              str1 += timeStr;
              str1 += """";

              //system("clock -w");电脑上用
             // system("hwclock --hctosys");hwclock --hctosys
              system(str1.toLatin1().data());//str1.toLatin1().data()

              system("hwclock -w");//arm a7 开发板上用.命令不一样。
}
