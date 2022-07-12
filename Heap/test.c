//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
//    date:   2022-7-12
//    author: Akashi
//    github: https://github.com/AkashiNeko/DataStructure
//    QQ:     1006554341
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

#include "Heap.h"

void HeapTest()
{
	HP hp;
	HPInit(&hp);
	srand(114514);
	for (int i = 0; i < 7; ++i)
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

int main()
{
	int i = 0;
	HeapTest();
	return 0;
}