#pragma once
#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//队列中元素的数据类型
typedef int DataType;

//队列的链式结构
typedef struct QueueNode
{
	struct QueueNode* next;
	DataType data;
}QNode, * pQNode;

//队列的结构
typedef struct Queue
{
	pQNode front;
	pQNode rear;
}LQ, * pLQ;

//初始化队列
void LQInit(pLQ pq);

//销毁队列
void LQDestroy(pLQ pq);

//入队、出队
void LQPush(pLQ pq, DataType data);
void LQPop(pLQ pq);

//取队头、队尾元素
DataType LQFront(pLQ pq);
DataType LQRear(pLQ pq);

//判断队列是否为空
int LQEmpty(pLQ pq);

//取队列中元素个数
int LQSize(pLQ pq);

#endif