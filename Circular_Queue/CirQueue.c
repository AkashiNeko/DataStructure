#include "CirQueue.h"

void CQInit(pCQ pq, int capacity)
{
	/*��ʼ������*/
	assert(pq);
	pq->data = (DataType*)malloc(capacity * sizeof(DataType));
	assert(pq->data);
	pq->capacity = capacity;
	pq->front = 0;
	pq->rear = 0;
} // CQInit

void CQDestroy(pCQ pq)
{
	/*���ٶ���*/
	assert(pq);
	free(pq->data);
	pq->data = NULL;
	pq->capacity = 0;
	pq->front = 0;
	pq->rear = 0;
} // CQDestroy

int CQPush(pCQ pq, DataType data)
{
	/*���*/
	assert(pq);
	assert(pq->data);
	int next = (pq->rear + 1) % pq->capacity;
	if (next == pq->front)
		//��������
		return 0;
	pq->data[pq->rear] = data;
	pq->rear = next;
	return 1;
} // CQPush

DataType CQPop(pCQ pq)
{
	/*����*/
	assert(pq);
	//����ǿն����򱨴�
	assert(pq->rear != pq->front);
	int next = (pq->front + 1) % pq->capacity;
	DataType ret = pq->data[pq->front];
	pq->front = next;
	return ret;
} // CQPop

DataType CQFront(pCQ pq)
{
	/*ȡ��ͷԪ��*/
	assert(pq);
	//����ǿն����򱨴�
	assert(pq->rear != pq->front);
	return pq->data[pq->front];
} // CQFront

DataType CQRear(pCQ pq)
{
	/*ȡ��βԪ��*/
	assert(pq);
	//����ǿն����򱨴�
	assert(pq->rear != pq->front);
	int prev = pq->rear == 0 ? pq->capacity - 1 : pq->rear - 1;
	return pq->data[prev];
} // CQRear

int CQEmpty(pCQ pq)
{
	/*�ж϶����Ƿ�Ϊ��*/
	assert(pq);
	assert(pq->data);
	return pq->rear == pq->front;
} // CQEmpty

int CQSize(pCQ pq)
{
	/*ȡ������Ԫ�ظ���*/
	assert(pq);
	assert(pq->data);
	return (pq->rear - pq->front + pq->capacity) % pq->capacity;
} // CQSize