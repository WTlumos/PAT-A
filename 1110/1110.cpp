#include<iostream>
#include<string>
#include<queue>
#include<vector>
using namespace std;
struct node{
	int data;
	int lchild,rchild;
}tree[30];
int indegree[30]={};
int root=0;
int after=0; int complete=1; 
vector<int> v;
void levelorder()
{
	queue<int> q;
	q.push(root);
	while(!q.empty())
	{
		int temp=q.front();
		//printf("%d\n",temp);
		v.push_back(temp);
		q.pop();
		if (tree[temp].lchild!=-1)
		{
			q.push(tree[temp].lchild);
			if (after)
			{
				complete=0;
			}
		}else{
			after=1;
		}
		if(tree[temp].rchild!=-1){
			q.push(tree[temp].rchild);
			if (after)
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
	cin>>n;
	string a,b;
	for (int i = 0; i < n; ++i)
	{
		cin>>a>>b;
		if (a!="-"){
			int atemp=atoi(a.c_str());
			tree[i].lchild=atemp;
			indegree[atemp]++;
		}
		else{
			tree[i].lchild=-1;
		}
		if (b!="-"){
			int btemp=atoi(b.c_str());
			tree[i].rchild=btemp;
			indegree[btemp]++;
		}
		else{
			tree[i].rchild=-1;
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
	if(complete==1){
		printf("YES %d\n",v[v.size()-1]);
	}else{
		printf("NO %d\n",root);
	}
	return 0;
}