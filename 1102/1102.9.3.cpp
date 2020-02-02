#include<cstdio>
#include<queue>
using namespace std;
struct node{
	int lchild,rchild;
}v[20];
char c1[5],c2[5];
int getnum(char c[]){
	int num=0;
	for (int i = 0; c[i] != '\0'; ++i)
	{
		num=num*10+c[i]-'0';
	}
	return num;
}
int indegree[30]={};

void inorder(int root,vector<int> &in){
	if (root==-1)
	{
		return;
	}
	inorder(v[root].rchild,in);
	in.push_back(root);
	inorder(v[root].lchild,in);
}

void levelorder(int root,vector<int> &level){
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int temp=q.front();
		level.push_back(temp);
		q.pop();
		if (v[temp].rchild!=-1)
		{
			q.push(v[temp].rchild);
		}
		if (v[temp].lchild!=-1)
		{
			q.push(v[temp].lchild);
		}
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s%s",c1,c2);
		if (c1[0]=='-')
		{
			v[i].lchild=-1;
		}else{
			v[i].lchild=getnum(c1);
			indegree[getnum(c1)]++;
		}
		if (c2[0]=='-')
		{
			v[i].rchild=-1;
		}else{
			v[i].rchild=getnum(c2);
			indegree[getnum(c2)]++;
		}
	}
	int root=0;
	for (int i = 0; i < n; ++i)
	{
		if (indegree[i]==0)
		{
			root=i;
			break;
		}
	}
	vector<int> in,level;
	inorder(root,in);
	levelorder(root,level);
	for (int i = 0; i < n; ++i)
	{
		printf("%d",level[i]);
		if (i<n-1)
		{
			printf(" ");
		}else{
			printf("\n");
		}
	}
	for (int i = 0; i < n; ++i)
	{
		printf("%d",in[i]);
		if (i<n-1)
		{
			printf(" ");
		}else{
			printf("\n");
		}
	}
	return 0;
}