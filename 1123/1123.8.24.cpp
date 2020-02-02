#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
struct node{
	int data,height;
	node *lchild,*rchild;
};
node* newNode(int x)
{
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
	}
	else{
		return root->height;
	}
}
int getBalanceFactor(node* root)
{
	return getHeight(root->lchild)-getHeight(root->rchild);
}
void getUpdate(node* root)
{
	root->height=max(getHeight(root->lchild),
		getHeight(root->rchild))+1;
}
void L(node* &root)
{
	node* temp=root->rchild;
	root->rchild=temp->lchild;
	temp->lchild=root;
	getUpdate(root);
	getUpdate(temp);
	root=temp;
}
void R(node* &root)
{
	node* temp=root->lchild;
	root->lchild=temp->rchild;
	temp->rchild=root;
	getUpdate(root);
	getUpdate(temp);
	root=temp;
}
void insert(node* &root,int x)
{
	if (root==NULL)
	{
		root=newNode(x);
		return;
	}
	else if(root->data>x){
		insert(root->lchild,x);
		getUpdate(root);
		if(getBalanceFactor(root)==2){
			if (getBalanceFactor(root->lchild)==1)
			{
				R(root);
			}else{
				L(root->lchild);
				R(root);
			}
		}
	}else{
		insert(root->rchild,x);
		getUpdate(root);
		if(getBalanceFactor(root)==-2){
			if(getBalanceFactor(root->rchild)==-1){
				L(root);
			}else{
				R(root->rchild);
				L(root);
			}
		}
	}
}
int cnt=0; int after=0; int complete=1;
void levelorder(node* root)
{
	queue<node*> q;
	q.push(root);
	while(!q.empty())
	{
		node* temp=q.front();
		if(cnt==0){
			printf("%d",temp->data);
			cnt++;
		}else{
			printf(" %d",temp->data);
		}
		q.pop();
		if (temp->lchild!=NULL)
		{
			q.push(temp->lchild);
			if (after>0)
			{
				complete=0;
			}
		}else{
			after=1;
		}
		if (temp->rchild!=NULL)
		{
			q.push(temp->rchild);

			if (after>0)
			{
				complete=0;
			}
		}else{
			after=1;
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	node* root=NULL;
	int a;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&a);
		insert(root,a);
	}
    levelorder(root);
    printf("\n%s\n",complete>0?"YES":"NO");
	return 0;
}