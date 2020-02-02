#include<cstdio>
#include<queue>
using namespace std;
char c1[5],c2[5];
struct node
{
	int lchild,rchild;
}v[30];
int getnum(char c[])
{
	int sum=0;
	for (int i = 0; c[i] != '\0'; ++i)
	{
		sum=sum*10+c[i]-'0';
	}
	return sum;
}
int indegree[30]={};
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
	int flag=0;
	bool complete=true;
	queue<int> q;
	q.push(root);
	int last=0;
	while(!q.empty()){
		int temp=q.front();
		last=temp;
		q.pop();
		if (v[temp].lchild!=-1)
		{
			q.push(v[temp].lchild);
			if (flag==1)
			{
				complete=false;
			}
		}else{
			flag=1;
		}
		if (v[temp].rchild!=-1)
		{
			q.push(v[temp].rchild);
			if (flag==1)
			{
				complete=false;
			}
		}else{
			flag=1;
		}
	}
	if (complete)
	{
		printf("YES %d\n",last);
	}else{
		printf("NO %d\n",root);
	}

	return 0;
}