#include "LinkList.h"

void SLPrint(pSL ps)
{
	if (ps == NULL)
	{
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
}

pSL SLCreateNode(int data)
{
	pSL NewNode = (pSL)malloc(sizeof(SLTNode));
	assert(NewNode);
	NewNode->data = data;
	NewNode->next = NULL;
	return NewNode;
}

void SLPushBack(pSL* ppHead, int data)
{
	pSL NewNode = SLCreateNode(data);
	if (*ppHead == NULL)
	{
		*ppHead = NewNode;
		return;
	}
	pSL p = *ppHead;
	while (p->next)
	{
		p = p->next;
	}
	p->next = NewNode;
}
