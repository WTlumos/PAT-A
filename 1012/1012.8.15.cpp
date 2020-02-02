#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
struct node
{
	int id;
	int score[4];
	int rank[4];
	int best;
};
node stu[2010];
int flag=-1;
bool cmp(node a,node b)
{
	return a.score[flag]>b.score[flag];
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int id,a,b,c,d;
	int sum=0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d%d%d",&id,&a,&b,&c);
		sum=a+b+c;
		d=(1.0)*sum/3+0.5;
		stu[i].id=id;
		stu[i].score[0]=d;
		stu[i].score[1]=a;
		stu[i].score[2]=b;
		stu[i].score[3]=c;	
	}
	for (flag=0; flag<4;flag++)
	{
		sort(stu,stu+n,cmp);
		stu[0].rank[flag]=1;
		for (int i = 1; i < n; ++i)
		{
			stu[i].rank[flag]=i+1;
			if (stu[i].score[flag]==stu[i-1].score[flag])
			{
				stu[i].rank[flag]=stu[i-1].rank[flag];
			}
		}
	}
	map<int,int> mIndex;
	for (int i = 0; i < n; ++i)
	{
		mIndex[stu[i].id]=i+1;
		int min=stu[i].rank[0];
		int best=0;
		for (int j = 1; j < 4; ++j)
		{
			if(stu[i].rank[j]<min){
				min=stu[i].rank[j];
				best=j;
			}
		}
		stu[i].best=best;	
	}

	char ans[]={'A','C','M','E'};
	for (int i = 0; i < m; ++i)
	{
		scanf("%d",&id);
		int index=mIndex[id];
		if (index>0)
		{
			index--;
			int best=stu[index].best;
			printf("%d %c\n",stu[index].rank[best],ans[best]);
		}else{
			printf("N/A\n");
		}

	}
	return 0;
}