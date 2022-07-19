#include "Sort.h"

void HEP_Swap(int* p1, int* p2)
{
	/*����*/
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
} // HEP_Swap

void AdjustDown(int* arr, int size, int parent)
{
	/*�����µ���*/
	int child = parent * 2 + 1;
	while (child < size)
	{
		//ѡ���������ӽڵ��и���/С��
		if (child + 1 < size && arr[child] SYM arr[child + 1])
			++child;

		if (arr[parent] SYM arr[child])
		{
			//���½���
			HEP_Swap(&arr[parent], &arr[child]);
			parent = child;
			child = child * 2 + 1;
		}
		else
		{
			break;
		}
	}
} // AdjustDown

void HeapSort(int* arr, int size)
{
	/*������*/
	if (size <= 1) return;
	int i, j;
	for (i = (size - 2) / 2; i >= 0; --i)
	{
		//����
		AdjustDown(arr, size, i);
	}

	for (i = size - 1; i > 0; --i)
	{
		//����
		HEP_Swap(&arr[i], &arr[0]);
		AdjustDown(arr, i, 0);
	}
} // HeapSort