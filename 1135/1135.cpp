#include<cstdio>
#include<algorithm>
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
//建树
void insert(int x,node *&root){
	if (root==NULL)
	{
		root=newNode(x);
		return;
	}
	else if(abs(root->data)>abs(x)){
		insert(x,root->lchild);
	}else{
		insert(x,root->rchild);
	}
}
// If a node is red, then both its children are black.
bool rRedcBlack(node *root){
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
//all simple paths from the node to descendant leaves contain the same number of black nodes.
int blackNumber(node *root){
	if (root==NULL)
	{
		return 0;
	}
	int l=blackNumber(root->lchild);
	int r=blackNumber(root->rchild);
	return root->data>0?max(l,r)+1:max(l,r);
}
bool sameBlack(node *root){
	if (root==NULL)
	{
		return true;
	}
	int l=blackNumber(root->lchild);
	int r=blackNumber(root->rchild);
	if (l!=r)
	{
		return false;
	}
	return sameBlack(root->lchild)&&sameBlack(root->rchild);
}
int main()
{
	int k,n,a;
	scanf("%d",&k);
	while(k--){
		scanf("%d",&n);
		node *root=NULL;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d",&a);
			insert(a,root);		
		}
		if (root->data<0||!rRedcBlack(root)||!sameBlack(root))
		{
			printf("No\n");
		}else{
			printf("Yes\n");
		}
		
	}
	return 0;
}