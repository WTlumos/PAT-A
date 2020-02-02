#include<cstdio>
#include<map>
using namespace std;
map<int,int> cnt;
int main()
{
	int m,n;
	scanf("%d%d",&m,&n);
	int a;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			scanf("%d",&a);
			cnt[a]++;
		}
	}
	for (map<int,int>::iterator i = cnt.begin(); i != cnt.end() ; ++i)
	{
		if (i->second>m*n/2)
		{
			printf("%d\n",i->first);
			break;
		}
	}
	return 0;
}