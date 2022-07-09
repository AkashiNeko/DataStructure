#include "DLinkList.h"

pDL DLCreateNode(DataType data)
{
	/*��������ڵ�ռ�*/
	pDL NewNode = (pDL)malloc(sizeof(DL));
	assert(NewNode);
	NewNode->data = data;
	NewNode->next = NULL;
	NewNode->prev = NULL;
	return NewNode;
} // DLCreateNode

pDL DLInit()
{
	/*��ʼ���ڱ�λ*/
	pDL head = DLCreateNode(-1);
	head->next = head;
	head->prev = head;
	return head;
} // DLInit

void DLPrint(pDL phead)
{
	/*��ӡ��������*/
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
	/*β��*/
	assert(phead);
	pDL tail = phead->prev;
	pDL NewNode = DLCreateNode(data);
	//�������ӽڵ���ָ��
	tail->next = NewNode;
	NewNode->next = phead;
	phead->prev = NewNode;
	NewNode->prev = tail;
} // DLPushBack

void DLPushFront(pDL phead, DataType data)
{
	/*ͷ��*/
	assert(phead);
	pDL nex = phead->next;
	pDL NewNode = DLCreateNode(data);
	//�������ӽڵ���ָ��
	phead->next = NewNode;
	NewNode->next = nex;
	nex->prev = NewNode;
	NewNode->prev = phead;
} // DLPushFront

void DLPopBack(pDL phead)
{
	/*βɾ*/
	assert(phead);
	if (phead->next == phead) return;
	pDL tail = phead->prev;
	pDL tailPrev = tail->prev;
	free(tail);
	//�������ӽڵ���ָ��
	tailPrev->next = phead;
	phead->prev = tailPrev;
} // DLPopBack

void DLPopFront(pDL phead)
{
	/*ͷɾ*/
	assert(phead);
	if (phead->next == phead) return;
	pDL fst = phead->next;
	pDL fstNext = fst->next;
	free(fst);
	//�������ӽڵ���ָ��
	phead->next = fstNext;
	fstNext->prev = phead;
} // DLPopFront

pDL DLFindNode(pDL phead, DataType data)
{
	/*��������ڵ�*/
	pDL cur = phead->next;
	while (cur != phead)
	{
		//��������
		if (cur->data == data)
			return cur;
		cur = cur->next;
	}
	return NULL;
} // DLFindNode

void DLInsert(pDL pos, DataType data)
{
	/*��posλ�ò���ڵ�*/
	assert(pos);
	pDL posPrev = pos->prev;
	pDL NewNode = DLCreateNode(data);
	//�������ӽڵ���ָ��
	posPrev->next = NewNode;
	NewNode->next = pos;
	pos->prev = NewNode;
	NewNode->prev = posPrev;
} // DLInsert

void DLErase(pDL pos)
{
	/*ɾ��posλ�õĽڵ�*/
	assert(pos);
	if (pos->next == pos) return;
	pDL posPrev = pos->prev;
	pDL posNext = pos->next;
	free(pos);
	//�������ӽڵ���ָ��
	posPrev->next = posNext;
	posNext->prev = posPrev;
} // DLErase

void DLDestroy(pDL phead)
{
	/*��������*/
	assert(phead);
	pDL cur = phead;
	pDL nex = phead->next;
	while (nex != phead)
	{
		//nex��������cur�ͷſռ�
		cur = nex;
		nex = nex->next;
		free(cur);
	}
	phead->next = phead;
	phead->prev = phead;
} // DLDestroy