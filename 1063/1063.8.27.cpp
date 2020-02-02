#include<cstdio>
#include<set>
#include<vector>
using namespace std;
set<int> v[60];
int main()
{
	int n;
	scanf("%d",&n);
	int m,a;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d",&m);
		set<int> s;
		for (int j = 0; j < m; ++j)
		{
			scanf("%d",&a);
			s.insert(a);
		}	
		v[i]=s;
	}
	int k;
	scanf("%d",&k);
	int b;
	for (int i = 0; i < k; ++i)
	{
		scanf("%d%d",&a,&b);
		int nc=0;
		int nt=v[b].size();
		for (set<int>::iterator j = v[a].begin(); j != v[a].end(); ++j)
		{
			if (v[b].find(*j)==v[b].end())
			{
				nt++;
			}else{
				nc++;
			}
		}
		//printf("%d %d\n",nt,nc);
		double temp=1.0*nc/nt*100;
		printf("%.1f%%\n",temp);
	}
	return 0;
}