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

#define SORT(function)      \
int start = clock();        \
Sort(arr, sz, function);    \
int end = clock();          \
printf(#function" clock: %d\n\n", end - start)

void Sort(int* arr, int size, void (*sort)(int*, int))
{
	sort(arr, size);
}

void PrintArr(int* arr, int size)
{
	int i;
	for (i = 0; i < size; ++i)
	{
		printf("%2d ", arr[i]);
	}
	printf("\n\n");
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

	//PrintArr(arr, sz);

	//²åÈëÅÅÐò	InsertionSort
	//Ï£¶ûÅÅÐò	ShellSort
	//Ñ¡ÔñÅÅÐò	SelectionSort
	//¶ÑÅÅÐò  	HeapSort
	//Ã°ÅÝÅÅÐò	BubbleSort
	//¿ìËÙÅÅÐò	QuickSort
	//¹é²¢ÅÅÐò	MergeSort
	//¼ÆÊýÅÅÐò	CountSort

	SORT(QuickSort);
	
	//PrintArr(arr, sz);

	free(arr);

	return 0;
}