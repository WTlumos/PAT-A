#include<iostream>
#include<string>
#include<cctype>
#include<map>
using namespace std;
map<char,int> m;
int main()
{
	string str1,str2;
	cin>>str1>>str2;
	for (int i = 0; i < str2.length(); ++i)
	{
		str2[i]=toupper(str2[i]);
		m[str2[i]]++;
	}
	string ans;
	for (int i = 0; i < str1.length(); ++i)
	{
		str1[i]=toupper(str1[i]);
		if (m[str1[i]]==0&&ans.find(str1[i])==string::npos)
		{
			ans+=str1[i];
		}	
	}
    cout<<ans<<endl;
	return 0;
}