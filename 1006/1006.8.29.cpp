#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
struct node
{
	string id,intime,outime;
};
int flag=0;
bool cmp(node a,node b)
{
	if (flag==0)
	{
		return a.intime<b.intime;
	}
	else
	{
		return a.outime>b.outime;
	}
}
vector<node> v;
int main()
{
	int n;
	cin>>n;
	node temp;
	for (int i = 0; i < n; ++i)
	{
		cin>>temp.id>>temp.intime>>temp.outime;
		v.push_back(temp);
	}
	sort(v.begin(), v.end(),cmp);
	cout<<v[0].id<<" ";
	flag=1;
	sort(v.begin(), v.end(),cmp);
	cout<<v[0].id<<endl;
	return 0;
}