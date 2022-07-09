//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
//    date:   2022-7-9
//    author: Akashi
//    github: https://github.com/AkashiNeko/DataStructure
//    QQ:     1006554341
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

#include "DLinkList.h"

void DLinkListTest1()
{
	pDL head = NULL;
	head = DLInit();
	DLPrint(head);

	DLPushBack(head, 1);
	DLPushBack(head, 2);
	DLPushBack(head, 3);
	DLPrint(head);

	DLPopBack(head);
	DLPopBack(head);
	DLPopBack(head);
	DLPrint(head);

	DLPushFront(head, 6);
	DLPushFront(head, 5);
	DLPushFront(head, 4);
	DLPrint(head);

	DLPopFront(head);
	DLPopFront(head);
	DLPopFront(head);
	DLPrint(head);
}

void DLinkListTest2()
{
	pDL head = NULL;
	head = DLInit();

	DLPushBack(head, 1);
	DLPushBack(head, 2);
	DLPushBack(head, 3);
	DLPrint(head);

	pDL found = DLFindNode(head, 2);
	if (found)
		DLInsert(found, 4);
	found = NULL;
	DLPrint(head);

	DLErase(head->next);
	DLPrint(head);

	DLClean(head);
	DLPrint(head);
}

int main()
{
	DLinkListTest1();
	DLinkListTest2();
	return 0;
}