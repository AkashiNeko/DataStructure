#include "Sort.h"

void QUI_Swap(int* p1, int* p2)
{
	/*交换*/
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
} // QUI_Swap

int MidIndex(int* arr, int size)
{
	//三数取中
	int left = 0;
	int right = size - 1;
	int mid = (left + right) / 2;
	if (arr[left] < arr[mid])
		if (arr[mid] < arr[right])
			return mid;
		else if (arr[right] < arr[left])
			return left;
		else
			return right;
	else
		if (arr[right] < arr[mid])
			return mid;
		else if (arr[right] < arr[left])
			return right;
		else
			return left;
} // MidIndex

int PartSort(int* arr, int size)
{
	//三数取中作为基准
	int key = MidIndex(arr, size);
	QUI_Swap(&arr[0], &arr[key]);

	int prev = 0;
	int cur = 1;
	while (cur < size)
	{
		if (arr[cur] SYM arr[0] && ++prev != cur)
		{
			//cur与prev的下一个元素交换
			QUI_Swap(&arr[cur], &arr[prev]);
		}
		++cur;
	}
	QUI_Swap(&arr[0], &arr[prev]);

	return prev;
} // PartSort

void QuickSort(int* arr, int size)
{
	if (size < 10)
	{
		//区间较小时
		InsertionSort(arr, size);
		return;
	}

	int key = PartSort(arr, size);

	//数组元素全部相同
	//if (arr[0] == arr[size - 1])
	//	return;

	//对prev左边的元素排序
	QuickSort(arr, key);
	//对prev右边的元素排序
	QuickSort(arr + key + 1, size - key - 1);
} // QuickSort