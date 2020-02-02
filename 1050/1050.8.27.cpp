#include<iostream>
#include<string>
#include<map>
using namespace std;
map<char,int> m;
int main()
{
	string s1,s2;
	getline(cin,s1);
	getline(cin,s2);
	for (int i = 0; i < s2.length(); ++i)
	{
		m[s2[i]]++;
	}
	for (int i = 0; i < s1.length(); ++i)
	{
		if (m[s1[i]]==0)
		{
			cout<<s1[i];
		}
	}
	cout<<endl;
	return 0;
}
