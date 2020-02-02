#include<cstdio>
#include<algorithm>
using namespace std;
struct node{
	int data;
	node *lchild,*rchild;
};
node* newNode(int x){
	node* root=new node;
	root->data=x;
	root->lchild=root->rchild=NULL;
	return root;
}
void create(int x,node* &root){
	if (root==NULL)
	{
		root=newNode(x);
		return;
	}else if (abs(root->data)>abs(x)){
		create(x,root->lchild);
	}else{
		create(x,root->rchild);
	}
}
bool rRedcBlack(node* root){
	if (root==NULL)
	{
		return true;
	}
	if (root->data<0)
	{
		if (root->lchild!=NULL&&root->lchild->data<0)
		{
			return false;
		}
		if (root->rchild!=NULL&&root->rchild->data<0)
		{
			return false;
		}
	}
	return rRedcBlack(root->lchild)&&rRedcBlack(root->rchild);
}
int blackNum(node* root)
{
	if (root==NULL)
	{
		return 0;
	}
	int leftBlack=blackNum(root->lchild);
	int rightBlack=blackNum(root->rchild);
	return root->data>0?max(leftBlack,rightBlack)+1:max(leftBlack,rightBlack);
}
bool equalBlack(node* root){
	if (root==NULL)
	{
		return true;
	}
	int l=blackNum(root->lchild);
	int r=blackNum(root->rchild);
	if (l!=r)
	{
		return false;
	}
	return equalBlack(root->lchild)&&equalBlack(root->rchild);

}
int main()
{
	int k;
	scanf("%d",&k);
	while(k--){
		int n;
		scanf("%d",&n);
		node* root=NULL;
		int a;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d",&a);
			create(a,root);
		}
		if (rRedcBlack(root)&&equalBlack(root)&&root->data>0)
		{
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	return 0;
}