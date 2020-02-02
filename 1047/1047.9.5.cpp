#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
char str[5];
vector<string> v[2510];
bool cmp(string a,string b){
	return a<b;
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s",str);
		string s=str;
		int c;
		scanf("%d",&c);
		int a;
		for (int i = 0; i < c; ++i)
		{
			scanf("%d",&a);
			v[a].push_back(s);
		}
	}
	for (int i = 1; i <= k; ++i)
	{
		sort(v[i].begin(),v[i].end(),cmp);
		printf("%d %lu\n", i,v[i].size());
		for (int j = 0; j < v[i].size(); ++j)
		{
			printf("%s\n",v[i][j].c_str());
		}
	}
	return 0;
}