#include<iostream>
#include"function.h"
#include"implement.h"

int main()
{
	BiNode* root;
	vector<int> test = { 1,2,-1,4,6,-1,-1,-1,3,-1,5,-1,-1 };
	int index = 0;
	BiTree_Init_list(root, test, index);
	//three kinds of PreOrder
	printf("PreOrders:\n");
	vector<int> cont;
	DFS_rev(root, cont);
	for (auto c : cont)
	{
		printf("%d\t", c);
	}
	printf("\n");
	DFS(root);
	PreOrder(root);
	//two kinds of InOrder
	printf("InOrders:\n");
	InOrder(root);
	InOrder_rev(root);
	printf("\n");
	//two kinds of LastOrder
	printf("LastOrders:\n");
	LastOrder(root);
	LastOrder_rev(root);
	printf("\n");
	printf("the BFS:\n");
	BFS(root);

	TNode* T;
	index = 0;
	vector<int> inorder = { 1,2,-1,4,-1,-1,3,5,-1,-1,-1 };
	Threaded_Init_list(T, inorder, index);
	//Threaded_InOrder_show(T);
	//printf("\n");
	CreateInThread(T);
	Threaded_InOrder_show(T);
	printf("\n");
	InOrder_Thread(T);
}