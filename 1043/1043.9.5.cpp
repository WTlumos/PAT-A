#include<cstdio>
#include<vector>
using namespace std;
vector<int> mirrorpre,mirrorpost,pre,post,origin;
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
void create(int x,node* &root){
	if (root==NULL)
	{
		root=newNode(x);
		return;
	}else if(root->data>x){
		create(x,root->lchild);
	}else{
		create(x,root->rchild);
	}
}
void preorder(node* root){
	if (root==NULL)
	{
		return;
	}
	pre.push_back(root->data);
	preorder(root->lchild);
	preorder(root->rchild);
}
void postorder(node* root){
	if (root==NULL)
	{
		return;
	}
	postorder(root->lchild);
	postorder(root->rchild);
	post.push_back(root->data);
}
void mipre(node* root){
	if (root==NULL)
	{
		return;
	}
	mirrorpre.push_back(root->data);
	mipre(root->rchild);
	mipre(root->lchild);
}
void mipost(node* root){
	if (root==NULL)
	{
		return;
	}
	mipost(root->rchild);
	mipost(root->lchild);
	mirrorpost.push_back(root->data);
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
		origin.push_back(a);
		create(a,root);
	}
	preorder(root);
	postorder(root);
	mipre(root);
	mipost(root);
	if (origin==pre||origin==mirrorpre)
	{
		printf("YES\n");
		if (origin==pre)
		{
			for (int i = 0; i < post.size(); ++i)
			{
				printf("%d",post[i]);
				if (i<post.size()-1)
				{
					printf(" ");
				}else{
					printf("\n");
				}
			}
		}else{
			for (int i = 0; i < mirrorpost.size(); ++i)
			{
				printf("%d",mirrorpost[i]);
				if (i<mirrorpost.size()-1)
				{
					printf(" ");
				}else{
					printf("\n");
				}
			}

		}
	}else{
		printf("NO\n");
	}
	return 0;
}