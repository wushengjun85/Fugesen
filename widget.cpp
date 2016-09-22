#include "widget.h"
#include "ui_widget.h"

#include<QDebug>
#include<QTime>
#include<QTimer>
#include<QPainter>
#include<QMouseEvent>
#include"signalcan.h"

#include"canread.h"

#include <QPalette>
#include <QFont>
#include<QTextCodec>

#include <QtSql>

//添加动态链接库
//#include"hwlib/libdev.h"

/***************************************************************************************************************/
//2016.8.1  变量定义
bool flaglanguage = false; //中英文切换标志变量。

//uchar numtmp = 0; //临时 测试所用。

bool beep_flag = true;

//uint xiaoshiJi_m;//分钟

long long xiaoshiJi_m;//分钟
float xiaoshiJi_h;//小时


static uchar can_err_count = 0; //Can 开路或者故障
bool  can_err_flag = false;//Can 开路或者故障
int   can_retern = 0; // can_return = ret //返回can 读取的数据


uchar btn = 0;// 记录手柄按下次数
//uchar wzxx = 0;//位置信息，记录所在位置
uchar MiJi_send = 0;

float tmp_zs = 0;//保存转速的值


int fff;

uchar jun[6] = {1,2,3,4,5,6};
uchar iiii;
/***************************************************************************************************************/
int num = 0;
int numtmp = 0;


unsigned char wsjtmpflag = 0;

bool OK = false;

extern bool ok;
extern bool BH;
extern bool flagqh2;


bool beep_widget = false;

//uchar wsj1 = 0;
//uchar wsj2 = 0;
//uchar wsj3 = 0;
//uchar wsj4 = 0;
/********************************************************************************************************************/
//定义时间变量用于各界面传递
//2016.7.11

QString  Datesetup;
/********************************************************************************************************************/



/********************************************************************************************************************/
//2016 6.1  wushengjun
//定义变量 控制图标闪烁。
//
/********************************************************************************************************************/
uchar j=0;
uchar jflag = 0;
ushort mm=0;
uchar jjjflag = 0;
//ushort  mybufflag[312] = {0};//15
//ushort  myindex[312] = {0};//15




/*English fmi spn */
//uchar  myindexFmi[4] = {0};//15
uchar fmiArry[4] = {0};
ulong spnArry[4] = {0};//1,2,3,9

uchar gzm_count = 0;

uchar gzm_widget = 0;
/* *******  */



unsigned char  countBuff = 0;


unsigned char flagLeft = 0;  //左转
unsigned char countLeft_W = 0; //左转

unsigned char flagBattery = 0;//电瓶指示灯

unsigned char flagWidthlamp = 0; //示宽灯

unsigned char  flagYG = 0; //远光灯

unsigned char  flagSW  = 0; //水温

unsigned char  flagJG = 0; //近光灯

unsigned char  flagJY = 0; //机油


unsigned char  flagLCM = 0; //粮仓满

unsigned char  flagLCM_seven = 0;//粮仓满70%

unsigned char   flagFDJYR = 0; //发动机预热

unsigned char   flagGL = 0; //过滤

unsigned char   flagYL = 0; //油量

unsigned char  flagYeyayouwen = 0;//液压油温

unsigned char    flagECU = 0;//ecu

unsigned char    flagPark = 0;//停车

unsigned char   flagFDJGZ = 0; //发动机故障

unsigned char   flagRight = 0; //右转

//unsigned char  flagyouxiangman = 0; //油量满
unsigned char  flagyouliangdi  = 0; // 油量低


//unsigned char  flagCanfault = 0;//Can 通信故障
//unsigned char  flagJinqifault = 0;//进气温度传感器故障
//unsigned char  flagYalisenserfault = 0;//增压压力传感器故障

//unsigned char  flagSwSenserfault = 0; //水温传感器故障
//unsigned char  flagTulunzhoufault = 0;//凸轮轴故障
//unsigned char flagQulunzhoufault = 0;//曲轴故障

/********************************************************************************************************************/


//2016.6.20 wsj
//下面是显示can数据 值的变量
//临时定义，后边产品要更根据情况去改和规范 变量的定义。 有一半的变量可以复用。
/********************************************************************************************************************/
// 最终协议
//2016.7.8
/********************************************************************************************************************/
//开关量
//18FF01F6


//第一个字节
unsigned char DC;  //倒车信号（倒车+） 7,
unsigned char SK;  //位置灯（位置灯+） 6,
unsigned char SouSa;//手刹指示灯（手刹指示灯+） 5,
unsigned char Zuozhuan; //左转向灯（左转向灯）4,
unsigned char Youzhuan;  //右转向灯（右转向灯）3,
unsigned char YuanGuang; //远光指示灯（远光指示灯） 2,
unsigned char Jinguang; //近光指示灯（近光指示灯） 1,


//第二个字节
uchar youshuifenli;  //油水分离 6,
uchar fadongjiguzhang;//发动机故障 5,
uchar yure; //预热 4,
uchar liangman; //粮满 3,
uchar KL;  //空滤报警开关（空滤-） 2,
//uchar CongDian; //充电指示灯-  1,


//频率量
ushort  shengyunqi;    //升运器
ushort  futuoqi;       //复脱器
ushort  zhouliuguntong;//轴流滚筒
float  shisu; //时速

//模拟量
//18FF04F6
unsigned char YouLiang;     //油量（油量）
unsigned char Yeyayouwen; //液压油油温（液压油油温）
unsigned int   MiJi = 0;      //米计（预留）
unsigned int   LiCheng = 0;   //里程（预留）

float MiJiFloat = 0.0;


//发动机 数据


//18FEEE00
unsigned char SuiWen;//水温；
float  jiyouyali; //机油压力

//0CF00400

float fadongzhuansu; //发动机转速


//18FECA00
//故障报文
//ulong guzhangbaowen; //故障报文
ulong  spn = 0;//spn 码
uchar fmi = 0;//fmi 码

ulong  spn2 = 0;//spn2 码
uchar fmi2 = 0;//fmi2 码

ulong  spn3 = 0;//spn3 码
uchar fmi3 = 0;//fmi3 码

ulong  spn4 = 0;//spn4 码
uchar fmi4 = 0;//fmi4 码


//预热指示灯
//18FEE400

//uchaflagFDJYRng;//18FEE400

//小时计
//18FEE500
unsigned int XiaoshiJi; //小时计

/********************************************************************************************************************/
//新增相关变量

uchar qianbulihezhishi;  //前部离合指示输入, 8

uchar tuolilihezhishi;  //脱粒离合指示输入, 7

uchar xieliangtongbaijin;//卸粮筒摆进限位开关 6

uchar Shoubing;//界面切换输入（手柄控制）4

//
uchar liangman70;//粮满 70, 1

//byte3
uchar xielianglihe_input;//卸粮离合开关输入 2
uchar guoqiaofanzhuan_input;//过桥反转指示输入 1


//byte4

uchar getaisheng_input;//割台升输入; 8
uchar getaijiang_input;//割台降输入; 7

uchar xltbj_input;//卸粮筒摆进输入 6
uchar xltbc_input;//卸粮筒摆出输入 5

uchar bhls_input;//拨禾轮升输入 4
uchar bhlj_input; //拨禾轮降输入; 3
uchar tltjiashu_input;//脱粒滚筒加速输入; 2

uchar tltjianshu_input = 0;//脱粒滚筒减速输入 1


//byte5

uchar getaisheng_out;//割台升输出; 8
uchar getaijiang_out;//割台降输出; 7

uchar xltbj_out;//卸粮筒摆进输出 6
uchar xltbc_out;//卸粮筒摆出输出 5

uchar bhls_out;//拨禾轮升输出 4
uchar bhlj_out; //拨禾轮降输出; 3
uchar tltjiashu_out;//脱粒滚筒加速输出; 2

uchar tltjianshu_out;//脱粒滚筒减速输出 1



uchar xiehefa_out;// 卸荷阀输出
uchar  xielianglihe_out;//卸粮离合输出; 1


//
ushort  qiesuiqizhuansu;//切碎器转速
ushort fengjizhuansu;//切碎器转速
ushort guoqiaozhuansu;//过桥转速；

ushort tuoliguntong;//脱粒滚筒转速
ushort fenliguntong;//分离滚筒转速


float jiyouwendu;//机油温度

/********************************************************************************************************************/
//故障码 标志定义
//用于数据库存储
/********************************************************************************************************************/

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    Widget::move(0,0);//回到原来主窗口的位置
    setWindowFlags(windowFlags()|Qt::FramelessWindowHint|Qt::WindowTitleHint);//删除 最小化、最大化、关闭按钮

//    //初始化 work子界面
//    work = new Work();
//    //初始化 Timesetup子界面
//    timeObj = new Timesetup();

//    //初始化 FindLook 子界面
//    findlook = new FindLook();


    setWindowTitle(tr("Haovel"));  //设置窗体名称
    resize(1024,600);

    QTimer *timer = new QTimer(this);   //声明一个定时器
    timer_xiaoshiji = new QTimer(); //声明小时计定时器

     timergzm = new QTimer();   //声明一个定时器

    //update()会自动产生重绘消息，调用paintEvent()
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));  //连接信号槽，定时器超时触发窗体更新
    connect(timer, SIGNAL(timeout()), this, SLOT(diplaytime()));  //连接信号槽，定时器超时触发窗体更新

    connect(timergzm, SIGNAL(timeout()), this, SLOT(gzmslot()));  //连接信号槽，定时器超时触发窗体更新


    connect(timer_xiaoshiji,SIGNAL(timeout()),this,SLOT(xiaoshiji()));//小时计



    //timertst->start(1000);


    timer->start(500);   //启动定时器
    timer_xiaoshiji->start(1000); //启动小时计定时器
    timergzm->start(1000);

    //timer->start(500);   //启动定时器


    //解析现象，当去掉 setWindowFlags(windowFlags()|Qt::FramelessWindowHint|Qt::WindowTitleHint); 这一句，在开发板子上能显示上方图标，但是不闪烁，
    //不注释则可以在板子上闪烁。
    setWindowFlags(windowFlags()|Qt::FramelessWindowHint|Qt::WindowTitleHint); //删除 最小化、最大化、关闭按钮

    //倒车摄像头信号与槽
    //connect(this,SIGNAL(sendcamersignal()),this,SLOT(cameraslot()));


    //线程初始化与启动
    mycan = new SignalCan();
    mycan->start();

    //测试库调用
  //Cam_Power_off(1);//1 为粮仓监视
  //Cam_Power_off(2);// 倒车
  //Cam_Power_off(3);//2 3 共用一个摄像头

   //beep_on_s();

}

Widget::~Widget()
{
    delete ui;

   qDebug() << "main widget delete" <<endl;
}


void Widget::paintEvent(QPaintEvent *event)
{
    //QTime time = QTime::currentTime();   //获取当前的时间
    QPainter painter(this);
    QPixmap pix;

    if (flaglanguage)
    {
    pix.load("./imagejy/xingzou2.bmp");
    painter.drawPixmap(0,0,800,600,pix);

    }
    else
    {
    pix.load("./imagejy/zw/xingzou.bmp");
    painter.drawPixmap(0,0,1024,600,pix);
    }

    painter.setRenderHint(QPainter::Antialiasing);//绘制的图像反锯齿
    painter.translate(218, 303);//重新定位坐标起始点，把坐标原点放到窗体的中央

    //下面两个数组用来定义表针的两个顶点，以便后面的填充
    static const QPoint hourHand[4] = {
        QPoint(8, 0),
        QPoint(-8,0),
        QPoint(-1.5, -170),
        QPoint(1.5, -170)
    };
    static const QPoint minuteHand[4] = {
        QPoint(8, 0),
        QPoint(-8,0),
        QPoint(-1.5, -170),
        QPoint(1.5, -170)
    };

    // r/mini

    painter.setPen(Qt::NoPen);//填充时针，不需要边线所以NoPen
    painter.setBrush(Qt::red);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.save();
   // painter.rotate(6.0 *time.second());  //设旋转(角度 = 6° * (分钟 + 秒 / 60))
    painter.rotate(-133);
//    painter.rotate(6.0 *numtmp);  //设置旋转(6° * 秒)
//    painter.rotate(numtmp++);  //设置旋转(6° * 秒)

    tmp_zs = fadongzhuansu/100;
    if(tmp_zs>30)
    {
        tmp_zs = 30;
    }
    painter.rotate(8.8*tmp_zs);


//    for (uchar numzs = 0; numzs < fadongzhuansu; numzs++)
//    {
//        painter.rotate(9.0);

//    }

    painter.drawConvexPolygon(hourHand, 4);  //填充分针部分

    painter.restore();

    /***********************************************/
    //2016.6.25   画白圈
    painter.setBrush(Qt::darkGray); //画上中心原点/home/vmuser/qtworkplace/chanpin/img2
    painter.save();
    painter.drawEllipse(QPoint(0,0),25,25);
    painter.restore();

    //画白圈
    /***********************************************/

    painter.setBrush(Qt::black);//画上中心原点/home/vmuser/qtworkplace/chanpin/img2
    painter.save();
    painter.drawEllipse(QPoint(0,0),20,20);
    painter.restore();


    //km/h
    painter.translate(579,1);//重新定位坐标起始点，把坐标原点放到窗体的中央
//painter.translate(220, 304);

    //painter.scale(side / 400.0, side / 300.0);

    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::red);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.save();

    //painter.rotate(6.0 *time.second());  //设旋转(角度 = 6° * (分钟 + 秒 / 60))

    painter.rotate(8.8*shisu);  //设旋转(角度 = 6° * )
    painter.rotate(-133);
   // painter.rotate(4.0 *shisu);  //设旋转(角度 = 6° * (分钟 + 秒 / 60))
    //内测用
    /****************************************************************************/
    //qDebug()<<"time: "<<time.second()<<endl;

    /****************************************************************************/

    painter.drawConvexPolygon(minuteHand, 4);  //填充分针部分
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.restore();

    /***********************************************/
    //2016.6.25   画白圈
    painter.setBrush(Qt::darkGray); //画上中心原点/home/vmuser/qtworkplace/chanpin/img2
    painter.save();
    painter.drawEllipse(QPoint(0,0),25,25);
    painter.restore();

    //画白圈
    /***********************************************/


    painter.setBrush(Qt::black);
    painter.save();//画上中心原点
     painter.drawEllipse(QPoint(0,0),20,20);
    painter.restore();


    //处理图片闪烁 shansuo
    painter.translate(-405,-432);//平移到左上角

/************************************************************************************************/

    //2016.6.25  定义数值
    #if 1
        ui->label->setText(QString::number(jiyouwendu,'f',0));//机油温度
        ui->label_2->setText(QString::number(Yeyayouwen));//液压油油温（液压油油温）
        ui->label_3->setText(QString::number(SuiWen));//水温；
        ui->label_4->setText(QString::number(jiyouyali,'f',2)); //机油压力
        //ui->label_5->setText(QString::number(XiaoshiJi));//小时计
        //ui->label_5->setText( QString("%1").arg(xiaoshiJi_h));

//        ui->label_11->setText(QString::number(MiJiFloat,'f',1));
//        ui->label_12->setText(QString::number(LiCheng,10));
    #endif

     /************************************************************************************************/

/************************************************************************************************/
#if 0
    if(beep_flag)
    {
        ui->pushButton_timesetup_3->setStyleSheet("QPushButton{border-image:url(./imagejy/laba.png);background-repeat: repeat-xy;background-position: center;background-attachment: fixed;background-clip: padding}");
        qDebug()<<"beep_flag = "<<beep_flag<<endl;

    }
    else
    {
        ui->pushButton_timesetup_3->setStyleSheet("QPushButton{border-image:url(./imagejy/labalaba.png);background-repeat: background-xy;background-position: center;background-attachment: fixed;background-clip: padding}");
        qDebug()<<"beep_flag = "<<beep_flag<<endl;
    }
#endif
/************************************************************************************************/







    //返回主界面。
#if 1
        if((DC==1)&&(wsjtmpflag == 0))
        {

            //DC = 0;
            //emit sendcamersignal();
             ok = true;

             QMouseEvent* press=new QMouseEvent(QEvent::MouseButtonPress,QPoint(2,2), Qt::LeftButton,Qt::LeftButton,Qt::NoModifier);
             QApplication::postEvent(ui->ptn_back,press);
             QMouseEvent* release=new QMouseEvent(QEvent::MouseButtonRelease,QPoint(2,2),Qt::LeftButton,Qt::LeftButton,Qt::NoModifier);
             QApplication::postEvent(ui->ptn_back,release);

             wsjtmpflag = 1;

        }

#endif
    /************************************************************************************************/
    //手柄切换控制

        //wzxx = 1;


#if 1

        if (Shoubing==1)
        {
            Shoubing = 0;
           // qDebug()<<"111 btn........ = "<<btn<<endl;
            btn++; //1,进入工作界面 ，
            switch(btn)
            {
                case 1:
                case 2:
                case 3:
            {
                btn++;
                if(btn>3)
                {
                    btn = 0;
                }

                QMouseEvent* pressWork=new QMouseEvent(QEvent::MouseButtonPress,QPoint(2,2), Qt::LeftButton,Qt::LeftButton,Qt::NoModifier);
                QApplication::postEvent(ui->ptn_back,pressWork);
                QMouseEvent* releaseWork=new QMouseEvent(QEvent::MouseButtonRelease,QPoint(2,2),Qt::LeftButton,Qt::LeftButton,Qt::NoModifier);
                QApplication::postEvent(ui->ptn_back,releaseWork);
            }
                break;


            default:
                btn = 0;
                break;

            }

        }

#endif




/************************************************************************************************/


    //闪烁不同步问题解决办法。
    //利用消息队列 和 for 循环解决。
    //2016.7.25

        QPainter paintShanshuo_W(this);
        QPixmap pixShanshuo_W;
        if(1) //左转灯闪烁
        {
            countLeft_W++;
            if (countLeft_W>1)
                countLeft_W = 0;
            switch(countLeft_W)
            {
                case 0:
                 qDebug()<<"000000000000000000000"<<endl;
                 break;

                case 1:

                if(flagSW)//水温 0~120度  95度以上报警。
                {
                     pixShanshuo_W.load("./imagejy/07.png");//07.jpg
                     paintShanshuo_W.drawPixmap(118,15,45,40,pixShanshuo_W);//正上方位置显示的图标
                }

                if(flagJY) //机油  油压报警 0～1 MPa,在0.1 MPa 以下为报警区。
                {
                     pixShanshuo_W.load("./imagejy/08.png");//08.jpg
                     paintShanshuo_W.drawPixmap(396,15,59,24,pixShanshuo_W);//正上方位置显示的图标
                     //paintShanshuo_W.drawPixmap(20,180,43,43,pixShanshuo_W);//左边显示的图标
                }


                if (flagyouliangdi)//油量
                {
                    pixShanshuo_W.load("./imagejy/09.png");//14.jpg
                    paintShanshuo_W.drawPixmap(615,15,31,36,pixShanshuo_W);

                    qDebug()<<"789789789789789"<<endl;

                    // paintShanshuo_W.drawPixmap(409,172,31,36,pixShanshuo_W);

                }

                break;
            }//endof switch()


        }//end if(1)

            //不用闪烁

            if(flagLeft)//左转灯闪烁
            {
                pixShanshuo_W.load("./imagejy/01.png");//14.jpg
                paintShanshuo_W.drawPixmap(0,15,44,46,pixShanshuo_W);
            }
            if(flagBattery)//电瓶指示灯  flagBattery
            {
                pixShanshuo_W.load("./imagejy/03.png");//14.jpg
                paintShanshuo_W.drawPixmap(60,15,46,32,pixShanshuo_W);//正上方图片显示
                //paintShanshuo_W.drawPixmap(20,335,43,34,pixShanshuo_W);//左边图片显示
            }
            if(flagGL)//空 滤
            {
                pixShanshuo_W.load("./imagejy/04.png");//04.jpg
                paintShanshuo_W.drawPixmap(469,15,42,43,pixShanshuo_W);
            }
            if(flagLCM)//flagLCM = 1; //粮仓满
            {
                pixShanshuo_W.load("./imagejy/13.png");//13.jpg
                paintShanshuo_W.drawPixmap(542,15,42,41,pixShanshuo_W);
            }

            if(flagLCM_seven)//flagLCM = 1; //粮仓满7000000000
            {
                pixShanshuo_W.load("./imagejy/70.png");//13.jpg
                paintShanshuo_W.drawPixmap(542,15,42,41,pixShanshuo_W);
            }

            if(flagFDJYR)//flagFDJYR = 1; //发动机预热
            {
                pixShanshuo_W.load("./imagejy/15.png");//15.jpg
                paintShanshuo_W.drawPixmap(761,25,46,27,pixShanshuo_W);
            }

            if(flagYeyayouwen)//液压油温
            {
                 pixShanshuo_W.load("./imagejy/10.png");//10.jpg
                 paintShanshuo_W.drawPixmap(688,15,48,38,pixShanshuo_W);//上边图标
                 //paintShanshuo_W.drawPixmap(423,216,49,38,pixShanshuo_W);//左边图标
            }

            if(flagECU)//ecu
            {
                pixShanshuo_W.load("./imagejy/91.png");//03.jpg
                paintShanshuo_W.drawPixmap(594,15,43,32,pixShanshuo_W);
            }

            if(flagFDJGZ)//发动机故障
            {
                pixShanshuo_W.load("./imagejy/16.png");//16.jpg
                paintShanshuo_W.drawPixmap(907,15,47,30,pixShanshuo_W);
            }


            if(flagWidthlamp)//示宽灯
            {
                pixShanshuo_W.load("./imagejy/06.png");//06.jpg
                paintShanshuo_W.drawPixmap(177,15,57,32,pixShanshuo_W);
            }

            if(flagJG)//近光灯flagJG
            {
                pixShanshuo_W.load("./imagejy/12.png");//12.jpg
                paintShanshuo_W.drawPixmap(250,15,46,37,pixShanshuo_W);
            }

            if(flagYG)//远光灯
            {
                pixShanshuo_W.load("./imagejy/05.png");//05.jpg
                paintShanshuo_W.drawPixmap(323,15,46,37,pixShanshuo_W);
            }

            if(flagPark)//停车 刹车
            {
                pixShanshuo_W.load("./imagejy/11.png");//11.jpg
                paintShanshuo_W.drawPixmap(834,15,48,37,pixShanshuo_W);
            }

            if(flagRight)//右转
            {
                pixShanshuo_W.load("./imagejy/02.png");//14.jpg
                paintShanshuo_W.drawPixmap(978,15,44,46,pixShanshuo_W);
            }




            //油量格数
            //if (flagyouxiangman|flagyouliangdi)//油量
            if (1)
            {
                switch(YouLiang)//flagyouxiangman
                {

                case 0:
                    pixShanshuo_W.load("./imagejy/yl00.png");//14.jpg
                    paintShanshuo_W.drawPixmap(446,182,166,26,pixShanshuo_W);
                    break;

                case 1:
                    pixShanshuo_W.load("./imagejy/yl01.png");//14.jpg
                    paintShanshuo_W.drawPixmap(446,182,166,26,pixShanshuo_W);
                    break;

                case 2:
                    pixShanshuo_W.load("./imagejy/yl02.png");//14.jpg
                    paintShanshuo_W.drawPixmap(446,182,166,26,pixShanshuo_W);
                    break;

                case 3:
                    pixShanshuo_W.load("./imagejy/yl03.png");//14.jpg
                    paintShanshuo_W.drawPixmap(446,182,166,26,pixShanshuo_W);
                    break;
                case 4:
                    pixShanshuo_W.load("./imagejy/yl04.png");//14.jpg
                    paintShanshuo_W.drawPixmap(446,182,166,26,pixShanshuo_W);
                    break;
                case 5:
                    pixShanshuo_W.load("./imagejy/yl05.png");//14.jpg
                    paintShanshuo_W.drawPixmap(446,182,166,26,pixShanshuo_W);
                    break;
                case 6:
                    pixShanshuo_W.load("./imagejy/yl06.png");//14.jpg
                    paintShanshuo_W.drawPixmap(446,182,166,26,pixShanshuo_W);
                    break;
                case 7:
                    pixShanshuo_W.load("./imagejy/yl07.png");//14.jpg
                    paintShanshuo_W.drawPixmap(446,182,166,26,pixShanshuo_W);
                    break;
                case 8:
                    pixShanshuo_W.load("./imagejy/yl08.png");//14.jpg
                    paintShanshuo_W.drawPixmap(446,182,166,26,pixShanshuo_W);
                    break;

                default:

                    pixShanshuo_W.load("./imagejy/yl00.png");//14.jpg
                    paintShanshuo_W.drawPixmap(446,182,166,26,pixShanshuo_W);
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

void Widget::on_pushButton_timesetup_clicked() //设置按钮
{
    this->close();
    timeObj.show();
    timeObj.exec();
    this->show();
}

void Widget::on_ptn_back_clicked()// 进入子界面，并返回按键事件
{
    this->close();
    work.show();
    work.exec();
    this->show();
}

void Widget::on_pushButton_timesetup_2_clicked()  //查询按钮
{
    this->close();
    findlook.show();
    findlook.exec();
    this->show();
}

void Widget::diplaytime()
{
//    QString time_display =  QTime::currentTime().toString();     //绘制当前的时间
//    ui->lcdNumber->display(time_display);

    QString timeStr= QTime::currentTime().toString();     //绘制当前的时间
    QString dateStr = QDate::currentDate().toString("yyyy-MM-dd");

    ui->lcdNumber_2->display(dateStr);
    ui->lcdNumber->display(timeStr);
}



void Widget::on_pushButton_timesetup_3_clicked()//喇叭按钮
{

#if 0
    if(beep_flag)
    {
        beep_flag = false;

        ui->pushButton_timesetup_3->setStyleSheet("QPushButton{border-image:url(./imagejy/labalaba.png);background-repeat: background-xy;background-position: center;background-attachment: fixed;background-clip: padding}");
        qDebug()<<"beep_flag = "<<beep_flag<<endl;

        qDebug()<<"youliangbutton =  "<<flagyouliangdi<<endl;

    }
    else
    {
        beep_flag = true;
        ui->pushButton_timesetup_3->setStyleSheet("QPushButton{border-image:url(./imagejy/laba.png);background-repeat: repeat-xy;background-position: center;background-attachment: fixed;background-clip: padding}");

        qDebug()<<"beep_flag = "<<beep_flag<<endl;
    }
#endif
}


//小时计 槽函数
void Widget::xiaoshiji()
{
   #if 0
    xiaoshiJi_m++;
    xiaoshiJi_h = (xiaoshiJi_m/60)*10 + ((xiaoshiJi_m%60)/10);
    xiaoshiJi_h /= 10;
    ui->label_5->setText( QString("%1").arg(xiaoshiJi_h));
    #endif

    //system("rm my.db");
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());//汉字显示


    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
      db = QSqlDatabase::database("qt_sql_default_connection");
    else
      db = QSqlDatabase::addDatabase("QSQLITE");


   //QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
   db.setDatabaseName("my6.db");
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

   query.exec("select id, name, age from myjy10");
   while (query.next())
   {

     // qDebug()<<"id("<<query.value(0).toInt()<<")  name:"<<query.value(1).toString()<<"  age:"<<query.value(2).toInt();
     //xiaoshiJi_m = query.value(2).toInt();

       xiaoshiJi_m = query.value(2).toLongLong();

   }

   if (fadongzhuansu>350)//
   {
        xiaoshiJi_m++;
   }
    xiaoshiJi_h = (xiaoshiJi_m/3600)*100 + (xiaoshiJi_m%3600)/60;
    xiaoshiJi_h /= 100;
    ui->label_5->setText(QString::number(xiaoshiJi_h,'f',1));



#if 0
    switch(jun[iiii])
    {
        case 1:
         ui->label_6->setText(QObject::tr("1"));
         break;
    case 2:
         ui->label_6->setText(QObject::tr("2"));
         break;
    case 3:
         ui->label_6->setText(QObject::tr("3"));
         break;

    case 4:
         ui->label_6->setText(QObject::tr("4"));
         break;
    case 5:
         ui->label_6->setText(QObject::tr("5"));
         break;
    case 6:
         ui->label_6->setText(QObject::tr("6"));
         break;
    }
    iiii++;
    if (iiii >= 6)
        iiii = 0;
#endif

    //ui->label_6->setText(QObject::tr("远程油门2倍关系不可信"));

          //query.prepare("INSERT INTO myjy10 (id, name, age) VALUES (:id, :name, :age)");

          query.prepare("update myjy10 set age = :age where id = :id");

          //query.prepare(update_sql);
          query.bindValue(":id",1);
          //query.bindValue(":name", QObject::tr("小时计"));
          query.bindValue(":age", xiaoshiJi_m);
          query.exec();



        query.exec("select id, name, age from myjy10");
        while (query.next())
        {

           //qDebug()<<"id("<<query.value(0).toInt()<<")  name:"<<query.value(1).toString()<<"  age:"<<query.value(2).toInt();
        }

        query.exec(QObject::tr("drop myjy10"));

/*******************************************************************/

}


void Widget::gzmslot()
{

        //qDebug()<<"88888888888888888888888                 "<<can_retern<<"conter = "<<can_err_count<<endl;

         if (can_retern == 0)
         {
            can_err_count++;
            if(can_err_count>=5)
            {
                ui->label_showCan->setText("CAN SIGNAL ERROR !!");
                //can_err_count = 0;

// 界面值归零

#if 1

                jiyouwendu = 0.0;
                Yeyayouwen = 0;
                SuiWen = 0;
                jiyouyali = 0;
                MiJiFloat = 0.0;
                LiCheng = 0;
                shisu = 0;
                fadongzhuansu = 0;
                jiyouyali = 0;


                flagSW = 0;
                //flagyouxiangman = 0;
                flagyouliangdi = 0;
                flagYeyayouwen = 0;

                flagLeft = 0;
                flagBattery = 0;
                flagLCM = 0;
                flagLCM_seven = 0;
                flagFDJYR = 0;
                flagGL = 0;
                flagECU = 0;
                flagFDJGZ = 0;
                flagRight = 0;
                flagWidthlamp = 0;
                flagJG = 0;
                flagYG = 0;
                flagPark = 0;



                flagJY = 0;
                qiesuiqizhuansu = 0;//切碎器转速
                fengjizhuansu = 0;//风机转速
                guoqiaozhuansu = 0;//过桥转速；

                tuoliguntong = 0;//脱粒滚筒转速
                fenliguntong = 0;//分离滚筒转速

                shengyunqi = 0;    //升运器
                futuoqi = 0;       //复脱器


                spn = 0;//spn 码
                fmi = 0;//fmi 码

                spn2 = 0;//spn2 码
                fmi2 = 0;//fmi2 码

                spn3 = 0;//spn3 码
                fmi3 = 0;//fmi3 码

                spn4 = 0;//spn4 码
                fmi4 = 0;//fmi4 码


                ok = false; //tui chu camera daoche
                BH = true;
                flagqh2 = true;



#endif
//

            }
            else
            {
                ui->label_showCan->setText("");

            }
         }
         else
         {
            can_err_count = 0;
            can_retern = 0;
            ui->label_showCan->setText("");
         }



         ui->label->setText(QString::number(jiyouwendu,'f',1));//机油温度
         ui->label_2->setText(QString::number(Yeyayouwen));//液压油油温（液压油油温）
         ui->label_3->setText(QString::number(SuiWen));//水温；
         ui->label_4->setText(QString::number(jiyouyali)); //机油压力
         //ui->label_5->setText(QString::number(XiaoshiJi));//小时计
         //ui->label_5->setText( QString("%1").arg(xiaoshiJi_h));

//         ui->label_11->setText(QString::number(MiJiFloat,'f',1));
//         ui->label_12->setText(QString::number(LiCheng,10));


#if 0
    if(beep_flag)
    {

        qDebug()<<"youlianggzmmmmm =  "<<flagyouliangdi<<endl;
        //添加蜂鸣器报警
        if(flagSW||flagyouliangdi||flagYeyayouwen)//flagyouxiangman||
        {
             //beep_off();//关闭蜂鸣器

            beep_on_s();//打开蜂鸣器

            //beep_on();

             //qDebug()<<"123456"<<wsj++<<endl;
             //beep_off();//关闭蜂鸣器

             beep_widget = true;

        }
        else
        {
            beep_off();//关闭蜂鸣器

            beep_widget = false;
        }
    }
    else
    {
        beep_off();
    }


#endif



#if 1


    if(fmiArry[gzm_widget] != 0)
    {
        ui->label_9->setText(QString::number(fmiArry[gzm_widget],10));
    }
    else
    {
        ui->label_9->setText("");

    }

    if(spnArry[gzm_widget] != 0)
    {
        ui->label_10->setText(QString::number(spnArry[gzm_widget],10));
    }
    else
    {
        ui->label_10->setText("");
    }

     gzm_widget++;
     if(gzm_widget>=4)
     {
        gzm_widget = 0;
        memset(fmiArry,0,4);
        memset(spnArry,0,32);
     }

#endif

}
