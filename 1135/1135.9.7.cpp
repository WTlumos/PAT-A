#include<cstdio>
#include<algorithm>
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
	}else if(abs(root->data)>abs(x)){
		create(root->lchild,x);
	}else{
		create(root->rchild,x);
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
int blacknum(node* root){
	if (root==NULL)
	{
		return 0;
	}
	int l=blacknum(root->lchild);
	int r=blacknum(root->rchild);
	return root->data>0?max(l,r)+1:max(l,r);
}
bool equalblack(node* root){
	if (root==NULL)
	{
		return true;
	}
	int l=blacknum(root->lchild);
	int r=blacknum(root->rchild);
	if (l!=r)
	{
		return false;
	}
	return equalblack(root->lchild)&&equalblack(root->rchild);
}
int main(){
	int k;
	scanf("%d",&k);
	while(k--){
		int n;
		scanf("%d",&n);
		int a;
		node* root=NULL;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d",&a);
			create(root,a);
		}
		if (root->data>0&&rRedcBlack(root)&&equalblack(root))
		{
			printf("Yes\n");
		}else{
			printf("No\n");
		}

	}	
	return 0;
}