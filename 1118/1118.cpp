#include<cstdio>
#include<set>
#include<map>
using namespace std;
const int maxn=10010;
int father[maxn]={};
void init()
{
	for (int i = 1; i < maxn; ++i)
	{
		father[i]=i;	
	}
}
int findFather(int x){
	int a=x;
	while(x!=father[x])
	{
		x=father[x];
	}
	while(a!=father[a]){
		int z=a;
		a=father[a];
		father[z]=x;
	}
	return x;
}
void unionAB(int a,int b)
{
	int fatherA=findFather(a);
	int fatherB=findFather(b);
	if (fatherA!=fatherB)
	{
		father[fatherA]=fatherB;
	}
}
set<int> s;
map<int,int> root;
int main()
{
	init();
	int n,k,a,b;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d",&k,&a);
		s.insert(a);
		for (int j = 1; j < k; ++j)
		{
			scanf("%d",&b);
			s.insert(b);
			unionAB(a,b);
			a=b;		
		}	
	}
	for (set<int>::iterator i=s.begin();i!= s.end(); ++i)
	{
		root[findFather(*i)]++;
	}
	printf("%lu %lu\n",root.size(),s.size());
	int q;
	scanf("%d",&q);
	for (int i = 0; i < q; ++i)
	{
		scanf("%d%d",&a,&b);
		int fatherA=findFather(a);
		int fatherB=findFather(b);
		if (fatherA==fatherB)
		{
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	return 0;
}