#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
int w[1010]={};
struct node{
   int id,mouse,weight,rank;
}pro[1010];
bool cmp(node a,node b){
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
	int a;
	for (int i = 0; i < np; ++i)
	{
		scanf("%d",&a);
		pro[i].id=i;
		pro[i].mouse=a;
		pro[i].weight=w[a];
	}
	queue<node> q;
	for (int i = 0; i < np; ++i)
	{
		q.push(pro[i]);
	}
	while(!q.empty()){
		int size=q.size();
		if (size==1)
		{
			pro[q.front().id].rank=1;
			break;		
		}
		int group=size/ng;
		if (size%ng!=0)
		{
			group++;
		}
		int max=-1; node maxnode; int cnt=0;
		for (int i = 0; i < size; ++i)
		{
			node temp=q.front();
			cnt++;
			q.pop();
			pro[temp.id].rank=group+1;
			if (pro[temp.id].weight>max)
			{
				max=pro[temp.id].weight;
				maxnode=temp;
			}
			if (cnt==ng||i==size-1)
			{
				cnt=0;
				max=-1;
				q.push(maxnode);
			}
		}
	}
	sort(pro,pro+np,cmp);
	for (int i = 0; i < np; ++i)
	{
		if (i!=0)
		{
			printf(" ");
		}
		printf("%d",pro[i].rank);
	}
	printf("\n");
	return 0;
}