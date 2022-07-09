#pragma once
#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//栈中成员的数据类型
typedef int DataType;

//栈的结构
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