#include "SinglyLinkList.h"

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
	pSL NewNode = (pSL)malloc(sizeof(SL));
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
	pSL NewNode = SLCreateNode(data); 
	NewNode->next = *ppHead;
	*ppHead = NewNode;
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
	/*���������нڵ�*/
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
	/*��ָ��λ�ò���ڵ�*/
	pSL NewNode = SLCreateNode(data);
	if (pNode == *ppHead)
	{
		NewNode->next = *ppHead;
		*ppHead = NewNode;
		return;
	}
	pSL cur = *ppHead;
	//��������Ѱ�ҵ�pNode��ǰһ���ڵ�
	while (cur->next != pNode)
	{
		cur = cur->next;
		//�����в�����pNode�򱨴�
		assert(cur);
	}
	cur->next = NewNode;
	NewNode->next = pNode;
} // SLInsert

void SLErase(pSL* ppHead, pSL pNode)
{
	/*��ָ��λ��ɾ���ڵ�*/
	if (*ppHead == NULL) return;
	pSL cur = *ppHead;
	while (cur->next != pNode)
	{
		cur = cur->next;
		//�����в�����pNode�򱨴�
		assert(cur);
	}
	cur->next = pNode->next;
	free(pNode);
} // SLErase

void SLInsertAfter(pSL pNode, int data)
{
	/*��ָ��λ��֮�����ڵ�*/
	pSL NewNode = SLCreateNode(data);
	assert(pNode);
	NewNode->next = pNode->next;
	pNode->next = NewNode;
} // SLInsert

void SLEraseAfter(pSL pNode)
{
	/*ɾ��ָ��λ��֮��Ľڵ�*/
	if (pNode == NULL || pNode->next == NULL) return;
	pSL next = pNode->next->next;
	free(pNode->next);
	pNode->next = next;
} // SLErase

void SLReverse(pSL* ppHead)
{
	/*�ߵ�����˳��*/
	if (*ppHead == NULL || (*ppHead)->next == NULL) return;
	//�����д������������Ͻڵ�ʱ
	pSL prv = *ppHead;
	pSL cur = prv->next;
	pSL nex = cur->next;
	//ԭ����ͷ��next�ÿ�
	prv->next = NULL;
	//ԭ����ڶ����ڵ�ָ���һ���ڵ�
	cur->next = prv;
	while (nex)
	{
		//nex����prv��cur������
		prv = cur;
		cur = nex;
		nex = nex->next;
		//prv��cur�޸Ľڵ�֮���ָ�뷽��
		cur->next = prv;
	}
	//�µ�����ͷ
	*ppHead = cur;
} // SLReverse

void SLDestroy(pSL* ppHead)
{
	/*��������*/
	if (*ppHead == NULL) return;
	pSL cur = *ppHead;
	pSL nex = cur->next;
	free(cur);
	//ָ��curָ������ͷ�ڵ㣬ָ��nexΪcur����һ���ڵ�
	while (nex)
	{
		//ָ��nex��������ָ��cur�ͷſռ�
		cur = nex;
		nex = nex->next;
		free(cur);
	}
	*ppHead = NULL;
} // SLDestroy