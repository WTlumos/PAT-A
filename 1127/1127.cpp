#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
const int maxn=31;
int in[maxn]={};
int post[maxn]={};
struct node{
	int data;
	node *lchild,*rchild;
};
node* newNode(int x){
	node *root=new node;
	root->data=x;
	root->lchild=root->rchild=NULL;
	return root;
}
void create(int pl,int pr,int il,int ir,node *&root){
	if (pl>pr)
	{
		return;
	}
	root=newNode(post[pr]);
	int i;
	for (i = il; i <= ir ; ++i)
	{
		if (in[i]==post[pr])
		{
			break;
		}
	}
	int left=i-il;
	create(pl,pl+left-1,il,i-1,root->lchild);
	create(pl+left,pr-1,i+1,ir,root->rchild);
} 
vector<int> ans[maxn];
int deep=0;
void level(node* root)
{
	node* lastnode=root;
	node* nownode;
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node* temp=q.front();
		ans[deep].push_back(temp->data);
		q.pop();
		if (temp->lchild!=NULL)
		{
			q.push(temp->lchild);
			nownode=temp->lchild;
		}
		if (temp->rchild!=NULL)
		{
			q.push(temp->rchild);
			nownode=temp->rchild;
		}
		if (lastnode==temp)
		{
			deep++;
			lastnode=nownode;
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&in[i]);
	}
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&post[i]);
	}
	node* root=NULL;
	create(0,n-1,0,n-1,root); 
	level(root);
	printf("%d",ans[0][0]);
	for (int i = 1; i <= deep; ++i)
	{
		if (i%2==0)
		{
			for (int j = ans[i].size()-1; j >= 0; j--)
			{
				printf(" %d",ans[i][j]);
			}
		}else{
			for (int j = 0; j < ans[i].size(); j++)
			{
				printf(" %d",ans[i][j]);
			}
		}
	}
	printf("\n");
	return 0;
}