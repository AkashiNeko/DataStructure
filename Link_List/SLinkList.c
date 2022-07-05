#include "LinkList.h"

void SLPrint(pSL ps)
{
	/*��ӡ������������*/
	if (ps == NULL)
	{
		//������
		printf("NULL\n");
		return;
	}
	printf("%d", ps->data);
	while (ps->next != NULL) 
	{
		ps = ps->next;
		printf("->%d", ps->data);
	}
	printf("->NULL\n");
} // SLPrint

pSL SLCreateNode(int data)
{
	/*��������ڵ�ռ�*/
	pSL NewNode = (pSL)malloc(sizeof(SLTNode));
	assert(NewNode);
	NewNode->data = data;
	NewNode->next = NULL;
	return NewNode;
} // SLCreateNode

void SLPushBack(pSL* ppHead, int data)
{
	/*β��*/
	pSL NewNode = SLCreateNode(data);
	if (*ppHead == NULL)
	{
		//����Ϊ��
		*ppHead = NewNode;
		return;
	}
	pSL p = *ppHead;
	while (p->next)
	{
		//�ҵ������β��
		p = p->next;
	}
	p->next = NewNode;
} // SLPushBack

void SLPopBack(pSL* ppHead)
{
	/*βɾ*/
	if (*ppHead == NULL) return;
	if ((*ppHead)->next == NULL)
	{
		//����ֻ��һ���ڵ�
		free(*ppHead);
		*ppHead = NULL;
		return;
	}
	pSL p = *ppHead;
	while (p->next->next)
	{
		//�ҵ������β��
		p = p->next;
	}
	free(p->next);
	p->next = NULL;
} // SLPopBack

void SLPushFront(pSL* ppHead, int data)
{
	/*ͷ��*/
	pSL next = *ppHead;
	*ppHead = SLCreateNode(data);
	(*ppHead)->next = next;
} // SLPushFront

void SLPopFront(pSL* ppHead)
{
	/*ͷɾ*/
	if (*ppHead == NULL) return;
	pSL p = *ppHead;
	*ppHead = (*ppHead)->next;
	free(p);
} // SLPopFront

pSL SLFindNode(pSL* ppHead, int data)
{
	/*Ѱ��������Ԫ��*/
	if (*ppHead == NULL) return NULL;
	pSL p = *ppHead;
	while (p)
	{
		if (p->data == data)
			return p;
		p = p->next;
	}
	return NULL;
} // SLFindNode

void SLInsert(pSL* ppNode, int data)
{
	/*��ָ��λ��֮�����ڵ�*/
	pSL NewNode = SLCreateNode(data);
	if (*ppNode == NULL)
	{
		//�������ڵ�Ϊ��ָ��
		*ppNode = NewNode;
		return;
	}
	NewNode->next = (*ppNode)->next;
	(*ppNode)->next = NewNode;
} // SLInsert

void SLErase(pSL* ppNode)
{
	/*ɾ��ָ��λ��֮��Ľڵ�*/
	if (*ppNode == NULL || (*ppNode)->next == NULL) return;
	pSL next = (*ppNode)->next->next;
	free((*ppNode)->next);
	(*ppNode)->next = next;
} // SLErase

void SLDestroy(pSL* ppHead)
{
	/*��������*/
	if (*ppHead == NULL) return;
	pSL p = *ppHead;
	pSL s = p->next;
	free(p);
	//ָ��pָ������ͷ�ڵ㣬ָ��sΪp����һ���ڵ�
	while (s)
	{
		//ָ��s��������ָ��p�ͷ�s֮ǰ�Ŀռ�
		p = s;
		s = s->next;
		free(p);
	}
	*ppHead = NULL;
} // SLDestroy