#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct node
{
	int id,ge,gi,final;
	vector<int> choice;
	node(int Id,int Ge,int Gi,int Final,vector<int> Choice):id(Id),ge(Ge),gi(Gi),final(Final),choice(Choice){};
};
vector<node> applicants;
bool cmp(node a,node b){
	if(a.final!=b.final){
		return a.final>b.final;
	}else{
		return a.ge>b.ge;
	}
}
bool cmp2(node a,node b)
{
	return a.id<b.id;

}
int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	int quota[m];
	for (int i = 0; i < m; ++i)
	{
		scanf("%d",&quota[i]);
	}
	int ge,gi,final,a;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d",&ge,&gi);
		final=ge+gi;
		vector<int> v;
		for (int j = 0; j < k; ++j)
		{
			scanf("%d",&a);
			v.push_back(a);
		}
		applicants.push_back(node(i,ge,gi,final,v));	
	}
	sort(applicants.begin(), applicants.end(),cmp);
	int cnt[n];
	fill(cnt,cnt+n,0);
	vector<node> school[m];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < k; ++j)
		{
			int pos=applicants[i].choice[j];
			int lastnode=cnt[pos]-1;
			if(cnt[pos]<quota[pos]||
				(school[pos][lastnode].final==applicants[i].final&&
					school[pos][lastnode].ge==applicants[i].ge)){
				school[pos].push_back(applicants[i]);
				cnt[pos]++;
				break;
			}
		}
	}
	for (int i = 0; i < m; ++i)
	{
		sort(school[i].begin(), school[i].end(),cmp2);
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