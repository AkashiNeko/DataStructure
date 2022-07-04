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
	SLPushBack(&s, 2);

	SLPrint(s);
}

int main()
{
	SLinkListTest();
	return 0;
}