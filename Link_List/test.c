//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
//    date:   2022-7-3
//    author: Akashi (·ú·ú)
//    github: https://github.com/AkashiNeko/DataStructure
//    QQ:     1006554341
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

#include "LinkList.h"

void SLinkListTest()
{
	pSL s = NULL;
	SLPrint(s);

	SLPushBack(&s, 1);
	SLPrint(s);

	SLPopBack(&s);
	SLPrint(s);

	SLPushFront(&s, 3);
	SLPrint(s);

	SLPushBack(&s, 4);
	SLPrint(s);

	SLPushFront(&s, 2);
	SLPrint(s);

	SLPopFront(&s);
	SLPrint(s);

	pSL found = SLFindNode(&s, 3);
	if (found)
		SLInsert(&found, 5);
	SLPrint(s);

	SLErase(&s->next);
	SLPrint(s);

	int i = 100;
	while (i--)
		SLPushFront(&s, i);
	SLPrint(s);

	SLDestroy(&s);
	SLPrint(s);
}

int main()
{
	SLinkListTest();
	return 0;
}