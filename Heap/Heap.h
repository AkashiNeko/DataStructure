#pragma once

#ifndef __HEAP_H__
#define __HEAP_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//0:最小堆（小根堆）
//1:最大堆（大根堆）
#define _MAX_HEAP 0

#if _MAX_HEAP
#define _CMP_ >
#else
#define _CMP_ <
#endif // 大小堆

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
void AdjustDown(DataType* data, int size, int parent);
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

//从根节点开始向下调整（maxHeap -> 0:最小堆, 1:最大堆）
void CustomAdjustDown(DataType* data, int size, int parent, int maxHeap);

//堆排序（seq -> 0:递增排序, 1:递减排序）
void HeapSort(DataType* data, int size, int seq);

//排序data数组中的k个元素（seq -> 0:最大的k个元素, 1:最小的k个元素）
void SortTopK(DataType* data, int size, int k, int seq);

#endif