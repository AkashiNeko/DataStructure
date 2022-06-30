#pragma once

#ifndef __SEQLIST_H__
#define __SEQLIST_H__

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

//顺序表
typedef struct SeqList
{
	int* list;
	int len;
	int size;
}SL, * pSL;

//初始化和销毁
void SLInit(pSL ps);
void SLDestory(pSL ps);

//扩容
void SLCheckCapacity(pSL ps);

//打印顺序表信息
void SLPrint(const pSL ps);

//尾增、尾删、头增、头删
void SLPushBack(pSL ps, int new);
void SLPopBack(pSL ps);
void SLPushFront(pSL ps, int new);
void SLPopFront(pSL ps);

//在指定位置增删
void SLInsert(pSL ps, int index, int new);
void SLErase(pSL ps, int index);

#endif