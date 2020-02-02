#include<cstdio>
#include<map>
#include<vector>
using namespace std;
map<int,int> exist;
vector<int> v[100000];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int a,b;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	while(m--)
	{
		int k; 
		scanf("%d%d",&k,&a);
		int flag=0;
		for (int i = 1; i < k; ++i)
		{
			scanf("%d",&b);
			if (exist[b]>0)
			{
				flag=1;
				continue;
			}
			if(flag==0){
				for (int j = 0; j < v[a].size(); ++j){
					exist[v[a][j]]++;
				}
			}
			a=b;
		}
		if (flag==0)
		{
			printf("Yes\n");
		}else{
			printf("No\n");
		}
		exist.clear();
	}
	return 0;
}