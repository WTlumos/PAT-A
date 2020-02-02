#include<cstdio>
#include<string>
#include<map>
#include<vector>;
using namespace std;
map<string,int> strtoin;
map<int,string> intostr;
int happiness[201];
int graph[201][201];
int num=0;
int minCost=312312312;
int maxHappy=-1;
vector<int> ans;
void dfs(int root,int cost,int happiness)
{
	if (intostr[root]=="ROM")
	{
		if (cost<minCost)
		{
			minCost=cost;
			num=1;
		}else if(cost==minCost){
			num++;
			if (happiness>maxHappy)
			{
				maxHappy=happiness;
			} 
		}
	}
}
int main()
{
	int n,k;
	char start[4];
	scanf("%d%d%s",&n,&k,start);
	strtoin[start]=0;
	char c[4];
	string str;
	for (int i = 0; i < n-1; ++i)
	{
		scanf("%s",c);
		str=c;
		strtoin[str]=i+1;
		intostr[i+1]=str;
		scanf("%d",&happiness[i+1]);
	}
	char a[4],b[4];
	for (int i = 0; i < k; ++i)
	{
		scanf("%s%s",a,b);
		scanf("%d",&graph[strtoin[a][strtoin[b]]);
	}
	dfs(strtoin[start],0,0);

	return 0;
}