#include "Sort.h"

void ShellSort(int* arr, int size)
{
	/*Ï£¶ûÅÅÐò*/
	if (size <= 1) return;
	int i, j;
	int gap = size;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (i = gap; i < size; ++i)
		{
			int temp = arr[i];
			for (j = i; j >= gap; j -= gap)
			{
				if (temp SYM arr[j - gap])
					arr[j] = arr[j - gap];
				else
					break;
			}
			arr[j] = temp;
		}
	}
} // ShellSort