/*
 * p2p_dgrm.h
 *
 *  Created on: 2016-6-9
 *      Author: jay
 */
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <json/json.h>
using namespace Json;
//p2p数据报
class P2pDatagram
{
public:
	P2pDatagram(){}
	P2pDatagram(const char *id, const char *stream);
	//重置时间戳
	void ResetTimeStamp();
	//获取时间差
	int GetTimeDiff();
	//发送准备,参数数据报编号
	void ReadySend(int index);
	//获取数据报
	int GetDatagram(char *out);
	//重载等于号
	P2pDatagram & operator=(P2pDatagram &dgrm);
private:
	Value root;					//需要发送的数据
	long long time_stamp;		//发送时间戳(微秒)
};