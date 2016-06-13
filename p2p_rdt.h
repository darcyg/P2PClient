/*
 * p2p_rdt.h
 *
 *  Created on: 2016-6-8
 *      Author: jay
 *	文件介绍:
 *	可靠数据传输协议实现
 *	需要功能:
 		滑动窗口技术
 		超时重传技术
 */
#include "p2p_dgrm.h"

//滑动窗口类
 class P2pSliderWnd
 {
 public:
 	P2pDatagram & operator[](int index);
 	void setsize(int size){realsize=size;}
 	int size(){return realsize;}
 private:
 	P2pDatagram wnd[100];			//窗口队列
 	int realsize;					//真实大小
 };