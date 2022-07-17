#pragma once

#ifndef __BINTREE_H__
#define __BINTREE_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//构建二叉树时代表NULL的符号
#define NullSign '#'

//打印节点元素
#define PRINT(data) printf("%c ", data)

//节点的数据类型
typedef char DataType;

//二叉树的链式结构
typedef struct BTNode
{
	DataType data;
	struct BTNode* left;
	struct BTNode* right;
}BT, * pBT;

//开辟新节点的空间
pBT BTCreateNode(DataType data);

//通过前序遍历的数组构建二叉树
pBT PreorderCreate(DataType* arr, int n, int* pi);
pBT BTCreateTree(DataType* arr, int n);

//二叉树销毁
void BTDestory(pBT root);

//二叉树节点个数
int BTSize(pBT root);

//叶子节点个数
int BTLeafSize(pBT root);

//第k层节点个数
int BTLevelKSize(pBT root, int k);

//查找值为x的节点
pBT BTFind(pBT root, DataType x);

//前序遍历
void BTPreorder(pBT root);

//中序遍历
void BTInorder(pBT root);

//后序遍历
void BTPostorder(pBT root);

#endif
