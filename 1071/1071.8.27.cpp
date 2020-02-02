#include<iostream>
#include<string>
#include<cctype>
#include<map>
using namespace std;
map<string,int> m;
int main()
{
	string str;
	getline(cin,str);
	int cnt=0;
	for (int i = 0; i < str.length(); ++i)
	{
		string ans;
		while (isalnum(str[i]))
		{
			ans+=tolower(str[i]);
			i++;
		}
		if (ans.length()>0)
		{
			m[ans]++;
		}
		ans.clear();	
	}
	int max=-1; string ans;
	for (map<string,int>::iterator i = m.begin(); i != m.end(); ++i)
	{
		if (i->second>max)
		{
			max=i->second;
			ans=i->first;
		}
	}
	cout<<ans<<" "<<max<<endl;
	return 0;
}