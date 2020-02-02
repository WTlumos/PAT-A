#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
struct node
{
   int id,total,talent,virtue;
   node(int Id,int Total,int Talent,int Virtue)
   {
   	  id=Id;
   	  total=Total;
   	  talent=Talent;
   	  virtue=Virtue;
   }
};
vector<node> v[4];
bool cmp(node a,node b)
{
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
	int id,virtue,talent;
	int ans=0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d%d",&id,&virtue,&talent);
		if(virtue>=l&&talent>=l){
			ans++;
			if (virtue>=h&&talent>=h)
			{
				v[0].push_back(node(id,virtue+talent,talent,virtue));
			}else if(virtue>=h&&talent<h){
				v[1].push_back(node(id,virtue+talent,talent,virtue));
			}else if(virtue<h&&talent<h&&virtue>=talent){
				v[2].push_back(node(id,virtue+talent,talent,virtue));
			}else{
				v[3].push_back(node(id,virtue+talent,talent,virtue));
			}
		}	
	}
    printf("%d\n",ans);
    for (int i = 0; i < 4; ++i)
    {
    	sort(v[i].begin(), v[i].end(),cmp);
    	for (int j = 0; j < v[i].size(); ++j)
    	{
    		printf("%08d %d %d\n",v[i][j].id,v[i][j].virtue,v[i][j].talent);
    	}
    }

	return 0;
}