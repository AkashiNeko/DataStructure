#include "Heap.h"

#if _MAX_HEAP
#define _CMP_ >
#else
#define _CMP_ <
#endif

void Swap(DataType* p1, DataType* p2)
{
	/*交换数据*/
	DataType temp = *p1;
	*p1 = *p2;
	*p2 = temp;
} // Swap

void AdjustDwon(DataType* data, int size, int parent)
{
	/*向下调整*/
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && data[child + 1] _CMP_ data[child])
		{
			//取两个子节点中最小/大的
			++child;
		}
		if (data[child] _CMP_ data[parent])
		{
			//向下交换父子节点
			Swap(&data[parent], &data[child]);
			parent = child;
			child = child * 2 + 1;
		}
		else
		{
			break;
		}
	}
} // AdjustDwon

void AdjustUp(DataType* data, int child)
{
	/*向上调整*/
	int parent = (child - 1) / 2;
	while (data[child] _CMP_ data[parent])
	{
		//向上交换父子节点
		Swap(&data[parent], &data[child]);
		child = parent;
		parent = (parent - 1) / 2;
	}
} // AdjustUp

void HPPrint(HP* php)
{
	/*打印堆*/
	assert(php);
	if (php->size == 0)
	{
		//堆为空
		printf("Heap is Empty.\n");
		return;
	}
	int order = 1;
	int count = 2;
	while (php->size >= count)
	{
		//计算堆的高度
		count *= 2;
		order++;
	}
	int step = 0;
	int index = 0;
	for(step = 0; step < order; ++step)
	{
		//逐层打印
		int i = 0, j;
		for (i = 1; i < count / 2; ++i)
			//数字前空格
			printf("  ");
		for (i = 0; i < (1 << step); i++)
		{
			if (index == php->size)
				//打印末尾未满的位置
				printf("__");
			else
				//打印数字
				printf("%2d", php->data[index++]);
			if (i != (1 << step) - 1)
			{
				for (j = 1; j < count; ++j)
					//打印数字间空格
					printf("  ");
			}
		}
		count /= 2;
		printf("\n");
	}
} // HPPrint

void HPInit(HP* php)
{
	/*初始化堆*/
	assert(php);
	php->data = NULL;
	php->size = 0;
	php->capacity = 0;
} // HPInit

void HPDestroy(HP* php)
{
	/*销毁堆*/
	assert(php);
	free(php->data);
	php->data = NULL;
	php->size = 0;
	php->capacity = 0;
} // HPDestroy

void HPPush(HP* php, DataType data)
{
	/*堆的插入*/
	assert(php);
	if (php->size == php->capacity)
	{
		//扩容
		php->capacity = php->capacity == 0 ? 4 : php->capacity * 2;
		DataType* temp = (DataType*)realloc(php->data, php->capacity * sizeof(DataType));
		assert(temp);
		php->data = temp;
	}
	php->data[php->size] = data;
	//向上调整
	AdjustUp(php->data, php->size);
	++php->size;
} // HPPush

DataType HPPop(HP* php)
{
	/*堆的删除*/
	assert(php);
	assert(php->size > 0);
	DataType ret = php->data[0];
	--php->size;
	if (php->size == 1) return ret;
	//交换根节点和最后一个节点
	Swap(&php->data[php->size], &php->data[0]);
	//向下调整
	AdjustDwon(php->data, php->size, 0);
	return ret;
} // HPPop

DataType HPTop(HP* php)
{
	/*取堆顶元素*/
	assert(php);
	assert(php->size > 0);
	return php->data[0];
} // HPTop

int HPEmpty(HP* php)
{
	/*判断堆是否为空*/
	assert(php);
	return !(php->size > 0);
} // HPEmpty

int HPSize(HP* php)
{
	/*堆中元素个数*/
	assert(php);
	return php->size;
} // HPSize

#undef _CMP_