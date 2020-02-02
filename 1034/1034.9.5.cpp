#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
using namespace std;
const int maxn=1010;

int graph[maxn][maxn];
int weigth[maxn]={};
bool visit[maxn]={false};
map<string,int> strtoint,ans;
map<int,string> intostr;

int idx=1;
int convert(char c[])
{
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
int n,k;
void dfs(int root,int &head,int &sum,int &cnt){
	//printf("%d %d %d %d\n", root,head,sum,cnt);
	visit[root]=true;
	cnt++;
	if (weigth[root]>weigth[head])
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
char str1[4],str2[4];
int main()
{
	fill(graph[0],graph[0]+maxn*maxn,0);
    scanf("%d%d",&n,&k);
    for (int i = 0; i < n; ++i)
    {
    	scanf("%s%s",str1,str2);
    	int a=convert(str1);
    	int b=convert(str2);
    	int c;
    	scanf("%d",&c);
    	graph[a][b]+=c;
    	graph[b][a]+=c;
    	weigth[a]+=c;
    	weigth[b]+=c;	
    }
    for (int i = 1; i <= n; ++i)
    {
    	int head=i;
    	int sum=0;
    	int cnt=0;
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