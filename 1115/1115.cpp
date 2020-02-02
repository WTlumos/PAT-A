#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
struct node
{
	int data;
	node *lchild,*rchild;
};
node* newNode(int x){
	node *root=new node;
	root->data=x;
	root->lchild=root->rchild=NULL;
	return root;
}
void insert(node* &root,int x){
	if (root==NULL)
	{
		root=newNode(x);
		return;
	}
	if (root->data<x)
	{
		insert(root->rchild,x);
	}else{
		insert(root->lchild,x);
	}
}
vector<int> level[1010]; int deep=0;
void levelorder(node* root)
{
	queue<node*> q;
	q.push(root);
	node* lastnode=root;
	node* nowNode;
	while(!q.empty()){
		node* temp=q.front();
		//printf("%d %d %d\n",lastnode->data,deep,temp->data);
        level[deep].push_back(temp->data);
		q.pop();
		if(temp->lchild!=NULL){
			q.push(temp->lchild);
			nowNode=temp->lchild;
		}
		if (temp->rchild!=NULL)
		{
			q.push(temp->rchild);
			nowNode=temp->rchild;
		}
		if (lastnode==temp)
		{
			deep++;
			lastnode=nowNode;
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	int a;
	node* root=NULL;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&a);
		insert(root,a);
	}
	levelorder(root);
	if (deep>1)
	{
		int n1=level[deep-1].size();
		int n2=level[deep-2].size();
		printf("%d + %d = %d\n",n1,n2,n1+n2);
	}
	return 0;
}