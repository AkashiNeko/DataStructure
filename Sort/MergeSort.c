#include "Sort.h"

void MER_Swap(int* p1, int* p2)
{
	/*交换*/
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
} // MER_Swap

void PartMergeSort(int* arr, int size, int* tmp)
{
	/*归并排序递归部分*/
	if (size <= 1) return;

	if (size == 2)
	{
		//数组只有两个元素
		if (arr[1] SYM arr[0])
			MER_Swap(&arr[0], &arr[1]);
		return;
	}

	//把数组分为左右两部分
	int mid = size / 2;

	//对mid左边的元素排序
	PartMergeSort(arr, mid, tmp);
	//对mid右边的元素排序
	PartMergeSort(arr + mid, size - mid, tmp);

	int left = 0;
	int right = mid;
	int cur = 0;
	//归并放入tmp数组
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
			//当 arr[left] == arr[right] 时，先入left，保持排序稳定
			tmp[cur++] = !(arr[right] SYM arr[left]) ? arr[left++] : arr[right++];
		}
	}

	//拷贝回原数组
	memcpy(arr, tmp, size * sizeof(int));
} // PartMergeSort

void MergeSort(int* arr, int size)
{
	/*归并排序*/
	if (size <= 1) return;

	//开辟临时数组空间 O(N)
	int* tmp = (int*)malloc(size * sizeof(int));
	assert(tmp);

	PartMergeSort(arr, size, tmp);

	free(tmp);
} // MergeSort