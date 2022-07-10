#pragma once
#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//ջ�г�Ա����������
typedef int DataType;

//ջ�Ľṹ
typedef struct Stact
{
	DataType* data;
	int top;
	int capacity;
}ST, * pST;

//��ʼ��ջ
void STInit(pST ps);

//����ջ
void STDestroy(pST ps);

//ѹջ
void STPush(pST ps, DataType data);

//��ջ
void STPop(pST ps);

//ȡջ��Ԫ��
DataType STTop(pST ps);

//�ж�ջ�Ƿ�Ϊ��
int STEmpty(pST ps);

//ȡջ��Ԫ�ظ���
int STSize(pST ps);

#endif