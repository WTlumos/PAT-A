#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int full[6]={};
struct node
{
	int best,id,total;
	int score[6];
	node(){
		best=total=0;
		fill(score,score+6,-2);
	}
}v[10010];
bool cmp(node a,node b)
{
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
int main()
{
	int n,k,m;
	scanf("%d%d%d",&n,&k,&m);
	for (int i = 0; i < k; ++i)
	{
		scanf("%d",&full[i]);
	}
	int id,a,score;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d",&id,&a);
		v[id].id=id;
		a--;
		scanf("%d",&score);
		if (score==-1)
		{
			score=0;
		}
		v[id].score[a]=max(v[id].score[a],score);
	}
	for (int i = 1; i <= n; ++i)
	{
		int num=0;
		for (int j = 0; j < k; ++j)
		{
			if (v[i].score[j]==full[j])
			{
				v[i].best++;
			}
			if (v[i].score[j]!=-2&&v[i].score[j]!=0)
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
	sort(ans.begin(), ans.end(),cmp);
	int r=1;
	for (int i = 0; i < ans.size(); ++i)
	{
		if (i>0&&ans[i].total!=ans[i-1].total)
		{
			r=i+1;
		}
		printf("%d ",r);
		printf("%05d %d",ans[i].id,ans[i].total);
		for (int j = 0; j < k; ++j)
		{
			if (ans[i].score[j]==-2)
			{
				printf(" -");
			}else{
				printf(" %d",ans[i].score[j]);
			}
		}
		printf("\n");
	}

	return 0;
}