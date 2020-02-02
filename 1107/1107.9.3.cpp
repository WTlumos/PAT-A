#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
map<int,int> hobbies,isroot;
vector<int> v;
int father[1010]={};
void init()
{
	for (int i = 0; i < 1010; ++i)
	{
		father[i]=i;
	}
}
int findFather(int x)
{
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
void together(int a,int b)
{
	int fatherA=findFather(a);
	int fatherB=findFather(b);
	if (fatherA!=fatherB)
	{
		father[fatherA]=fatherB;
	}
}
bool cmp(int x,int y){
	return x>y;
}
int main()
{
	init();
	int n;
	scanf("%d",&n);
	int k,a;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d:",&k);
		for (int j = 0; j < k; ++j)
		{
			scanf("%d",&a);
			if (hobbies[a]==0)
			{
				hobbies[a]=i;
			}
			together(i,findFather(hobbies[a]));
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		isroot[findFather(i)]++;
	}
	printf("%lu\n",isroot.size());
	for (map<int,int>::iterator i = isroot.begin(); i != isroot.end(); ++i)
	{
		v.push_back(i->second);
	}
	sort(v.begin(),v.end(),cmp);
	printf("%d",v[0]);
	for (int i = 1; i < v.size(); ++i)
	{
		printf(" %d",v[i]);
	}
	printf("\n");

	return 0;
}