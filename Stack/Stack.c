#include "Stack.h"

void STInit(pST ps)
{
	/*��ʼ��ջ*/
	assert(ps);
	ps->data = NULL;
	ps->top = 0;
	ps->capacity = 4;
	ps->data = (DataType*)malloc(ps->capacity * sizeof(DataType));
	assert(ps->data);
} // STInit

void STDestroy(pST ps)
{
	/*����ջ*/
	assert(ps);
	free(ps->data);
	ps->data = NULL;
	ps->top = 0;
	ps->capacity = 0;
} // STDestroy

void STPush(pST ps, DataType data)
{
	/*ѹջ����ջ��*/
	assert(ps);
	if (ps->top + 1 == ps->capacity)
	{
		//����
		ps->capacity *= 2;
		DataType* temp = NULL;
		temp = (DataType*)realloc(ps->data, ps->capacity * sizeof(DataType));
		assert(temp);
		ps->data = temp;
	}
	ps->data[ps->top++] = data;
} // STPush

void STPop(pST ps)
{
	/*��ջ*/
	assert(ps);
	if (ps->top)
		--ps->top;
} // STPop

DataType STTop(pST ps)
{
	/*ȡջ��Ԫ��*/
	assert(ps);
	assert(ps->top);
	return ps->data[ps->top - 1];
} // STTop

int STEmpty(pST ps)
{
	/*�ж��Ƿ�Ϊ��*/
	assert(ps);
	return !ps->top;
} // STEmpty

int STSize(pST ps)
{
	/*ջ�Ĵ�С*/
	assert(ps);
	return ps->top;
} // STSize