#pragma once
#ifndef __HEAP_H__
#define __HEAP_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//����Ԫ�ص���������
typedef int DataType;

//�ѵĶ�̬����ṹ
typedef struct Heap
{
	DataType* data;
	int capacity;
	int size;
}HP, * pHP;



#endif