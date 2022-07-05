#pragma once
#ifndef __LINKLIST_H__
#define __LINKLIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//����ڵ�ṹ��
typedef struct SLinkList
{
	int data;
	struct SLinkList* next;
}SLTNode, * pSL;

//��ӡ������������
void SLPrint(pSL ps);

//��������ڵ�ռ�
pSL SLCreateNode(int data);

//ͷ����ͷɾ��β����βɾ
void SLPushBack(pSL* ppHead, int data);
void SLPopBack(pSL* ppHead);
void SLPushFront(pSL* ppHead, int data);
void SLPopFront(pSL* ppHead);

//Ѱ������ڵ㣨�����ڷ���NULL��
pSL SLFindNode(pSL* ppHead, int data);

//��ָ��λ��֮�����ڵ�
void SLInsert(pSL* ppNode, int data);

//ɾ��ָ��λ��֮��Ľڵ�
void SLErase(pSL* ppNode);

//��������
void SLDestroy(pSL* ppHead);

#endif