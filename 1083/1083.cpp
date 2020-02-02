#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
struct node{
   string name;
   string id;
   int grade;
   node(string Name,string Id,int Grade):name(Name),id(Id),grade(Grade){};
};
vector<node> v;
bool cmp(node a,node b){
	return a.grade>b.grade;
}
int main()
{
	int n;
	cin>>n;
	string name,id;
	int grade;
	for (int i = 0; i < n; ++i)
	{
		cin>>name>>id>>grade;
		v.push_back(node(name,id,grade));
	}
	sort(v.begin(), v.end(),cmp);
	int g1,g2;
	cin>>g1>>g2;
	bool flag=true;
	for (int i = 0; i < n; ++i)
	{
		if (v[i].grade>=g1&&v[i].grade<=g2)
		{
			flag=false;
			cout<<v[i].name<<" "<<v[i].id<<endl;
		}
	}
		
	if(flag){
		cout<<"NONE"<<endl;
	}
	return 0;
}