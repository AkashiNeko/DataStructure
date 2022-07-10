//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
//    date:   2022-7-10
//    author: Akashi
//    github: https://github.com/AkashiNeko/DataStructure
//    QQ:     1006554341
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

#include "Queue.h"

void QueueTest()
{
	Queue q;
	QInit(&q);

	printf("Size : %d\n", QSize(&q));
	printf("Empty: %d\n", QEmpty(&q));

	QPush(&q, 11);
	QPush(&q, 45);
	QPush(&q, 14);
	QPush(&q, 19);
	QPush(&q, 81);
	printf("\nQPush 5\n");

	printf("\nFront: %d\n", QFront(&q));
	printf("Rear : %d\n", QRear(&q));
	printf("\nSize : %d\n", QSize(&q));
	printf("Empty: %d\n", QEmpty(&q));

	QPop(&q);
	QPop(&q);
	QPop(&q);
	printf("\nQPop 3\n");

	printf("\nFront: %d\n", QFront(&q));
	printf("Rear : %d\n", QRear(&q));
	printf("\nSize : %d\n", QSize(&q));
	printf("Empty: %d\n", QEmpty(&q));

	QDestroy(&q);
	printf("\nQDestroy\n");
	printf("\nSize : %d\n", QSize(&q));
	printf("Empty: %d\n", QEmpty(&q));
}

int main()
{
	QueueTest();
	return 0;
}