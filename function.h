#pragma once
#include<vector>
#include"implement.h"
using namespace std;


//binary tree related
BiNode* BiTree_Init();
void BiTree_Init_list(BiNode* &root, const vector<int>& list, int &index);
vector<int> DFS(BiTree root);
vector<int> BFS(BiTree root);
void DFS_rev(BiTree root,vector<int>& ans);
vector<int> PreOrder(BiTree root);// all are non-rev algorithm
vector<int> InOrder(BiTree root);
void InOrder_rev(BiTree root);
vector<int> LastOrder(BiTree root);
void LastOrder_rev(BiTree root);


//threaded binary tree related
void Threaded_InOrder_show(ThreadTree root);
void Threaded_Init_list(TNode* &root, const vector<int>&list, int &index);
void CreateInThread(ThreadTree T);
void InOrder_Thread(ThreadTree root);

