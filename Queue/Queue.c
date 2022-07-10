#include "Queue.h"

void QInit(pQ pq)
{
	/*初始化队列*/
	assert(pq);
	pq->front = NULL;
	pq->rear = NULL;
} // QInit

void QDestroy(pQ pq)
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
} // QDestroy

void QPush(pQ pq, DataType data)
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
} // QPush

void QPop(pQ pq)
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
} // QPop

DataType QFront(pQ pq)
{
	/*取队头元素*/
	assert(pq);
	assert(pq->front);
	return pq->front->data;
} // QFront

DataType QRear(pQ pq)
{
	/*取队尾元素*/
	assert(pq);
	assert(pq->rear);
	return pq->rear->data;
} // QRear

int QEmpty(pQ pq)
{
	/*判断队列是否为空*/
	assert(pq);
	return !pq->front;
} // QEmpty

int QSize(pQ pq)
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
} // QSize