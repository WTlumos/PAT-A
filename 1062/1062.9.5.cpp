#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
struct node{
   int id,virtue,talent,total;
};
bool cmp(node a,node b){
	if (a.total!=b.total)
	{
		return a.total>b.total;
	}else if (a.virtue!=b.virtue)
	{
		return a.virtue>b.virtue;
	}else {
		return a.id<b.id;
	}
}
vector<node> v[4];
int main()
{
	int n,l,h;
	scanf("%d%d%d",&n,&l,&h);
	node temp;
	int ans=0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d%d",&temp.id,&temp.virtue,&temp.talent);
		temp.total=temp.virtue+temp.talent;
		if (temp.virtue>=l&&temp.talent>=l)
		{
			ans++;
			if (temp.virtue>=h&&temp.talent>=h)
			{
				v[0].push_back(temp);
			}else if (temp.virtue>=h&&temp.talent<h)
			{
				v[1].push_back(temp);
			}else if (temp.virtue<h&&temp.talent<h&&temp.virtue>=temp.talent)
			{
				v[2].push_back(temp);
			}else 
			{
				v[3].push_back(temp);
			}
		}
	}
	printf("%d\n",ans);
	for (int i = 0; i < 4; ++i)
	{
		sort(v[i].begin(),v[i].end(),cmp);
		for (int j = 0; j < v[i].size(); ++j)
		{
			printf("%08d %d %d\n", v[i][j].id,v[i][j].virtue,v[i][j].talent);
		}
	}

	return 0;
}