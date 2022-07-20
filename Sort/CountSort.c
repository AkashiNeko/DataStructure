#include "Sort.h"

void CountSort(int* arr, int size)
{
	/*��������*/
	if (size <= 1) return;

	int i, j;
	//���㷶Χ
	int min = arr[0];
	int max = arr[0];
	for (i = 0; i < size; ++i)
	{
		if (arr[i] < min)
			min = arr[i];
		if (arr[i] > max)
			max = arr[i];
	}
	int range = max - min + 1;

	//���ټ�������ռ�
	int* count = (int*)calloc(range, sizeof(int));
	assert(count);

	//д������������
	for (i = 0; i < size; ++i)
	{
		++count[arr[i] - min];
	}

	//д��ԭ����
	if (0 SYM 1)
	{
		//����
		i = 0;
		for (j = 0; j < range; ++j)
		{
			while (count[j]--)
				arr[i++] = j + min;
		}
	}
	else
	{
		//����
		for (j = 0; j < range; ++j)
		{
			while (count[j]--)
				arr[--size] = j + min;
		}
	}
	free(count);
} // CountSort