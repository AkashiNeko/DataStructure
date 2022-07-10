#pragma once
#ifndef __CQUEUE_H__
#define __CQUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//������Ԫ�ص���������
typedef int DataType;

//���еĻ��νṹ
typedef struct CQueue
{
	DataType* data;
	int capacity;
	int front;
	int rear;
}CQ, * pCQ;

//��ʼ������
void CQInit(pCQ pq, int capacity);

//���ٶ���
void CQDestroy(pCQ pq);

//��ӣ��ɹ�����1��ʧ�ܷ���0��
int CQPush(pCQ pq, DataType data);

//���ӣ����ض�ͷԪ�أ�
DataType CQPop(pCQ pq);

//ȡ��ͷ����βԪ��
DataType CQFront(pCQ pq);
DataType CQRear(pCQ pq);

//�ж϶����Ƿ�Ϊ��
int CQEmpty(pCQ pq);

//ȡ������Ԫ�ظ���
int CQSize(pCQ pq);

#endif