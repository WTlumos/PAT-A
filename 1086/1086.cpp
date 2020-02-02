#include<iostream>
#include<cstring>
#include<stack>
#include<queue>
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
int cnt=0;
void postOrder(node *root)
{
	if (root==NULL)
	{
		return;
	}
	postOrder(root->lchild);
	postOrder(root->rchild);
	if (cnt==0)
	{
		printf("%d",root->data);
		cnt++;
	}else{
		printf(" %d",root->data);
	}

}
int main()
{
	int n;
	scanf("%d",&n);

	node *root=NULL;
	node *tree=NULL;
	char c[5];
	int x;
	stack<node*> s;
	scanf("%s",c);
	if (strlen(c)==4)
	{
		scanf("%d",&x);
		root=newNode(x);
		tree=root;
		s.push(root);
	}else{
		return 0;
	}
	int flag=1;
	for (int i = 1; i < 2*n; ++i)
	{
		scanf("%s",c);
		if (strlen(c)==4)
		{
			scanf("%d",&x);
			node *temp=newNode(x);
			if (flag==-1)
			{
				root->rchild=temp;
				flag=-flag;
			}else{
				root->lchild=temp;
			}
			root=temp;
			s.push(temp);
		}else{
			node *temp=s.top();
			s.pop();
			root=temp;
			flag=-1;
		}	
	}
	postOrder(tree);

	return 0;
}