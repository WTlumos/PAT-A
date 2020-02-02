#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
int w[1010]={};
struct node{
	int weight,index,mouse,rank;
};
bool cmp(node a,node b){
	return a.mouse<b.mouse;
}
node v[1010];
int main()
{
	int np,ng;
	scanf("%d%d",&np,&ng);
	for (int i = 0; i < np; ++i)
	{
		scanf("%d",&w[i]);
	}
	int a;
	for (int i = 0; i < np; ++i)
	{
		scanf("%d",&a);
		v[i].weight=w[a];
		v[i].index=i;
		v[i].mouse=a;
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
		if(size%ng!=0){
			group++;
		}
		int maxn=-1; int cnt=0; node maxnode;
		for (int i = 0; i < size; ++i)
		{
			node temp=q.front();
			q.pop();
			cnt++;
			v[temp.index].rank=group+1;
			if (temp.weight>maxn)
			{
				maxn=temp.weight;
				maxnode=temp;
			}
			if (cnt==ng||i==size-1)
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