#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
map<int,int> m,root;
int father[1010]={};
void init()
{
	for (int i = 1; i < 1010; ++i)
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
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	init();
	int n;
	scanf("%d",&n);
	int k,hobby;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d:",&k);
		for (int j = 0; j < k; ++j)
		{
			scanf("%d",&hobby);
			if (m[hobby]==0)
			{
				m[hobby]=i;
			}
			together(i,findFather(m[hobby]));
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		root[findFather(i)]++;
	}
	vector<int> ans;
	for (map<int,int>::iterator i = root.begin(); i != root.end(); ++i)
	{
		ans.push_back(i->second);
	}
	sort(ans.begin(), ans.end(),cmp);
	printf("%d\n",(int)ans.size());
	for (int i = 0; i < ans.size(); ++i)
	{
		if (i!=0)
		{
			printf(" ");
		}
		printf("%d",ans[i]);
	}
	printf("\n");

	return 0;
}