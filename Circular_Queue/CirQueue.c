#include "CirQueue.h"

void CQInit(pCQ pq, int capacity)
{
	/*初始化队列*/
	assert(pq);
	pq->data = (DataType*)malloc(capacity * sizeof(DataType));
	assert(pq->data);
	pq->capacity = capacity;
	pq->front = 0;
	pq->rear = 0;
} // CQInit

void CQDestroy(pCQ pq)
{
	/*销毁队列*/
	assert(pq);
	free(pq->data);
	pq->data = NULL;
	pq->capacity = 0;
	pq->front = 0;
	pq->rear = 0;
} // CQDestroy

int CQPush(pCQ pq, DataType data)
{
	/*入队*/
	assert(pq);
	assert(pq->data);
	int next = (pq->rear + 1) % pq->capacity;
	if (next == pq->front)
		//队列已满
		return 0;
	pq->data[pq->rear] = data;
	pq->rear = next;
	return 1;
} // CQPush

DataType CQPop(pCQ pq)
{
	/*出队*/
	assert(pq);
	//如果是空队列则报错
	assert(pq->rear != pq->front);
	int next = (pq->front + 1) % pq->capacity;
	DataType ret = pq->data[pq->front];
	pq->front = next;
	return ret;
} // CQPop

DataType CQFront(pCQ pq)
{
	/*取队头元素*/
	assert(pq);
	//如果是空队列则报错
	assert(pq->rear != pq->front);
	return pq->data[pq->front];
} // CQFront

DataType CQRear(pCQ pq)
{
	/*取队尾元素*/
	assert(pq);
	//如果是空队列则报错
	assert(pq->rear != pq->front);
	int prev = pq->rear == 0 ? pq->capacity - 1 : pq->rear - 1;
	return pq->data[prev];
} // CQRear

int CQEmpty(pCQ pq)
{
	/*判断队列是否为空*/
	assert(pq);
	assert(pq->data);
	return pq->rear == pq->front;
} // CQEmpty

int CQSize(pCQ pq)
{
	/*取队列中元素个数*/
	assert(pq);
	assert(pq->data);
	return (pq->rear - pq->front + pq->capacity) % pq->capacity;
} // CQSize