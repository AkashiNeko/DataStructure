#include "BinaryTree.h"

pBT BTCreateNode(DataType data)
{
	/*开辟新节点的空间*/
	pBT NewNode = (pBT)malloc(sizeof(BT));
	assert(NewNode);
	NewNode->data = data;
	NewNode->left = NULL;
	NewNode->right = NULL;
	return NewNode;
} // BTCreateNode

pBT PreorderCreate(DataType* arr, int n, int* pi)
{
	/*递归创建二叉树*/
	assert(*pi < n);
	if (arr[*pi] == NullSign)
	{
		++(*pi);
		return NULL;
	}
	pBT NewNode = BTCreateNode(arr[*pi]);
	++(*pi);
	NewNode->left = PreorderCreate(arr, n, pi);
	NewNode->right = PreorderCreate(arr, n, pi);
	return NewNode;
} // BTCreate

pBT BTCreateTree(DataType* arr, int n)
{
	/*通过前序遍历的数组构建二叉树*/
	assert(arr);
	int i = 0;
	return PreorderCreate(arr, n, &i);
} // BTCreate

void BTDestory(pBT root)
{
	/*二叉树销毁*/
	if (root == NULL)
		return;

	BTDestory(root->left);
	BTDestory(root->right);
	free(root);
} // BTDestory

int BTSize(pBT root)
{
	/*二叉树节点个数*/
	if (root == NULL)
		return 0;

	return BTSize(root->left) + BTSize(root->right) + 1;
} // BTSize

int BTLeafSize(pBT root)
{
	/*叶子节点个数*/
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	return BTLeafSize(root->left) + BTLeafSize(root->right);
} // BTLeafSize

int BTLevelKSize(pBT root, int k)
{
	/*第k层节点个数*/
	assert(k > 0);
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BTLevelKSize(root->left, k - 1)
		+ BTLevelKSize(root->right, k - 1);
} // BTLevelKSize

pBT BTFind(pBT root, DataType x)
{
	/*查找值为x的节点*/
	if (root == NULL)
		return NULL;

	if (root->data == x)
		return root;

	pBT left = BTFind(root->left, x);
	if (left)
		return left;

	pBT right = BTFind(root->right, x);
	if (right)
		return right;

	return NULL;
} // BTFind

void BTPreorder(pBT root)
{
	/*前序遍历*/
	if (root == NULL)
	{
		PRINT(NullSign);
		return;
	}
	PRINT(root->data);
	BTPreorder(root->left);
	BTPreorder(root->right);
} // BTPrevorder

void BTInorder(pBT root)
{
	/*中序遍历*/
	if (root == NULL)
	{
		PRINT(NullSign);
		return;
	}
	BTInorder(root->left);
	PRINT(root->data);
	BTInorder(root->right);
} // BTInorder

void BTPostorder(pBT root)
{
	/*后序遍历*/
	if (root == NULL)
	{
		PRINT(NullSign);
		return;
	}
	BTPostorder(root->left);
	BTPostorder(root->right);
	PRINT(root->data);
} // BTPostorder