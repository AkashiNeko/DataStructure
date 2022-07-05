#pragma once
#ifndef __LINKLIST_H__
#define __LINKLIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//链表节点结构体
typedef struct SLinkList
{
	int data;
	struct SLinkList* next;
}SLTNode, * pSL;

//打印整个单向链表
void SLPrint(pSL ps);

//创建链表节点空间
pSL SLCreateNode(int data);

//头增、头删、尾增、尾删
void SLPushBack(pSL* ppHead, int data);
void SLPopBack(pSL* ppHead);
void SLPushFront(pSL* ppHead, int data);
void SLPopFront(pSL* ppHead);

//寻找链表节点（不存在返回NULL）
pSL SLFindNode(pSL* ppHead, int data);

//在指定位置之后插入节点
void SLInsert(pSL* ppNode, int data);

//删除指定位置之后的节点
void SLErase(pSL* ppNode);

//销毁链表
void SLDestroy(pSL* ppHead);

#endif