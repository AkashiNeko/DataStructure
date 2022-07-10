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
}Queue, * pQ;

//��ʼ������
void QInit(pQ pq);

//���ٶ���
void QDestroy(pQ pq);

//��ӡ�����
void QPush(pQ pq, DataType data);
void QPop(pQ pq);

//ȡ��ͷ����βԪ��
DataType QFront(pQ pq);
DataType QRear(pQ pq);

//�ж϶����Ƿ�Ϊ��
int QEmpty(pQ pq);

//ȡ������Ԫ�ظ���
int QSize(pQ pq);

#endif