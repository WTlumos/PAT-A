#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string str[10010];
bool cmp(string a,string b)
{
	return a+b<b+a;
}
int main()
{
	int n;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>str[i];
	}
	sort(str,str+n,cmp);
	string ans;
	for (int i = 0; i < n; ++i)
	{
		ans+=str[i];
	}
	//cout<<ans<<endl;
	while(ans.length()>0&&ans[0]=='0'){
		ans.erase(ans.begin());
	}
	if (ans.length()==0)
	{
		cout<<"0"<<endl;
		return 0;
	}
	cout<<ans<<endl;

	return 0;
}