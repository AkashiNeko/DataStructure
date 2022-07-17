//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//
//    date:   2022-7-17
//    author: Akashi
//    github: https://github.com/AkashiNeko/DataStructure
//    QQ:     1006554341
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

#include "BinaryTree.h"

void BinaryTreeTest()
{
	pBT root = BTCreateTree("ABC##DE#G##F##H##", 17);

	printf("Preorder : ");
	BTPreorder(root);
	printf("\n");

	printf("Inorder  : ");
	BTInorder(root);
	printf("\n");

	printf("Postorder: ");
	BTPostorder(root);
	printf("\n");

	printf("\n");

	printf("Node   : %d\n", BTSize(root));
	printf("Leaf   : %d\n", BTLeafSize(root));
	int k = 4;
	printf("Level%d : %d\n", k, BTLevelKSize(root, k));

	pBT Node = BTFind(root, 'H');
	if (Node)
	{
		Node->right = BTCreateNode('I');
		printf("\npush %c->%c\n", Node->data, Node->right->data);
	}

	printf("\n");
	printf("Preorder : ");
	BTPreorder(root);
	printf("\n");

	BTDestory(root);
}

int main()
{
	BinaryTreeTest();
	return 0;
}