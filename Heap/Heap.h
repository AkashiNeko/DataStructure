#pragma once
#ifndef __HEAP_H__
#define __HEAP_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//堆中元素的数据类型
typedef int DataType;

//堆的动态数组结构
typedef struct Heap
{
	DataType* data;
	int capacity;
	int size;
}HP, * pHP;



#endif