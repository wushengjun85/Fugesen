
#include "canread.h"
#include <QWidget>
extern unsigned char flagWidthlamp;

//2016.8.30 extern 短路开路按钮
extern uchar duanlu_tlgt;
extern uchar duanlu_qsq;
extern uchar duanlu_fj;
extern uchar duanlu_ftq;
extern uchar duanlu_syq;
extern uchar duanlu_gq;
extern uchar duanlu_fl;



extern uchar MiJi_send;
extern int   can_retern; // can_return = ret //返回can 读取的数据

extern bool resetFlag;//从findlook.cpp 引用的变量


//2016.6.22  extern widget.cpp 中的变量。
/********************************************************************************************************************/
//速度定义 speed
extern unsigned short int speed = 0;
//unsigned short int
extern unsigned char daoche = 0;

extern float jiyouwendu;

uchar PackGZM[4][8] = {{0,0}};
uchar Packend = 1; //结束标志
uchar Packcount = 0;//接收到的包数

uchar gzmend = 0;
uchar gzmi = 0;
uchar gzmj = 0;


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

//extern unsigned char flagBattery;//电瓶指示灯 充电指示灯

//第三个字节

//第二个字节



//第一个字节


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

extern float MiJiFloat;


//发动机 数据
//18FEEE00
extern unsigned char SuiWen;//水温；
extern float  jiyouyali; //机油压力

//0CF00400

extern float fadongzhuansu; //发动机转速


//18FECA00
//故障报文
//extern ulong guzhangbaowen; //故障报文
extern ulong  spn;//spn 码
extern uchar fmi;//fmi 码


extern ulong  spn2;//spn 码
extern uchar fmi2;//fmi 码

extern ulong  spn3;//spn 码
extern uchar fmi3;//fmi 码

extern ulong  spn4;//spn 码
extern uchar fmi4;//fmi 码


//预热指示灯
//18FEE400

uchar yurezhishideng = 0;// 以后时间替换掉 这个变量。

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
extern ushort fengjizhuansu;//风机转速
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


extern unsigned char flagBattery;//电瓶指示灯 充电指示灯


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

Canread::Canread()
{
}

void Canread::shutdownfd(int fd)
{
    close(fd);
}


 int Canread::initcan(int *retfd)
 {
     int s;
         int ret;
         struct sockaddr_can addr;
         struct ifreq ifr;



     srand(time(NULL));
         s = socket(PF_CAN, SOCK_RAW, CAN_RAW);
         if (s < 0) {
             perror("socket PF_CAN failed");
             return 1;
         }
         else
         {
            *retfd = s;
         }

         strcpy(ifr.ifr_name, "can0");
         ret = ioctl(s, SIOCGIFINDEX, &ifr);
         if (ret < 0) {
             perror("ioctl failed");
             return 1;
         }

         addr.can_family = PF_CAN;
         addr.can_ifindex = ifr.ifr_ifindex;

         ret = bind(s, (struct sockaddr *)&addr, sizeof(addr));
         if (ret < 0) {
             perror("bind failed");
             return 1;
         }
     if (1) {
         struct can_filter filter[20];
         filter[0].can_id = 0x200 | CAN_EFF_FLAG;
         filter[0].can_mask = 0xFFF;

         filter[1].can_id = 0x20F | CAN_EFF_FLAG;
         filter[1].can_mask = 0xFFF;

         filter[2].can_id = 0x18FF01F6;
         filter[2].can_mask = 0xfff;

#if 1
         filter[3].can_id = 0x18FF11F6;
         filter[3].can_mask = 0xfff;

         filter[4].can_id = 0x18FF21F6;
         filter[4].can_mask = 0xfff;

         filter[5].can_id = 0x18FF31F6;
         filter[5].can_mask = 0xfff;


         filter[6].can_id = 0x18FF04F6;
         filter[6].can_mask = 0xfff;


         filter[7].can_id = 0x18FECA00;
         filter[7].can_mask = 0xfff;


         filter[8].can_id = 0x0CF00400;
         filter[8].can_mask = 0xfff;



         filter[9].can_id = 0x18ecff00;
         filter[9].can_mask = 0xfff;

         filter[10].can_id = 0x18ebff00;
         filter[10].can_mask = 0xfff;

         filter[11].can_id = 0x18FEEF00;
         filter[11].can_mask = 0xfff;


#endif

         ret = setsockopt(s, SOL_CAN_RAW, CAN_RAW_FILTER, &filter, sizeof(filter));
         if (ret < 0) {
             perror("setsockopt failed");
             return 1;
         }
     }

 }


 void Canread::print_frame(struct can_frame *fr)
{
    int i;
    printf("%08x\n", fr->can_id & CAN_EFF_MASK);
    //printf("%08x\n", fr->can_id);
    printf("dlc = %d\n", fr->can_dlc);
    printf("data = ");
    for (i = 0; i < fr->can_dlc; i++)
        printf("%02x ", fr->data[i]);//
    printf("\n");
}


 void Canread::handle_err_frame(const struct can_frame *fr)
{
    if (fr->can_id & CAN_ERR_TX_TIMEOUT) {
        errout("CAN_ERR_TX_TIMEOUT");
    }
    if (fr->can_id & CAN_ERR_LOSTARB) {
        errout("CAN_ERR_LOSTARB");
        errcode(fr->data[0]);
    }
    if (fr->can_id & CAN_ERR_CRTL) {
        errout("CAN_ERR_CRTL");
        errcode(fr->data[1]);
    }
    if (fr->can_id & CAN_ERR_PROT) {
        errout("CAN_ERR_PROT");
        errcode(fr->data[2]);
        errcode(fr->data[3]);
    }
    if (fr->can_id & CAN_ERR_TRX) {
        errout("CAN_ERR_TRX");
        errcode(fr->data[4]);
    }
    if (fr->can_id & CAN_ERR_ACK) {
        errout("CAN_ERR_ACK");
    }
    if (fr->can_id & CAN_ERR_BUSOFF) {
        errout("CAN_ERR_BUSOFF");
    }
    if (fr->can_id & CAN_ERR_BUSERROR) {
        errout("CAN_ERR_BUSERROR");
    }
    if (fr->can_id & CAN_ERR_RESTARTED) {
        errout("CAN_ERR_RESTARTED");
    }
}

 int Canread::test_can_rw(int fd, int master)
{
    int ret, i;
    struct can_frame fr, frdup,send_frame;
    struct timeval tv;
    fd_set rset;

    while (1) {
        tv.tv_sec = 1;
        tv.tv_usec = 0;
        FD_ZERO(&rset);
        FD_SET(fd, &rset);
       // printf("=====\r\n");
/*
        ret = select(fd+1, &rset, NULL, NULL, NULL);
        if (ret == 0) {
            myerr("select time out");
            return -1;
        }
*/
        //printf("------------------------ \n");
        ret = read(fd, &frdup, sizeof(frdup));
        if (ret < sizeof(frdup)) {
            myerr("read failed");
            return -1;
        }
        can_retern = ret;//返回can 读取的数量 作为通信标志

        if (frdup.can_id & CAN_ERR_FLAG) { /* 出错设备错误 */
            handle_err_frame(&frdup);
            myerr("CAN device error");
            continue;
        }


       //解析数据
       switch(frdup.can_id&CAN_EFF_MASK)
       {
            case 0x18ff01f6:
            speed = frdup.data[0]|frdup.data[1];


            /********************************************************************/
            //仪表值 有可以不用定义的变量，目前来说只是实验，等到正式产品的时候可以精简一下。
            /********************************************************************/
            //byte1 移位操作
            YuanGuang = (frdup.data[0]>>7)&0x01; //远光指示灯（远光指示灯） 8,
            flagYG = YuanGuang;

            Jinguang = (frdup.data[0]>>6)&0x01; //近光指示灯（近光指示灯） 7,
            flagJG = Jinguang;

            SK = (frdup.data[0]>>5)&0x01; //位置灯（位置灯+） 6,
            flagWidthlamp =SK;

            Zuozhuan = (frdup.data[0]>>4)&0x01; //左转向灯（左转向灯）5,
            flagLeft = Zuozhuan;

            Youzhuan = (frdup.data[0]>>3)&0x01; //右转向灯（右转向灯）4,
            flagRight = Youzhuan;

            SouSa = (frdup.data[0]>>2)&0x01; //手刹指示灯（手刹指示灯+） 3,
            flagPark= SouSa;

            DC = (frdup.data[0]>>1)&0x01; //倒车信号（倒车+） 2,
            //flagGL = DC;

            yure = frdup.data[0]&0x01;  //预热  1,
            flagFDJYR = yure;




            //byte2
#if 0
            youshuifenli = (frdup.data[1]>>5)&0x01;  //油水分离 6,
            flagBattery = youshuifenli;

            fadongjiguzhang = (frdup.data[1]>>4)&0x01;//发动机故障 5,

#endif

            qianbulihezhishi = (frdup.data[1]>>7)&0x01;  //前部离合指示输入, 8

            tuolilihezhishi =  (frdup.data[1]>>6)&0x01;  //脱粒离合指示输入, 7

            xieliangtongbaijin = (frdup.data[1]>>5)&0x01;//卸粮筒摆进限位开关 6

            flagBattery = (frdup.data[1]>>4)&0x01;  //充电指示灯-  5,

            Shoubing = (frdup.data[1]>>3)&0x01;  //界面切换输入（手柄控制）4

            KL = (frdup.data[1]>>2)&0x01;   //空滤报警开关（空滤-） 3,
            flagGL = KL;

            liangman = (frdup.data[1]>>1)&0x01; //粮满100 , 2
            flagLCM = liangman;

            liangman70 = frdup.data[1]&0x01; //粮满 70, 1

            flagLCM_seven = liangman70;


            //byte3
            xielianglihe_input = (frdup.data[2]>>1)&0x01;//卸粮离合开关输入 2
            guoqiaofanzhuan_input = (frdup.data[2])&0x01;    //过桥反转指示输入 1


            //byte4

            getaisheng_input = (frdup.data[3]>>7)&0x01;//割台升输入; 8
            getaijiang_input = (frdup.data[3]>>6)&0x01;//割台降输入; 7

            xltbj_input = (frdup.data[3]>>5)&0x01;//卸粮筒摆进输入 6
            xltbc_input = (frdup.data[3]>>4)&0x01;//卸粮筒摆出输入 5

            bhls_input = (frdup.data[3]>>3)&0x01;//拨禾轮升输入 4
            bhlj_input = (frdup.data[3]>>2)&0x01; //拨禾轮降输入; 3
            tltjiashu_input = (frdup.data[3]>>1)&0x01;//脱粒滚筒加速输入; 2

            tltjianshu_input = frdup.data[3]&0x01;//脱粒滚筒减速输入 1


            //byte5

            getaisheng_out = (frdup.data[4]>>7)&0x01;//割台升输出; 8
            getaijiang_out = (frdup.data[4]>>6)&0x01;//割台降输出; 7

            xltbj_out = (frdup.data[4]>>5)&0x01;//卸粮筒摆进输出 6
            xltbc_out = (frdup.data[4]>>4)&0x01;//卸粮筒摆出输出 5

            bhls_out = (frdup.data[4]>>3)&0x01;//拨禾轮升输出 4
            bhlj_out = (frdup.data[4]>>2)&0x01; //拨禾轮降输出; 3
            tltjiashu_out = (frdup.data[4]>>1)&0x01;//脱粒滚筒加速输出; 2

            tltjianshu_out = frdup.data[4]&0x01;//脱粒滚筒减速输出 1

            //byte6

            xiehefa_out = (frdup.data[5]>>1)&0x01;//卸荷阀输出; 2

            xielianglihe_out = frdup.data[5]&0x01;//卸粮离合输出; 1

            break;


      case  0x18FF11F6:
            futuoqi  = frdup.data[7]<<8|frdup.data[6];// 复脱器转速
            futuoqi &= 0x3fff;
            duanlu_ftq = (frdup.data[7]>>6)&0x03;

            //printf("duanlu_ftq................................ = %d\r\n",duanlu_ftq);


            shengyunqi = frdup.data[5]<<8|frdup.data[4];//升运器转速
            shengyunqi &= 0x3fff;
            duanlu_syq = (frdup.data[5]>>6)&0x03;


            fenliguntong = frdup.data[3]<<8|frdup.data[2];//分离滚筒转速
            fenliguntong &= 0x3fff;
            duanlu_fl = (frdup.data[3]>>6)&0x03;


            tuoliguntong = frdup.data[1]<<8|frdup.data[0];//脱粒滚筒转速
            tuoliguntong &= 0x3fff;
            duanlu_tlgt = (frdup.data[1]>>6)&0x03;

            break;


           //频率量
     case  0x18FF21F6:

           shisu = (frdup.data[7]<<8|frdup.data[6]);//时速

            shisu =shisu/10;//时速
           if(shisu>30)
           {
                shisu = 30;
           }
           else if(shisu<1)
           {
                shisu = 0;
           }

           guoqiaozhuansu = frdup.data[5]<<8|frdup.data[4];////过桥转速；
           guoqiaozhuansu &= 0x3ffff;
           duanlu_gq = (frdup.data[5]>>6)&0x03;

           fengjizhuansu =  frdup.data[3]<<8|frdup.data[2];//风机转速
           fengjizhuansu &= 0x3fff;
           duanlu_fj = (frdup.data[3]>>6)&0x03;

           qiesuiqizhuansu = frdup.data[1]<<8|frdup.data[0];//切碎器转速
           qiesuiqizhuansu &= 0x3fff;
           duanlu_qsq = (frdup.data[1]>>6)&0x03;

            break;

           //模拟量 18FF31F6
       case 0x18FF31F6:
           YouLiang = frdup.data[1]; //油量（油量）
           if(frdup.data[1]>= 8)
           {
               //frdup.data[0] = 100;//邮箱满了
//               flagyouxiangman = 1;
               flagyouliangdi = 0;

           }
           else if(frdup.data[1]<1)
           {
                flagyouliangdi = 1; //油量低报警
//                flagyouxiangman = 0;
           }
           else if((frdup.data[1]<8)&&(frdup.data[1]>1))
           {
                flagyouliangdi = 0;
//                 flagyouxiangman = 0;
           }

           Yeyayouwen = frdup.data[0];//液压油油温（液压油油温）
           if(frdup.data[0]>90)
           {
                flagYeyayouwen = 1;
           }
           else
           {
                flagYeyayouwen = 0;
           }


           //MiJi  = frdup[2];// 暂时不定义。
#if 1
           MiJi = frdup.data[4];
           MiJi = MiJi<<8;
           MiJi = MiJi|frdup.data[3];
           MiJi = (MiJi<<8)|frdup.data[2];

           MiJiFloat = MiJi;
           MiJiFloat /= 10;


#endif

           LiCheng = frdup.data[7];
           LiCheng = LiCheng<<8;
           LiCheng = LiCheng|frdup.data[6];
           LiCheng = (LiCheng<<8)|frdup.data[5];

           break;

           //发动机 数据
           //18FEEE00
       case 0x18FEEE00:      //机油温度，水温
           SuiWen = frdup.data[0]; //水温；
           SuiWen -= 40;
           if(SuiWen > 95)
           {
                flagSW = 1;
           }
           else
           {
                flagSW = 0;
           }


           jiyouwendu = (frdup.data[3]<<8|frdup.data[2]); //机油温度
           jiyouwendu *= 0.03125;
           jiyouwendu = jiyouwendu - 273;
           break;

           //发动机 数据
           //18FEEF00
       case 0x18FEEF00:
           jiyouyali = frdup.data[3]; //机油压力
           jiyouyali /= 256;

           if(jiyouyali<0.1)
           {
                flagJY = 1;
           }
           else
           {
                flagJY = 0;
           }
           break;

           //发动机 数据
           //0CF00400
       case 0x0CF00400:
           fadongzhuansu = (frdup.data[4]<<8|frdup.data[3]); //发动机转速
           fadongzhuansu = fadongzhuansu/8;
           break;

           //18FECA00
           //故障报文
           //memcpy  dai chuli
           //guzhangbaowen = frdup.data[]; //故障报文
        case 0x18FECA00://单包故障
           fmi = frdup.data[4]&0x1f; //Byte5 的 5-1 位为fmi 码；

           spn = frdup.data[4]&0xe0;
           spn = spn<<8;
           spn = spn|frdup.data[3];
           spn = spn<<8;
           spn = spn|frdup.data[2];

//           printf("fmi ,spn ................................ = %d,%d\r\n",fmi,spn);

           break;
        case 0x18ECFF00://多包故障码
           Packcount = frdup.data[3];
           //printf("Packcount ,Packend ................................ = %d,%d\r\n",Packcount,Packend);

            break;

       case 0x18EBFF00://多包故障码

//           for(gzmj = 0; gzmj < 8; gzmj++)
//              {

//                  printf("frdup.data[gzmj]   == %d\r\n",frdup.data[gzmj]);

//              }


          if((Packcount>0)&&(Packend == 1))
           {
                Packcount--;

                gzmi=frdup.data[0];
                 for(gzmj = 0; gzmj < 8; gzmj++)
                    {
                        PackGZM[gzmi-1][gzmj] = frdup.data[gzmj];

                        //printf("PackGZM[gzmi-1][gzmj]m == %d\r\n",PackGZM[gzmi-1][gzmj]);

                        //printf("PackGZM[gzmi-1][gzmj] ................................ = %d,%d\r\n",PackGZM[gzmi-1][gzmj],gzmi);
                    }
//                 printf("count = %d\r\n",Packcount);

            }
            else if ((Packcount==0)&&(Packend == 1))
           {
                gzmend = 1;
                Packcount = 0;
           }

           // printf("Packcount ,Packend ................................ = %d,%d\r\n",Packcount,Packend);

           //解析故障码
           if (gzmend == 1)
           {
               /***********SPN1************/
               if(PackGZM[0][0] == 0x01)
               {
                   spn=PackGZM[0][5]>>5;
                   spn=PackGZM[0][4]|spn<<8;
                   spn=PackGZM[0][3]|spn<<8;
                   fmi=PackGZM[0][5]&0x1f;
               }
               else
               {
                   fmi = 0;
                   spn = 0;
               }

            //printf("66666666............................666666 = %d,%d\r\n",Packcount,Packend);

               /***********SPN2 SPN3************/

               if((PackGZM[0][0] == 0x01)&&(PackGZM[1][0] == 0x02))
               {
                 spn2=PackGZM[2][2]>>5;
                 spn2=PackGZM[2][1]|spn2<<8;
                 spn2=PackGZM[1][7]|spn2<<8;
                 fmi2=PackGZM[2][2]&0x1f;

                 spn3=PackGZM[2][6]>>5;
                 spn3=PackGZM[2][5]|spn3<<8;
                 spn3=PackGZM[2][4]|spn3<<8;
                 fmi3=PackGZM[2][6]&0x1f;
               }
               else
               {
                 spn2=0;
                 fmi2=0;
                 spn3=0;
                 fmi3=0;
               }
               /***********SPN4************/
               if(PackGZM[2][0]==0x03)
               {
                 spn4=PackGZM[3][3]>>5;
                 spn4=PackGZM[3][2]|spn4<<8;
                 spn4=PackGZM[3][1]|spn4<<8;
                 fmi4=PackGZM[3][3]&0x1f;
               }
               else
               {
                 spn4=0;
                 fmi4=0;
               }
           }

//           for (uchar ijw = 0; ijw <8; ijw++)
//           {
//               printf("spn == %d\r\n",spn);
//               printf("spn2 == %d\r\n",spn2);
//               printf("spn3 == %d\r\n",spn3);
//               printf("spn4 == %d\r\n",spn4);
//           }


           break;

//           //预热指示灯
//           //18FEE400
//       case 0x18FEE400:
//           yurezhishideng = frdup.data[3];//18FEE400

//           if (yurezhishideng == 1)
//           {
//                flagFDJYR = 1;
//           }
//           else if (yurezhishideng == 0)
//           {
//                flagFDJYR = 0;
//           }
//            break;

           //小时计
           //18FEE500
       //case 18FEE500:
           //XiaoshiJi = frdup.data[]; //小时计
           // break;

            default:
            break;

       }//endof switch(1)

#if 1


       if(resetFlag)
       {
           send_frame.can_id = 0x18FF01FB|CAN_EFF_FLAG;
           send_frame.can_dlc = 1;
           send_frame.data[0] = 0x01;
            ret = write(fd, &send_frame, sizeof(send_frame));

            printf("ret = === %d\r\n",ret);
           //ret = write(fd, &frdup, sizeof(frdup));
           if (ret <= 0) {
               myerr("write failed");
               return -1;
           }
           else
           {
               printf("can write is ok!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\r\n");
               resetFlag = false;
           }

       }
#endif
        //print_frame(&frdup);

        memset(&frdup,0,sizeof(frdup));
        //sleep(1);
    }
    close(fd);
    return 0;
}

