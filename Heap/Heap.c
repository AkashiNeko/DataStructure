#include "Heap.h"

void Swap(DataType* p1, DataType* p2)
{
	/*��������*/
	DataType temp = *p1;
	*p1 = *p2;
	*p2 = temp;
} // Swap

void AdjustDown(DataType* data, int size, int parent)
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
} // AdjustDown

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
	if (php->size == 0) return ret;
	//���һ���ڵ��ƶ������ڵ�
	php->data[0] = php->data[php->size];
	//���µ���
	AdjustDown(php->data, php->size, 0);
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

void CustomAdjustDown(DataType* data, int size, int parent, int maxHeap)
{
	/*�Ӹ��ڵ㿪ʼ���µ�������ѡ�����ѻ���С�ѣ�*/
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && data[child + 1] != data[child])
		{
			//����������ӽڵ�
			if (maxHeap ^ (data[child + 1] < data[child]))
			{
				++child;
			}
		}
		if (maxHeap ^ (data[child] < data[parent]))
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
} // CustomAdjustDown

void HeapSort(DataType* data, int size, int seq)
{
	/*������*/
	assert(data);
	int i;
	for (i = (size - 2) / 2; i >= 0; --i)
	{
		CustomAdjustDown(data, size, i, !seq);
	}
	while (size--)
	{
		Swap(data, data + size);
		CustomAdjustDown(data, size, 0, !seq);
	}
} // HeapSort

void SortTopK(DataType* data, int size, int k, int seq)
{
	/*����data���������/С��k��Ԫ��*/
	assert(data);
	if (k <= 0) return;
	if(k > size) k = size;
	int i;
	for (i = (k - 2) / 2; i >= 0; --i)
	{
		CustomAdjustDown(data, k, i, !seq);
	}
	for (i = k; i < size; ++i)
	{
		if (data[i] == data[0])
			continue;
		if (seq ^ (data[i] < data[0]))
		{
			Swap(data + i, data);
			CustomAdjustDown(data, k, 0, !seq);
		}
	}
	while (k--)
	{
		Swap(data, data + k);
		CustomAdjustDown(data, k, 0, !seq);
	}
} // SortTopK