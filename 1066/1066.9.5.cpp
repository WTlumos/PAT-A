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
int getHeight(node *root){
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
void update(node* &root){
	root->height=max(getHeight(root->lchild),getHeight(root->rchild))+1;
}
void L(node* &root){
	node* temp=root->rchild;
	root->rchild=temp->lchild;
	temp->lchild=root;
	update(root);
	update(temp);
	root=temp;
}
void R(node* &root){
	node* temp=root->lchild;
	root->lchild=temp->rchild;
	temp->rchild=root;
	update(root);
	update(temp);
	root=temp;
}
void create(node* &root,int x){
	if (root==NULL)
	{
		root=newNode(x);
	}else if(root->data>x){
		create(root->lchild,x);
		update(root);
		if (getFactor(root)==2)
		{
			if(getFactor(root->lchild)==1){
				R(root);
			}else if(getFactor(root->lchild)==-1){
				L(root->lchild);
				R(root);
			}
		}
	}else{
		create(root->rchild,x);
		update(root);
		if (getFactor(root)==-2)
		{
			if (getFactor(root->rchild)==-1)
			{
				L(root);
			}else if(getFactor(root->rchild)==1){
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
		create(root,a);
	}
	printf("%d\n",root->data);
	return 0;
}