#pragma once

#ifndef __SEQLIST_H__
#define __SEQLIST_H__

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

//˳���
typedef struct SeqList
{
	int* list;
	int len;
	int size;
}SL, * pSL;

//��ʼ��������
void SLInit(pSL ps);
void SLDestory(pSL ps);

//����
void SLCheckCapacity(pSL ps);

//��ӡ˳�����Ϣ
void SLPrint(const pSL ps);

//β����βɾ��ͷ����ͷɾ
void SLPushBack(pSL ps, int new);
void SLPopBack(pSL ps);
void SLPushFront(pSL ps, int new);
void SLPopFront(pSL ps);

//��ָ��λ����ɾ
void SLInsert(pSL ps, int index, int new);
void SLErase(pSL ps, int index);

#endif