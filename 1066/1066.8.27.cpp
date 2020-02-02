#include<cstdio>
#include<algorithm>
using namespace std;
struct node
{
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
int getBalanceFactor(node* root)
{
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
void create(int x,node* &root)
{
	if (root==NULL)
	{
		root=newNode(x);
		return;
	}else if(root->data>x){
		create(x,root->lchild);
		updateHeight(root);
		if (getBalanceFactor(root)==2)
		{
			if (getBalanceFactor(root->lchild)==1)
			{
				R(root);
			}else if(getBalanceFactor(root->lchild)==-1){
				L(root->lchild);
				R(root);
			}
		}
	}else{
		create(x,root->rchild);
		updateHeight(root);
		if (getBalanceFactor(root)==-2)
		{
			if (getBalanceFactor(root->rchild)==-1)
			{
				L(root);
			}else if(getBalanceFactor(root->rchild)==1){
				R(root->rchild);
				L(root);
			}
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
	printf("%d\n",root->data);
	return 0;
}