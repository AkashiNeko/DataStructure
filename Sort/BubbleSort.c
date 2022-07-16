#include "Sort.h"

void BUB_Swap(int* p1, int* p2)
{
	/*½»»»*/
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
} // BUB_Swap

void BubbleSort(int* arr, int size)
{
	/*Ã°ÅÝÅÅÐò*/
	int i, j;
	for (i = size - 1; i > 0; --i)
	{
		int NotExchange = 1;
		for (j = 0; j < i; ++j)
		{
			if (arr[j + 1] SYM arr[j])
			{
				BUB_Swap(&arr[j], &arr[j + 1]);
				NotExchange = 0;
			}
		}
		if (NotExchange)
			break;
	}
} // BubbleSort