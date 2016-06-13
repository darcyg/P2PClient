/*
 * p2p_txbuf.h
 *
 *  Created on: 2016-6-9
 *      Author: jay
 */
#include "p2p_rdt.h"
#include <semaphore.h>
#include <pthread.h>
#include <queue>
typedef std::queue<P2pDatagram> DgrmList;
//发送缓冲队列
class P2pTxbuf
{
public:
	P2pTxbuf();
	int Push(P2pDatagram dgrm);
	P2pDatagram Take();
	//取出一个窗口
	P2pSliderWnd TakeWnd(int max);
private:
	DgrmList dl;			//发送缓冲区队列
	sem_t dlist_count;
	pthread_mutex_t lock;
};