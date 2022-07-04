#pragma once
#ifndef __LINKLIST_H__
#define __LINKLIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int;

typedef struct SLinkList
{
	int data;
	struct SLinkList* next;
}SLTNode, * pSL;

void SLPrint(pSL ps);

pSL SLCreateNode(int data);

void SLPushBack(pSL* ppHead, int data);

#endif