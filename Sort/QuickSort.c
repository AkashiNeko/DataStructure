#include "Sort.h"

void QUI_Swap(int* p1, int* p2)
{
	/*交换*/
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
} // QUI_Swap

void QuickSort(int* arr, int size)
{
	if (size <= 1) return;
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

	//对prev左边的元素排序
	QuickSort(arr, prev);
	//对prev右边的元素排序
	QuickSort(arr + prev + 1, size - prev - 1);
}