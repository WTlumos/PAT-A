#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=26*26*26*10;
int convert(char c[]){
	int idx=0;
	for (int i = 0; i < 3; ++i)
	{
		idx=idx*26+c[i]-'A';
	}
	idx=idx*10+c[3]-'0';
	return idx;
}
char str[5];
vector<int> v[maxn];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for (int i = 0; i < k; ++i)
	{
		int coursei,cnt;
		scanf("%d%d",&coursei,&cnt);
		for (int j = 0; j < cnt; ++j)
		{
			scanf("%s",str);
			int a=convert(str);
			v[a].push_back(coursei);
		}
	}
    for (int i = 0; i < n; ++i)
    {
    	scanf("%s",str);
    	int a=convert(str);
    	sort(v[a].begin(),v[a].end());
    	printf("%s %lu",str,v[a].size());
    	for (int j = 0; j < v[a].size(); ++j)
    	{
    		printf(" %d",v[a][j]);
    	}
    	printf("\n");
    }
	return 0;
}