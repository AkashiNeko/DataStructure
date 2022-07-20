#include "Sort.h"

void MER_Swap(int* p1, int* p2)
{
	/*����*/
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
} // MER_Swap

void PartMergeSort(int* arr, int size, int* tmp)
{
	/*�鲢����ݹ鲿��*/
	if (size <= 1) return;

	if (size == 2)
	{
		//����ֻ������Ԫ��
		if (arr[1] SYM arr[0])
			MER_Swap(&arr[0], &arr[1]);
		return;
	}

	//�������Ϊ����������
	int mid = size / 2;

	//��mid��ߵ�Ԫ������
	PartMergeSort(arr, mid, tmp);
	//��mid�ұߵ�Ԫ������
	PartMergeSort(arr + mid, size - mid, tmp);

	int left = 0;
	int right = mid;
	int cur = 0;
	//�鲢����tmp����
	while (cur < size)
	{
		if (left == mid)
		{
			tmp[cur++] = arr[right++];
		}
		else if (right == size)
		{
			tmp[cur++] = arr[left++];
		}
		else
		{
			//�� arr[left] == arr[right] ʱ������left�����������ȶ�
			tmp[cur++] = !(arr[right] SYM arr[left]) ? arr[left++] : arr[right++];
		}
	}

	//������ԭ����
	memcpy(arr, tmp, size * sizeof(int));
} // PartMergeSort

void MergeSort(int* arr, int size)
{
	/*�鲢����*/
	if (size <= 1) return;

	//������ʱ����ռ� O(N)
	int* tmp = (int*)malloc(size * sizeof(int));
	assert(tmp);

	PartMergeSort(arr, size, tmp);

	free(tmp);
} // MergeSort