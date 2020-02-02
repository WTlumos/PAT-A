#include<cstdio>
#include<set>
#include<map>
using namespace std;
const int maxn=10010;
set<int> v;
map<int,int> isroot;
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
	while(x!=father[x]){
		x=father[x];
	}
	while(a!=father[a]){
		int z=a;
		a=father[a];
		father[z]=x;
	}
	return x;
}
void together(int a,int b){
	int fatherA=findFather(a);
	int fatherB=findFather(b);
	if (fatherB!=fatherA)
	{
		father[fatherA]=fatherB;
	}
}
int main()
{
	init();
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int k,a;
		scanf("%d%d",&k,&a);
		v.insert(a);
		int b;
		for (int i = 1; i < k; ++i)
		{
			scanf("%d",&b);
			v.insert(b);
			together(a,b);
			a=b;
		}
	}
	for (set<int>::iterator i = v.begin(); i != v.end(); ++i)
	{
		isroot[findFather(*i)]++;
	}
	printf("%lu %lu\n", isroot.size(),v.size());
	int q;
	scanf("%d",&q);
	int a,b;
	for (int i = 0; i < q; ++i)
	{
		scanf("%d%d",&a,&b);
		if (father[a]==father[b])
		{
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}

	return 0;
}