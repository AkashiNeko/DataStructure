//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
//    date:   2022-7-16
//    author: Akashi
//    github: https://github.com/AkashiNeko/DataStructure
//    QQ:     1006554341
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

#include "Sort.h"
#include <stdio.h>
#include <time.h>

void SortTest(int* arr, int size, void (*sort)(int*, int))
{
	int i = 0;
	sort(arr, size);
	for (i = 0; i < size; ++i)
	{
		printf("%2d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	srand((unsigned int)time(NULL));

	int arr[25];
	int sz = sizeof(arr) / sizeof(arr[0]);

	for (int i = 0; i < sz; ++i)
	{
		arr[i] = rand() % 100;
	}
	for (int i = 0; i < sz; ++i)
	{
		printf("%2d ", arr[i]);
	}
	printf("\n\n");

					//InsertionSort
					//ShellSort
					//SelectionSort
					//BubbleSort
	SortTest(arr, sz, QuickSort);

	return 0;
}