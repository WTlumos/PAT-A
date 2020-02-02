#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node
{
	char name[10];
	int age,worth;
};
node people[100010];
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
	for (int i = 0; i < n; ++i)
	{
		scanf("%s%d%d",people[i].name,&people[i].age,&people[i].worth);	
	}
	sort(people,people+n,cmp);
	int index,amin,amax;
	for (int i = 1; i <= k; ++i)
	{
		scanf("%d%d%d",&index,&amin,&amax);
		printf("Case #%d:\n",i);
		int cnt=0;
		node ans[n];
		for (int j = 0; j < n; ++j)
		{
			//printf("%s %d %d\n",people[j].name,people[j].age,people[j].worth);
			if (people[j].age<=amax&&people[j].age>=amin)
			{
				ans[cnt++]=people[j];
			}
			if (cnt>=index)
			{
				break;
			}
		}
		if(cnt==0){
			printf("None\n");
		}else{
			for (int j = 0; j <cnt ; ++j)
			{
				printf("%s %d %d\n",ans[j].name,ans[j].age,ans[j].worth);
			}

		}
	}
	return 0;
}