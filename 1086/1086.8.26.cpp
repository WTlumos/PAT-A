#include<iostream>
#include<string>
#include<stack>
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
int cnt=0;
void postorder(node* root)
{
	if (root==NULL)
	{
		return;
	}
	postorder(root->lchild);
	postorder(root->rchild);
	if (cnt==0)
	{
		cout<<root->data;
		cnt++;
	}
	else{
		cout<<" "<<root->data;
	}
}
int main()
{
	int n;
	cin>>n;
	string str;
	cin>>str;
	int a;
	node* root=NULL;
	node* tree=NULL;
	stack<node*> s;
	if (str=="Pop")
	{
		return 0;
	}else{
		cin>>a;
		root=newNode(a);
		tree=root;
		s.push(root);
	}
	int flag=0;
	for (int i = 1; i < 2*n; ++i)
	{
		cin>>str;
		if (str=="Push")
		{
			cin>>a;
			node* temp=newNode(a);
			if (flag>0)
			{
				root->rchild=temp;
				flag=0;
			}else{
				root->lchild=temp;
			}
			root=temp;
			s.push(temp);
		}else{
			node* temp=s.top();
			s.pop();
			root=temp;
			flag=1;
		}
	}
	postorder(tree);
	cout<<endl;
	return 0;
}