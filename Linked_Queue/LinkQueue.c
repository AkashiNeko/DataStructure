#include "LinkQueue.h"

void LQInit(pLQ pq)
{
	/*初始化队列*/
	assert(pq);
	pq->front = NULL;
	pq->rear = NULL;
} // LQInit

void LQDestroy(pLQ pq)
{
	/*销毁队列*/
	assert(pq);
	if (pq->front == NULL) return;
	pQNode cur = pq->front;
	pQNode nex = cur->next;
	free(cur);
	while (nex)
	{
		cur = nex;
		nex = nex->next;
		free(cur);
	}
	pq->front = NULL;
	pq->rear = NULL;
} // LQDestroy

void LQPush(pLQ pq, DataType data)
{
	/*入队*/
	assert(pq);
	if (pq->front == NULL)
	{
		//队列为空
		pq->front = (pQNode)malloc(sizeof(QNode));
		assert(pq->front);
		pq->rear = pq->front;
	}
	else
	{
		//链表尾插
		pq->rear->next = (pQNode)malloc(sizeof(QNode));
		assert(pq->rear->next);
		pq->rear = pq->rear->next;
	}
	pq->rear->next = NULL;
	pq->rear->data = data;
} // LQPush

void LQPop(pLQ pq)
{
	/*出队*/
	assert(pq);
	if (pq->front == NULL) return;
	pQNode cur = pq->front;
	pq->front = pq->front->next;
	free(cur);
	if (pq->front == NULL)
	{
		//出队后队列为空
		pq->rear = NULL;
	}
} // LQPop

DataType LQFront(pLQ pq)
{
	/*取队头元素*/
	assert(pq);
	assert(pq->front);
	return pq->front->data;
} // LQFront

DataType LQRear(pLQ pq)
{
	/*取队尾元素*/
	assert(pq);
	assert(pq->rear);
	return pq->rear->data;
} // LQRear

int LQEmpty(pLQ pq)
{
	/*判断队列是否为空*/
	assert(pq);
	return !pq->front;
} // LQEmpty

int LQSize(pLQ pq)
{
	/*取队列中元素个数*/
	assert(pq);
	int count = 0;
	pQNode cur = pq->front;
	while (cur)
	{
		cur = cur->next;
		count++;
	}
	return count;
} // LQSize