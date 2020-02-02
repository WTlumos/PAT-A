#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
vector<map<int,int> > v;
int main()
{
	int n;
	scanf("%d",&n);
	map<int,int> ma;
	v.push_back(ma);
	for (int i = 0; i < n; ++i)
	{
		int m,a;
		scanf("%d",&m);
		for (int j = 0; j < m; ++j)
		{
			scanf("%d",&a);
			ma[a]++;
		}
		v.push_back(ma);
		ma.clear();
	}
	int k;
	scanf("%d",&k);
	int a,b;
	map<int,int> c,d;
	int nc=0;
	int nt=0;
	int size=0;
	for (int i = 0; i < k; ++i)
	{
		scanf("%d%d",&a,&b);
		c=v[a]; d=v[b];
		size=c.size();
		for (map<int,int>::iterator i=d.begin();i!=d.end(); ++i)
		{
			if(c[i->first]>0){
				nc++;
			}else{
				nt++;
			}
		}
		nt+=size;
		printf("%.1f%%\n",(1.0)*nc/nt*100);
		nc=nt=0;
	}
	return 0;
}