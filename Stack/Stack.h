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

void STInit(pST ps);
void STDestroy(pST ps);
void STPush(pST ps, DataType data);
void STPop(pST ps);
DataType STTop(pST ps);
int STEmpty(pST ps);
int STSize(pST ps);


#endif