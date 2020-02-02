#include<cstdio>
#include<algorithm>
using namespace std;
struct node
{
	int data;
	int height;
	node *lchild,*rchild;
};
node* newNode(int x){
	node *root=new node;
	root->data=x;
	root->height=1;
	root->lchild=root->rchild=NULL;
	return root;
}
int getHeight(node *root)
{
	if (root==NULL)
	{
		return 0;
	}
	return root->height;
}
int getBalance(node *root)
{
	return getHeight(root->lchild)-getHeight(root->rchild);
}
void updateHeight(node *root)
{
	root->height=max(getHeight(root->lchild),getHeight(root->rchild))+1;
}
void L(node *&root)
{
	node *temp=root->rchild;
	root->rchild=temp->lchild;
	temp->lchild=root;
	updateHeight(root);
	updateHeight(temp);
	root=temp;
}
void R(node *&root)
{
	node *temp=root->lchild;
	root->lchild=temp->rchild;
	temp->rchild=root;
	updateHeight(root);
	updateHeight(temp);
	root=temp;
}
void insert(node *&root,int x)
{
	if (root==NULL)
	{
		root=newNode(x);
		return;
	}
	if(root->data>x){
		insert(root->lchild,x);
		updateHeight(root);
		if (getBalance(root)==2)
		{
			if (getBalance(root->lchild)==1)
			{
				R(root);
			}else{
				L(root->lchild);
				R(root);
			}
		}

	}else{
		insert(root->rchild,x);
		updateHeight(root);
		if (getBalance(root)==-2)
		{
			if (getBalance(root->rchild)==-1)
			{
				L(root);
			}else{
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
	node *root=NULL;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&a);
		insert(root,a);
		//printf("%d\n",root->data);
	}
	printf("%d\n",root->data);
	return 0;
}