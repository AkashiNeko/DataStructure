#pragma once
#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//������Ԫ�ص���������
typedef int DataType;

//���е���ʽ�ṹ
typedef struct QueueNode
{
	struct QueueNode* next;
	DataType data;
}QNode, * pQNode;

//���еĽṹ
typedef struct Queue
{
	pQNode front;
	pQNode rear;
}LQ, * pLQ;

//��ʼ������
void LQInit(pLQ pq);

//���ٶ���
void LQDestroy(pLQ pq);

//��ӡ�����
void LQPush(pLQ pq, DataType data);
void LQPop(pLQ pq);

//ȡ��ͷ����βԪ��
DataType LQFront(pLQ pq);
DataType LQRear(pLQ pq);

//�ж϶����Ƿ�Ϊ��
int LQEmpty(pLQ pq);

//ȡ������Ԫ�ظ���
int LQSize(pLQ pq);

#endif