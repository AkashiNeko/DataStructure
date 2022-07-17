#pragma once

#ifndef __BINTREE_H__
#define __BINTREE_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//����������ʱ����NULL�ķ���
#define NullSign '#'

//��ӡ�ڵ�Ԫ��
#define PRINT(data) printf("%c ", data)

//�ڵ����������
typedef char DataType;

//����������ʽ�ṹ
typedef struct BTNode
{
	DataType data;
	struct BTNode* left;
	struct BTNode* right;
}BT, * pBT;

//�����½ڵ�Ŀռ�
pBT BTCreateNode(DataType data);

//ͨ��ǰ����������鹹��������
pBT PreorderCreate(DataType* arr, int n, int* pi);
pBT BTCreateTree(DataType* arr, int n);

//����������
void BTDestory(pBT root);

//�������ڵ����
int BTSize(pBT root);

//Ҷ�ӽڵ����
int BTLeafSize(pBT root);

//��k��ڵ����
int BTLevelKSize(pBT root, int k);

//����ֵΪx�Ľڵ�
pBT BTFind(pBT root, DataType x);

//ǰ�����
void BTPreorder(pBT root);

//�������
void BTInorder(pBT root);

//�������
void BTPostorder(pBT root);

#endif
