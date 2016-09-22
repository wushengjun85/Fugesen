#include "timesetup.h"
#include "ui_timesetup.h"
#include<QTime>
#include<QTimer>
#include<QDebug>
#include<QPainter>
#include<QString>

#include<QtSql>
#include<QTextCodec>

int ele0;
bool flag_bjd = true;
bool flag_bjd2 = true;

bool flag_sz = true;

uint bjd[8] = {0}; //保存风机，复托器，升运器，等转速

uint kaku = 0;
uint kaku2 = 0;
bool flagjiajia = true;
int startflag = 0;


uchar duanlu_tlgt = 0;
uchar duanlu_qsq = 0;
uchar duanlu_fj = 0;
uchar duanlu_ftq = 0;
uchar duanlu_syq = 0;
uchar duanlu_gq = 0;
uchar duanlu_fl = 0;

uchar kailu_tlgt = 0;
uchar kailu_qsq = 0;
uchar kailu_fj = 0;
uchar kailu_ftq = 0;
uchar kailu_syq = 0;
uchar kailu_gq = 0;
uchar kailu_fl = 0;


int  tuoliguntong_zs = 80; //脱离滚筒转速
int fenliguntong_zs = 80;//分离滚筒
int fj_zs = 80;//风机
int ftq_zs = 80;//复脱器
int syq_zs = 80; //升运器
int qsq_zs = 80; //切碎器
int gq_zs = 80;//过桥转速



int kaku_tlgt;//脱离滚筒转速
int kaku_flgt;//分离滚筒
int kaku_fj;//风机
int kaku_ftq;//复脱器
int kaku_syq;//升运器
int kaku_qsq;//切碎器
int kaku_gqzs;//过桥转速


int ka_tlgt;//脱离滚筒转速
int ka_flgt;//分离滚筒
int ka_fj;//风机
int ka_ftq;//复脱器
int ka_syq;//升运器
int ka_qsq;//切碎器
int ka_gqzs;//过桥转速



//
extern ushort  qiesuiqizhuansu;//切碎器转速
extern ushort fengjizhuansu;//风机转速
extern ushort guoqiaozhuansu;//过桥转速；

extern ushort tuoliguntong;//脱粒滚筒转速
extern ushort fenliguntong;//分离滚筒转速

extern ushort  shengyunqi;    //升运器
extern ushort  futuoqi;       //复脱器
//extern ushort  zhouliuguntong;//轴流滚筒

Timesetup::Timesetup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Timesetup)
{
    ui->setupUi(this);

    Timesetup::move(0,0);//回到原来主窗口的位置
    setWindowFlags(windowFlags()|Qt::FramelessWindowHint|Qt::WindowTitleHint);//删除 最小化、最大化、关闭按钮

    time_timeset = new TimesetupTrue();


    QTimer *tm = new QTimer(this);

    connect(tm, SIGNAL(timeout()), this, SLOT(update()));  //连接信号槽，定时器超时触发窗体更新

    tm->start(500);


}

Timesetup::~Timesetup()
{
    delete ui;
}


void Timesetup::paintEvent(QPaintEvent *)
{
    //QTime time = QTime::currentTime();   //获取当前的时间

    QPainter painter(this);
    QPixmap pix;
    pix.load("./imagejy/zw/setup.bmp");
    painter.drawPixmap(0,0,1024,600,pix);

    /**************************************************************************************************************/
    //显示时间 。2016.7.12
        QString timeStr1= QTime::currentTime().toString();     //绘制当前的时间
        QString dateStr1 = QDate::currentDate().toString("yyyy-MM-dd");

        ui->lcdNumber_2->display(dateStr1);//dateStr1
        ui->lcdNumber->display(timeStr1);
    /**************************************************************************************************************/

        QPainter painterDuanl(this);
        QPixmap pixDuanl;
        //duanlu = 1;

        qDebug()<<"duanlu_tlgt = "<<duanlu_tlgt<<endl;

        if(duanlu_tlgt == 2)
        {
            pixDuanl.load("./imagejy/duanlu.bmp");
            painterDuanl.drawPixmap(486,248,176,36,pixDuanl);
            ui->label->hide();
            ui->pushButton_4->hide();
            ui->pushButton_5->hide();
        }
        else if(duanlu_tlgt == 1)
        {
            pixDuanl.load("./imagejy/kailu.bmp");
            painterDuanl.drawPixmap(486,248,176,36,pixDuanl);
            ui->label->hide();
            ui->pushButton_4->hide();
            ui->pushButton_5->hide();
        }
        else if(duanlu_tlgt == 0)
        {
            ui->label->show();
            ui->pushButton_4->show();
            ui->pushButton_5->show();
        }

        //切碎器
        //duanlu_qsq = 1;

         qDebug()<<"duanlu_qsq = "<<duanlu_qsq<<endl;

        if(duanlu_qsq == 2)
        {
            pixDuanl.load("./imagejy/duanlu.bmp");
            painterDuanl.drawPixmap(486,312,176,36,pixDuanl);
            ui->label_2->hide();
            ui->pushButton_6->hide();
            ui->pushButton_7->hide();
        }
        else if(duanlu_qsq == 1)
        {
            pixDuanl.load("./imagejy/kailu.bmp");
            painterDuanl.drawPixmap(486,312,176,36,pixDuanl);
            ui->label_2->hide();
            ui->pushButton_6->hide();
            ui->pushButton_7->hide();
        }
        else if(duanlu_qsq == 0)
        {
            ui->label_2->show();
            ui->pushButton_6->show();
            ui->pushButton_7->show();
        }

        //风机转速
        //duanlu_fj = 1;
        if(duanlu_fj == 2)
        {
            pixDuanl.load("./imagejy/duanlu.bmp");
            painterDuanl.drawPixmap(486,376,176,36,pixDuanl);
            ui->label_5->hide();
            ui->pushButton_12->hide();
            ui->pushButton_13->hide();
        }
        else if(duanlu_fj == 1)
        {
            pixDuanl.load("./imagejy/kailu.bmp");
            painterDuanl.drawPixmap(486,376,176,36,pixDuanl);
            ui->label_5->hide();
            ui->pushButton_12->hide();
            ui->pushButton_13->hide();
        }
        else if(duanlu_fj == 0)
        {
            ui->label_5->show();
            ui->pushButton_12->show();
            ui->pushButton_13->show();
        }

        //复脱器堵塞转速
        //duanlu_ftq = 1;
        if(duanlu_ftq == 2)
        {
            pixDuanl.load("./imagejy/duanlu.bmp");
            painterDuanl.drawPixmap(730,180,176,36,pixDuanl);
            ui->label_7->hide();
            ui->pushButton_17->hide();
            ui->pushButton_18->hide();
        }
        else if(duanlu_ftq == 1)
        {
            pixDuanl.load("./imagejy/kailu.bmp");
            painterDuanl.drawPixmap(730,180,176,36,pixDuanl);
            ui->label_7->hide();
            ui->pushButton_17->hide();
            ui->pushButton_18->hide();
        }
        else if(duanlu_ftq == 0)
        {
            ui->label_7->show();
            ui->pushButton_17->show();
            ui->pushButton_18->show();
        }

        //升运器
        //duanlu_syq = 1;
        if(duanlu_syq == 2)
        {
            pixDuanl.load("./imagejy/duanlu.bmp");
            painterDuanl.drawPixmap(730,248,176,36,pixDuanl);
            ui->label_33->hide();
            ui->pushButton_9->hide();
            ui->pushButton_11->hide();
        }
        else if(duanlu_syq == 1)
        {
            pixDuanl.load("./imagejy/kailu.bmp");
            painterDuanl.drawPixmap(730,248,176,36,pixDuanl);
            ui->label_33->hide();
            ui->pushButton_9->hide();
            ui->pushButton_11->hide();
        }
        else if(duanlu_syq == 0)
        {
            ui->label_33->show();
            ui->pushButton_9->show();
            ui->pushButton_11->show();
        }

        //过桥
        //duanlu_gq = 1;
        if(duanlu_gq == 2)
        {
            pixDuanl.load("./imagejy/duanlu.bmp");
            painterDuanl.drawPixmap(730,312,176,36,pixDuanl);
            ui->label_4->hide();
            ui->pushButton_8->hide();
            ui->pushButton_10->hide();
        }
        else if(duanlu_gq == 1)
        {
            pixDuanl.load("./imagejy/kailu.bmp");
            painterDuanl.drawPixmap(730,312,176,36,pixDuanl);
            ui->label_4->hide();
            ui->pushButton_8->hide();
            ui->pushButton_10->hide();
        }
        else if(duanlu_gq == 0)
        {
            ui->label_4->show();
            ui->pushButton_8->show();
            ui->pushButton_10->show();
        }

        //分离滚筒
        //duanlu_fl = 1;
        if(duanlu_fl == 2)
        {
            pixDuanl.load("./imagejy/duanlu.bmp");
            painterDuanl.drawPixmap(730,375,176,36,pixDuanl);
            ui->label_6->hide();
            ui->pushButton_14->hide();
            ui->pushButton_15->hide();
        }
        else if(duanlu_fl == 1)
        {
            pixDuanl.load("./imagejy/kailu.bmp");
            painterDuanl.drawPixmap(730,375,176,36,pixDuanl);
            ui->label_6->hide();
            ui->pushButton_14->hide();
            ui->pushButton_15->hide();
        }
        else if(duanlu_fl == 0)
        {
            ui->label_6->show();
            ui->pushButton_14->show();
            ui->pushButton_15->show();
        }

        /***********************************************************************************/
        //读取报警点(报警点 == 一键设定值*打滑率)
        /***********************************************************************************/
        //读取数据库信息
        //

        //读取数据库信息
        //
        QTextCodec::setCodecForTr(QTextCodec::codecForLocale());//汉字显示

        QSqlDatabase db;
        if(QSqlDatabase::contains("qt_sql_default_connection"))
          db = QSqlDatabase::database("qt_sql_default_connection");
        else
          db = QSqlDatabase::addDatabase("QSQLITE");

       db.setDatabaseName("my5.db");
       if (!db.open())
       {
           qDebug()<<"open database failed ---"<<db.lastError().text()<<"/n";
       }
       QSqlQuery query;
    //   bool ok = query.exec("CREATE TABLE IF NOT EXISTS  myjy10 (id INTEGER PRIMARY KEY AUTOINCREMENT,"
    //                                      "name VARCHAR(20) NOT NULL,"
    //                                      "age INTEGER NULL)");
#if 0
       bool ok = query.exec("create table myjy10(id INTEGER,name varchar,age INTEGER)");
       if (ok)
       {
           qDebug()<<"ceate table partition success"<<endl;
       }
       else
       {
           qDebug()<<"ceate table partition failed"<<endl;
       }
#endif
            //query.prepare("INSERT INTO myjy10 (id, name, age) VALUES (:id, :name, :age)");

            uchar i = 0;
            query.exec("select id, name, age from myjy10");
            while (query.next())
            {

               //qDebug()<<"id("<<query.value(0).toInt()<<")  name:"<<query.value(1).toString()<<"  age:"<<query.value(2).toInt();
                //qDebug()<<query.value(2).toInt();

                bjd[i++] = query.value(2).toInt();
            }

            ka_tlgt = bjd[0];
            //qDebug()<<"kaku = "<<ka_tlgt<<endl;
            ka_qsq = bjd[1];
            ka_fj  = bjd[2];
            ka_ftq = bjd[3];
            ka_syq = bjd[4];
            ka_gqzs = bjd[5];
            ka_flgt = bjd[6];


            startflag = bjd[7];



            if (flag_bjd)
            {
                ui->label->setText(QString::number(bjd[0],10));
                ui->label_2->setText(QString::number(bjd[1],10));
                ui->label_5->setText(QString::number(bjd[2],10));
                ui->label_7->setText(QString::number(bjd[3],10));
                ui->label_33->setText(QString::number(bjd[4],10));
                ui->label_4->setText(QString::number(bjd[5],10));
                ui->label_6->setText(QString::number(bjd[6],10));


                kaku_tlgt = bjd[0];
                kaku_qsq = bjd[1];

                kaku_fj  = bjd[2];
                kaku_ftq = bjd[3];
                kaku_syq = bjd[4];
                kaku_gqzs = bjd[5];
                kaku_flgt = bjd[6];
            }
            else
            {

                 ui->label->setText(QString::number(kaku_tlgt,10));//(ui->label->text().toInt()
                 ui->label_2->setText(QString::number(kaku_qsq,10));//kaku_qsq

                 ui->label_5->setText(QString::number(kaku_fj,10));
                 ui->label_7->setText(QString::number(kaku_ftq,10));
                 ui->label_33->setText(QString::number(kaku_syq,10));

                 ui->label_4->setText(QString::number(kaku_gqzs,10));
                 ui->label_6->setText(QString::number(kaku_flgt,10));

            }

#if 0

            i = 0;
            for (i = 0; i < 7; i++)
                {
                    qDebug()<<matchine[i]<<endl;
                }
            i = 0;
#endif
            query.exec(QObject::tr("drop myjy10"));


}

void Timesetup::on_pushButton_clicked()//返回按钮 并保存打滑率的值
{


 ui->pushButton_16->setStyleSheet("QPushButton{border-image:url(./imagejy/yjsd.png);background-repeat: repeat-xy;background-position: center;background-attachment: fixed;background-clip: padding}");


    //system("rm my5.db");
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());//汉字显示

    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
      db = QSqlDatabase::database("qt_sql_default_connection");
    else
      db = QSqlDatabase::addDatabase("QSQLITE");

//   QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
   db.setDatabaseName("my5.db");
   if (!db.open())
   {
       qDebug()<<"open database failed ---"<<db.lastError().text()<<"/n";
   }
   QSqlQuery query;


#if 0
   bool ok = query.exec("create table myjy10(id INTEGER,name varchar,age INTEGER)");
   if (ok)
   {
       qDebug()<<"ceate table partition success"<<endl;
   }
   else
   {
       qDebug()<<"ceate table partition failed"<<endl;
   }
#endif
          //query.prepare("INSERT INTO myjy10 (id, name, age) VALUES (:id, :name, :age)");

          query.prepare("update myjy10 set age = :age where id = :id");

          query.bindValue(":id",1);
          //query.bindValue(":name", QObject::tr("脱粒滚筒转速"));
          query.bindValue(":age", kaku_tlgt);//ui->label->text().toInt()
          query.exec();

          query.bindValue(":id",2);
          //query.bindValue(":name", QObject::tr("切碎器转速"));
          query.bindValue(":age", kaku_qsq);//ui->label_2->text().toInt()
          query.exec();

          query.bindValue(":id",3);
          //query.bindValue(":name", QObject::tr("风机转速"));
          query.bindValue(":age", kaku_fj);//ui->label_5->text().toInt()
          query.exec();

          query.bindValue(":id",4);
          //query.bindValue(":name", QObject::tr("复脱器堵塞转速"));
          query.bindValue(":age", kaku_ftq);//ui->label_7->text().toInt()
          query.exec();

          query.bindValue(":id",5);
          //query.bindValue(":name", QObject::tr("升运器堵塞转速"));
          query.bindValue(":age", kaku_syq);//ui->label_3->text().toInt()
          query.exec();

          query.bindValue(":id",6);
          //query.bindValue(":name", QObject::tr("过桥转速"));
          query.bindValue(":age", kaku_gqzs);//ui->label_4->text().toInt()
          query.exec();

          query.bindValue(":id",7);
          //query.bindValue(":name", QObject::tr("分离滚筒转速"));
          query.bindValue(":age", kaku_flgt);//ui->label_6->text().toInt()
          query.exec();


          query.bindValue(":id",8);
          //query.bindValue(":name", QObject::tr("初始化标志"));
          query.bindValue(":age", 1);
          query.exec();

        query.exec("select id, name, age from myjy10");
        while (query.next())
        {

           qDebug()<<"id("<<query.value(0).toInt()<<")  name:"<<query.value(1).toString()<<"  age:"<<query.value(2).toInt();
        }

        query.exec(QObject::tr("drop myjy10"));

        //ui->label->setText(QString::number(bjd[0],10));

        flag_bjd = true;

        flag_bjd2 = true;

    this->close();
}

void Timesetup::on_pushButton_2_clicked() //时间设置界面按钮
{
    //this->close();
    time_timeset->show();
    time_timeset->exec();
    this->show();
}


void Timesetup::on_pushButton_16_clicked()//一键设定 最佳转速值作为参考值
{

    ui->pushButton_16->setStyleSheet("QPushButton{border-image:url(./imagejy/yjsdbh.png);background-repeat: repeat-xy;background-position: center;background-attachment: fixed;background-clip: padding}");

    //system("rm my5.db");
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());//汉字显示

    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
      db = QSqlDatabase::database("qt_sql_default_connection");
    else
      db = QSqlDatabase::addDatabase("QSQLITE");

   db.setDatabaseName("my5.db");
   if (!db.open())
   {
       qDebug()<<"open database failed ---"<<db.lastError().text()<<"/n";
   }
   QSqlQuery query;


#if 0
   bool ok = query.exec("create table bjd(id INTEGER,name varchar,age INTEGER)");
   if (ok)
   {
       qDebug()<<"ceate table partition success"<<endl;
   }
   else
   {
       qDebug()<<"ceate table partition failed"<<endl;
   }

          query.prepare("INSERT INTO bjd (id, name, age) VALUES (:id, :name, :age)");

          query.bindValue(":id",1);
          query.bindValue(":name", QObject::tr("脱粒滚筒转速"));
          query.bindValue(":age", tuoliguntong);
          query.exec();

          query.bindValue(":id",2);
          query.bindValue(":name", QObject::tr("切碎器转速"));
          query.bindValue(":age", qiesuiqizhuansu);
          query.exec();

          query.bindValue(":id",3);
          query.bindValue(":name", QObject::tr("风机转速"));
          query.bindValue(":age", fengjizhuansu);
          query.exec();

          query.bindValue(":id",4);
          query.bindValue(":name", QObject::tr("复脱器堵塞转速"));
          query.bindValue(":age", futuoqi);
          query.exec();

          query.bindValue(":id",5);
          query.bindValue(":name", QObject::tr("升运器堵塞转速"));
          query.bindValue(":age", shengyunqi);
          query.exec();

          query.bindValue(":id",6);
          query.bindValue(":name", QObject::tr("过桥转速"));
          query.bindValue(":age", guoqiaozhuansu);
          query.exec();

          query.bindValue(":id",7);
          query.bindValue(":name", QObject::tr("分离滚筒转速"));
          query.bindValue(":age", fenliguntong);
          query.exec();


          query.bindValue(":id",8);
          query.bindValue(":name", QObject::tr("初始化标志"));
          query.bindValue(":age", startflag);
          query.exec();
#endif

#if 1

          query.prepare("update bjd set age = :age where id = :id");

          //query.prepare("INSERT INTO bjd (id, name, age) VALUES (:id, :name, :age)");

          query.bindValue(":id",1);
          //query.bindValue(":name", QObject::tr("脱粒滚筒转速"));
          query.bindValue(":age", tuoliguntong);
          query.exec();

          query.bindValue(":id",2);
          //query.bindValue(":name", QObject::tr("切碎器转速"));
          query.bindValue(":age", qiesuiqizhuansu);
          query.exec();

          query.bindValue(":id",3);
          //query.bindValue(":name", QObject::tr("风机转速"));
          query.bindValue(":age", fengjizhuansu);
          query.exec();

          query.bindValue(":id",4);
          //query.bindValue(":name", QObject::tr("复脱器堵塞转速"));
          query.bindValue(":age", futuoqi);
          query.exec();

          query.bindValue(":id",5);
          //query.bindValue(":name", QObject::tr("升运器堵塞转速"));
          query.bindValue(":age", shengyunqi);
          query.exec();

          query.bindValue(":id",6);
          //query.bindValue(":name", QObject::tr("过桥转速"));
          query.bindValue(":age", guoqiaozhuansu);
          query.exec();

          query.bindValue(":id",7);
          //query.bindValue(":name", QObject::tr("分离滚筒转速"));
          query.bindValue(":age", fenliguntong);
          query.exec();


          query.bindValue(":id",8);
          //query.bindValue(":name", QObject::tr("初始化标志"));
          query.bindValue(":age", startflag);
          query.exec();



#endif






        query.exec("select id, name, age from bjd");
        while (query.next())
        {

           qDebug()<<"id("<<query.value(0).toInt()<<")  name:"<<query.value(1).toString()<<"  age:"<<query.value(2).toInt();
        }

        query.exec(QObject::tr("drop bjd"));
}


void Timesetup::on_pushButton_5_clicked()//脱粒滚筒转速 - 号
{
    if(startflag==0)
    {

        flag_bjd = false;
        tuoliguntong_zs--;
        ui->label->setText(QString::number(tuoliguntong_zs,10));
        kaku_tlgt = tuoliguntong_zs;
        startflag = 1;
    }
    else
    {
        flag_bjd = false;
        if(flagjiajia)//承上启下作用标志
        {
             ka_tlgt--;
             kaku_tlgt = ka_tlgt;
            flagjiajia = false;
        }
        else
        {
            kaku_tlgt--;
        }


        ui->label->setText(QString::number(kaku_tlgt,10));

        //qDebug()<<"flag_tlgt--"<<kaku_tlgt<<endl;
    }

}

void Timesetup::on_pushButton_4_clicked()//脱粒滚筒转速 + 号
{

    if(startflag==0)
    {

        flag_bjd = false;
        tuoliguntong_zs++;
        ui->label->setText(QString::number(tuoliguntong_zs,10));
        kaku_tlgt = tuoliguntong_zs;
        startflag = 1;
    }
    else
    {
        flag_bjd = false;

        if(flagjiajia)//承上启下作用标志
        {
             ka_tlgt++;
             kaku_tlgt = ka_tlgt;
            flagjiajia = false;
        }
        else
        {
            kaku_tlgt++;
        }

        ui->label->setText(QString::number(kaku_tlgt,10));



        //qDebug()<<"flag_tlgt"<<kaku_tlgt<<endl;
    }


}

void Timesetup::on_pushButton_7_clicked()//切碎器转速 - 号
{

    if(startflag==0)
    {

        flag_bjd = false;
        qsq_zs--;
        ui->label_2->setText(QString::number(qsq_zs,10));
        kaku_qsq = qsq_zs;
        startflag = 1;
    }
    else
    {
        flag_bjd = false;
        if(flagjiajia)//承上启下作用标志
        {
             ka_qsq--;
             kaku_qsq = ka_qsq;
            flagjiajia = false;
        }
        else
        {
            kaku_qsq--;
        }

        ui->label_2->setText(QString::number(kaku_qsq,10));

        //qDebug()<<"kaku_qsq "<<kaku_qsq<<endl;
    }
}

void Timesetup::on_pushButton_6_clicked()//切碎器转速 + 号
{

    if(startflag==0)
    {

        flag_bjd = false;
        qsq_zs++;
        ui->label_2->setText(QString::number(qsq_zs,10));
        kaku_qsq = qsq_zs;
        startflag = 1;
    }
    else
    {
        flag_bjd = false;
        if(flagjiajia)//承上启下作用标志
        {
             ka_qsq++;
             kaku_qsq = ka_qsq;
            flagjiajia = false;
        }
        else
        {
            kaku_qsq++;
        }
        ui->label_2->setText(QString::number(kaku_qsq,10));

        //qDebug()<<"kaku_qsq"<<kaku_qsq<<endl;
    }
}

void Timesetup::on_pushButton_9_clicked()//升运器堵塞转速 -号按钮
{

    if(startflag==0)
    {

        flag_bjd = false;
        syq_zs--;
        //ui->label_33->setText(QString::number(syq_zs,10));
        ui->label_33->setText(QString::number(syq_zs,10));
        kaku_qsq = syq_zs;
        startflag = 1;
    }
    else
    {
        flag_bjd = false;
        if(flagjiajia)//承上启下作用标志
        {
             ka_syq--;
             kaku_syq = ka_syq;
            flagjiajia = false;
        }
        else
        {
            kaku_syq--;
        }
        ui->label_33->setText(QString::number(kaku_syq,10));

        //qDebug()<<"flag_123"<<kaku_syq<<endl;
    }
}



void Timesetup::on_pushButton_11_clicked()//升运器堵塞转速 +号按钮
{


    if(startflag==0)
    {

        flag_bjd = false;
        syq_zs++;
         ui->label_33->setText(QString::number(syq_zs,10));
        kaku_qsq = syq_zs;
        startflag = 1;
    }
    else
    {
        flag_bjd = false;
        if(flagjiajia)//承上启下作用标志
        {
             ka_syq++;
             kaku_syq = ka_syq;
            flagjiajia = false;
        }
        else
        {
            kaku_syq++;
        }
        ui->label_33->setText(QString::number(kaku_syq,10));

        //qDebug()<<"flag_123"<<kaku_syq<<endl;
    }
}

void Timesetup::on_pushButton_8_clicked() //过桥器转速 - 号按钮
{

    if(startflag==0)
    {

        flag_bjd = false;
        gq_zs--;
        ui->label_4->setText(QString::number(gq_zs,10));
        kaku_gqzs = gq_zs;
        startflag = 1;
    }
    else
    {
        flag_bjd = false;
        if(flagjiajia)//承上启下作用标志
        {
             ka_gqzs--;
             kaku_gqzs = ka_gqzs;
            flagjiajia = false;
        }
        else
        {
            kaku_gqzs--;
        }
        ui->label_4->setText(QString::number(kaku_gqzs,10));

        //qDebug()<<"flag_123"<<kaku_gqzs<<endl;
    }
}

void Timesetup::on_pushButton_10_clicked()//过桥器转速 + 号按钮
{


    if(startflag==0)
    {

        flag_bjd = false;
        gq_zs++;
        ui->label_4->setText(QString::number(gq_zs,10));
        kaku_gqzs = gq_zs;
        startflag = 1;
    }
    else
    {
        flag_bjd = false;
        if(flagjiajia)//承上启下作用标志
        {
             ka_gqzs++;
             kaku_gqzs = ka_gqzs;
            flagjiajia = false;
        }
        else
        {
            kaku_gqzs++;
        }
        ui->label_4->setText(QString::number(kaku_gqzs,10));

        //qDebug()<<"flag_123"<<kaku_gqzs<<endl;
    }
}



void Timesetup::on_pushButton_18_clicked()//复脱器 -号
{


    if(startflag==0)
    {

        flag_bjd = false;
        ftq_zs--;
        ui->label_7->setText(QString::number(ftq_zs,10));
        kaku_ftq = ftq_zs;
        startflag = 1;
    }
    else
    {
        flag_bjd = false;
        if(flagjiajia)//承上启下作用标志
        {
             ka_ftq--;
             kaku_ftq = ka_ftq;
            flagjiajia = false;
        }
        else
        {
            kaku_ftq--;
        }
        ui->label_7->setText(QString::number(kaku_ftq,10));

        //qDebug()<<"flag_123"<<kaku_ftq<<endl;
    }
}


void Timesetup::on_pushButton_17_clicked()//复脱器 +号
{


    if(startflag==0)
    {

        flag_bjd = false;
        ftq_zs++;
        ui->label_7->setText(QString::number(ftq_zs,10));
        kaku_ftq = ftq_zs;
        startflag = 1;
    }
    else
    {
        flag_bjd = false;
        if(flagjiajia)//承上启下作用标志
        {
             ka_ftq++;
             kaku_ftq = ka_ftq;
            flagjiajia = false;
        }
        else
        {
            kaku_ftq++;
        }
        ui->label_7->setText(QString::number(kaku_ftq,10));

        //qDebug()<<"flag_123"<<kaku_ftq<<endl;
    }
}

void Timesetup::on_pushButton_15_clicked()//分离滚筒 -号
{

    if(startflag==0)
    {

        flag_bjd = false;
        fenliguntong_zs--;
        ui->label_6->setText(QString::number(fenliguntong_zs,10));
        kaku_flgt = fenliguntong_zs;
        startflag = 1;
    }
    else
    {
        flag_bjd = false;
        if(flagjiajia)//承上启下作用标志
        {
             ka_flgt--;
             kaku_flgt = ka_flgt;
            flagjiajia = false;
        }
        else
        {
            kaku_flgt--;
        }
        ui->label_6->setText(QString::number(kaku_flgt,10));

        //qDebug()<<"flag_123"<<kaku_flgt<<endl;
    }
}

void Timesetup::on_pushButton_14_clicked()//分离滚筒 +号
{

    if(startflag==0)
    {

        flag_bjd = false;
        fenliguntong_zs++;
        ui->label_6->setText(QString::number(fenliguntong_zs,10));
        kaku_flgt = fenliguntong_zs;
        startflag = 1;
    }
    else
    {
        flag_bjd = false;
        if(flagjiajia)//承上启下作用标志
        {
             ka_flgt++;
             kaku_flgt = ka_flgt;
            flagjiajia = false;
        }
        else
        {
            kaku_flgt++;
        }
        ui->label_6->setText(QString::number(kaku_flgt,10));

        //qDebug()<<"flag_123"<<kaku_flgt<<endl;
    }
}

void Timesetup::on_pushButton_12_clicked()//风机转速 -号
{

    if(startflag==0)
    {

        flag_bjd = false;
        fj_zs--;
        ui->label_5->setText(QString::number(fj_zs,10));
        kaku_fj = fj_zs;
        startflag = 1;
    }
    else
    {
        flag_bjd = false;
        if(flagjiajia)//承上启下作用标志
        {
             ka_fj--;
             kaku_fj = ka_fj;
            flagjiajia = false;
        }
        else
        {
            kaku_fj--;
        }
        ui->label_5->setText(QString::number(kaku_fj,10));

        //qDebug()<<"flag_123"<<kaku_fj<<endl;
    }
}

void Timesetup::on_pushButton_13_clicked()//风机转速 +号
{

    if(startflag==0)
    {

        flag_bjd = false;
        fj_zs++;
        ui->label_5->setText(QString::number(fj_zs,10));
        kaku_fj = fj_zs;
        startflag = 1;
    }
    else
    {
        flag_bjd = false;
        if(flagjiajia)//承上启下作用标志
        {
             ka_fj++;
             kaku_fj = ka_fj;
            flagjiajia = false;
        }
        else
        {
            kaku_fj++;
        }
        ui->label_5->setText(QString::number(kaku_fj,10));

        //qDebug()<<"flag_123"<<kaku_fj<<endl;
    }
}
