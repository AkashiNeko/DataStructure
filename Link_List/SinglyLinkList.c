#include "SinglyLinkList.h"

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
	pSL NewNode = (pSL)malloc(sizeof(SL));
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
	pSL NewNode = SLCreateNode(data); 
	NewNode->next = *ppHead;
	*ppHead = NewNode;
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
	/*查找链表中节点*/
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

void SLInsert(pSL* ppHead, pSL pNode, int data)
{
	/*在指定位置插入节点*/
	pSL NewNode = SLCreateNode(data);
	if (pNode == *ppHead)
	{
		NewNode->next = *ppHead;
		*ppHead = NewNode;
		return;
	}
	pSL cur = *ppHead;
	//遍历链表寻找到pNode的前一个节点
	while (cur->next != pNode)
	{
		cur = cur->next;
		//链表中不存在pNode则报错
		assert(cur);
	}
	cur->next = NewNode;
	NewNode->next = pNode;
} // SLInsert

void SLErase(pSL* ppHead, pSL pNode)
{
	/*在指定位置删除节点*/
	if (*ppHead == NULL) return;
	pSL cur = *ppHead;
	while (cur->next != pNode)
	{
		cur = cur->next;
		//链表中不存在pNode则报错
		assert(cur);
	}
	cur->next = pNode->next;
	free(pNode);
} // SLErase

void SLInsertAfter(pSL pNode, int data)
{
	/*在指定位置之后插入节点*/
	pSL NewNode = SLCreateNode(data);
	assert(pNode);
	NewNode->next = pNode->next;
	pNode->next = NewNode;
} // SLInsert

void SLEraseAfter(pSL pNode)
{
	/*删除指定位置之后的节点*/
	if (pNode == NULL || pNode->next == NULL) return;
	pSL next = pNode->next->next;
	free(pNode->next);
	pNode->next = next;
} // SLErase

void SLReverse(pSL* ppHead)
{
	/*颠倒链表顺序*/
	if (*ppHead == NULL || (*ppHead)->next == NULL) return;
	//链表中存在两个及以上节点时
	pSL prv = *ppHead;
	pSL cur = prv->next;
	pSL nex = cur->next;
	//原链表头的next置空
	prv->next = NULL;
	//原链表第二个节点指向第一个节点
	cur->next = prv;
	while (nex)
	{
		//nex带着prv和cur向后遍历
		prv = cur;
		cur = nex;
		nex = nex->next;
		//prv和cur修改节点之间的指针方向
		cur->next = prv;
	}
	//新的链表头
	*ppHead = cur;
} // SLReverse

void SLDestroy(pSL* ppHead)
{
	/*销毁链表*/
	if (*ppHead == NULL) return;
	pSL cur = *ppHead;
	pSL nex = cur->next;
	free(cur);
	//指针cur指向链表头节点，指针nex为cur的下一个节点
	while (nex)
	{
		//指针nex向后遍历，指针cur释放空间
		cur = nex;
		nex = nex->next;
		free(cur);
	}
	*ppHead = NULL;
} // SLDestroy