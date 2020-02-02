#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int quota[110]={};
int cnt[10]={};
int k;
struct node
{
	int id,ge,gi,final;
	int choice[7];
};
vector<node> v;
bool cmp(node a,node b){
	if (a.final!=b.final)
	{
		return a.final>b.final;
	}else{
		return a.ge>b.ge;
	}
}
bool cmp1(node a,node b)
{
	return a.id<b.id;
}
int main()
{
	int n,m;
	scanf("%d%d%d",&n,&m,&k);
	for (int i = 0; i < m; ++i)
	{
		scanf("%d",&quota[i]);
	}
	node temp;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d",&temp.ge,&temp.gi);
		temp.id=i;
		temp.final=temp.ge+temp.gi;
		for (int j = 0; j < k; ++j)
		{
			scanf("%d",&temp.choice[j]);
		}
		v.push_back(temp);
	}
	sort(v.begin(),v.end(),cmp);
	vector<node> school[m];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < k; ++j)
		{
			int pos=v[i].choice[j];
			int lastnode=cnt[pos]-1;
			if (cnt[pos]<quota[pos]||
				(school[pos][lastnode].final==v[i].final
					&&school[pos][lastnode].ge==v[i].ge))
			{
				school[pos].push_back(v[i]);
				cnt[pos]++;
				break;
			}
			
		}
	}
	for (int i = 0; i < m; ++i)
	{
		sort(school[i].begin(),school[i].end(),cmp1);
		for (int j = 0; j < cnt[i]; ++j)
		{
			if (j!=0)
			{
				printf(" ");
			}
			printf("%d",school[i][j].id);
		}
		printf("\n");
		
	}
	return 0;
}