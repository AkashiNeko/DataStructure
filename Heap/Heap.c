#include "Heap.h"

#if _MAX_HEAP
#define _CMP_ >
#else
#define _CMP_ <
#endif

void Swap(DataType* p1, DataType* p2)
{
	/*��������*/
	DataType temp = *p1;
	*p1 = *p2;
	*p2 = temp;
} // Swap

void AdjustDwon(DataType* data, int size, int parent)
{
	/*���µ���*/
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && data[child + 1] _CMP_ data[child])
		{
			//ȡ�����ӽڵ�����С/���
			++child;
		}
		if (data[child] _CMP_ data[parent])
		{
			//���½������ӽڵ�
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
	/*���ϵ���*/
	int parent = (child - 1) / 2;
	while (data[child] _CMP_ data[parent])
	{
		//���Ͻ������ӽڵ�
		Swap(&data[parent], &data[child]);
		child = parent;
		parent = (parent - 1) / 2;
	}
} // AdjustUp

void HPPrint(HP* php)
{
	/*��ӡ��*/
	assert(php);
	if (php->size == 0)
	{
		//��Ϊ��
		printf("Heap is Empty.\n");
		return;
	}
	int order = 1;
	int count = 2;
	while (php->size >= count)
	{
		//����ѵĸ߶�
		count *= 2;
		order++;
	}
	int step = 0;
	int index = 0;
	for(step = 0; step < order; ++step)
	{
		//����ӡ
		int i = 0, j;
		for (i = 1; i < count / 2; ++i)
			//����ǰ�ո�
			printf("  ");
		for (i = 0; i < (1 << step); i++)
		{
			if (index == php->size)
				//��ӡĩβδ����λ��
				printf("__");
			else
				//��ӡ����
				printf("%2d", php->data[index++]);
			if (i != (1 << step) - 1)
			{
				for (j = 1; j < count; ++j)
					//��ӡ���ּ�ո�
					printf("  ");
			}
		}
		count /= 2;
		printf("\n");
	}
} // HPPrint

void HPInit(HP* php)
{
	/*��ʼ����*/
	assert(php);
	php->data = NULL;
	php->size = 0;
	php->capacity = 0;
} // HPInit

void HPDestroy(HP* php)
{
	/*���ٶ�*/
	assert(php);
	free(php->data);
	php->data = NULL;
	php->size = 0;
	php->capacity = 0;
} // HPDestroy

void HPPush(HP* php, DataType data)
{
	/*�ѵĲ���*/
	assert(php);
	if (php->size == php->capacity)
	{
		//����
		php->capacity = php->capacity == 0 ? 4 : php->capacity * 2;
		DataType* temp = (DataType*)realloc(php->data, php->capacity * sizeof(DataType));
		assert(temp);
		php->data = temp;
	}
	php->data[php->size] = data;
	//���ϵ���
	AdjustUp(php->data, php->size);
	++php->size;
} // HPPush

DataType HPPop(HP* php)
{
	/*�ѵ�ɾ��*/
	assert(php);
	assert(php->size > 0);
	DataType ret = php->data[0];
	--php->size;
	if (php->size == 1) return ret;
	//�������ڵ�����һ���ڵ�
	Swap(&php->data[php->size], &php->data[0]);
	//���µ���
	AdjustDwon(php->data, php->size, 0);
	return ret;
} // HPPop

DataType HPTop(HP* php)
{
	/*ȡ�Ѷ�Ԫ��*/
	assert(php);
	assert(php->size > 0);
	return php->data[0];
} // HPTop

int HPEmpty(HP* php)
{
	/*�ж϶��Ƿ�Ϊ��*/
	assert(php);
	return !(php->size > 0);
} // HPEmpty

int HPSize(HP* php)
{
	/*����Ԫ�ظ���*/
	assert(php);
	return php->size;
} // HPSize

#undef _CMP_