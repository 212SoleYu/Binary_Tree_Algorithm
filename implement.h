#pragma once

//binary tree related

typedef struct BiNode
{
	int val;
	int visited;//used in the LastOrder to identify whether the node has been visited, 0 means unvisited.
	BiNode* left;
	BiNode* right;
	BiNode()
	{
		val = 0; visited = 0;
		left = nullptr; right = nullptr;
	}
	
}*BiTree;


//threaded binary tree related
typedef struct TNode
{
	int data;
	int ltag;
	int rtag;
	TNode* left;
	TNode* right;
	TNode()
	{
		data = 0;
		ltag = rtag = 1;
		left = nullptr;
		right = nullptr;
	}
}*ThreadTree;