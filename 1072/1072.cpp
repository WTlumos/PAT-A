#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int Inf=312312312;
const int maxn=1020;
int n,m,k,d;
int graph[maxn][maxn];
int exchange(char c[])
{
	int num=0;
	if (c[0]=='G')
	{
		for (int i = 1; i < strlen(c); ++i)
		{
			num=num*10+c[i]-'0';
		}
		num+=n;
	}else{
		for (int i = 0; i < strlen(c); ++i)
		{
			num=num*10+c[i]-'0';
		}
	}
	return num;
}
int minDis=-1;
int minSum=Inf;
int gas=-1;
int ds[maxn];
bool visit[maxn];
void Dijskstra(int s)
{
	fill(ds,ds+maxn,Inf);
	fill(visit,visit+maxn,false);
	ds[s]=0;
	for (int i = 1; i <= n+m; ++i)
	{
		int min=Inf;
		int u=-1;
		for (int j = 1; j <=n+m; ++j)
		{
			if(visit[j]==false&&ds[j]<min){
				min=ds[j];
				u=j;
			}
		}
		if (u==-1)
		{
			break;
		}
		visit[u]=true;
		for (int v = 1; v <=n+m ; ++v)
		{
			int dis=graph[u][v];
			if(visit[v]==false&&dis!=Inf){
				if(ds[u]+dis<ds[v]){
					ds[v]=ds[u]+graph[u][v];
				}
			}
			
		}
	}
	bool flag=true;
    int minimum=Inf;
	int sum=0;
	for (int i = 1; i <= n; ++i)
	{
		if (ds[i]>d)
		{
			flag=false;
            break;
		}
        if (ds[i]<minimum)
		{
			minimum=ds[i];
		}
		sum+=ds[i];
	}
	if (flag)
	{
		if(minimum>minDis){
			minSum=sum;
			minDis=minimum;
			gas=s;
		}
		else if(minimum==minDis&&sum<minSum){
			minSum=sum;
			gas=s;
		}
	}
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&k,&d);
	fill(graph[0],graph[0]+maxn*maxn,Inf);
	char a[maxn],b[maxn];
	int c,d;
	for (int i = 0; i < k; ++i)
	{
		scanf("%s%s",a,b);
		c=exchange(a);
		d=exchange(b);
		scanf("%d",&graph[c][d]);
		graph[d][c]=graph[c][d];		
	}
	for (int i = 1; i <= m; ++i)
	{
		Dijskstra(n+i);
	}
	if (gas==-1)
	{
		printf("No Solution\n");
	}else{
		printf("G");
		printf("%d\n",gas-n);
		printf("%.1f %.1f\n", 1.0*minDis,1.0*minSum/n);
	}
	return 0;
}