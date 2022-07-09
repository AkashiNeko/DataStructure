#include "Stack.h"

void STInit(pST ps)
{
	/*初始化栈*/
	assert(ps);
	ps->data = NULL;
	ps->top = 0;
	ps->capacity = 4;
	ps->data = (DataType*)malloc(ps->capacity * sizeof(DataType));
	assert(ps->data);
} // STInit

void STDestroy(pST ps)
{
	/*销毁栈*/
	assert(ps);
	free(ps->data);
	ps->data = NULL;
	ps->top = 0;
	ps->capacity = 0;
} // STDestroy

void STPush(pST ps, DataType data)
{
	/*压栈（入栈）*/
	assert(ps);
	if (ps->top + 1 == ps->capacity)
	{
		//扩容
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
	/*出栈*/
	assert(ps);
	if (ps->top)
		--ps->top;
} // STPop

DataType STTop(pST ps)
{
	/*取栈顶元素*/
	assert(ps);
	assert(ps->top);
	return ps->data[ps->top - 1];
} // STTop

int STEmpty(pST ps)
{
	/*判断是否为空*/
	assert(ps);
	return !ps->top;
} // STEmpty

int STSize(pST ps)
{
	/*栈的大小*/
	assert(ps);
	return ps->top;
} // STSize