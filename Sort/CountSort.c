#include "Sort.h"

void CountSort(int* arr, int size)
{
	/*计数排序*/
	if (size <= 1) return;

	int i, j;
	//计算范围
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

	//开辟计数数组空间
	int* count = (int*)calloc(range, sizeof(int));
	assert(count);

	//写到计数数组中
	for (i = 0; i < size; ++i)
	{
		++count[arr[i] - min];
	}

	//写回原数组
	if (0 SYM 1)
	{
		//升序
		i = 0;
		for (j = 0; j < range; ++j)
		{
			while (count[j]--)
				arr[i++] = j + min;
		}
	}
	else
	{
		//降序
		for (j = 0; j < range; ++j)
		{
			while (count[j]--)
				arr[--size] = j + min;
		}
	}
	free(count);
} // CountSort