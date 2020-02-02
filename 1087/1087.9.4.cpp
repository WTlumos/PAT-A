#include<cstdio>
#include<map>
#include<string>
using namespace std;
const int maxn=210;
const int Inf=312312312;
map<string,int> strtoint;
map<int,string> intostr;
int weight[maxn]={};
int cost[maxn][maxn];
int co[maxn];
int w[maxn]={};
bool visit[maxn]={false};
int num[maxn]={};
int pre[maxn]={};
int cnt[maxn]={};
int idx=1;
int convert(char c[]){
	string str=c;
	if (strtoint[str]>0)
	{
		return strtoint[str];
	}else{
		strtoint[str]=idx;
		intostr[idx]=str;
		return idx++;
	}
}
char str[4],str2[4];
int s=0; int key=0;
void dfs(int t){
   if (t==s)
   {
   	 return;
   }else{
   	dfs(pre[t]);
   }
   printf("->%s",intostr[t].c_str());
}
int main()
{
	fill(cost[0],cost[0]+maxn*maxn,Inf);
	int n,k;
	scanf("%d%d%s",&n,&k,str);
	s=convert(str);
	for (int i = 0; i < n-1; ++i)
	{
		scanf("%s",str);
		scanf("%d",&weight[convert(str)]);
	}
	for (int i = 0; i < k; ++i)
	{
		scanf("%s%s",str,str2);
		int a=convert(str);
		int b=convert(str2);
		scanf("%d",&cost[a][b]);
		cost[b][a]=cost[a][b];
	}
	fill(co,co+maxn,Inf);
	fill(num,num+maxn,Inf);
	co[s]=0;
	num[s]=1;
	w[s]=0;
	cnt[s]=1;
	for (int i = 1; i <idx ; ++i)
	{
		int u=-1; int min=Inf;
		for (int j = 1; j < idx; ++j)
		{
			if (visit[j]==false&&co[j]<min)
			{
				u=j;
				min=co[j];
			}
		}
		if (u==-1)
		{
			break;
		}
		visit[u]=true;
		for (int v = 1; v < idx; ++v)
		{
			if (visit[v]==false&&cost[u][v]!=Inf)
			{
				if (co[u]+cost[u][v]<co[v])
				{
					co[v]=co[u]+cost[u][v];
					num[v]=num[u]+1;
					w[v]=w[u]+weight[v];
					pre[v]=u;
					cnt[v]=cnt[u];
				}else if(co[u]+cost[u][v]==co[v]){
					if (w[u]+weight[v]>w[v])
					{
						w[v]=w[u]+weight[v];
						num[v]=num[u]+1;
						pre[v]=u;
					}else if(w[u]+weight[v]==w[v]){
						if (num[u]+1<num[v])
						{
							num[v]=num[u]+1;
							pre[v]=u;
						}
					}
					cnt[v]+=cnt[u];
				}
			}
		}
	}
	int t=strtoint["ROM"];
    printf("%d %d %d %d\n", cnt[t],co[t],w[t],(int)1.0*w[t]/(num[t]-1));
    printf("%s",intostr[s].c_str());
    dfs(t);
	return 0;
}