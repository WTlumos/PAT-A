#include<cstdio>
#include<map>
#include<string>
#include<algorithm>
using namespace std;
const int maxn=2020;
map<string,int> strtoint,ans;
map<int,string> intostr;
int weight[maxn]={};
bool visit[maxn]={false};
int graph[maxn][maxn];
int idx=1; int n;
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
void dfs(int root,int &head,int &sum,int &cnt){
	visit[root]=true;
	cnt++;
	if (weight[root]>weight[head])
	{
		head=root;
	}
	for (int i = 1; i <= n; ++i)
	{
		if (graph[root][i]!=0)
		{
			sum+=graph[root][i];
			graph[root][i]=graph[i][root]=0;
			if (visit[i]==false)
			{
				dfs(i,head,sum,cnt);
			}
		}
	}

}
char c1[4],c2[4];
int main()
{
	fill(graph[0],graph[0]+maxn*maxn,0);
	int k;
	scanf("%d%d",&n,&k);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s%s",c1,c2);
		int a=convert(c1);
		int b=convert(c2);
		int c;
		scanf("%d",&c);
		graph[a][b]+=c;
		graph[b][a]+=c;
		weight[a]+=c;
		weight[b]+=c;
	}
	for (int i = 1; i <= n; ++i)
	{
		int head=i;
		int cnt=0;
		int sum=0;
		dfs(i,head,sum,cnt);
		if (cnt>2&&sum>k)
		{
			ans[intostr[head]]=cnt;
		}
	}
	printf("%lu\n", ans.size());
	for (map<string,int>::iterator i = ans.begin(); i != ans.end(); ++i)
	{
		printf("%s %d\n", i->first.c_str(),i->second);
	}
	return 0;
}