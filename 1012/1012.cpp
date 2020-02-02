#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
map<int,int> exist;
struct node
{
	int id, best;
	int score[4],rank[4];
};
node stu[2010];
int flag=-1;
bool cmp(node x,node y)
{
	return x.score[flag]>y.score[flag];

}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int average;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&stu[i].id);
		scanf("%d%d%d",&stu[i].score[1],&stu[i].score[2],&stu[i].score[3]);
		average=(stu[i].score[3]+stu[i].score[1]+stu[i].score[2])/((1.0)*3)+0.5;
		stu[i].score[0]=average;
	}
	for (flag=0;flag<4;flag++)
	{
		sort(stu,stu+n,cmp);
		stu[0].rank[flag]=1;
		for (int i = 1; i < n; ++i)
		{
			stu[i].rank[flag]=i+1;
			if(stu[i].score[flag]==stu[i-1].score[flag]){
				stu[i].rank[flag]=stu[i-1].rank[flag];
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		exist[stu[i].id]=i+1;
		stu[i].best=0;
		int min=stu[i].rank[0];
		for (int j = 1; j < 4; ++j)
		{
			if(stu[i].rank[j]<min){
				min=stu[i].rank[j];
				stu[i].best=j;
			}
		}
	}

	int a;
	char c[]={'A','C','M','E'};
	for (int i = 0; i < m; ++i)
	{
		scanf("%d",&a);
		int temp=exist[a];
		if(temp>0)
		{
			temp--;
			int best=stu[temp].best;
			printf("%d %c\n",stu[temp].rank[best],c[best]);

		}else{
			printf("N/A\n");
		}

	}
	return 0;
}