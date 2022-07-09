#pragma once
#ifndef __DLINKLIST_H__
#define __DLINKLIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//链表节点data数据类型
typedef int DataType;

//链表节点结构体
typedef struct DLinkList
{
	struct DLinkList* next;
	struct DLinkList* prev;
	DataType data;
}DL, * pDL;

//创建链表节点空间
pDL DLCreateNode(DataType data);

//初始化哨兵位
pDL DLInit();

//打印整个链表
void DLPrint(pDL phead);

//头插、头删、尾插、尾删
void DLPushBack(pDL phead, DataType data);
void DLPushFront(pDL phead, DataType data);
void DLPopBack(pDL phead);
void DLPopFront(pDL phead);

//查找链表节点（不存在返回NULL）
pDL DLFindNode(pDL phead, DataType data);

//在pos位置插入节点
void DLInsert(pDL pos, DataType data);

//删除pos位置的节点
void DLErase(pDL pos);

//销毁链表
void DLDestroy(pDL phead);

#endif