#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int k;
struct node
{
	int id;
	int score[6];
	int total;
	int num;
	node()
	{
		num=0;
		total=0;
		fill(score,score+6,-2);
	}
};
bool cmp(node a,node b)
{
	if (a.total!=b.total)
	{
		return a.total>b.total;
	}else if(a.num!=b.num){
		return a.num>b.num;
	}else{
		return a.id<b.id;
	}
}
node user[10010];
int main()
{
	int n,m;
	scanf("%d%d%d",&n,&k,&m);
	int full[k];
	for (int i = 0; i < k; ++i)
	{
		scanf("%d",&full[i]);
	}
	int id,index,score;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d",&id,&index);
		user[id].id=id;
		index--;
		scanf("%d",&score);
		if (score==-1)
		{
			score=0;
		}
		user[id].score[index]=max(user[id].score[index],score);
	}
	vector<node> v;
	for (int i = 1; i <= n; ++i)
	{
		int num=0;
		for (int j = 0; j < k; ++j)
		{
			if (user[i].score[j]!=-2&&user[i].score[j]!=0)
			{
				user[i].total+=user[i].score[j];
			}else{
				num++;
			}
			if (user[i].score[j]==full[j])
			{
				user[i].num++;
			}
		}
		if (num<k)
		{
			v.push_back(user[i]);
		}
	}
	sort(v.begin(), v.end(),cmp);
	int r=1;
	for (int i = 0; i < v.size(); ++i)
	{
		if (i>0&&v[i].total!=v[i-1].total)
		{
			r=i+1;
		}
		printf("%d ",r);
		printf("%05d %d",v[i].id,v[i].total);
		for (int j = 0; j < k; ++j)
		{
			if (v[i].score[j]==-2)
			{
				printf(" -");
			}else{
				printf(" %d",v[i].score[j]);
			}
		}
		printf("\n");
	}

	return 0;
}