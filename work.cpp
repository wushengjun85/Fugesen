#include "work.h"
#include "ui_work.h"

#include<QMouseEvent>
#include<QPainter>
#include<QString>
#include<QTime>
#include<QTimer>
#include<QDebug>

#include"camera_thread.h"
#include"hwlib/libdev.h"
#include <QtSql>
#include <QTextCodec>

/***************************************************************************************************************/
//2016.8.11  变量定义
//bool flaglanguage = false; //中英文切换标志变量。

//uchar numtmp = 0; //临时 测试所用。

extern  bool beep_flag;// 蜂鸣器标志

extern uchar fmiArry[4];
extern ulong  spnArry[4];

extern uchar gzm_count;

bool flagqh2 = false;//切换标志位
bool BH = false;

bool BH2 = false;

extern int   can_retern; // can_return = ret //返回can 读取的数据

extern uchar btn;// 记录手柄按下次数
//uchar wzxx2 = 0;//位置信息，记录所在位置


float lsls0 = 0.0;
float lsls1 = 0.0;
float lsls2 = 0.0;
float lsls3 = 0.0;
float lsls4 = 0.0;
float lsls5 = 0.0;
float lsls6 = 0.0;

int ruby[7] = {0};

uint matchine[7] = {0}; //保存风机，复托器，升运器，等转速 的百分比

uint bjd_array[7] = {0}; //保存风机，复托器，升运器，等转速



extern float jiyouwendu;//机油温度

extern float xiaoshiJi_h;//小时计

uchar j_w;
uchar jflag_w;
ushort mm_w;
uchar jjjflag_w;
ushort  mybufflag_w[312];//15
ushort  myindex_w[312];//15


unsigned char  countBuff_w = 0;

//uint wsj2 = 0;

extern bool beep_widget;



//18FECA00
//故障报文
//ulong guzhangbaowen; //故障报文
extern ulong  spn;//spn 码
extern uchar fmi;//fmi 码

extern ulong  spn2;//spn 码
extern uchar fmi2;//fmi 码

extern ulong  spn3;//spn 码
extern uchar fmi3;//fmi 码

extern ulong  spn4;//spn 码
extern uchar fmi4;//fmi 码
/***************************************************************************************************************/

//控制倒车影像的变量
uchar numjy = 0;
bool ok = false;
//

extern  unsigned char wsjtmpflag;

extern unsigned char DC;


//extern unsigned char SouSa;
//extern unsigned char tmpflag;

//extern unsigned char KL;
//extern unsigned char SK;

extern unsigned char flagWidthlamp;

//2016.6.22  extern widget.cpp 中的变量。
/********************************************************************************************************************/
//速度定义 speed
extern unsigned short int speed;
//unsigned short int
extern unsigned char daoche;

/********************************************************************************************************************/


//2016.6.20 wsj
//下面是显示can数据 值的变量
//临时定义，后边产品要更根据情况去改和规范 变量的定义。 有一半的变量可以复用。
/********************************************************************************************************************/

//开关量
// 最终协议

//第一个字节
extern unsigned char DC;  //倒车信号（倒车+） 7,
extern unsigned char SK;  //位置灯（位置灯+） 6,
extern unsigned char SouSa;//手刹指示灯（手刹指示灯+） 5,
extern unsigned char Zuozhuan; //左转向灯（左转向灯）4,
extern unsigned char Youzhuan;  //右转向灯（右转向灯）3,
extern unsigned char YuanGuang; //远光指示灯（远光指示灯） 2,
extern unsigned char Jinguang; //近光指示灯（近光指示灯） 1,


//第二个字节
extern uchar youshuifenli;  //油水分离 6,
extern uchar fadongjiguzhang;//发动机故障 5,
extern uchar yure; //预热 4,
extern uchar liangman; //粮满 3,
extern uchar KL;  //空滤报警开关（空滤-） 2,
//extern uchar CongDian; //充电指示灯-  1,


//频率量
extern ushort  shengyunqi;    //升运器
extern ushort  futuoqi;       //复脱器
extern ushort  zhouliuguntong;//轴流滚筒
extern float  shisu; //时速

//模拟量
//18FF04F6
extern unsigned char YouLiang;     //油量（油量）
extern unsigned char Yeyayouwen; //液压油油温（液压油油温）
extern unsigned int   MiJi;      //米计（预留）
extern unsigned int   LiCheng;   //里程（预留）

//extern float MiJiFloat;


//发动机 数据
//18FEEE00
extern unsigned char SuiWen;//水温；
extern float  jiyouyali; //机油压力

//0CF00400

extern float fadongzhuansu; //发动机转速


////18FECA00
////故障报文
////ulong guzhangbaowen; //故障报文
//extern uint  spn;//spn 码
//extern uchar fmi;//fmi 码

//extern uint  spn2;//spn2 码
//extern uchar fmi2;//fmi2 码

//extern uint  spn3;//spn3 码
//extern uchar fmi3;//fmi3 码

//extern uint  spn4;//spn4 码
//extern uchar fmi4;//fmi4 码


//预热指示灯
//18FEE400

//extern uchaflagFDJYRng;//18FEE400

//小时计
//18FEE500
extern unsigned int XiaoshiJi; //小时计



//新增相关变量


extern uchar qianbulihezhishi;  //前部离合指示输入, 8

extern uchar tuolilihezhishi;  //脱粒离合指示输入, 7

extern uchar xieliangtongbaijin;//卸粮筒摆进限位开关 6

extern uchar Shoubing;//界面切换输入（手柄控制）4
//
extern uchar liangman70;//粮满 70, 1

//byte3
extern uchar xielianglihe_input;//卸粮离合开关输入 2
extern uchar guoqiaofanzhuan_input;//过桥反转指示输入 1


//byte4

extern uchar getaisheng_input;//割台升输入; 8
extern uchar getaijiang_input;//割台降输入; 7

extern uchar xltbj_input;//卸粮筒摆进输入 6
extern uchar xltbc_input;//卸粮筒摆出输入 5

extern uchar bhls_input;//拨禾轮升输入 4
extern uchar bhlj_input; //拨禾轮降输入; 3
extern uchar tltjiashu_input;//脱粒滚筒加速输入; 2

extern uchar tltjianshu_input;//脱粒滚筒减速输入 1


//byte5

extern uchar getaisheng_out;//割台升输出; 8
extern uchar getaijiang_out;//割台降输出; 7

extern uchar xltbj_out;//卸粮筒摆进输出 6
extern uchar xltbc_out;//卸粮筒摆出输出 5

extern uchar bhls_out;//拨禾轮升输出 4
extern uchar bhlj_out; //拨禾轮降输出; 3
extern uchar tltjiashu_out;//脱粒滚筒加速输出; 2

extern uchar tltjianshu_out;//脱粒滚筒减速输出 1



extern uchar xiehefa_out;// 卸荷阀输出
extern uchar  xielianglihe_out;//卸粮离合输出; 1


//
extern ushort  qiesuiqizhuansu;//切碎器转速
extern ushort fengjizhuansu;//切碎器转速
extern ushort guoqiaozhuansu;//过桥转速；

extern ushort tuoliguntong;//脱粒滚筒转速
extern ushort fenliguntong;//分离滚筒转速
//extern ushort
/********************************************************************************************************************/


/********************************************************************************************************************/
//2016 6.1  wushengjun
//定义变量 控制图标闪烁。
//
/********************************************************************************************************************/

extern unsigned char flagLeft;  //左转
unsigned char countLeft; //左转


extern unsigned char flagBattery;//电瓶指示灯


extern unsigned char flagWidthlamp; //示宽灯


extern unsigned char  flagYG; //远光灯


extern unsigned char  flagSW; //水温


extern unsigned char  flagJG; //近光灯



extern unsigned char  flagJY; //机油


extern unsigned char  flagLCM; //粮仓满

extern unsigned char  flagLCM_seven; //粮仓满70


extern unsigned char   flagFDJYR; //发动机预热


extern unsigned char   flagGL; //过滤


extern unsigned char   flagYL; //油量


extern unsigned char  flagYeyayouwen;//液压油温


extern unsigned char    flagECU;//ecu


extern unsigned char    flagPark;//停车


extern unsigned char   flagFDJGZ; //发动机故障


extern unsigned char   flagRight; //右转



//extern unsigned char  flagyouxiangman;//油量满报警
extern unsigned char  flagyouliangdi; //油量低报警


/********************************************************************************************************************/

/********************************************************************************************************************/

Work::Work(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Work)
{
    ui->setupUi(this);

//    findlokk_work = new FindLook();//初始化查询对象

//    time_work = new Timesetup();//初始化设置对象

     //video = new Camera_thread();


    resize(1024,600);
    Work::move(0,0);//回到原来主窗口的位置
    setWindowFlags(windowFlags()|Qt::FramelessWindowHint|Qt::WindowTitleHint);//删除 最小化、最大化、关闭按钮

#if 1
    QTimer *dialogtime = new QTimer(this);
    connect(dialogtime, SIGNAL(timeout()), this, SLOT(update()));  //连接信号槽，定时器超时触发窗体更新


    dialogtime->start(500);

#endif

#if 0
       connect(this,SIGNAL(camerastartsignal()),this,SLOT(start_thread()));//摄像头程序打开 1

       connect(this,SIGNAL(camerastartsignal2()),this,SLOT(start_thread()));//摄像头程序打开 2
#endif




       QTimer *timerGzm = new QTimer();/////////////////////////
       connect(timerGzm,SIGNAL(timeout()),this,SLOT(workgzmslot()));//
       timerGzm->start(1000);//////

       //dialogtime->start(500);


    //



    //申请提取帧缓冲区空间
    //pp = (unsigned char *)malloc(IMG_WIDTH * IMG_HEIGTH/*QWidget::width()*QWidget::height()*/* 3 * sizeof(char));
    p = (unsigned char *)malloc(IMG_WIDTH * IMG_HEIGTH/*QWidget::width()*QWidget::height()*/* 3 * sizeof(char));
    //pp1 = (unsigned char *)malloc(IMG_WIDTH * IMG_HEIGTH/*QWidget::width()*QWidget::height()*/* 3 * sizeof(char));
    p1 = (unsigned char *)malloc(IMG_WIDTH * IMG_HEIGTH/*QWidget::width()*QWidget::height()*/* 3 * sizeof(char));

    frame = new QImage(p,IMG_WIDTH,IMG_HEIGTH,QImage::Format_RGB888);//定义摄像头抓取帧句柄-QImage类型
    frame1 = new QImage(p1,IMG_WIDTH,IMG_HEIGTH,QImage::Format_RGB888);//定义摄像头抓取帧句柄-QImage类型

    //labelx = new MyLabel();//定义显示窗体

    vd = new VideoDevice(tr("/dev/video0"));//定义摄像头设备，linux下摄像头句柄为/mnt/dev/video0\1\2...
    vd1 = new VideoDevice(tr("/dev/video1"));//定义摄像头设备，linux下摄像头句柄为/mnt/dev/video0\1\2...

#if 1
    rs = vd->open_device();//打开设备
    if(-1==rs)
    {
        //QMessageBox::warning(this,"error","open /dev/video0 error",QMessageBox::Yes);
        vd->close_device();
    }

    rs = vd->init_device();//初始化摄像头设备
    if(-1==rs)
    {
        //QMessageBox::warning(this,"error","init failed",QMessageBox::Yes);
        vd->close_device();
    }

    rs = vd->start_capturing();//控制摄像头设备开始抓图
    if(-1==rs)
    {
        //QMessageBox::warning(this,tr("error"),tr("start capture failed"),QMessageBox::Yes);
        vd->close_device();
    }

    if(-1==rs)
    {
        //QMessageBox::warning(this,tr("error"),tr("get frame failed"),QMessageBox::Yes);
        vd->stop_capturing();
    }
#endif

#if 1
    rs1 = vd1->open_device();//打开设备
    if(-1==rs1)
    {
        //QMessageBox::warning(this,"error","open /dev/video1 error",QMessageBox::Yes);
        vd1->close_device();
    }

    rs1 = vd1->init_device();//初始化摄像头设备
    if(-1==rs1)
    {
        //QMessageBox::warning(this,"error","init failed1",QMessageBox::Yes);
        vd1->close_device();
    }

    rs1 = vd1->start_capturing();//控制摄像头设备开始抓图
    if(-1==rs1)
    {
        //QMessageBox::warning(this,tr("error"),tr("start capture failed1"),QMessageBox::Yes);
        vd1->close_device();
    }

    if(-1==rs1)
    {
        //QMessageBox::warning(this,tr("error"),tr("get frame failed1"),QMessageBox::Yes);
        vd1->stop_capturing();
    }

#endif


            ////Cam_Power_off(2);
            ////Cam_Power_off(3);

            timercamera = new QTimer(this);
            connect(timercamera,SIGNAL(timeout()),this,SLOT(cameraslot1()));//链接定时器到时间后执行的槽函数
            //timercamera->start(10);//开启定时器,33ms;即每秒30帧


            timercamera2 = new QTimer(this);
            connect(timercamera2,SIGNAL(timeout()),this,SLOT(cameraslot2()));//链接定时器到时间后执行的槽函数
           // timercamera2->start(1);//开启定时器,33ms;即每秒30帧
}


Work::~Work()
{

    delete ui;
}

#if 0
void Work::start_thread()
{
    //video = new Camera_thread();
    video->start();
    connect(video,SIGNAL(image_data(QImage *)),this,SLOT(show_picture(QImage *)));//摄像头程序打开 1

    //connect(video,SIGNAL(image_data2(QImage *)),this,SLOT(show_picture2(QImage *)));//摄像头程序打开 2
}
void Work::show_picture(QImage *img)
{


     ui->show_label1->setPixmap(QPixmap::fromImage(*img));
     ui->show_label1->setScaledContents(true);//图片自适应label大小 等比例大小,缩放问题解决。

     //全屏显示 要加条件判断
     if(numjy ==1)
     {
#if 0
         ui->show_label1->resize(img->width(),img->height());
         ui->show_label1->resize(1024,600);
         ui->show_label1->move(0,0);

#endif
     }

}


void Work::show_picture2(QImage *img2)
{
     ui->show_label2->setPixmap(QPixmap::fromImage(*img2));
     ui->show_label2->setScaledContents(true);//图片自适应label大小 等比例大小,缩放问题解决。
}
void Work::stop_thread()
{
   // delete video;
}
#endif



void Work::on_pushButton_clicked()
{
    this->close();
}


void Work::paintEvent(QPaintEvent *event)
{
    QPainter dp(this);
    QPixmap dppix;
    //dppix.load("./imagejy/english/work.bmp");

    dppix.load("./imagejy/zw/work.bmp");
    dp.drawPixmap(0,0,1024,600,dppix);



    //qDebug()<<"klsklskslskslkslks"<<endl;

    /**************************************************************************************************************/
    //显示时间 。2016.7.12
        QString timeStr1= QTime::currentTime().toString();     //绘制当前的时间
        QString dateStr1 = QDate::currentDate().toString("yyyy-MM-dd");

        ui->lcdNumber_2->display(dateStr1);//dateStr1
        ui->lcdNumber->display(timeStr1);
    /**************************************************************************************************************/

    /**************************************************************************************************************/
        //测试摄像头直接采集图像并显示
        //
        #if 1

        if (((ok == true)&&(numjy==0))||(flagqh2 == true))
        {
            numjy = 1;
            BH = true;
            BH2 = true;
            timercamera->stop();

          //// Cam_Power_off(2);
          //// Cam_Power_on(1);
           timercamera2->start(1);
           ui->show_label2->resize(frame1->width(),frame1->height());
           ui->show_label2->resize(1024,600);
           ui->show_label2->move(0,0);

        }
        else if ((ok == false)&&(numjy==0))
        {
           //// Cam_Power_off(1);//
          ////  Cam_Power_on(2);
            timercamera2->start(1);
            timercamera->start(1);
        }
        else if((ok == true)&&(BH==true))
        {
           ////  Cam_Power_off(1);//
           ////  Cam_Power_on(2);
            timercamera2->start(1);
            timercamera->start(1);
        }
        else if ((ok == false)&&(flagqh2==true))
        {
           ////   Cam_Power_off(1);//
           ////   Cam_Power_on(2);
            timercamera2->start(1);
            timercamera->start(1);
        }



        #endif

   /************************************************************************************************/

            //2016.8.8  定义数值

            #if 1
                ui->label->setText(QString::number(fadongzhuansu,'f',0)); //r/ min  QString::number(fadongzhuansu)

                ui->label_2->setText(QString::number(shisu));// k/mh
                ui->label_3->setText(QString::number(xiaoshiJi_h,'f',1));// xiaoshiji

                ui->label_4->setText(QString::number(SuiWen));//水温
                ui->label_5->setText(QString::number(Yeyayouwen));//液压油油温（液压油油温）
                ui->label_6->setText(QString::number(jiyouwendu,'f',0));//机油温度
                ui->label_7->setText(QString::number(jiyouyali,'f',2));//机油压力
                ui->label_8->setText(QString::number(guoqiaozhuansu));//过桥转速
                ui->label_9->setText(QString::number(fengjizhuansu));//风机转速
                ui->label_10->setText(QString::number(futuoqi));//复脱器转速
                ui->label_11->setText(QString::number(shengyunqi));//升运器转速
                ui->label_12->setText(QString::number(qiesuiqizhuansu));//切碎器转速
                ui->label_13->setText(QString::number(tuoliguntong));//脱粒滚筒转速
                ui->label_14->setText(QString::number(fenliguntong));//分离滚筒转速

            #endif

                /************************************************************************************************/

#if 1
                if((DC == 0)&&(wsjtmpflag == 1)) //返回主界面。
                    {
                        //emit back();
                        QMouseEvent* pressdialog=new QMouseEvent(QEvent::MouseButtonPress,QPoint(2,2), Qt::LeftButton,Qt::LeftButton,Qt::NoModifier);
                        QApplication::postEvent(ui->pushButton,pressdialog);
                        QMouseEvent* releasedialog=new QMouseEvent(QEvent::MouseButtonRelease,QPoint(2,2),Qt::LeftButton,Qt::LeftButton,Qt::NoModifier);
                        QApplication::postEvent(ui->pushButton,releasedialog);
                        wsjtmpflag = 0;

                        //ui->show_label2->resize(frame1->width(),frame1->height());
                        ui->show_label2->resize(395,228);
                        ui->show_label2->move(317,300);
                       // ui->show_label2->setScaledContents(true);


                      ////  Cam_Power_on(2);
                      ////  Cam_Power_off(1);//
                        timercamera2->stop();

                        //qDebug()<<"jdjddddddddddddddddddddd"<<endl;


                    }
                    else if ((DC == 1)&&(wsjtmpflag == 1))
                {
                    BH2 = true;//删除标志
                }

                 if (DC==1)
                {
                    flagqh2 = true;

                }
                 else if ((DC == 0)&&(BH2 == true))
                 {
                    flagqh2 = false;

                    ui->show_label2->resize(391,223);
                    ui->show_label2->move(317,300);

                    timercamera->start(1);
                   // ui->show_label2->setScaledContents(true);

                    //timercamera2->stop();

                 }


#endif
                 /************************************************************************************************/
                 //手柄切换控制

#if 1
                 if (Shoubing==1)
                 {

                     Shoubing = 0;

                    // qDebug()<<"2222 btn........ = "<<btn<<endl;

                     if(btn ==2)
                     {
                         QMouseEvent* press33=new QMouseEvent(QEvent::MouseButtonPress,QPoint(2,2), Qt::LeftButton,Qt::LeftButton,Qt::NoModifier);
                         QApplication::postEvent(ui->pushButton_4,press33);
                         QMouseEvent* release33=new QMouseEvent(QEvent::MouseButtonRelease,QPoint(2,2),Qt::LeftButton,Qt::LeftButton,Qt::NoModifier);
                         QApplication::postEvent(ui->pushButton_4,release33);
                     }

                     btn++; //1,进入查询界面
                     switch(btn)
                     {
                         case 1: //进入查询界面
                        {
                         btn++;

                         QMouseEvent* press33=new QMouseEvent(QEvent::MouseButtonPress,QPoint(2,2), Qt::LeftButton,Qt::LeftButton,Qt::NoModifier);
                         QApplication::postEvent(ui->pushButton_4,press33);
                         QMouseEvent* release33=new QMouseEvent(QEvent::MouseButtonRelease,QPoint(2,2),Qt::LeftButton,Qt::LeftButton,Qt::NoModifier);
                         QApplication::postEvent(ui->pushButton_4,release33);
                        }
                         break;

                        case 3: //1,进入行走界面 ，

                        {
                        btn = 0;
                         QMouseEvent* press22=new QMouseEvent(QEvent::MouseButtonPress,QPoint(2,2), Qt::LeftButton,Qt::LeftButton,Qt::NoModifier);
                         QApplication::postEvent(ui->pushButton,press22);
                         QMouseEvent* release22=new QMouseEvent(QEvent::MouseButtonRelease,QPoint(2,2),Qt::LeftButton,Qt::LeftButton,Qt::NoModifier);
                         QApplication::postEvent(ui->pushButton,release22);

                        }
                         break;

                     default:
                         btn = 0;
                         break;

                     }

                 }
#endif



/************************************************************************************************/
#if 0
    if(beep_flag)
    {
        ui->pushButton_3->setStyleSheet("QPushButton{border-image:url(./imagejy/laba.png);background-repeat: repeat-xy;background-position: center;background-attachment: fixed;background-clip: padding}");
        //qDebug()<<"beep_flag = "<<beep_flag<<endl;

    }
    else
    {
        ui->pushButton_3->setStyleSheet("QPushButton{border-image:url(./imagejy/labalaba.png);background-repeat: background-xy;background-position: center;background-attachment: fixed;background-clip: padding}");
        //qDebug()<<"beep_flag = "<<beep_flag<<endl;
    }
#endif
/************************************************************************************************/

//加载上方图标 闪烁用到
//zuo zhuandeng
//                QPainter paintLeft(this);
//                QPixmap pixLeft;


/************************************************************************************************/
            //闪烁不同步问题解决办法。
            //利用消息队列 和 for 循环解决。
            //2016.7.25

                QPainter paintShanshuo(this);
                QPixmap pixShanshuo;
                if(1) //左转灯闪烁
                {
                    countLeft++;
                    if (countLeft>1)
                        countLeft = 0;
                    switch(countLeft)
                    {
                        case 1:

                        if(flagSW)//水温 0~120度  95度以上报警。
                        {
                             pixShanshuo.load("./imagejy/07.png");//07.jpg
                             paintShanshuo.drawPixmap(118,15,45,40,pixShanshuo);//正上方位置显示的图标
                        }

                        if(flagJY) //机油  油压报警 0～1 MPa,在0.1 MPa 以下为报警区。
                        {
                             pixShanshuo.load("./imagejy/08.png");//08.jpg
                             paintShanshuo.drawPixmap(396,15,59,24,pixShanshuo);//正上方位置显示的图标
                             //paintShanshuo.drawPixmap(20,180,43,43,pixShanshuo);//左边显示的图标
                        }


                        if (flagyouliangdi)//油量
                        {
                            pixShanshuo.load("./imagejy/09.png");//14.jpg
                            paintShanshuo.drawPixmap(615,15,31,36,pixShanshuo);

                            // paintShanshuo.drawPixmap(409,172,31,36,pixShanshuo);

                        }

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
                                matchine[i++] = query.value(2).toInt();
                            }

#if 0
                            i = 0;
                            for (i = 0; i < 7; i++)
                                {
                                    qDebug()<<"matchine % bi "<<matchine[i]<<endl;
                                }
                            i = 0;
#endif
                            i = 0;
                          query.exec("select id, name, age from bjd");
                           while (query.next())
                           {

                               bjd_array[i++] = query.value(2).toInt();
                           }

                           i = 0;

#if 0
                           i = 0;
                           for (i = 0; i < 7; i++)
                               {
                                   qDebug()<<"bjd_array[i] "<<bjd_array[i]<<endl;
                               }
                           i = 0;

#endif
                            query.exec(QObject::tr("drop myjy10"));

/*******************************************************************/

                                //float -> int 小数点后面的数据有丢失，回头要加上去四舍五入 。

                                   lsls0 =(matchine[0]*bjd_array[0]);
                                   lsls0 /= 100;

                                   lsls1 =(matchine[1]*bjd_array[1]);
                                   lsls1 /= 100;

                                   lsls2 =(matchine[2]*bjd_array[2]);
                                   lsls2 /= 100;

                                   lsls3 =(matchine[3]*bjd_array[3]);
                                   lsls3 /= 100;

                                   lsls4 =(matchine[4]*bjd_array[4]);
                                   lsls4 /= 100;

                                   lsls5 =(matchine[5]*bjd_array[5]);
                                   lsls5 /= 100;

                                   lsls6 =(matchine[6]*bjd_array[6]);
                                   lsls6 /= 100;


                                   ruby[0] = lsls0;
                                   ruby[1] = lsls1;
                                   ruby[2] = lsls2;
                                   ruby[3] = lsls3;
                                   ruby[4] = lsls4;
                                   ruby[5] = lsls5;
                                   ruby[6] = lsls6;

//                            qDebug()<<"lsls0 "<<lsls0<<"ruby0 "<<ruby[0]<<endl;
//                            qDebug()<<"lsls1 "<<lsls1<<"ruby "<<ruby[1]<<endl;

//                            qDebug()<<"tuoliguntong  "<<tuoliguntong<<"qsq "<<qiesuiqizhuansu<<endl;
//比较can传过来的值 ，实现闪烁

                   if(can_retern != 0)
                   {


                        if(tuoliguntong<ruby[0])//脱粒滚筒转速
                        {
                            pixShanshuo.load("./imagejy/english/shanshuo/04m.png");//11.   jpgenglish/shanshuo/
                            paintShanshuo.drawPixmap(727,406,217,21,pixShanshuo);
                        }

                        if(qiesuiqizhuansu<ruby[1])//切碎器转速
                        {
                            pixShanshuo.load("./imagejy/english/shanshuo/02.png");//11.jpg
                            paintShanshuo.drawPixmap(727,342,130,20,pixShanshuo);
                        }

                        if(fengjizhuansu<ruby[2])//风机转速
                        {
                            pixShanshuo.load("./imagejy/english/shanshuo/03.png");//11.jpg
                            paintShanshuo.drawPixmap(727,165,88,20,pixShanshuo);
                        }
                        if(futuoqi<ruby[3])//复脱器堵塞转速
                        {
                            pixShanshuo.load("./imagejy/english/shanshuo/05.png");//11.jpg
                            paintShanshuo.drawPixmap(726,224,229,21,pixShanshuo);
                        }
                        if(shengyunqi<ruby[4])//升运器堵塞转速
                        {
                            pixShanshuo.load("./imagejy/english/shanshuo/06.png");//11.jpg
                            paintShanshuo.drawPixmap(726,282,207,21,pixShanshuo);
                        }
                        if(guoqiaozhuansu<ruby[5])//过桥转速
                        {
                            pixShanshuo.load("./imagejy/english/shanshuo/01.png");//11.jpg
                            paintShanshuo.drawPixmap(727,117,112,20,pixShanshuo);
                        }
                        if(fenliguntong<ruby[6])//分离滚筒转速
                        {
                            pixShanshuo.load("./imagejy/english/shanshuo/07.png");//11.jpg
                            paintShanshuo.drawPixmap(727,464,215,23,pixShanshuo);
                        }
                   }//endof if(can_return != 0)


/*******************************************************************/

                        break;
                    }//endof switch()

                }//endof if(1)

                    //不用闪烁

                    if(flagLeft)//左转灯闪烁
                    {
                        pixShanshuo.load("./imagejy/01.png");//14.jpg
                        paintShanshuo.drawPixmap(0,15,44,46,pixShanshuo);
                    }
                    if(flagBattery)//电瓶指示灯
                    {
                        pixShanshuo.load("./imagejy/03.png");//14.jpg
                        paintShanshuo.drawPixmap(60,15,46,32,pixShanshuo);//正上方图片显示
                        //paintShanshuo.drawPixmap(20,335,43,34,pixShanshuo);//左边图片显示
                    }

                    if(flagLCM)//flagLCM = 1; //粮仓满
                    {
                        pixShanshuo.load("./imagejy/13.png");//13.jpg
                        paintShanshuo.drawPixmap(542,15,42,41,pixShanshuo);
                    }

                    if(flagLCM_seven)//flagLCM = 1; //粮仓满7000000000
                    {
                        pixShanshuo.load("./imagejy/70.png");//13.jpg
                        paintShanshuo.drawPixmap(542,15,42,41,pixShanshuo);
                    }

                    if(flagFDJYR)//flagFDJYR = 1; //发动机预热
                    {
                        pixShanshuo.load("./imagejy/15.png");//15.jpg
                        paintShanshuo.drawPixmap(761,25,46,27,pixShanshuo);
                    }

                    if(flagGL)//空 滤
                    {
                        pixShanshuo.load("./imagejy/04.png");//04.jpg
                        paintShanshuo.drawPixmap(469,15,42,43,pixShanshuo);
                    }


                    if(flagECU)//ecu
                    {
                        pixShanshuo.load("./imagejy/91.png");//03.jpg
                        paintShanshuo.drawPixmap(594,15,43,32,pixShanshuo);
                    }

                    if(flagFDJGZ)//发动机故障
                    {
                        pixShanshuo.load("./imagejy/16.png");//16.jpg
                        paintShanshuo.drawPixmap(907,15,47,30,pixShanshuo);
                    }

                    if(flagRight)//右转
                    {
                        pixShanshuo.load("./imagejy/02.png");//14.jpg
                        paintShanshuo.drawPixmap(980,15,44,46,pixShanshuo);
                    }


                    if(flagWidthlamp)//示宽灯
                    {
                        pixShanshuo.load("./imagejy/06.png");//06.jpg
                        paintShanshuo.drawPixmap(177,15,57,32,pixShanshuo);
                    }

                    if(flagJG)//近光灯flagJG
                    {
                        pixShanshuo.load("./imagejy/12.png");//12.jpg
                        paintShanshuo.drawPixmap(250,15,46,37,pixShanshuo);
                    }

                    if(flagYG)//远光灯
                    {
                        pixShanshuo.load("./imagejy/05.png");//05.jpg
                        paintShanshuo.drawPixmap(323,15,46,37,pixShanshuo);
                    }

                    if(flagPark)//停车 刹车
                    {
                        pixShanshuo.load("./imagejy/11.png");//11.jpg
                        paintShanshuo.drawPixmap(834,15,48,37,pixShanshuo);
                    }

                    if(flagYeyayouwen)//液压油温
                    {
                         pixShanshuo.load("./imagejy/10.png");//10.jpg
                         paintShanshuo.drawPixmap(688,15,48,38,pixShanshuo);//上边图标
                         //paintShanshuo.drawPixmap(423,216,49,38,pixShanshuo);//左边图标
                    }


                    //油量格数
                   // if (flagyouxiangman|flagyouliangdi)//油量
                    if (1)//油量
                    {
                        switch(YouLiang)
                        {

                        case 0:
                            pixShanshuo.load("./imagejy/yl00.png");//14.jpg
                            paintShanshuo.drawPixmap(106,225,166,26,pixShanshuo);
                            break;

                        case 1:
                            pixShanshuo.load("./imagejy/yl01.png");//14.jpg
                            paintShanshuo.drawPixmap(106,225,166,26,pixShanshuo);
                            break;

                        case 2:
                            pixShanshuo.load("./imagejy/yl02.png");//14.jpg
                            paintShanshuo.drawPixmap(106,225,166,26,pixShanshuo);
                            break;

                        case 3:
                            pixShanshuo.load("./imagejy/yl03.png");//14.jpg
                            paintShanshuo.drawPixmap(106,225,166,26,pixShanshuo);
                            break;
                        case 4:
                            pixShanshuo.load("./imagejy/yl04.png");//14.jpg
                            paintShanshuo.drawPixmap(106,225,166,26,pixShanshuo);
                            break;
                        case 5:
                            pixShanshuo.load("./imagejy/yl05.png");//14.jpg
                            paintShanshuo.drawPixmap(106,225,166,26,pixShanshuo);
                            break;
                        case 6:
                            pixShanshuo.load("./imagejy/yl06.png");//14.jpg
                            paintShanshuo.drawPixmap(106,225,166,26,pixShanshuo);
                            break;
                        case 7:
                            pixShanshuo.load("./imagejy/yl07.png");//14.jpg
                            paintShanshuo.drawPixmap(106,225,166,26,pixShanshuo);
                            break;
                        case 8:
                            pixShanshuo.load("./imagejy/yl08.png");//14.jpg
                            paintShanshuo.drawPixmap(106,225,166,26,pixShanshuo);
                            break;


                        default:
                            pixShanshuo.load("./imagejy/yl00.png");//14.jpg
                            paintShanshuo.drawPixmap(446,182,166,26,pixShanshuo);
                            break;
                        }

                    }//end off //油量格数


                fmiArry[0] = fmi;
                fmiArry[1] = fmi2;//
                fmiArry[2] = fmi3;
                fmiArry[3] = fmi4;

                spnArry[0] = spn;
                spnArry[1] = spn2;
                spnArry[2] = spn3;
                spnArry[3] = spn4;
}

void Work::on_pushButton_4_clicked()//查询按钮
{
    //this->close();
    findlokk_work.show();
    findlokk_work.exec();
    this->show();
}

void Work::on_pushButton_2_clicked()// 设置按钮
{
    //this->close();
    time_work.show();
    time_work.exec();
    this->show();
}

void Work::on_pushButton_3_clicked()//喇叭按钮
{
#if 0
    if(beep_flag)
    {
        beep_flag = false;

        ui->pushButton_3->setStyleSheet("QPushButton{border-image:url(./imagejy/labalaba.png);background-repeat: background-xy;background-position: center;background-attachment: fixed;background-clip: padding}");
        qDebug()<<"beep_flag = "<<beep_flag<<endl;

    }
    else
    {
        beep_flag = true;
        ui->pushButton_3->setStyleSheet("QPushButton{border-image:url(./imagejy/laba.png);background-repeat: repeat-xy;background-position: center;background-attachment: fixed;background-clip: padding}");

        qDebug()<<"beep_flag = "<<beep_flag<<endl;
    }
#endif
}


void Work::workgzmslot()
{

#if 0
    if(beep_flag)
    {
        //添加蜂鸣器报警
        if(flagSW||flagyouliangdi||flagYeyayouwen)//flagyouxiangman||
        {

            if (beep_widget)
            {
#if 0
            beep_off();//关闭蜂鸣器

            beep_on_s();//打开蜂鸣器

#endif
            }
            else
            {
                beep_on_s();//打开蜂鸣器
                beep_off();//关闭蜂鸣器
            }


            //qDebug()<<"987653"<<wsj2++<<endl;

            //beep_off();//关闭蜂鸣器
        }
        else
        {
            beep_off();//关闭蜂鸣器
        }
    }
    else
    {
        beep_off();
    }




    if(fmiArry[gzm_count] != 0)
    {
     ui->label_16->setText(QString::number(fmiArry[gzm_count],10));

     //qDebug()<<"88888888888888888888888"<<endl;
    }
    else
    {
        ui->label_16->setText("");
    }

    if(spnArry[gzm_count] != 0)
    {
     ui->label_19->setText(QString::number(spnArry[gzm_count],10));
    }
    else
    {
        ui->label_19->setText("");
    }

     gzm_count++;
     if(gzm_count>=4)
     {
        gzm_count = 0;
        memset(fmiArry,0,4);
        memset(spnArry,0,32);
     }

     #endif

}



void Work::cameraslot1()
{

#if 1
    rs = vd->unget_frame();
    rs = vd->get_frame((void **)&p,(size_t*)&len);//抓取帧
    //convert_yuv_to_rgb_buffer(p,pp,IMG_WIDTH,IMG_HEIGTH);//转换为RGB数据
    frame->loadFromData((uchar *)p,/*len*/IMG_WIDTH * IMG_HEIGTH * 3 * sizeof(char));//载入转换后的RGB数据到帧句柄
    //memcpy(pimg,pp,sizeof(pp));

    ui->show_label1->setPixmap(QPixmap::fromImage(*frame));
    ui->show_label1->setScaledContents(true);

#if 0
    if(numjy ==1)
    {

        ui->show_label1->resize(frame->width(),frame->height());
        ui->show_label1->resize(1024,600);
        ui->show_label1->move(0,0);
    }
#endif

    //ui->show_label1->setFixedSize(480,320);
    //ui->show_label1->setPixmap(QPixmap::fromImage(*frame,Qt::AutoColor));//显示帧图像到窗体,此处会执行子类化的label函数体--MyLabel.cpp中的void MyLabel::paintEvent(QPaintEvent * event)
    //ui->show_label2->setPixmap(QPixmap::fromImage(*frame,Qt::AutoColor));//显示帧图像到窗体,此处会执行子类化的label函数体--MyLabel.cpp中的void MyLabel::paintEvent(QPaintEvent * event)
    //rs = vd->unget_frame();
#endif


#if 0
    rs1 = vd1->unget_frame();
    rs1 = vd1->get_frame((void **)&p1,(size_t*)&len);//抓取帧
    //convert_yuv_to_rgb_buffer(p1,pp1,IMG_WIDTH,IMG_HEIGTH);//转换为RGB数据
    frame1->loadFromData((uchar *)p1,IMG_WIDTH * IMG_HEIGTH * 3 * sizeof(char));//载入转换后的RGB数据到帧句柄
    ui->show_label2->setPixmap(QPixmap::fromImage(*frame1));
    ui->show_label2->setScaledContents(true);
#endif


}

void Work::cameraslot2()
{
#if 1
    rs1 = vd1->unget_frame();
    rs1 = vd1->get_frame((void **)&p1,(size_t*)&len);//抓取帧
    //convert_yuv_to_rgb_buffer(p1,pp1,IMG_WIDTH,IMG_HEIGTH);//转换为RGB数据
    frame1->loadFromData((uchar *)p1,IMG_WIDTH * IMG_HEIGTH * 3 * sizeof(char));//载入转换后的RGB数据到帧句柄
    ui->show_label2->setPixmap(QPixmap::fromImage(*frame1));
    ui->show_label2->setScaledContents(true);

#if 0
    if((BH == true)&&(flagqh2 == true))
    {
        ui->show_label2->resize(frame1->width(),frame1->height());
        ui->show_label2->resize(1024,600);
        ui->show_label2->move(0,0);
    }
#endif


#endif
}



