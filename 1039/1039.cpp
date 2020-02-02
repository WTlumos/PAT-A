#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int getId(char c[])
{
	int id=0;
	for (int i = 0; i <3 ; ++i)
	{
		id=id*26+c[i]-'A';
	}
	id=id*10+c[3]-'0';
	return id;
}
const int maxn=26*26*26*10+10;
vector<int> v[maxn];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int index,num;
	char name[5];
	for (int i = 0; i < k; ++i)
	{
		scanf("%d%d",&index,&num);
		for (int j = 0; j < num; ++j)
		{
			scanf("%s",name);
			int id=getId(name);
			v[id].push_back(index);
			printf("%s %d %d\n",name,id,index);	
		}	
	}
	for (int i = 0; i < n; ++i)
	{
		scanf("%s",name);
		printf("%s",name);
		int id=getId(name);
		sort(v[id].begin(), v[id].end());
		printf(" %lu",v[id].size());
		for (int j = 0; j < v[id].size(); ++j)
		{
			printf(" %d",v[id][j]);
		}
		printf("\n");
		
	}
	return 0;
}