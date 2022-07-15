#include "Sort.h"

void InsertionSort(int* arr, int size)
{
	if (size <= 1)
		return;
	int i, j;
	for (i = 1; i < size; ++i)
	{
		//ц©лкеепР
		for (j = i - 1; i >= 0; --j)
		{
			//╣╔лкеепР
			if (arr[j + 1] SYM arr[j])
				Swap(arr[j + 1], arr[j]);
			else
				break;
		}
	}
}