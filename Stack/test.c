//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
//    date:   2022-7-9
//    author: Akashi
//    github: https://github.com/AkashiNeko/DataStructure
//    QQ:     1006554341
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

#include "Stack.h"

void StackTest()
{
	ST s;
	STInit(&s);
	STPush(&s, 1);
	STPush(&s, 2);
	STPush(&s, 3);
	STPush(&s, 4);
	STPush(&s, 5);
	while (!STEmpty(&s))
	{
		printf("top:  %d\nsize: %d\n\n", STTop(&s), STSize(&s));
		STPop(&s);
	}
	STDestroy(&s);
}

int main()
{
	StackTest();
	return 0;
}