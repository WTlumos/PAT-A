#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
const int maxn=100000;
map<int,int> couple;
map<int,int> exist;
vector<int> people;
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
		people.push_back(a);
		exist[couple[a]]++;
	}
	vector<int> v;
	for (int i = 0; i < m; ++i)
	{
		if (exist[people[i]]==0)
		{
			v.push_back(people[i]);
		}
	}
	printf("%lu\n",v.size());
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); ++i)
	{
		printf("%05d",v[i]);
		if (i<v.size()-1)
		{
			printf(" ");
		}
		else{
			printf("\n");
		}
	}

	return 0;
}