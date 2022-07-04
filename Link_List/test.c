//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
//    date:   2022-7-3
//    author: Akashi
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

	pSL found = SLFindNode(&s, 3);
	if (found)
		found->data = 5;
	SLPrint(s);

	SLPopFront(&s);
	SLPrint(s);

	SLDestroy(&s);
	SLPrint(s);
}

int main()
{
	SLinkListTest();
	return 0;
}
