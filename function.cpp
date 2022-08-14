#include"implement.h"
#include"function.h"
#include<stack>
#include<queue>
//binary tree related
void BiTree_Init_list(BiNode* &root, const vector<int>& list, int &index)
{
	// return a new binary tree's root
	// the order in list is preorder, -1 means it's nullptr
	// it;s a reverse prodece
	if (list[index] != -1)
	{
		BiNode* temp = new BiNode;
		temp->val = list[index];
		index++;
		BiTree_Init_list(temp->left, list, index);
		index++;
		BiTree_Init_list(temp->right, list, index);
		root = temp;
	}
}
vector<int> DFS(BiTree root)
{
	vector<int> ans;
	stack<BiNode*> s;
	if (root == nullptr)
		return ans;
	s.push(root);
	while (!s.empty())
	{
		BiNode* temp = s.top();
		ans.push_back(temp->val);
		printf("%d\t", temp->val);
		s.pop();
		if (temp->right)
			s.push(temp->right);
		if (temp->left)
			s.push(temp->left);
	}
	printf("\n");
	return ans;
}
vector<int> BFS(BiTree root)
{
	vector<int> ans;
	queue<BiNode*> q;
	if (root == nullptr)
		return ans;
	q.push(root);
	while (!q.empty())
	{
		BiNode* temp = q.front();
		q.pop();
		ans.push_back(temp->val);
		printf("%d\t", temp->val);
		if (temp->left)
			q.push(temp->left);
		if (temp->right)
			q.push(temp->right);
	}
	printf("\n");
	return ans;
}
void DFS_rev(BiTree root, vector<int>& ans)
{
	//the same function with PreOrder rev
	if (root)
	{
		ans.push_back(root->val);
		DFS_rev(root->left, ans);
		DFS_rev(root->right, ans);
	}
}
vector<int> PreOrder(BiTree root)
{
	//the same as the DFS
	vector<int> ans;
	if (root != nullptr)
	{
		stack<BiNode*> s;
		s.push(root);
		while (!s.empty())
		{
			BiNode* temp = s.top();
			ans.push_back(temp->val);
			printf("%d\t", temp->val);
			s.pop();
			if (temp->right)
				s.push(temp->right);
			if (temp->left)
				s.push(temp->left);
		}
	}
	printf("\n");
	return ans;
}
vector<int> InOrder(BiTree root)
{
	vector<int> ans;
	if (root == nullptr)
		return ans;
	stack<BiNode*> s;
	BiNode * pointer = root;
	while (pointer || !s.empty())
	{
		if (pointer)
		{
			s.push(pointer);
			pointer = pointer->left;//find the most left one
		}
		else
		{
			BiNode* temp = s.top();
			s.pop(); ans.push_back(temp->val); printf("%d\t", temp->val);
			pointer = temp->right;
		}
	}
	printf("\n");
	return ans;
}
void InOrder_rev(BiTree root)
{
	if (root)
	{
		InOrder_rev(root->left);
		printf("%d\t", root->val);
		InOrder_rev(root->right);
	}
}
vector<int> LastOrder(BiTree root)
{
	vector<int> ans;
	if (root != nullptr)
	{
		stack<BiNode*>s;
		BiNode* p = root;
		while (p || !s.empty())
		{
			if (p)
			{
				s.push(p);
				p = p->left;
			}
			else
			{
				BiNode* temp = s.top();
				if (temp->right && temp->right->visited == 0)
				{
					//right tree exits and unvisited
					p = temp->right;
				}
				else
				{
					//no right tree or right tree has been visited
					s.pop(); temp->visited = 1;
					ans.push_back(temp->val);
					printf("%d\t", temp->val);
					p = nullptr;
				}
			}
		}
		printf("\n");
	}
	return ans;
}
void LastOrder_rev(BiTree root)
{
	if (root)
	{
		LastOrder_rev(root->left);
		LastOrder_rev(root->right);
		printf("%d\t", root->val);
	}
}


//threaded tree related
void Threaded_Init_list(TNode* &root, const vector<int>&list, int &index)
{
	//just initial the tree without threading it
	if (list[index] != -1)
	{
		TNode *temp = new TNode;
		temp->data = list[index];
		++index;
		Threaded_Init_list(temp->left, list, index);
		++index;
		Threaded_Init_list(temp->right, list, index);
		if (temp->left != nullptr)
			temp->ltag = 0;
		if (temp->right != nullptr)
			temp->rtag = 0;
		root = temp;
	}
}
void InThread(ThreadTree &p, ThreadTree &pre)
{
	if (p)
	{
		InThread(p->left, pre);
		if (p->left == nullptr)
		{
			p->left = pre;
			p->ltag = 1;
		}
		if (pre != nullptr && pre->right == nullptr)
		{
			pre->right = p;
			pre->rtag = 1;
		}
		pre = p;
		InThread(p->right, pre);
	}
}
void CreateInThread(ThreadTree T)
{
	ThreadTree pre = nullptr;
	if (T)
	{
		InThread(T, pre);
		pre->right = nullptr;
		pre->rtag = 1;
	}
}
void Threaded_InOrder_show(ThreadTree root)
{
	if (root)
	{
		if(root->ltag==0)
			Threaded_InOrder_show(root->left);
		if (root->left == nullptr)
			printf("NULL ");
		else printf("%d ",root->left->data);
		printf("%d ",root->data);
		if (root->right == nullptr)
			printf("NULL\t");
		else printf("%d\t", root->right->data);
		if(root->rtag==0)
			Threaded_InOrder_show(root->right);
	}
}
TNode* FirstNode_InOrder(ThreadTree root)
{
	while (root->ltag == 0) root = root->left;
	return root;
}
TNode* NextNode_InOrder(TNode* p)
{
	if (p->rtag == 1) 
		return p->right;
	else
		return FirstNode_InOrder(p->right);
}
TNode* LastNode_InOrder(ThreadTree root)
{
	while (root->rtag == 0) root = root->right;
	return root;
}
TNode* PreNode_InOrder(TNode* p)
{
	if (p->ltag == 1)
		return p->left;
	else
		return LastNode_InOrder(p->left);
}
void InOrder_Thread(ThreadTree root)
{
	for (TNode* p = FirstNode_InOrder(root); p != nullptr; p = NextNode_InOrder(p))
		printf("%d ", p->data);
	printf("\n");
}



