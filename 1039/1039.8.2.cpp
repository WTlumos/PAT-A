#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=26*26*26*10+10;
vector<int> v[maxn];
int extoint(char str[]){
	int idx=0;
	for (int i = 0; i < 3; ++i)
	{
		idx=idx*26+str[i]-'A';
	}
	idx=idx*10+str[3]-'0';
	return idx;
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int course,number,idx; char str[5];
	while(k--)
	{
		scanf("%d%d",&course,&number);
		for (int i = 0; i < number; ++i)
		{
			scanf("%s",str);
			idx=extoint(str);
			//printf("%d\n",idx);
			v[idx].push_back(course);
		}		
	}
	while(n--)
	{
		scanf("%s",str);
		idx=extoint(str);
		printf("%s %d",str,(int)v[idx].size());
		sort(v[idx].begin(),v[idx].end());
		for (int i = 0; i < v[idx].size(); ++i)
		{
			printf(" %d",v[idx][i]);
		}
		printf("\n");
	}
	return 0;
}