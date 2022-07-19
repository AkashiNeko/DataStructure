#include "Sort.h"

void HEP_Swap(int* p1, int* p2)
{
	/*交换*/
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
} // HEP_Swap

void AdjustDown(int* arr, int size, int parent)
{
	/*堆向下调整*/
	int child = parent * 2 + 1;
	while (child < size)
	{
		//选择两个孩子节点中更大/小的
		if (child + 1 < size && arr[child] SYM arr[child + 1])
			++child;

		if (arr[parent] SYM arr[child])
		{
			//向下交换
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
	/*堆排序*/
	if (size <= 1) return;
	int i, j;
	for (i = (size - 2) / 2; i >= 0; --i)
	{
		//建堆
		AdjustDown(arr, size, i);
	}

	for (i = size - 1; i > 0; --i)
	{
		//出堆
		HEP_Swap(&arr[i], &arr[0]);
		AdjustDown(arr, i, 0);
	}
} // HeapSort