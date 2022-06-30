//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
//    date:   2022-6-30
//    author: Akashi (·ú·ú)
//    github: https://github.com/AkashiNeko/DataStructure
//    QQ:     1006554341
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

#include "SeqList.h"

void SeqListTest()
{
	SL s;
	SLInit(&s);
	SLPrint(&s);

	SLPushBack(&s, 2);
	SLPrint(&s);

	SLPushBack(&s, 5);
	SLPrint(&s);

	SLInsert(&s, 1, 4);
	SLPrint(&s);

	SLPushFront(&s, 1);
	SLPrint(&s);

	SLInsert(&s, 2, 3);
	SLPrint(&s);
}

int main()
{
	SeqListTest();
	return 0;
}