//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
//    date:   2022-7-12
//    author: Akashi
//    github: https://github.com/AkashiNeko/DataStructure
//    QQ:     1006554341
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

#include "Heap.h"

void HeapTest1()
{
	HP hp;
	HPInit(&hp);
	srand(114514);
	for (int i = 0; i < 15; ++i)
	{
		HPPush(&hp, rand() % 90 + 10);
		HPPrint(&hp);
		printf("\n\n");
	}
	while (!HPEmpty(&hp))
	{
		//printf("%d ", HPPop(&hp));
		HPPop(&hp);
		HPPrint(&hp);
		printf("\n\n");
	}
}

void HeapTest2()
{
	srand(1919810);
	int arr[20];
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < sz; ++i)
	{
		arr[i] = rand() % 100;
		printf("%d ", arr[i]);
	}
	//ÅÅÐò
	HeapSort(arr, sz);
	printf("\n");
	for (int i = 0; i < sz; ++i)
	{
		printf("%d ", arr[i]);
	}
}

int main()
{
	int i = 0;
	//HeapTest1();
	HeapTest2();
	return 0;
}