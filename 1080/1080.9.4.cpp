#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
struct node{
	int id,exam,interview,final;
	int chioce[7];
};
vector<node> v;
int quota[110]={};
int cnt[110]={};
bool cmp(node a,node b){
	if (a.final!=b.final)
	{
		return a.final>b.final;
	}else{
		return a.exam>b.exam;
	}
}
vector<node> school[110];
bool cmp2(node a,node b){
	return a.id<b.id;
}
int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for (int i = 0; i < m; ++i)
	{
		scanf("%d",&quota[i]);
	}
	node temp;
	for (int i = 0; i < n; ++i)
	{
		temp.id=i;
		scanf("%d%d",&temp.exam,&temp.interview);
		temp.final=temp.exam+temp.interview;
		for (int j = 0; j < k; ++j)
		{
			scanf("%d",&temp.chioce[j]);
		}
		v.push_back(temp);
	}
	sort(v.begin(),v.end(),cmp);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < k; ++j)
		{
			int pos=v[i].chioce[j];
			int lastnode=cnt[pos]-1;
			if (cnt[pos]<quota[pos]||
				(school[pos][lastnode].final==v[i].final&&
					school[pos][lastnode].exam==v[i].exam))
			{
				school[pos].push_back(v[i]);
				cnt[pos]++;
				break;
			}
		}
	}
	for (int i = 0; i < m; ++i)
	{
		sort(school[i].begin(),school[i].end(),cmp2);
		for (int j = 0; j < cnt[i]; ++j)
		{
			printf("%d",school[i][j].id);
			if (j<cnt[i]-1)
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}