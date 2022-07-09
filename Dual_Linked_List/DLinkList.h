#pragma once
#ifndef __DLINKLIST_H__
#define __DLINKLIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//����ڵ�data��������
typedef int DataType;

//����ڵ�ṹ��
typedef struct DLinkList
{
	struct DLinkList* next;
	struct DLinkList* prev;
	DataType data;
}DL, * pDL;

//��������ڵ�ռ�
pDL DLCreateNode(DataType data);

//��ʼ���ڱ�λ
pDL DLInit();

//��ӡ��������
void DLPrint(pDL phead);

//ͷ�塢ͷɾ��β�塢βɾ
void DLPushBack(pDL phead, DataType data);
void DLPushFront(pDL phead, DataType data);
void DLPopBack(pDL phead);
void DLPopFront(pDL phead);

//��������ڵ㣨�����ڷ���NULL��
pDL DLFindNode(pDL phead, DataType data);

//��posλ�ò���ڵ�
void DLInsert(pDL pos, DataType data);

//ɾ��posλ�õĽڵ�
void DLErase(pDL pos);

//��������
void DLDestroy(pDL phead);

#endif