#pragma once

#ifndef __SLINKLIST_H__
#define __SLINKLIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//����ڵ�ṹ��
typedef struct SLinkList
{
	int data;
	struct SLinkList* next;
}SL, * pSL;

//��ӡ������������
void SLPrint(pSL ps);

//��������ڵ�ռ�
pSL SLCreateNode(int data);

//ͷ����ͷɾ��β����βɾ
void SLPushBack(pSL* ppHead, int data);
void SLPopBack(pSL* ppHead);
void SLPushFront(pSL* ppHead, int data);
void SLPopFront(pSL* ppHead);

//��������ڵ㣨�����ڷ���NULL��
pSL SLFindNode(pSL* ppHead, int data);

//��ָ��λ�ò���ڵ�
void SLInsert(pSL* ppHead, pSL pNode, int data);

//��ָ��λ��ɾ���ڵ�
void SLErase(pSL* ppHead, pSL pNode);

//��ָ��λ��֮�����ڵ�
void SLInsertAfter(pSL pNode, int data);

//ɾ��ָ��λ��֮��Ľڵ�
void SLEraseAfter(pSL pNode);

//��ת����
void SLReverse(pSL* ppHead);

//��������
void SLDestroy(pSL* ppHead);

#endif