#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct node
{
	char name[20],id[20],gender[2];
	int grade;
};
vector<node> male,female;
bool cmp1(node a,node b){
	return a.grade>b.grade;
}
bool cmp2(node a,node b){
	return a.grade<b.grade;
}
int main()
{
	int n;
	scanf("%d",&n);
	node temp;
	for (int i = 0; i < n; ++i)
	{
		scanf("%s%s%s%d",temp.name,temp.gender,temp.id,&temp.grade);
		if (temp.gender[0]=='M')
		{
			male.push_back(temp);
		}
		if (temp.gender[0]=='F')
		{
			female.push_back(temp);
		}
	}
	sort(female.begin(),female.end(),cmp1);
	sort(male.begin(),male.end(),cmp2);
	int flag1=0; int flag2=0;
	int num1=0; int num2=0;
	if (female.size()==0)
	{
		flag1=1;
		printf("Absent\n");
	}else{
		num1=female[0].grade;
		printf("%s %s\n", female[0].name,female[0].id);
	}
	if (male.size()==0)
	{
		flag2=1;
		printf("Absent\n");
	}else{
		num2=male[0].grade;
		printf("%s %s\n", male[0].name,male[0].id);
	}
	if (flag1==1||flag2==1)
	{
		printf("NA\n");
	}else{
		printf("%d\n",num1-num2);
	}

	return 0;
}