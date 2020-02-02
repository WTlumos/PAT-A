#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
bool cmp(string a,string b)
{
	return a<b;
}
vector<string> v[2510];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int c,course;
	char name[5];
	for (int i = 0; i < n; ++i)
	{
		scanf("%s%d",name,&c);
		string id=name;
		for (int j = 0; j < c; ++j)
		{
			scanf("%d",&course);
			v[course].push_back(id);
		}
	}
	for (int i = 1; i <= m; ++i)
	{
		sort(v[i].begin(),v[i].end(),cmp);
		printf("%d %d\n",i,(int)v[i].size());
		for (int j = 0; j < v[i].size(); ++j)
		{
			printf("%s\n",v[i][j].c_str());
		}
	}
	return 0;
}