#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node
{
	char name[10];
	int age,worth;
}v[100010];
bool cmp(node a,node b)
{
	if (a.worth!=b.worth)
	{
		return a.worth>b.worth;
	}else if(a.age!=b.age){
		return a.age<b.age;
	}else{
		return strcmp(a.name,b.name)<0;
	}
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	node temp;
	for (int i = 0; i < n; ++i)
	{
		scanf("%s%d%d",temp.name,&temp.age,&temp.worth);
		v[i]=temp;
	}
	sort(v,v+n,cmp);
	for (int i = 1; i <= k; ++i)
	{
		printf("Case #%d:\n", i);
		int m,amin,amax; int cnt=0; int flag=0;
		scanf("%d%d%d",&m,&amin,&amax);
		for (int j = 0; j < n; ++j)
		{
			if (v[j].age<=amax&&v[j].age>=amin&&cnt<m)
			{
				flag=1;
				printf("%s %d %d\n",v[j].name,v[j].age,v[j].worth);
				cnt++;
			}
		}
		if (flag==0)
		{
			printf("None\n");
		}
	}
	return 0;
}