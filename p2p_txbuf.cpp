#include "p2p_txbuf.h"

P2pTxbuf::P2pTxbuf()
{
	pthread_mutex_init(&lock, NULL);
	sem_init(&dlist_count,0,0);
}

int P2pTxbuf::Push(P2pDatagram dgrm)
{
	pthread_mutex_lock(&lock);
	dl.push(dgrm);
	pthread_mutex_unlock(&lock);
	sem_post(&dlist_count);
	return dl.size();
}

P2pDatagram P2pTxbuf::Take()
{
	//队列不为空才能进入
	sem_wait(&dlist_count);
	P2pDatagram dgrm =  dl.front();
	pthread_mutex_lock(&lock);
	dl.pop();
	pthread_mutex_unlock(&lock);
	return dgrm;
}

P2pSliderWnd P2pTxbuf::TakeWnd(int max)
{
	int i;
	P2pSliderWnd wnd;
	//队列不为空才能进入
	sem_wait(&dlist_count);
	pthread_mutex_lock(&lock);
	if(dl.size() < max){
		for(i = 0; i < dl.size(); i++){
			wnd[i] = dl.front();
			dl.pop();
		}
	}else{
		for(i = 0; i < max; i++){
			wnd[i] = dl.front();
			dl.pop();
		}
	}

	pthread_mutex_unlock(&lock);
	wnd.setsize(i);
	return wnd;
}