/*
 * p2p_rdt.cpp
 *
 *  Created on: 2016-6-8
 *      Author: jay
 *	文件介绍:
 *	可靠数据传输协议实现
 *	需要功能:
 		滑动窗口技术
 		超时重传技术
 */
#include "p2p_rdt.h"

P2pDatagram &P2pSliderWnd::operator[](int index)
{
	return wnd[index];
}