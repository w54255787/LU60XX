#ifndef __USB2IIC_H_
#define __USB2IIC_H_

//定义初始化IIC的数据类型
typedef struct _IIC_CONFIG{
  unsigned int    ClockSpeedHz; //IIC时钟频率:单位为Hz
  unsigned short  OwnAddr;      //USB2XXX为从机时自己的地址
  unsigned char   Master;       //主从选择控制:0-从机，1-主机
  unsigned char   AddrBits;     //从机地址模式，7-7bit模式，10-10bit模式
  unsigned char   EnablePu;     //使能引脚芯片内部上拉电阻，若不使能，则I2C总线上必须接上拉电阻
}IIC_CONFIG,*PIIC_CONFIG;

//定义函数返回错误代码
#define IIC_SUCCESS             (0)   //函数执行成功
#define IIC_ERR_NOT_SUPPORT     (-1)  //适配器不支持该函数
#define IIC_ERR_USB_WRITE_FAIL  (-2)  //USB写数据失败
#define IIC_ERR_USB_READ_FAIL   (-3)  //USB读数据失败
#define IIC_ERR_CMD_FAIL        (-4)  //命令执行失败
#define IIC_ERR_PARA_ERROR      (-5)  //参数传入错误
//定义IIC函数返回错误代码
#define IIC_ERROR_SUCCESS     0   //操作成功
#define IIC_ERROR_CHANNEL     1   //该通道不支持该函数
#define IIC_ERROR_BUSY        2   //总线忙
#define IIC_ERROR_START_FAILD 3   //启动总线失败
#define IIC_ERROR_TIMEOUT     4   //超时
#define IIC_ERROR_NACK        5   //从机无应答
#define IIC_ERROR_PEC         6   //PEC校验失败

#ifdef __cplusplus
extern "C"
{
#endif
int IIC_Init(int DevHandle,int IICIndex, PIIC_CONFIG pConfig);
int IIC_GetSlaveAddr(int DevHandle,int IICIndex,short *pSlaveAddr);
int IIC_WriteBytes(int DevHandle,int IICIndex,short SlaveAddr,unsigned char *pWriteData,int WriteLen,int TimeOutMs);
int IIC_ReadBytes(int DevHandle,int IICIndex,short SlaveAddr,unsigned char *pReadData,int ReadLen,int TimeOutMs);
int IIC_WriteReadBytes(int DevHandle,int IICIndex,short SlaveAddr,unsigned char *pWriteData,int WriteLen,unsigned char *pReadData,int ReadLen,int TimeOutMs);

#ifdef __cplusplus
}
#endif
#endif
