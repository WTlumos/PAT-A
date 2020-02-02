#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct node
{
	char name[11],id[11];
	int grade;
};
vector<node> v;
bool cmp(node a,node b)
{
	return a.grade>b.grade;
}
int main()
{
	int n;
	scanf("%d",&n);
	node temp;
	for (int i = 0; i < n; ++i)
	{
		scanf("%s%s%d",temp.name,temp.id,&temp.grade);
		v.push_back(temp);
	}
	sort(v.begin(),v.end(),cmp);
	int grade1,grade2;
	scanf("%d%d",&grade1,&grade2);
	int flag=0;
	for (int i = 0; i < n; ++i)
	{
		if (v[i].grade>=grade1&&v[i].grade<=grade2)
		{
			printf("%s %s\n",v[i].name,v[i].id);
			flag=1;
		}
	}
	if (flag==0)
	{
		printf("NONE\n");
	}
	return 0;
}