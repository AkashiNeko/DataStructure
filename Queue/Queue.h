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
}Queue, * pQ;

//初始化队列
void QInit(pQ pq);

//销毁队列
void QDestroy(pQ pq);

//入队、出队
void QPush(pQ pq, DataType data);
void QPop(pQ pq);

//取队头、队尾元素
DataType QFront(pQ pq);
DataType QRear(pQ pq);

//判断队列是否为空
int QEmpty(pQ pq);

//取队列中元素个数
int QSize(pQ pq);

#endif