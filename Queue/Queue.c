#include "Queue.h"

void QInit(pQ pq)
{
	/*��ʼ������*/
	assert(pq);
	pq->front = NULL;
	pq->rear = NULL;
} // QInit

void QDestroy(pQ pq)
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
} // QDestroy

void QPush(pQ pq, DataType data)
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
} // QPush

void QPop(pQ pq)
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
} // QPop

DataType QFront(pQ pq)
{
	/*ȡ��ͷԪ��*/
	assert(pq);
	assert(pq->front);
	return pq->front->data;
} // QFront

DataType QRear(pQ pq)
{
	/*ȡ��βԪ��*/
	assert(pq);
	assert(pq->rear);
	return pq->rear->data;
} // QRear

int QEmpty(pQ pq)
{
	/*�ж϶����Ƿ�Ϊ��*/
	assert(pq);
	return !pq->front;
} // QEmpty

int QSize(pQ pq)
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
} // QSize