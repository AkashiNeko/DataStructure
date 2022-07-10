//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
//    date:   2022-7-10
//    author: Akashi
//    github: https://github.com/AkashiNeko/DataStructure
//    QQ:     1006554341
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

#include "LinkQueue.h"

void LQueueTest()
{
	LQ q;
	LQInit(&q);

	printf("Size : %d\n", LQSize(&q));
	printf("Empty: %d\n", LQEmpty(&q));

	LQPush(&q, 11);
	LQPush(&q, 45);
	LQPush(&q, 14);
	LQPush(&q, 19);
	LQPush(&q, 81);
	printf("\nLQPush 5\n");

	printf("\nFront: %d\n", LQFront(&q));
	printf("Rear : %d\n", LQRear(&q));
	printf("\nSize : %d\n", LQSize(&q));
	printf("Empty: %d\n", LQEmpty(&q));

	LQPop(&q);
	LQPop(&q);
	LQPop(&q);
	printf("\nLQPop 3\n");

	printf("\nFront: %d\n", LQFront(&q));
	printf("Rear : %d\n", LQRear(&q));
	printf("\nSize : %d\n", LQSize(&q));
	printf("Empty: %d\n", LQEmpty(&q));

	LQDestroy(&q);
	printf("\nLQDestroy\n");
	printf("\nSize : %d\n", LQSize(&q));
	printf("Empty: %d\n", LQEmpty(&q));
}

int main()
{
	LQueueTest();
	return 0;
}