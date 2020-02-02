#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
const int maxn=1010;
int father[maxn]={};
map<int,int> course;
int isRoot[maxn]={};
void init()
{
	for (int i = 1; i < maxn; ++i)
	{
		father[i]=i;
	}
}
int findFather(int x)
{
	int a=x;
	while(x!=father[x])
	{
		x=father[x];
	}
	while(a!=father[a])
	{
		int z=a;
		a=father[a];
		father[z]=x;
	}
	return x;
}
void together(int a,int b){
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
			if (course[hobby]==0)
			{
				course[hobby]=i;
			}
			together(i,findFather(course[hobby]));
		}
	}
	for (int i=1;i<=n;i++)
	{
		isRoot[findFather(i)]++;	
	}
	int ans=0;
	for (int i = 1; i <= n; ++i)
	
		if (isRoot[i]>0)
		{
			ans++;
		}
	}
	sort(isRoot+1,isRoot+n+1,cmp);
	printf("%d\n",ans);
	for (int i = 1; i <= ans; ++i)
	{
		printf("%d",isRoot[i]);
		if (i<ans)
		{
			printf(" ");
		}else{
			printf("\n");
		}
	}
	return 0;
}