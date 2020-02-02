#include<iostream>
#include<map>
#include<string>
using namespace std;

map<char,int> match;
int main()
{
	string str1,str2;
	getline(cin,str1);	
	getline(cin,str2);
	for (int i = 0; str2[i] != '\0'; ++i)
	{
		match[str2[i]]++;
	}
	for (int i = 0; str1[i] != '\0'; ++i)
	{
		if (match[str1[i]]==0)
		{
			cout<<str1[i];
		}
	}
	return 0;
}