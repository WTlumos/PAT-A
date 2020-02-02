#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
struct node
{
	string name;
	string id;
	int grade;
	node(string Name,string Id,int Grade){
		name=Name;
		id=Id;
		grade=Grade;
	}
};
bool cmp1(node a,node b)
{
	return a.grade>b.grade;
}
bool cmp2(node a,node b)
{
	return a.grade<b.grade;
}
vector<node> female;
vector<node> male;
int main()
{
	int n;
	cin>>n;
	string name,gender,id;
	int grade;
	for (int i = 0; i < n; ++i)
	{
		cin>>name>>gender>>id>>grade;
		if (gender=="M")
		{
			male.push_back(node(name,id,grade));
		}else{
			female.push_back(node(name,id,grade));
		}
	}
	sort(male.begin(), male.end(),cmp2);
	sort(female.begin(), female.end(),cmp1);
    int a,b;
    a=b=0;
    int flag1,flag2;
    flag1=flag2=0;
	if (female.size()==0)
	{
		cout<<"Absent"<<endl;
	}else{
		flag1=1;
		a=female[0].grade;
		cout<<female[0].name<<" "<<female[0].id<<endl;
	}
	if (male.size()==0)
	{
		cout<<"Absent"<<endl;
	}else{
		flag2=1;
		b=male[0].grade;
		cout<<male[0].name<<" "<<male[0].id<<endl;
	}
	if (flag1==1&&flag2==1)
	{
		cout<<a-b<<endl;
	}else{
		cout<<"NA"<<endl;
	}

	return 0;
}