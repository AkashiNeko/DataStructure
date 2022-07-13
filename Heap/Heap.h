#pragma once

#ifndef __HEAP_H__
#define __HEAP_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//0:��С�ѣ�С���ѣ�
//1:���ѣ�����ѣ�
#define _MAX_HEAP 0

#if _MAX_HEAP
#define _CMP_ >
#else
#define _CMP_ <
#endif // ��С��

//����Ԫ�ص���������
typedef int DataType;

//�ѵĶ�̬����ṹ
typedef struct Heap
{
	DataType* data;
	int capacity;
	int size;
}HP, * pHP;

//��������
void Swap(DataType* p1, DataType* p2);

//����/���ϵ���
void AdjustDown(DataType* data, int size, int parent);
void AdjustUp(DataType* data, int child);

//��ӡ��
void HPPrint(HP* php);

//��ʼ����
void HPInit(HP* php);

//���ٶ�
void HPDestroy(HP* php);

//�ѵĲ���
void HPPush(HP* php, DataType data);

//�ѵ�ɾ��
DataType HPPop(HP* php);

//ȡ�Ѷ�Ԫ��
DataType HPTop(HP* php);

//�ж϶��Ƿ�Ϊ��
int HPEmpty(HP* php);

//����Ԫ�ظ���
int HPSize(HP* php);

//�Ӹ��ڵ㿪ʼ���µ�����maxHeap -> 0:��С��, 1:���ѣ�
void CustomAdjustDown(DataType* data, int size, int parent, int maxHeap);

//������seq -> 0:��������, 1:�ݼ�����
void HeapSort(DataType* data, int size, int seq);

//����data�����е�k��Ԫ�أ�seq -> 0:����k��Ԫ��, 1:��С��k��Ԫ�أ�
void SortTopK(DataType* data, int size, int k, int seq);

#endif