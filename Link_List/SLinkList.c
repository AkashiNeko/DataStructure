#include "LinkList.h"

void SLPrint(pSL ps)
{
	/*打印整个单向链表*/
	if (ps == NULL)
	{
		//空链表
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
	/*创建链表节点空间*/
	pSL NewNode = (pSL)malloc(sizeof(SLTNode));
	assert(NewNode);
	NewNode->data = data;
	NewNode->next = NULL;
	return NewNode;
} // SLCreateNode

void SLPushBack(pSL* ppHead, int data)
{
	/*尾增*/
	pSL NewNode = SLCreateNode(data);
	if (*ppHead == NULL)
	{
		//链表为空
		*ppHead = NewNode;
		return;
	}
	pSL p = *ppHead;
	while (p->next)
	{
		//找到链表的尾部
		p = p->next;
	}
	p->next = NewNode;
} // SLPushBack

void SLPopBack(pSL* ppHead)
{
	/*尾删*/
	if (*ppHead == NULL) return;
	if ((*ppHead)->next == NULL)
	{
		//链表只有一个节点
		free(*ppHead);
		*ppHead = NULL;
		return;
	}
	pSL p = *ppHead;
	while (p->next->next)
	{
		//找到链表的尾部
		p = p->next;
	}
	free(p->next);
	p->next = NULL;
} // SLPopBack

void SLPushFront(pSL* ppHead, int data)
{
	/*头增*/
	pSL next = *ppHead;
	*ppHead = SLCreateNode(data);
	(*ppHead)->next = next;
} // SLPushFront

void SLPopFront(pSL* ppHead)
{
	/*头删*/
	if (*ppHead == NULL) return;
	pSL p = *ppHead;
	*ppHead = (*ppHead)->next;
	free(p);
} // SLPopFront

pSL SLFindNode(pSL* ppHead, int data)
{
	/*寻找链表中元素*/
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
	/*在指定位置之后插入节点*/
	pSL NewNode = SLCreateNode(data);
	if (*ppNode == NULL)
	{
		//如果链表节点为空指针
		*ppNode = NewNode;
		return;
	}
	NewNode->next = (*ppNode)->next;
	(*ppNode)->next = NewNode;
} // SLInsert

void SLErase(pSL* ppNode)
{
	/*删除指定位置之后的节点*/
	if (*ppNode == NULL || (*ppNode)->next == NULL) return;
	pSL next = (*ppNode)->next->next;
	free((*ppNode)->next);
	(*ppNode)->next = next;
} // SLErase

void SLDestroy(pSL* ppHead)
{
	/*销毁链表*/
	if (*ppHead == NULL) return;
	pSL p = *ppHead;
	pSL s = p->next;
	free(p);
	//指针p指向链表头节点，指针s为p的下一个节点
	while (s)
	{
		//指针s向后遍历，指针p释放s之前的空间
		p = s;
		s = s->next;
		free(p);
	}
	*ppHead = NULL;
} // SLDestroy