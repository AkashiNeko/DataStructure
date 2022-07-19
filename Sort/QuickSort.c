#include "Sort.h"

void QUI_Swap(int* p1, int* p2)
{
	/*����*/
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
} // QUI_Swap

int MidIndex(int* arr, int size)
{
	//����ȡ��
	int left = 0;
	int right = size - 1;
	int mid = (left + right) / 2;
	if (arr[left] < arr[mid])
		if (arr[mid] < arr[right])
			return mid;
		else if (arr[right] < arr[left])
			return left;
		else
			return right;
	else
		if (arr[right] < arr[mid])
			return mid;
		else if (arr[right] < arr[left])
			return right;
		else
			return left;
} // MidIndex

int PartSort(int* arr, int size)
{
	//����ȡ����Ϊ��׼
	int key = MidIndex(arr, size);
	QUI_Swap(&arr[0], &arr[key]);

	int prev = 0;
	int cur = 1;
	while (cur < size)
	{
		if (arr[cur] SYM arr[0] && ++prev != cur)
		{
			//cur��prev����һ��Ԫ�ؽ���
			QUI_Swap(&arr[cur], &arr[prev]);
		}
		++cur;
	}
	QUI_Swap(&arr[0], &arr[prev]);

	return prev;
} // PartSort

void QuickSort(int* arr, int size)
{
	if (size < 10)
	{
		//�����Сʱ
		InsertionSort(arr, size);
		return;
	}

	int key = PartSort(arr, size);

	//����Ԫ��ȫ����ͬ
	//if (arr[0] == arr[size - 1])
	//	return;

	//��prev��ߵ�Ԫ������
	QuickSort(arr, key);
	//��prev�ұߵ�Ԫ������
	QuickSort(arr + key + 1, size - key - 1);
} // QuickSort