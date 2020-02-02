#include<cstdio>
#include<string>
#include<map>
using namespace std;
const int maxn=2010;
int k;
map<string,int> strtoint;
map<int,string> inttostr;
int weight[maxn]={};
int graph[maxn][maxn];
bool visit[maxn]={false};
map<string,int> ans;
int cnt=1;
int convert(string str)
{
	if (strtoint[str]==0)
	{
		inttostr[cnt]=str;
		strtoint[str]=cnt;
		return cnt++;
	}else{
		return strtoint[str];
	}
}
void dfs(int root,int &num,int &head,int &total)
{
	visit[root]=true;
	num++;
	if(weight[root]>weight[head]){
		head=root;
	}
	for (int i = 1; i < cnt; ++i)
	{
		if (graph[root][i]>0)
		{
			total+=graph[root][i];
			graph[root][i]=graph[i][root]=0;
			if (visit[i]==false)
			{
				dfs(i,num,head,total);
			}
		}
	}

}
int main()
{
	int n;
	scanf("%d%d",&n,&k);
	char a[4],b[4];
	string str1,str2;
	int id1,id2;
	int c;
	for (int i = 0; i < n; ++i)
	{
		scanf("%s%s%d",a,b,&c);
		str1=a; str2=b;
		id1=convert(str1);
		id2=convert(str2);
		weight[id1]+=c;
		weight[id2]+=c;
		graph[id1][id2]+=c;
		graph[id2][id1]+=c;
	}
	for (int i = 1; i < cnt; ++i)
	{
		if (visit[i]==false)
		{
			int head=i;
			int num=0;
			int total=0;
			dfs(i,num,head,total);
			if (num>2&&total>k)
			{
				ans[inttostr[head]]=num;	
			}
		}

	}
	printf("%lu\n",ans.size());
	for (map<string,int>::iterator i=ans.begin();i!=ans.end(); ++i)
	{
		printf("%s %d\n",i->first.c_str(),i->second);
	}
	return 0;
}