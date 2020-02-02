#include<cstdio>
#include<queue>
using namespace std;
struct node
{
	int data;
	node *lchild,*rchild;
};
node* newNode(int x)
{
	node* root=new node;
	root->data=x;
	root->lchild=root->rchild=NULL;
	return root;

}
void create(int x,node* &root)
{
    if (root==NULL)
    {
    	root=newNode(x);
    	return;
    }else if (root->data>=x)
    {
    	create(x,root->lchild);
    }else{
    	create(x,root->rchild);
    }
}
int level=0;
int cnt[2020]={};
void bfs(node* root)
{
	queue<node*> q;
	q.push(root);
    node* lastnode=root;
    node* newnode;
	while(!q.empty())
	{
		node* temp=q.front();
		q.pop();
		cnt[level]++;
		if (temp->lchild!=NULL)
		{
			q.push(temp->lchild);
			newnode=temp->lchild;
		}if (temp->rchild!=NULL)
		{
			q.push(temp->rchild);
			newnode=temp->rchild;
		}
		if (lastnode==temp)
		{
			level++;
			lastnode=newnode;
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
		create(a,root);
	}
	bfs(root);
	int cnt1=cnt[level-2];
	int cnt2=cnt[level-1];
	printf("%d + %d = %d\n",cnt2,cnt1,cnt1+cnt2);
	return 0;
}