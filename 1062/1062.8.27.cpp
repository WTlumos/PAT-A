#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
	int id,virtue,talent,total;
};
//sage,nobleman,foolman,smallman
vector<node> v[4];
bool cmp(node a,node b){
	if (a.total!=b.total)
	{
		return a.total>b.total;
	}else if(a.virtue!=b.virtue){
		return a.virtue>b.virtue;
	}else{
		return a.id<b.id;
	}
}
int main()
{
	int n,l,h;
	scanf("%d%d%d",&n,&l,&h);
	node temp;
	int cnt=0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d%d",&temp.id,&temp.virtue,&temp.talent);
		temp.total=temp.virtue+temp.talent;
		if (temp.virtue>=l&&temp.talent>=l)
		{
			cnt++;
			if (temp.virtue>=h&&temp.talent>=h)
			{
				v[0].push_back(temp);
			}else if(temp.talent<h&&temp.virtue>=h){
				v[1].push_back(temp);
			}else if(temp.virtue<h&&temp.talent<h&&temp.virtue>=temp.talent){
				v[2].push_back(temp);
			}else{
				v[3].push_back(temp);
			}
		}
	}
	printf("%d\n",cnt);
	for (int i = 0; i < 4; ++i)
	{
		sort(v[i].begin(), v[i].end(),cmp);
		for (int j = 0; j < v[i].size(); ++j)
		{
			printf("%08d %d %d\n", v[i][j].id,v[i][j].virtue,v[i][j].talent);
		}
	}
	return 0;
}