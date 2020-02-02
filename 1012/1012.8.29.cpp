#include<cstdio>
#include<algorithm>
using namespace std;
struct node
{
	int id,best,index;
	int course[4],rank[4];
	node(){
		index=best=0;
	}
}stu[2010];
int flag;
bool cmp(node a,node b){
	return a.course[flag]>b.course[flag];
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	node temp;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&temp.id);
		int sum=0;
		for (int j = 1; j <= 3; ++j)
		{
			scanf("%d",&temp.course[j]);
			sum+=temp.course[j];
		}
		temp.course[0]=(1.0)*sum/3+0.5;
		stu[i]=temp;
	}
	for (flag = 0; flag < 4; ++flag)
	{
		sort(stu,stu+n,cmp);
		stu[0].rank[flag]=1;
		for (int i = 1; i < n; ++i)
		{
			stu[i].rank[flag]=stu[i-1].rank[flag];
			if (stu[i].course[flag]!=stu[i-1].course[flag])
			{
				stu[i].rank[flag]=i+1;
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		int best=stu[i].rank[0];
		for (int j = 1; j < 4; ++j)
		{
			if (stu[i].rank[j]<best)
			{
				best=stu[i].rank[j];
				stu[i].index=j;
			}
		}
		stu[i].best=best;
	}
	int a;
	char c[]={"ACME"};
	for (int i = 0; i < m; ++i)
	{
		scanf("%d",&a);
		int flag=0;
		for (int j = 0; j < n; ++j)
		{
			if (stu[j].id==a)
			{
				flag=1;
                printf("%d %c\n",stu[j].best,c[stu[j].index]);
				break;
			}
		}
		if (flag==0)
		{
			printf("N/A\n");
		}
	}
	return 0;
}