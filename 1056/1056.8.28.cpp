#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
int w[1010];
struct node{
	int weight,index,mouse,rank;
}v[1010];
bool cmp(node a,node b)
{
	return a.mouse<b.mouse;
}
int main()
{
	int np,ng;
	scanf("%d%d",&np,&ng);
	for (int i = 0; i < np; ++i)
	{
		scanf("%d",&w[i]);
	}
	int num;
	for (int i = 0; i < np; ++i)
	{
		scanf("%d",&num);
		v[i].weight=w[num];
		v[i].index=i;
		v[i].mouse=num;
	}
	queue<node> q;
	for (int i = 0; i < np; ++i)
	{
		q.push(v[i]);
	}
	while(!q.empty()){
		int size=q.size();
		if (size==1)
		{
			node temp=q.front();
			v[temp.index].rank=1;
			break;
		}
		int group=size/ng;
		if (size%ng!=0)
		{
			group++;
		}
		node maxnode;
		int cnt=0;
		int maxn=-1;
		for (int i = 0; i < size; ++i)
		{
			node temp=q.front();
			cnt++;
			q.pop();
			v[temp.index].rank=group+1;
			if (v[temp.index].weight>maxn)
			{
				maxn=v[temp.index].weight;
			    maxnode=temp;
			}
			if (cnt==ng || i==size-1)
			{
				cnt=0;
				maxn=-1;
				q.push(maxnode);
			}
		}
	}
	sort(v,v+np,cmp);
	for (int i = 0; i < np; ++i)
	{
		if (i!=0)
		{
			printf(" ");
		}
		printf("%d",v[i].rank);
	}
	printf("\n");


	return 0;
}