#include "SeqList.h"

void SLInit(pSL ps)
{
	/*初始化*/
	assert(ps);
	// 初始大小
	ps->size = 4;
	// 分配内存
	ps->list = (int*)malloc(ps->size * sizeof(int*));
	if (ps->list == NULL)
	{
		perror("SLInit malloc");
		exit(114514);
	}
	ps->len = 0;
} // SLInit

void SLDestory(pSL ps)
{
	/*销毁顺序表*/
	assert(ps);
	free(ps->list);
	ps->list = NULL;
	ps->len = 0;
	ps->size = 0;
} // SLDestory

void SLCheckCapacity(pSL ps)
{
	/*长度达到容量时扩容*/
	assert(ps->list);
	if (ps->len < ps->size)
		return;
	// 空间翻倍
	ps->size *= 2;
	// 扩容
	int* pTemp = (int*)realloc(ps->list, ps->size * sizeof(int*));
	if (pTemp == NULL)
	{
		perror("SLCheckCapacity realloc");
		exit(114514);
	}
	ps->list = pTemp;
} // SLCheckCapacity

void SLPrint(const pSL ps)
{
	/*打印顺序表信息*/
	int i;
	printf("\nlist: ");
	if (ps->len)
		for (i = 0; i < ps->len; i++)
			printf("%d ", ps->list[i]);
	else
		printf("none");
	printf("\nlen:  %d\n", ps->len);
	printf("size: %d\n", ps->size);
} // SLPrint

void SLPushBack(pSL ps, int new)
{
	/*在顺序表尾部添加元素*/
	SLCheckCapacity(ps);
	ps->list[ps->len] = new;
	++ps->len;
} // SLPushBack

void SLPopBack(pSL ps)
{
	/*在顺序表尾部删除元素*/
	if(ps->len)
		--ps->len;
} // SLPopBack

void SLPushFront(pSL ps, int new)
{
	/*在顺序表头部添加元素*/
	SLCheckCapacity(ps);
	int len = ps->len;
	while (len--)
	{
		ps->list[len + 1] = ps->list[len];
	}
	ps->list[0] = new;
	++ps->len;
} // SLPushFront

void SLPopFront(pSL ps)
{
	/*在顺序表头部移除元素*/
	if (ps->len == 0)
		return;
	int i = 0;
	// 将下标为1之后的元素整体向前移动1位
	for (i = 0; i < ps->len - 1; i++)
	{
		ps->list[i] = ps->list[i + 1];
	}
	--ps->len;
} // SLPopFront

void SLInsert(pSL ps, int index, int new)
{
	/*在顺序表指定下标处插入元素*/
	SLCheckCapacity(ps);
	assert(index >= 0 && index <= ps->len);
	int i = ps->len;
	// 将下标为index之后的元素整体向后移动1位
	while (i-- > index)
	{
		ps->list[i + 1] = ps->list[i];
	}
	ps->list[index] = new;
	++ps->len;
} // SLInsert

void SLErase(pSL ps, int index)
{
	/*删除顺序表中指定下标的元素*/
	if (ps->len == 0)
		return;
	assert(index >= 0 && index < ps->len);
	// 将下标为index之后的元素整体向前移动1位
	while (++index < ps->len)
	{
		ps->list[index - 1] = ps->list[index];
	}
	--ps->len;
} // SLErase