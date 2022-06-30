#include "SeqList.h"

void SLInit(pSL ps)
{
	/*��ʼ��*/
	assert(ps);
	// ��ʼ��С
	ps->size = 4;
	// �����ڴ�
	ps->list = (int*)malloc(ps->size * sizeof(int*));
	if (ps->list == NULL)
	{
		perror("SLInit malloc");
		exit(114514);
	}
	ps->len = 0;
} // SLInit

void SLDestory(pSL ps)
{
	/*����˳���*/
	assert(ps);
	free(ps->list);
	ps->list = NULL;
	ps->len = 0;
	ps->size = 0;
} // SLDestory

void SLCheckCapacity(pSL ps)
{
	/*���ȴﵽ����ʱ����*/
	assert(ps->list);
	if (ps->len < ps->size)
		return;
	// �ռ䷭��
	ps->size *= 2;
	// ����
	int* pTemp = (int*)realloc(ps->list, ps->size * sizeof(int*));
	if (pTemp == NULL)
	{
		perror("SLCheckCapacity realloc");
		exit(114514);
	}
	ps->list = pTemp;
} // SLCheckCapacity

void SLPrint(const pSL ps)
{
	/*��ӡ˳�����Ϣ*/
	int i;
	printf("\nlist: ");
	if (ps->len)
		for (i = 0; i < ps->len; i++)
			printf("%d ", ps->list[i]);
	else
		printf("none");
	printf("\nlen:  %d\n", ps->len);
	printf("size: %d\n", ps->size);
} // SLPrint

void SLPushBack(pSL ps, int new)
{
	/*��˳���β�����Ԫ��*/
	SLCheckCapacity(ps);
	ps->list[ps->len] = new;
	++ps->len;
} // SLPushBack

void SLPopBack(pSL ps)
{
	/*��˳���β��ɾ��Ԫ��*/
	if(ps->len)
		--ps->len;
} // SLPopBack

void SLPushFront(pSL ps, int new)
{
	/*��˳���ͷ�����Ԫ��*/
	SLCheckCapacity(ps);
	int len = ps->len;
	while (len--)
	{
		ps->list[len + 1] = ps->list[len];
	}
	ps->list[0] = new;
	++ps->len;
} // SLPushFront

void SLPopFront(pSL ps)
{
	/*��˳���ͷ���Ƴ�Ԫ��*/
	if (ps->len == 0)
		return;
	int i = 0;
	// ���±�Ϊ1֮���Ԫ��������ǰ�ƶ�1λ
	for (i = 0; i < ps->len - 1; i++)
	{
		ps->list[i] = ps->list[i + 1];
	}
	--ps->len;
} // SLPopFront

void SLInsert(pSL ps, int index, int new)
{
	/*��˳���ָ���±괦����Ԫ��*/
	SLCheckCapacity(ps);
	assert(index >= 0 && index <= ps->len);
	int i = ps->len;
	// ���±�Ϊindex֮���Ԫ����������ƶ�1λ
	while (i-- > index)
	{
		ps->list[i + 1] = ps->list[i];
	}
	ps->list[index] = new;
	++ps->len;
} // SLInsert

void SLErase(pSL ps, int index)
{
	/*ɾ��˳�����ָ���±��Ԫ��*/
	if (ps->len == 0)
		return;
	assert(index >= 0 && index < ps->len);
	// ���±�Ϊindex֮���Ԫ��������ǰ�ƶ�1λ
	while (++index < ps->len)
	{
		ps->list[index - 1] = ps->list[index];
	}
	--ps->len;
} // SLErase