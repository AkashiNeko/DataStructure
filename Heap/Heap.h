#pragma once

#ifndef __HEAP_H__
#define __HEAP_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//0:最小堆（小根堆）
//1:最大堆（大根堆）
#define _MAX_HEAP 0

//堆中元素的数据类型
typedef int DataType;

//堆的动态数组结构
typedef struct Heap
{
	DataType* data;
	int capacity;
	int size;
}HP, * pHP;

//交换数据
void Swap(DataType* p1, DataType* p2);

//向下/向上调整
void AdjustDwon(DataType* data, int size, int parent);
void AdjustUp(DataType* data, int child);

//打印堆
void HPPrint(HP* php);

//初始化堆
void HPInit(HP* php);

//销毁堆
void HPDestroy(HP* php);

//堆的插入
void HPPush(HP* php, DataType data);

//堆的删除
DataType HPPop(HP* php);

//取堆顶元素
DataType HPTop(HP* php);

//判断堆是否为空
int HPEmpty(HP* php);

//堆中元素个数
int HPSize(HP* php);

#endif