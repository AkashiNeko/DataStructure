#include "SLinkList.h"

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

pSL SLCreateNode(DataType data)
{
	/*���������ڵ�ռ�*/
	pSL NewNode = (pSL)malloc(sizeof(SL));
	assert(NewNode);
	NewNode->data = data;
	NewNode->next = NULL;
	return NewNode;
} // SLCreateNode

void SLPushBack(pSL* ppHead, DataType data)
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
		//�ҵ�������β��
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
		//�ҵ�������β��
		p = p->next;
	}
	free(p->next);
	p->next = NULL;
} // SLPopBack

void SLPushFront(pSL* ppHead, DataType data)
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

pSL SLFindNode(pSL* ppHead, DataType data)
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

void SLInsert(pSL* ppHead, pSL pos, DataType data)
{
	/*��posλ�ò���ڵ�*/
	pSL NewNode = SLCreateNode(data);
	if (pos == *ppHead)
	{
		NewNode->next = *ppHead;
		*ppHead = NewNode;
		return;
	}
	pSL cur = *ppHead;
	//��������Ѱ�ҵ�pos��ǰһ���ڵ�
	while (cur->next != pos)
	{
		cur = cur->next;
		//�����в�����pos�򱨴�
		assert(cur);
	}
	cur->next = NewNode;
	NewNode->next = pos;
} // SLInsert

void SLErase(pSL* ppHead, pSL pos)
{
	/*��posλ��ɾ���ڵ�*/
	if (*ppHead == NULL) return;
	pSL cur = *ppHead;
	while (cur->next != pos)
	{
		cur = cur->next;
		//�����в�����pos�򱨴�
		assert(cur);
	}
	cur->next = pos->next;
	free(pos);
} // SLErase

void SLInsertAfter(pSL pos, DataType data)
{
	/*��posλ��֮�����ڵ�*/
	pSL NewNode = SLCreateNode(data);
	assert(pos);
	NewNode->next = pos->next;
	pos->next = NewNode;
} // SLInsert

void SLEraseAfter(pSL pos)
{
	/*ɾ��posλ��֮��Ľڵ�*/
	if (pos == NULL || pos->next == NULL) return;
	pSL next = pos->next->next;
	free(pos->next);
	pos->next = next;
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
	//ԭ�����ڶ����ڵ�ָ���һ���ڵ�
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