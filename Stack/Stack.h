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

//初始化栈
void STInit(pST ps);

//销毁栈
void STDestroy(pST ps);

//压栈
void STPush(pST ps, DataType data);

//出栈
void STPop(pST ps);

//取栈顶元素
DataType STTop(pST ps);

//判断栈是否为空
int STEmpty(pST ps);

//取栈中元素个数
int STSize(pST ps);

#endif