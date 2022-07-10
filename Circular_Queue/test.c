//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
//    date:   2022-7-10
//    author: Akashi
//    github: https://github.com/AkashiNeko/DataStructure
//    QQ:     1006554341
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

#include "CirQueue.h"

void CQueueTest()
{
	CQ q;
	CQInit(&q, 8);

	printf("Size : %d\n", CQSize(&q));
	printf("Empty: %d\n", CQEmpty(&q));

	CQPush(&q, 11);
	CQPush(&q, 45);
	CQPush(&q, 14);
	CQPush(&q, 19);
	CQPush(&q, 81);
	printf("\nCQPush 5\n");

	printf("\nFront: %d\n", CQFront(&q));
	printf("Rear : %d\n", CQRear(&q));
	printf("\nSize : %d\n", CQSize(&q));
	printf("Empty: %d\n", CQEmpty(&q));

	CQPop(&q);
	CQPop(&q);
	CQPop(&q);
	printf("\nCQPop 3\n");

	printf("\nFront: %d\n", CQFront(&q));
	printf("Rear : %d\n", CQRear(&q));
	printf("\nSize : %d\n", CQSize(&q));
	printf("Empty: %d\n", CQEmpty(&q));

	CQDestroy(&q);
}

int main()
{
	CQueueTest();
	return 0;
}