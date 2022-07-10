#pragma once
#ifndef __CQUEUE_H__
#define __CQUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//队列中元素的数据类型
typedef int DataType;

//队列的环形结构
typedef struct CQueue
{
	DataType* data;
	int capacity;
	int front;
	int rear;
}CQ, * pCQ;

//初始化队列
void CQInit(pCQ pq, int capacity);

//销毁队列
void CQDestroy(pCQ pq);

//入队（成功返回1，失败返回0）
int CQPush(pCQ pq, DataType data);

//出队（返回队头元素）
DataType CQPop(pCQ pq);

//取队头、队尾元素
DataType CQFront(pCQ pq);
DataType CQRear(pCQ pq);

//判断队列是否为空
int CQEmpty(pCQ pq);

//取队列中元素个数
int CQSize(pCQ pq);

#endif