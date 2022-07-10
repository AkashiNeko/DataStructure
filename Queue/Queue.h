#pragma once
#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//队列中元素的数据类型
typedef int QDataType;

//队列的链式结构
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QNode;

//队列的结构
typedef struct Queue
{
	//int size;
	QNode* head;
	QNode* tail;
}Queue, * pQ;

//初始化队列
void QueueInit(pQ pq);

//销毁队列
void QueueDestroy(pQ pq);

//入队、出队
void QueuePush(pQ pq, QDataType x);
void QueuePop(pQ pq);

//取队头、队尾元素
QDataType QueueFront(pQ pq);
QDataType QueueBack(pQ pq);

//判断队列是否为空
int QueueEmpty(pQ pq);

//取队列中元素个数
int QueueSize(pQ pq);

#endif