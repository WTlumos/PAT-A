#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v[2510];
char name[40010][5];
bool cmp(int a,int b)
{
	return strcmp(name[a],name[b])<0;
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int c; int a; char str[5];
	for (int i = 0; i < n; ++i)
	{
		scanf("%s%d",str,&c);
		strcpy(name[i],str);
		for (int j = 0; j < c; ++j)
		{
			scanf("%d",&a);
			v[a].push_back(i);	
		}
	}
	for (int i = 1; i <=k ; ++i)
	{
		sort(v[i].begin(), v[i].end(),cmp);
		int size=v[i].size();
		printf("%d %d\n",i,size);
		for (int j = 0; j < size; ++j)
		{
			printf("%s\n",name[v[i][j]]);
		}
	}
	return 0;
}