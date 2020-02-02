#include<cstdio>
#include<map>
#include<set>
using namespace std;
map<int,int> couple,match;
set<int> order,ans;
int main()
{
	int n;
	scanf("%d",&n);
	int a,b;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d",&a,&b);
		couple[a]=b;
		couple[b]=a;
	}
	int m;
	scanf("%d",&m);
	for (int i = 0; i < m; ++i)
	{
		scanf("%d",&a);
		order.insert(a);
		match[couple[a]]++;
	}
	for (set<int>::iterator i = order.begin(); i != order.end(); ++i)
	{
		if (match[*i]==0)
		{
			ans.insert(*i);
		}
	}
	printf("%lu\n",ans.size());
	for (set<int>::iterator i = ans.begin(); i != ans.end(); ++i)
	{
		if (i!=ans.begin())
		{
			printf(" ");
		}
		printf("%05d",*i);
	}
	return 0;
}