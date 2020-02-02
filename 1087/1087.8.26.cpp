#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
map<string,int> strtoint;
map<int,string> inttostr;
const int maxn=210;
const int Inf=312312312;
int happiness[maxn]={};
int graph[maxn][maxn];
int dis[maxn];
int w[maxn]={};
int num[maxn]={};
bool visit[maxn]={false};
int pre[maxn]={};
int number[maxn]={};
int cnt=1;
int exchange(string str)
{
	if (strtoint[str]==0)
	{
		strtoint[str]=cnt;
		inttostr[cnt]=str;
		return cnt++;
	}else{
		return strtoint[str];
	}
}
int s=0;
vector<int> ans;
void dfs(int t)
{
	if (s==t)
	{
		ans.push_back(s);
		return;
	}else{
		dfs(pre[t]);
	}
	ans.push_back(t);

}
int main()
{
	fill(graph[0],graph[0]+maxn*maxn,Inf);
	int n,k;
	string start;
	cin>>n>>k>>start;
	string str;
	int happy;
	for (int i = 0; i < n-1; ++i)
	{
		cin>>str>>happy;
		happiness[exchange(str)]=happy;	
	}
	string a,b;
	int c;
	for (int i = 0; i < k; ++i)
	{
		cin>>a>>b>>c;
		int indexa=exchange(a);
		int indexb=exchange(b);
		graph[indexa][indexb]=c;
		graph[indexb][indexa]=c;
	}
	s=strtoint[start];
	fill(dis,dis+maxn,Inf);
	fill(number,number+maxn,Inf);
	dis[s]=0;
	num[s]=1;
	number[s]=1;
	for (int i = 0; i < n; ++i)
	{
		int u=-1;int min=Inf;
		for (int j = 1; j <= n; ++j)
		{
			if (visit[j]==false&&dis[j]<min)
			{
				min=dis[j];
				u=j;
			}
		}
		if (u==-1)
		{
			break;
		}
		visit[u]=true;
		for (int v = 1; v <= n; ++v)
		{
			if (visit[v]==false&&graph[u][v]!=Inf)
			{
				if (dis[v]>dis[u]+graph[u][v])
				{
					dis[v]=dis[u]+graph[u][v];
					w[v]=w[u]+happiness[v];
					pre[v]=u;
					num[v]=num[u];
					number[v]=number[u]+1;
				}else if(dis[v]==dis[u]+graph[u][v]){
					if(w[u]+happiness[v]>w[v]){
						w[v]=w[u]+happiness[v];
						number[v]=number[u]+1;
						pre[v]=u;
					}else if(w[u]+happiness[v]==w[v]){
						if (number[v]>number[u]+1)
	                    {
	                        number[v]=number[u]+1;
	                        pre[v]=u;
	                    }
					}
					num[v]+=num[u];
				}
			}
		}
	}
	int end=strtoint["ROM"];
	cout<<num[end]<<" "<<dis[end]<<" "<<w[end]<<" ";
	int average=1.0*w[end]/(number[end]-1);
	cout<<average<<endl;
	dfs(end);
	for (int i = 0; i < ans.size(); ++i)
	{
		if (i!=0)
		{
			cout<<"->";
		}
		cout<<inttostr[ans[i]];
	}
	cout<<endl;
	return 0;
}