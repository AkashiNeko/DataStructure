#pragma once

#ifndef __SLINKLIST_H__
#define __SLINKLIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//链表节点结构体
typedef struct SLinkList
{
	int data;
	struct SLinkList* next;
}SL, * pSL;

//打印整个单向链表
void SLPrint(pSL ps);

//创建链表节点空间
pSL SLCreateNode(int data);

//头增、头删、尾增、尾删
void SLPushBack(pSL* ppHead, int data);
void SLPopBack(pSL* ppHead);
void SLPushFront(pSL* ppHead, int data);
void SLPopFront(pSL* ppHead);

//查找链表节点（不存在返回NULL）
pSL SLFindNode(pSL* ppHead, int data);

//在指定位置插入节点
void SLInsert(pSL* ppHead, pSL pNode, int data);

//在指定位置删除节点
void SLErase(pSL* ppHead, pSL pNode);

//在指定位置之后插入节点
void SLInsertAfter(pSL pNode, int data);

//删除指定位置之后的节点
void SLEraseAfter(pSL pNode);

//翻转链表
void SLReverse(pSL* ppHead);

//销毁链表
void SLDestroy(pSL* ppHead);

#endif