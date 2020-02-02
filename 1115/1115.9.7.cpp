#include<cstdio>
#include<queue>
using namespace std;
struct node
{
	int data;
	node *lchild,*rchild;
};
node* newNode(int x){
	node* root=new node;
	root->data=x;
	root->lchild=root->rchild=NULL;
	return root;
}
void create(node* &root,int x){
	if (root==NULL)
	{
		root=newNode(x);
		return;
	}else if(root->data<=x){
		create(root->lchild,x);
	}else{
		create(root->rchild,x);
	}
}
int ans[2020]={}; int level=0;
void levelorder(node* root){
	queue<node*> q;
	q.push(root);
	node *lastnode=root;
	node* nownode;
	while(!q.empty()){
		node* temp=q.front();
		q.pop();
		if (temp->lchild!=NULL)
		{
			q.push(temp->lchild);
			nownode=temp->lchild;
		}
		if (temp->rchild!=NULL)
		{
			q.push(temp->rchild);
			nownode=temp->rchild;
		}
		ans[level]++;
		if (lastnode==temp)
		{
			level++;
			lastnode=nownode;
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	node* root=NULL;
	int x;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&x);
		create(root,x);
	}
	levelorder(root);
	int n1=ans[level-1];
	int n2=ans[level-2];
	printf("%d + %d = %d\n", n1,n2,n1+n2);

	return 0;
}