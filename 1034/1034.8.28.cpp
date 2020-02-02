#include<cstdio>
#include<map>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
const int Inf=312312312;
map<string,int> strtoint;
map<int,string> inttostr;
int cnt=1;
char c1[4],c2[4];
int exchange(string str){
	if (strtoint[str]>0)
	{
		return strtoint[str];
	}else{
		strtoint[str]=cnt;
		inttostr[cnt]=str;
		return cnt++;
	}
}
int graph[1010][1010];
int weight[1010]={};
bool visit[1010]={};
void dfs(int index,int &head,int &num,int &sum)
{
	//printf("%s %d %d\n",inttostr[index].c_str(),num,sum);
	visit[index]=true;
	if (weight[index]>weight[head])
	{
		head=index;
	}
	for (int i = 1; i < cnt; ++i)
	{
		if(graph[index][i]>0)
		{
			sum+=graph[index][i];
			graph[index][i]=graph[i][index]=0;
			if (visit[i]==false)
			{
				num++;
				dfs(i,head,num,sum);
			}
		}
	}
}
map<string,int> ans;
int main()
{
	fill(graph[0],graph[0]+1010*1010,0);
	int n,k;
	scanf("%d%d",&n,&k);
	int cost; string str1,str2;
	for (int i = 0; i < n; ++i)
	{
		scanf("%s%s%d",c1,c2,&cost);
		str1=c1; str2=c2;
		int a=exchange(str1);
		int b=exchange(str2);
		graph[a][b]+=cost;
		graph[b][a]+=cost;
		weight[a]+=cost;
		weight[b]+=cost;
	}
	for (int i = 1; i < cnt; ++i)
	{
		int head=i;
		int num=1;
		int sum=0;
		//fill(visit,visit+1010,false);
		dfs(i,head,num,sum);
		if (num<=2||sum<=k)
		{
			continue;		
		}else{
			//printf("%d %d %d\n", head,num,sum);
			ans[inttostr[head]]=num;
		}
	}
	printf("%d\n",(int)ans.size());
	for (map<string,int>::iterator i = ans.begin(); i != ans.end(); ++i)
	{
		printf("%s %d\n",i->first.c_str(),i->second);
	}
	return 0;
}