#include "Sort.h"

void InsertionSort(int* arr, int size)
{
	/*��������*/
	if (size <= 1) return;
	int i, j;
	for (i = 1; i < size; ++i)
	{
		int temp = arr[i];
		for (j = i; j > 0; --j)
		{
			if (temp SYM arr[j - 1])
				arr[j] = arr[j - 1];
			else
				break;
		}
		arr[j] = temp;
	}
} // InsertionSort