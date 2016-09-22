#ifndef WORK_H
#define WORK_H

#include <QDialog>
#include"findlook.h"
#include"timesetup.h"
//#include"camera_thread.h"
#include"videodevice.h"
#include"common.h"
#include<QMessageBox>

namespace Ui {
class Work;
}

class Work : public QDialog
{
    Q_OBJECT
    
public:
    explicit Work(QWidget *parent = 0);
    ~Work();
    
private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

#if 0
    void show_picture(QImage  *img);
    void show_picture2(QImage *img2);

    void start_thread(void);
    void stop_thread();
#endif
    void on_pushButton_3_clicked();

    void workgzmslot();

private:
    Ui::Work *ui;
    FindLook findlokk_work;
    Timesetup time_work;


    //Camera_thread *video;



protected:
    void paintEvent(QPaintEvent *event);


//signals:
//        void camerastartsignal();

//        void camerastartsignal2();



public slots:

        void cameraslot1();
        void cameraslot2();

private:
    /*****************************************************************************/
    //摄像头对象定义
    QImage *frame;//定义抓取帧
    QImage *frame1;//定义抓取帧
    //QPixmap *frame;
    //MyLabel *labelx;//定义子类化显示窗体
    QTimer *timercamera;//定时器

    QTimer *timercamera2;//定时器

    int rs,rs1;
    //uchar *pp;//摄像头抓取指针
    uchar * p;//转换RGB指针
    //uchar *pp1;//摄像头抓取指针
    uchar * p1;//转换RGB指针
    //uchar * pimg;//转换IMG需要的指针缓冲区
    unsigned int len;//帧缓冲区长度
    int convert_yuv_to_rgb_pixel(int y, int u, int v);//YUV格式到RGB的转换
    int convert_yuv_to_rgb_buffer(unsigned char *yuv, unsigned char *rgb, unsigned int width, unsigned int height);
    VideoDevice *vd;//定义摄像头设备
    VideoDevice *vd1;//定义摄像头设备
    /*****************************************************************************/

};

#endif // WORK_H
