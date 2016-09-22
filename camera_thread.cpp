


#if 0



#include "camera_thread.h"
#include"videodevice.h"
#include"common.h"
#include<QDebug>



uchar *m;
QImage *img;


uchar *m2;
QImage *img2;

Camera_thread::Camera_thread(QObject *parent) :
    QThread(parent)
{
}


//Camera_thread::~Camera_thread()
//{

////   // HWE_CloseVideo();
////    this->quit();
////    //quit_flag = true;
////    this->wait();
//}


void Camera_thread::run()
{
    camera_hw.camera_init();
    m = (unsigned char *)malloc(IMG_WIDTH * IMG_HEIGTH/*QWidget::width()*QWidget::height()*/* 3 * sizeof(char));
    //m2 = (unsigned char *)malloc(IMG_WIDTH * IMG_HEIGTH/*QWidget::width()*QWidget::height()*/* 3 * sizeof(char));


    img = new QImage(m,IMG_WIDTH,IMG_HEIGTH,QImage::Format_RGB888);//定义摄像头抓取帧句柄-QImage类型
    //img2 = new QImage(m2,IMG_WIDTH,IMG_HEIGTH,QImage::Format_RGB888);//定义摄像头抓取帧句柄-QImage类型

    while(1)
    {

//        img = new QImage(m,IMG_WIDTH,IMG_HEIGTH,QImage::Format_RGB888);//定义摄像头抓取帧句柄-QImage类型
//        img2 = new QImage(m2,IMG_WIDTH,IMG_HEIGTH,QImage::Format_RGB888);//定义摄像头抓取帧句柄-QImage类型



         //m = (unsigned char *)malloc(IMG_WIDTH * IMG_HEIGTH/*QWidget::width()*QWidget::height()*/* 3 * sizeof(char));
        //QImage *img = new QImage(m,IMG_WIDTH,IMG_HEIGTH,QImage::Format_RGB888);//定义摄像头抓取帧句柄-QImage类型
        camera_hw.tmtt(img);
        //camera_hw.tmtt2(img2);


        emit image_data(img);
        //msleep(40); //停留40毫秒

         //QThread::msleep(4);
        //emit image_data2(img2);
       // msleep(40); //停留40毫秒

        QThread::msleep(40);


    }

    //delete img;
    //delete img2;

    camera_hw.realsedate();
}


#endif
