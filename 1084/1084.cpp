#include<iostream>
#include<cctype>
#include<string>
using namespace std;
int main()
{
	string a,b;
	cin>>a>>b;
	string ans;
	for (int i = 0; i < a.length(); ++i)
	{
		if (b.find(a[i])==string::npos&&ans.find(toupper(a[i]))==string::npos)
		{
			ans+=toupper(a[i]);
		}
	}
	cout<<ans<<endl;
	return 0;
}