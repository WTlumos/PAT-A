#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node
{
	int score,localnum,localrank;
	char id[14];
}stu[30010];
bool cmp(node a,node b)
{
	if(a.score!=b.score){
		return a.score>b.score;
	}else{
		return strcmp(a.id,b.id)<0;
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	int k;
	int index=0;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d",&k);
		for (int j = 0; j < k; ++j)
		{
			scanf("%s%d",stu[index].id,&stu[index].score);
			stu[index].localnum=i;
			index++;		
		}
		sort(stu+index-k,stu+index,cmp);
		stu[index-k].localrank=1;
		for (int j = index-k+1; j <index ; ++j)
		{
			stu[j].localrank=j+1-(index-k);
			if (stu[j].score==stu[j-1].score)
			{
				stu[j].localrank=stu[j-1].localrank;
			}
		}
	}
	printf("%d\n",index);
	sort(stu,stu+index,cmp);
	int r=1;
	for (int i=0;i<index;i++)
	{
		printf("%s ", stu[i].id);
		if(i>0&&stu[i].score!=stu[i-1].score){
			r=i+1;
		}
		printf("%d %d %d",r,stu[i].localnum,stu[i].localrank);
		if (i<index-1)
		{
			printf("\n");
		}
		
	}
	return 0;
}