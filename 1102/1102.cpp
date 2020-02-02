#include<iostream>
#include<string>
#include<queue>
using namespace std;
struct node{
	int lchild,rchild;
}tree[20];
int indegree[20]={};
int root=0;
int cnt=0;
void levelorder(){
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int temp=q.front();
		if (cnt==0)
		{
			printf("%d",temp);
			cnt++;
		}else{
			printf(" %d",temp);
		}
		q.pop();
		if (tree[temp].lchild!=-1)
		{
			q.push(tree[temp].lchild);
		}
		if (tree[temp].rchild!=-1)
		{
			q.push(tree[temp].rchild);
		}
	}
	cnt=0;
}
void inorder(int root)
{
	if(root==-1)
	{
		return;
	}
	inorder(tree[root].lchild);
	if (cnt==0)
	{
		printf("%d",root);
		cnt++;
	}else{
		printf(" %d",root);
	}
	inorder(tree[root].rchild);


}
int main()
{
	int n;
	cin>>n;
	string a,b;
	for (int i = 0; i < n; ++i)
	{
		cin>>a>>b;
		if (a=="-")
		{
			tree[i].rchild=-1;
		}else{
			int temp=atoi(a.c_str());
			tree[i].rchild=temp;
			indegree[temp]++;
		}
		if (b=="-")
		{
			tree[i].lchild=-1;
		}else{
			int temp=atoi(b.c_str());
			tree[i].lchild=temp;
			indegree[temp]++;
		}	
	}
	for (int i = 0; i < n; ++i)
	{
		if (indegree[i]==0)
		{
			root=i;
		}
	}
	levelorder();
	printf("\n");
	inorder(root);
	printf("\n");
	return 0;
}