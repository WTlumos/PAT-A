#include<cstdio>
#include<map>
using namespace std;
map<int,int> match;
int main()
{
	int m,n;
	scanf("%d%d",&m,&n);
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int a;
			scanf("%d",&a);
			match[a]++;
		}
	}
	for (map<int,int>::iterator i = match.begin(); i != match.end(); ++i)
	{
		if (i->second>(m*n/2))
		{
			printf("%d\n", i->first);
			break;
		}
	}
	return 0;
}