#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node
{
	int id,grade;
	char name[10];
}v[100010];
int c;
bool cmp(node a,node b)
{
	if (c==1)
	{
		return a.id<b.id;
	}else if(c==2){
		if (strcmp(a.name,b.name)!=0)
		{
			return strcmp(a.name,b.name)<0;
		}else{
			return a.id<b.id;
		}
	}else{
		if (a.grade!=b.grade)
		{
			return a.grade<b.grade;
		}else{
			return a.id<b.id;
		}
	}
}
int main()
{
	int n;
	scanf("%d%d",&n,&c);
	node temp;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%s%d",&temp.id,temp.name,&temp.grade);
		v[i]=temp;
	}
	sort(v,v+n,cmp);
	for (int i = 0; i < n; ++i)
	{
		printf("%06d %s %d\n",v[i].id,v[i].name,v[i].grade);
	}

	return 0;
}