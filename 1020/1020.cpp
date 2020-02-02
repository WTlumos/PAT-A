#include<cstdio>
#include<queue>
using namespace std;
struct node{
   int data;
   node *lchild,*rchild;
};
const int maxn=31;
int post[maxn];
int in[maxn];
node* newNode(int x)
{
	node* root=new node;
	root->data=x;
	root->lchild=root->rchild=NULL;
	return root;
}
void create(int p1,int p2,int in1,int in2,node* &root){
	if (p1>p2)
	{
		return;
	}
	root=newNode(post[p2]);
	//printf("%d\n",root->data);
	int i=in1;
	for(;i<=in2;i++)
	{
		if(in[i]==post[p2]){
			break;
		}
	}
    int left=i-in1;
    create(p1,p1+left-1,in1,i-1,root->lchild);
    create(p1+left,p2-1,i+1,in2,root->rchild);
}
int flag=0;
void levelOrder(node* root)
{
	queue<node*> q;
	q.push(root);
	while(!q.empty())
	{
		node* temp=q.front();
		if (flag==0)
		{
			printf("%d",temp->data);
			flag++;
		}else{
			printf(" %d",temp->data);
		}
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
    node* root=NULL;
    create(0,n-1,0,n-1,root);
    levelOrder(root);
	return 0;
}