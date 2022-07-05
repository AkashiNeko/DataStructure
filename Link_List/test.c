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
	//β��
	SLPushBack(&s, 1);
	SLPrint(s);
	//βɾ
	SLPopBack(&s);
	SLPrint(s);

	int i = 10;
	while (i--)
		//ͷ��
		SLPushFront(&s, i);
	SLPrint(s);
	//ͷɾ
	SLPopFront(&s);
	SLPrint(s);

	//�ߵ�
	SLReverse(&s);
	SLPrint(s);
	//����
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

	//����
	found = SLFindNode(&s, 3);
	if (found)
		//ָ��λ��֮�����
		SLInsertAfter(found, 5);
	found = NULL;
	SLPrint(s);

	//����
	found = SLFindNode(&s, 3);
	if (found)
		//ָ��λ��֮��ɾ��
		SLEraseAfter(found);
	SLPrint(s);

	//����
	found = SLFindNode(&s, 3);
	if (found)
		//ָ��λ�ò���
		SLInsert(&s, found, 5);
	found = NULL;
	SLPrint(s);

	//����
	found = SLFindNode(&s, 5);
	if (found)
		//ָ��λ��ɾ��
		SLErase(&s, found);
	SLPrint(s);
}

int main()
{
	//SLinkListTest1();
	//SLinkListTest2();
	return 0;
}
