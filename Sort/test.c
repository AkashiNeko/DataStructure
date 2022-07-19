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

void Sort(int* arr, int size, void (*sort)(int*, int))
{
	sort(arr, size);
}

int main()
{
	srand((unsigned int)time(NULL));

	int sz = 1000000;
	int* arr = (int*)malloc(sz * sizeof(int));
	assert(arr);
	
	for (int i = 0; i < sz; ++i)
	{
		arr[i] = rand();
		//arr[i] = 1;
	}

	/*for (int i = 0; i < sz; ++i)
	{
		printf("%2d ", arr[i]);
	}*/
	//printf("\n\n");

	//InsertionSort
	//ShellSort
	//SelectionSort
	//BubbleSort
	//QuickSort

	int start = clock();
	Sort(arr, sz, QuickSort);
	int end = clock();
	printf("clock: %d", end - start);

	return 0;
}