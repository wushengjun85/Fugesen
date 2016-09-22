#include "findlook.h"
#include "ui_findlook.h"


#include<QPainter>
#include<QString>
#include<QTime>
#include<QTimer>
#include<QMouseEvent>
#include<QDebug>


bool resetFlag = false;

extern unsigned int   LiCheng;   //里程（预留）

extern float MiJiFloat; //米计


extern uchar btn;

extern uchar qianbulihezhishi;  //前部离合指示输入, 8

extern uchar tuolilihezhishi;  //脱粒离合指示输入, 7

extern uchar xieliangtongbaijin;//卸粮筒摆进限位开关 6

extern uchar Shoubing;//界面切换输入（手柄控制）4


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




FindLook::FindLook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindLook)
{
    ui->setupUi(this);

    FindLook::move(0,0);//回到原来主窗口的位置
    setWindowFlags(windowFlags()|Qt::FramelessWindowHint|Qt::WindowTitleHint);//删除 最小化、最大化、关闭按钮

    QTimer *tmf = new QTimer(this);
    connect(tmf, SIGNAL(timeout()), this, SLOT(update()));  //连接信号槽，定时器超时触发窗体更新
    tmf->start(500);
}

FindLook::~FindLook()
{
    delete ui;
}

void FindLook::on_pushButton_clicked()
{
    this->close();
}

void FindLook::paintEvent(QPaintEvent *)
{
    QTime time = QTime::currentTime();   //获取当前的时间
    QPainter painter(this);
    QPixmap pix;
    pix.load("./imagejy/english/findlook.bmp");
    painter.drawPixmap(0,0,1024,600,pix);


    /**************************************************************************************************************/
    //显示时间 。2016.7.12
        QString timeStr1= QTime::currentTime().toString();     //绘制当前的时间
        QString dateStr1 = QDate::currentDate().toString("yyyy-MM-dd");

        ui->lcdNumber_2->display(dateStr1);//dateStr1
        ui->lcdNumber->display(timeStr1);


        ui->label->setText(QString::number(MiJiFloat,'f',1));
        ui->label_2->setText(QString::number(LiCheng,10));
    /**************************************************************************************************************/


#if 1

        if (Shoubing==1)
        {

                qDebug()<<"333 btn........ = "<<btn<<endl;
                Shoubing = 0;
                btn++; //1,进入工作界面 ，

            switch(btn)
            {
                case 1:
                case 2:
                case 3:
            {
                btn = 0;

                QMouseEvent* presslook=new QMouseEvent(QEvent::MouseButtonPress,QPoint(2,2), Qt::LeftButton,Qt::LeftButton,Qt::NoModifier);
                QApplication::postEvent(ui->pushButton,presslook);
                QMouseEvent* releaselook=new QMouseEvent(QEvent::MouseButtonRelease,QPoint(2,2),Qt::LeftButton,Qt::LeftButton,Qt::NoModifier);
                QApplication::postEvent(ui->pushButton,releaselook);
            }
                break;

            default:
                btn = 0;
                break;

            }

        }

#endif


    /**********************************************************************************************************************/
    //2016.7.6 radiobutton input and output;


    //bhls_input = 1;

    QPainter point1_in(this);
    QPixmap pointpix1_in;

    if (bhls_input) //拨禾轮升输入
    {

        pointpix1_in.load("./imagejy/deng1.png");
        point1_in.drawPixmap(402,162,15,15,pointpix1_in);
    }

    //bhls_out = 1;

    if (bhls_out)//拨禾轮升输出 4
    {
         pointpix1_in.load("./imagejy/deng1.png");
         point1_in.drawPixmap(453,162,15,15,pointpix1_in);
    }


    //bhlj_input = 1;
    if (bhlj_input) //拨禾轮降输入; 3
    {
        pointpix1_in.load("./imagejy/deng1.png");
        point1_in.drawPixmap(402,198,15,15,pointpix1_in);
    }

   // bhlj_out = 1;
    if (bhlj_out)//拨禾轮降输出; 3
    {
        pointpix1_in.load("./imagejy/deng1.png");
        point1_in.drawPixmap(453,198,15,15,pointpix1_in);
    }


    //getaisheng_input = 1;
    if (getaisheng_input)//割台升输入;
    {
        pointpix1_in.load("./imagejy/deng1.png");
        point1_in.drawPixmap(402,234,15,15,pointpix1_in);
    }


    //getaisheng_out = 1;
    if (getaisheng_out)//割台升输出;
    {
        pointpix1_in.load("./imagejy/deng1.png");
        point1_in.drawPixmap(453,234,15,15,pointpix1_in);
    }

    //getaijiang_input = 1;
    if (getaijiang_input)//割台降输入; 7
    {
        pointpix1_in.load("./imagejy/deng1.png");
        point1_in.drawPixmap(402,270,15,15,pointpix1_in);
    }

    //getaijiang_out = 1;
    if (getaijiang_out)//割台降输出; 7
    {
        pointpix1_in.load("./imagejy/deng1.png");
        point1_in.drawPixmap(453,270,15,15,pointpix1_in);
    }




    //xltbj_input = 1;
    if (xltbj_input)//卸粮筒摆进输入 6
    {
        pointpix1_in.load("./imagejy/deng1.png");
        point1_in.drawPixmap(402,305,15,15,pointpix1_in);
    }

    //xltbj_out = 1;
    if (xltbj_out)//卸粮筒摆进输出 6
    {
        pointpix1_in.load("./imagejy/deng1.png");
        point1_in.drawPixmap(453,305,15,15,pointpix1_in);
    }


    //xltbc_input = 1;
    if (xltbc_input)//卸粮筒摆出输入 5
    {
        pointpix1_in.load("./imagejy/deng1.png");
        point1_in.drawPixmap(402,340,15,15,pointpix1_in);
    }

    //xltbc_out = 1;
    if (xltbc_out)//卸粮筒摆出输出 5
    {
        pointpix1_in.load("./imagejy/deng1.png");
        point1_in.drawPixmap(453,340,15,15,pointpix1_in);
    }



    //tltjiashu_input = 1;
    if (tltjiashu_input)//脱粒滚筒加速输入;
    {
        pointpix1_in.load("./imagejy/deng1.png");
        point1_in.drawPixmap(402,376,15,15,pointpix1_in);
    }

    //tltjiashu_out = 1;
    if (tltjiashu_out)//脱粒滚筒加速输出;
    {
        pointpix1_in.load("./imagejy/deng1.png");
        point1_in.drawPixmap(453,376,15,15,pointpix1_in);
    }

    //tltjianshu_input = 1;
    if (tltjianshu_input)//脱粒滚筒减速输入 1
    {
        pointpix1_in.load("./imagejy/deng1.png");
        point1_in.drawPixmap(402,411,15,15,pointpix1_in);
    }

    //tltjianshu_out = 1;

    if (tltjianshu_out)//脱粒滚筒减速输出 1
    {
        pointpix1_in.load("./imagejy/deng1.png");
        point1_in.drawPixmap(453,411,15,15,pointpix1_in);
    }


    //Shoubing = 1;
    if (Shoubing)//界面切换输入（手柄控制）4
    {
        pointpix1_in.load("./imagejy/deng1.png");
        point1_in.drawPixmap(807,162,15,15,pointpix1_in);
    }

    //qianbulihezhishi = 1;
    if (qianbulihezhishi)//前部离合指示输入, 8
    {
        pointpix1_in.load("./imagejy/deng1.png");
        point1_in.drawPixmap(807,198,15,15,pointpix1_in);
    }

    //guoqiaofanzhuan_input = 1;
    if (guoqiaofanzhuan_input)//过桥反转指示输入 1
    {
        pointpix1_in.load("./imagejy/deng1.png");
        point1_in.drawPixmap(807,234,15,15,pointpix1_in);
    }

    //xieliangtongbaijin = 1;
    if (xieliangtongbaijin)//卸粮筒摆进限位开关 6
    {
        pointpix1_in.load("./imagejy/deng1.png");
        point1_in.drawPixmap(807,270,15,15,pointpix1_in);
    }

    //tuolilihezhishi =1;
    if ( tuolilihezhishi)//脱粒离合指示输入, 7
    {
        pointpix1_in.load("./imagejy/deng1.png");
        point1_in.drawPixmap(807,306,15,15,pointpix1_in);
    }


    //xielianglihe_input =1;
    if (xielianglihe_input)//卸粮离合输入; 1
    {
        pointpix1_in.load("./imagejy/deng1.png");
        point1_in.drawPixmap(807,341,15,15,pointpix1_in);
    }


    //xielianglihe_out = 1;
    if (xielianglihe_out)//卸粮离合输出; 1
    {
        pointpix1_in.load("./imagejy/deng1.png");
        point1_in.drawPixmap(858,341,15,15,pointpix1_in);
    }


    //xiehefa_out =1;

    if (xiehefa_out)// 卸荷阀输出
    {
        pointpix1_in.load("./imagejy/deng1.png");
        point1_in.drawPixmap(858,377,15,15,pointpix1_in);
    }
    /********************************************************************************************************/

}

void FindLook::on_pushButton_2_clicked() //reset 米计 清零
{
    resetFlag = true; 
    //ui->pushButton_16->setStyleSheet("QPushButton{border-image:url(./imagejy/yjsdbh.png);background-repeat: repeat-xy;background-position: center;background-attachment: fixed;background-clip: padding}");
}
