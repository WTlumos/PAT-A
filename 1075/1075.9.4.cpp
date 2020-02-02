#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int problems[10]={};
struct node
{
	int id,total,best;
	int score[10];
	node(){
		best=0;
		total=0;
		fill(score,score+10,-2);
	}
}v[10010];
bool cmp(node a,node b){
	if (a.total!=b.total)
	{
		return a.total>b.total;
	}else if (a.best!=b.best){
		return a.best>b.best;
	}else{
		return a.id<b.id;
	}
}
vector<node> ans;
int main(){
	int n,k,m;
	scanf("%d%d%d",&n,&k,&m);
	for (int i = 1; i <= k; ++i)
	{
		scanf("%d",&problems[i]);
	}
	int id,pid,sc;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d",&id,&pid);
		scanf("%d",&sc);
		v[id].id=id;
		v[id].score[pid]=max(v[id].score[pid],sc);	
	}
	for (int i = 1; i <= n; ++i)
	{
		int num=0;
		for (int j = 1; j <= k; ++j)
		{
			if (v[i].score[j]==problems[j])
			{
				v[i].best++;
			}
			if (v[i].score[j]!=-1&&v[i].score[j]!=-2)
			{
				v[i].total+=v[i].score[j];
			}else{
				num++;
			}
		}
		if (num<k)
		{
			ans.push_back(v[i]);
		}
	}
	sort(ans.begin(),ans.end(),cmp);
	int r=1;
	for (int i = 0; i < ans.size(); ++i)
	{
		if (i>0&&ans[i].total!=ans[i-1].total)
		{
			r=i+1;
		}
		printf("%d %05d %d",r,ans[i].id,ans[i].total);
		for (int j = 1; j <= k; ++j)
		{
			if (ans[i].score[j]==-1)
			{
				printf(" 0");
			}else if(ans[i].score[j]==-2){
				printf(" -");
			}
			else{
				printf(" %d",ans[i].score[j]);
			}
		}
		printf("\n");
	}
	return 0;
}