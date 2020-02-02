#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
struct node
{
	char name[20],gender[2],ID[20];
	int grade;
	bool operator < (const node &a) const{
		return grade>a.grade;
	}
};
vector<node> male,female;
int main()
{
	int n;
	scanf("%d",&n);
	node temp;
	for (int i = 0; i < n; ++i)
	{
		scanf("%s%s%s%d",temp.name,temp.gender,temp.ID,&temp.grade);
		if (temp.gender[0]=='F')
		{
			female.push_back(temp);
		}else{
			male.push_back(temp);
		}	
	}
	sort(female.begin(),female.end());
	sort(male.begin(), male.end());
	int flag1=0; int flag2=0; int g1=0; int g2=0;
	if ((int)female.size()==0)
	{
		flag1=1;
		printf("Absent\n");
	}else{
		g1=female[0].grade;
		printf("%s %s\n",female[0].name,female[0].ID);
	}
	int size=male.size();
	if (size==0)
	{
		flag2=1;
		printf("Absent\n");
	}else{
		g2=male[size-1].grade;
		printf("%s %s\n",male[size-1].name,male[size-1].ID);
	}
	if (flag1==0&&flag2==0)
	{
		printf("%d\n",g1-g2);
	}else{
		printf("NA\n");
	}

	return 0;
}