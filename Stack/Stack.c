#include "Stack.h"

void STInit(pST ps)
{
	/*��ʼ��ջ*/
	assert(ps);
	ps->data = NULL;
	ps->top = 0;
	ps->capacity = 0;
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

}
void STPop(pST ps)
{

}
DataType STTop(pST ps)
{

}
int STEmpty(pST ps)
{

}
int STSize(pST ps)
{

}