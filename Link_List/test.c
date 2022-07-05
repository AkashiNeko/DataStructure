//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
//    date:   2022-7-3
//    author: Akashi
//    github: https://github.com/AkashiNeko/DataStructure
//    QQ:     1006554341
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

#include "SinglyLinkList.h"

void SLinkListTest1()
{
	pSL s = NULL;
	
	SLPrint(s);
	//尾增
	SLPushBack(&s, 1);
	SLPrint(s);
	//尾删
	SLPopBack(&s);
	SLPrint(s);

	int i = 10;
	while (i--)
		//头增
		SLPushFront(&s, i);
	SLPrint(s);
	//头删
	SLPopFront(&s);
	SLPrint(s);

	//颠倒
	SLReverse(&s);
	SLPrint(s);
	//销毁
	SLDestroy(&s);
	SLPrint(s);
}

void SLinkListTest2()
{
	pSL s = NULL;
	pSL found = NULL;
	SLPushFront(&s, 5);
	SLPushFront(&s, 4);
	SLPushFront(&s, 3);
	SLPushFront(&s, 2);
	SLPushFront(&s, 1);
	SLPrint(s);

	//查找
	found = SLFindNode(&s, 3);
	if (found)
		//指定位置之后插入
		SLInsertAfter(found, 5);
	found = NULL;
	SLPrint(s);

	//查找
	found = SLFindNode(&s, 3);
	if (found)
		//指定位置之后删除
		SLEraseAfter(found);
	SLPrint(s);

	//查找
	found = SLFindNode(&s, 3);
	if (found)
		//指定位置插入
		SLInsert(&s, found, 5);
	found = NULL;
	SLPrint(s);

	//查找
	found = SLFindNode(&s, 5);
	if (found)
		//指定位置删除
		SLErase(&s, found);
	SLPrint(s);
}

int main()
{
	//SLinkListTest1();
	//SLinkListTest2();
	return 0;
}
