#include<cstdio>
#include<cstring>
#include<stack>
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
int key=0;
void postorder(node* root){
	if (root==NULL)
	{
		return;
	}
	postorder(root->lchild);
	postorder(root->rchild);
	if (key==0)
	{
		printf("%d",root->data);
		key++;
	}else{
		printf(" %d",root->data);
	}

}
char str[5];
stack<node*> s;
int main(){
	int n,x;
	scanf("%d",&n);
	node *root=NULL;
	node *tree=NULL;
	scanf("%s",str);
	if (strcmp(str,"Pop")==0)
	{
		return 0;
	}else{
		scanf("%d",&x);
		root=newNode(x);
		tree=root;
		s.push(root);
	}
	int flag=0;
	for (int i = 1; i < n*2; ++i)
	{
		scanf("%s",str);
		if (strcmp(str,"Push")==0)
		{
			scanf("%d",&x);
			node *temp=newNode(x);
			s.push(temp);
			if (flag==0)
			{
				root->lchild=temp;
			}else{
				root->rchild=temp;
				flag=0;
			}	
			root=temp;
		}else{
			node *temp=s.top();
			s.pop();
			root=temp;
			flag=1;
		}
	
	}
	postorder(tree);
	return 0;
}