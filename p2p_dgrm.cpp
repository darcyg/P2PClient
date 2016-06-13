/*
 * p2p_dgrm.cpp
 *
 *  Created on: 2016-6-9
 *      Author: jay
 */
#include "p2p_dgrm.h"
#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <memory.h>
//P2pDatagram类实现
P2pDatagram::P2pDatagram(const char *id, const char *stream)
{
	Value head;
	head["srcid"] = id;
	head["pkgtype"] = 0x7004;
	head["sendtime"] = "0";
	head["index"] = 0;
	root["head"] = head;
}

void P2pDatagram::ResetTimeStamp()
{
	char time_stamp_str[20];
	struct timeval tm;
	gettimeofday(&tm,NULL);
	time_stamp = (long long)tm.tv_sec*1000000+tm.tv_usec;
	sprintf(time_stamp_str,"%lld", time_stamp);
	root["head"]["sendtime"] = time_stamp_str;
}

int P2pDatagram::GetTimeDiff()
{
	long long now;
	struct timeval tm;
	gettimeofday(&tm,NULL);
	now = (long long)tm.tv_sec*1000000+tm.tv_usec;
	return (int)(now - time_stamp);
}

void P2pDatagram::ReadySend(int index)
{
	root["head"]["index"]=index;
}

int P2pDatagram::GetDatagram(char *out)
{
	FastWriter writer;
	std::string json_str=writer.write(root);
	strcpy(out, json_str.data());
	return json_str.size();
}

P2pDatagram & P2pDatagram::operator=(P2pDatagram &dgrm)
{
	this->root = dgrm.root;
	this->time_stamp = dgrm.time_stamp;
	return *this;
}
