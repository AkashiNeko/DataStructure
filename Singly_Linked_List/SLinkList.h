#pragma once

#ifndef __SLINKLIST_H__
#define __SLINKLIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//����ڵ�data��������
typedef int DataType;

//����ڵ�ṹ��
typedef struct SLinkList
{
	DataType data;
	struct SLinkList* next;
}SL, * pSL;

//��ӡ��������
void SLPrint(pSL ps);

//��������ڵ�ռ�
pSL SLCreateNode(DataType data);

//ͷ�塢ͷɾ��β�塢βɾ
void SLPushBack(pSL* ppHead, DataType data);
void SLPopBack(pSL* ppHead);
void SLPushFront(pSL* ppHead, DataType data);
void SLPopFront(pSL* ppHead);

//��������ڵ㣨�����ڷ���NULL��
pSL SLFindNode(pSL* ppHead, DataType data);

//��ָ��λ�ò���ڵ�
void SLInsert(pSL* ppHead, pSL pos, DataType data);

//��ָ��λ��ɾ���ڵ�
void SLErase(pSL* ppHead, pSL pos);

//��ָ��λ��֮�����ڵ�
void SLInsertAfter(pSL pos, DataType data);

//ɾ��ָ��λ��֮��Ľڵ�
void SLEraseAfter(pSL pos);

//��ת����
void SLReverse(pSL* ppHead);

//��������
void SLDestroy(pSL* ppHead);

#endif