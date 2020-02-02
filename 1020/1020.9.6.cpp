#include<cstdio>
#include<queue>
using namespace std;
int post[40],in[40],level[40];
struct node
{
	int data;
	node *lchild,*rchild;
};
node *root=NULL; int cnt=0;
void create(int inl,int inr,int postl,int postr,node* &root){
	if (inl>inr)
	{
		return;
	}
	if (root==NULL)
	{
		root=new node;
		root->data=post[postr];
		root->lchild=root->rchild=NULL;
	}	
	//printf("%d\n", root->data);
	int i=0;
	for (i = inl; i <= inr; ++i)
	{
		if (in[i]==post[postr])
		{
			break;
		}
	}
	create(inl,i-1,postl,postl+(i-inl)-1,root->lchild);
	create(i+1,inr,postl+(i-inl),postr-1,root->rchild);
}
void levelorder()
{
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node* temp=q.front();
		level[cnt++]=temp->data;
		q.pop();
		if (temp->lchild!=NULL)
		{
			q.push(temp->lchild);
		}
		if (temp->rchild!=NULL)
		{
			q.push(temp->rchild);
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&post[i]);
	}
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&in[i]);
	}
	create(0,n-1,0,n-1,root);
	levelorder();
	for (int i = 0; i < cnt; ++i)
	{
		if (i!=0)
		{
			printf(" ");
		}
		printf("%d",level[i]);
	}
	printf("\n");
	return 0;
}