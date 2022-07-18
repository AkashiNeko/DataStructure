#include "Sort.h"

void SEL_Swap(int* p1, int* p2)
{
	/*Ωªªª*/
	if (p1 == p2)
		return;
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
} // SEL_Swap

void SelectionSort(int* arr, int size)
{
	/*—°‘Ò≈≈–Ú*/
	int i, j;
	for (i = 0; i < size - 1; ++i)
	{
		int index = i;
		for (j = i + 1; j < size; ++j)
		{
			if (arr[j] SYM arr[index])
				index = j;
		}
		SEL_Swap(&arr[index], &arr[i]);
	}
} // SelectionSort