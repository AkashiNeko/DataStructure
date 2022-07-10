#pragma once
#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//������Ԫ�ص���������
typedef int QDataType;

//���е���ʽ�ṹ
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QNode;

//���еĽṹ
typedef struct Queue
{
	//int size;
	QNode* head;
	QNode* tail;
}Queue, * pQ;

//��ʼ������
void QueueInit(pQ pq);

//���ٶ���
void QueueDestroy(pQ pq);

//��ӡ�����
void QueuePush(pQ pq, QDataType x);
void QueuePop(pQ pq);

//ȡ��ͷ����βԪ��
QDataType QueueFront(pQ pq);
QDataType QueueBack(pQ pq);

//�ж϶����Ƿ�Ϊ��
int QueueEmpty(pQ pq);

//ȡ������Ԫ�ظ���
int QueueSize(pQ pq);

#endif