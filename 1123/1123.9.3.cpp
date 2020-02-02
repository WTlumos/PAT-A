#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
struct node{
	int data,height;
	node *lchild,*rchild;
};
node* newNode(int x){
   node* root=new node;
   root->data=x;
   root->height=1;
   root->lchild=root->rchild=NULL;
   return root;
}
int getHeight(node* root)
{
	if (root==NULL)
	{
		return 0;
	}else{
		return root->height;
	}
}
int getFactor(node* root){
	return getHeight(root->lchild)-getHeight(root->rchild);
}
void updateHeight(node* root)
{
	root->height=max(getHeight(root->lchild),getHeight(root->rchild))+1;
}
void L(node* &root){
	node* temp=root->rchild;
	root->rchild=temp->lchild;
	temp->lchild=root;
	updateHeight(root);
	updateHeight(temp);
	root=temp;
}
void R(node* &root){
	node* temp=root->lchild;
	root->lchild=temp->rchild;
	temp->rchild=root;
	updateHeight(root);
	updateHeight(temp);
	root=temp;
}
void create(int x,node* &root){
	if (root==NULL)
	{
		root=newNode(x);
		return;
	}else if(root->data>x){
		create(x,root->lchild);
		updateHeight(root);
		if (getFactor(root)==2)
		{
			if (getFactor(root->lchild)==1)
			{
				R(root);
			}else if (getFactor(root->lchild)==-1)
			{
				L(root->lchild);
				R(root);
			}
		}
	}else{
		create(x,root->rchild);
		updateHeight(root);
		if (getFactor(root)==-2)
		{
			if (getFactor(root->rchild)==-1)
			{
				L(root);
			}else if (getFactor(root->rchild)==1)
			{
				R(root->rchild);
				L(root);
			}
		}
	}
}
int complete=0; int key=0; int flag=0;
void bfs(node* root)
{
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node* temp=q.front();
		q.pop();
		if (key==0)
		{
			printf("%d",temp->data);
			key++;
		}else{
			printf(" %d",temp->data);
		}
		if (temp->lchild!=NULL)
		{
			q.push(temp->lchild);
			if (flag==1)
			{
				complete=1;
			}
		}else{
			flag=1;
		}
		if (temp->rchild!=NULL)
		{
			q.push(temp->rchild);
			if (flag==1)
			{
				complete=1;
			}
		}else{
			flag=1;
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
	printf("\n");
	if (complete==0)
	{
		printf("YES\n");
	}else{
		printf("NO\n");
	}
	return 0;
}