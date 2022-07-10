#include "LinkQueue.h"

void LQInit(pLQ pq)
{
	/*��ʼ������*/
	assert(pq);
	pq->front = NULL;
	pq->rear = NULL;
} // LQInit

void LQDestroy(pLQ pq)
{
	/*���ٶ���*/
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
	/*���*/
	assert(pq);
	if (pq->front == NULL)
	{
		//����Ϊ��
		pq->front = (pQNode)malloc(sizeof(QNode));
		assert(pq->front);
		pq->rear = pq->front;
	}
	else
	{
		//����β��
		pq->rear->next = (pQNode)malloc(sizeof(QNode));
		assert(pq->rear->next);
		pq->rear = pq->rear->next;
	}
	pq->rear->next = NULL;
	pq->rear->data = data;
} // LQPush

void LQPop(pLQ pq)
{
	/*����*/
	assert(pq);
	if (pq->front == NULL) return;
	pQNode cur = pq->front;
	pq->front = pq->front->next;
	free(cur);
	if (pq->front == NULL)
	{
		//���Ӻ����Ϊ��
		pq->rear = NULL;
	}
} // LQPop

DataType LQFront(pLQ pq)
{
	/*ȡ��ͷԪ��*/
	assert(pq);
	assert(pq->front);
	return pq->front->data;
} // LQFront

DataType LQRear(pLQ pq)
{
	/*ȡ��βԪ��*/
	assert(pq);
	assert(pq->rear);
	return pq->rear->data;
} // LQRear

int LQEmpty(pLQ pq)
{
	/*�ж϶����Ƿ�Ϊ��*/
	assert(pq);
	return !pq->front;
} // LQEmpty

int LQSize(pLQ pq)
{
	/*ȡ������Ԫ�ظ���*/
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