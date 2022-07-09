#include "DLinkList.h"

pDL DLCreateNode(DataType data)
{
	/*创建链表节点空间*/
	pDL NewNode = (pDL)malloc(sizeof(DL));
	assert(NewNode);
	NewNode->data = data;
	NewNode->next = NULL;
	NewNode->prev = NULL;
	return NewNode;
} // DLCreateNode

pDL DLInit()
{
	/*初始化哨兵位*/
	pDL head = DLCreateNode(-1);
	head->next = head;
	head->prev = head;
	return head;
} // DLInit

void DLPrint(pDL phead)
{
	/*打印整个链表*/
	assert(phead);
	printf("head");
	pDL cur = phead->next;
	while (cur != phead)
	{
		printf("->%d", cur->data);
		cur = cur->next;
	}
	printf("->head\n");
} // DLPrint

void DLPushBack(pDL phead, DataType data)
{
	/*尾插*/
	assert(phead);
	pDL tail = phead->prev;
	pDL NewNode = DLCreateNode(data);
	//重新连接节点间的指针
	tail->next = NewNode;
	NewNode->next = phead;
	phead->prev = NewNode;
	NewNode->prev = tail;
} // DLPushBack

void DLPushFront(pDL phead, DataType data)
{
	/*头插*/
	assert(phead);
	pDL nex = phead->next;
	pDL NewNode = DLCreateNode(data);
	//重新连接节点间的指针
	phead->next = NewNode;
	NewNode->next = nex;
	nex->prev = NewNode;
	NewNode->prev = phead;
} // DLPushFront

void DLPopBack(pDL phead)
{
	/*尾删*/
	assert(phead);
	if (phead->next == phead) return;
	pDL tail = phead->prev;
	pDL tailPrev = tail->prev;
	free(tail);
	//重新连接节点间的指针
	tailPrev->next = phead;
	phead->prev = tailPrev;
} // DLPopBack

void DLPopFront(pDL phead)
{
	/*头删*/
	assert(phead);
	if (phead->next == phead) return;
	pDL fst = phead->next;
	pDL fstNext = fst->next;
	free(fst);
	//重新连接节点间的指针
	phead->next = fstNext;
	fstNext->prev = phead;
} // DLPopFront

pDL DLFindNode(pDL phead, DataType data)
{
	/*查找链表节点*/
	pDL cur = phead->next;
	while (cur != phead)
	{
		//遍历查找
		if (cur->data == data)
			return cur;
		cur = cur->next;
	}
	return NULL;
} // DLFindNode

void DLInsert(pDL pos, DataType data)
{
	/*在pos位置插入节点*/
	assert(pos);
	pDL posPrev = pos->prev;
	pDL NewNode = DLCreateNode(data);
	//重新连接节点间的指针
	posPrev->next = NewNode;
	NewNode->next = pos;
	pos->prev = NewNode;
	NewNode->prev = posPrev;
} // DLInsert

void DLErase(pDL pos)
{
	/*删除pos位置的节点*/
	assert(pos);
	if (pos->next == pos) return;
	pDL posPrev = pos->prev;
	pDL posNext = pos->next;
	free(pos);
	//重新连接节点间的指针
	posPrev->next = posNext;
	posNext->prev = posPrev;
} // DLErase

void DLDestroy(pDL phead)
{
	/*销毁链表*/
	assert(phead);
	pDL cur = phead;
	pDL nex = phead->next;
	while (nex != phead)
	{
		//nex向后遍历，cur释放空间
		cur = nex;
		nex = nex->next;
		free(cur);
	}
	phead->next = phead;
	phead->prev = phead;
} // DLDestroy