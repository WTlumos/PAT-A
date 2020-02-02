#include<cstdio>
#include<vector>
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
void insert(node* &root,int x){
	if (root==NULL)
	{
		root=newNode(x);
		return;
	}
	if (root->data>x)
	{
		insert(root->lchild,x);
	}else{
		insert(root->rchild,x);
	}
}
void preOrder(node* root,vector<int> &v)
{
	if (root==NULL)
	{
		return;
	}
	v.push_back(root->data);
	preOrder(root->lchild,v);
	preOrder(root->rchild,v);
}
void MirrorpreOrder(node* root,vector<int> &v)
{
	if (root==NULL)
	{
		return;
	}
	v.push_back(root->data);
	MirrorpreOrder(root->rchild,v);
	MirrorpreOrder(root->lchild,v);
}
void postOrder(node* root,vector<int> &v)
{
	if (root==NULL)
	{
		return;
	}
	postOrder(root->lchild,v);
	postOrder(root->rchild,v);
	v.push_back(root->data);
}
void MirrorpostOrder(node* root,vector<int> &v)
{
	if (root==NULL)
	{
		return;
	}
	MirrorpostOrder(root->rchild,v);
	MirrorpostOrder(root->lchild,v);
	v.push_back(root->data);
}
int main()
{
	int n;
	scanf("%d",&n);
	int x;
	node* root=NULL; 
	vector<int> origin;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&x);
		origin.push_back(x);
		insert(root,x);
	}
	vector<int> pre,post,mirrorpre,mirrorpost;
	preOrder(root,pre);
	MirrorpreOrder(root,mirrorpre);
	postOrder(root,post);
	MirrorpostOrder(root,mirrorpost);
	if (origin==pre)
	{
		printf("YES\n%d",post[0]);
		for (int i = 1; i < n; ++i)
		{
			printf(" %d",post[i]);
		}
		printf("\n");
	}else if(origin==mirrorpre){
		printf("YES\n%d",mirrorpost[0]);
		for (int i = 1; i < n; ++i)
		{
			printf(" %d",mirrorpost[i]);
		}
		printf("\n");
	}else{
		printf("NO\n");
	}
	return 0;
}