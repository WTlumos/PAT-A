#include<iostream>
#include<string>
#include<cctype>
#include<map>
using namespace std;
map<string,int> exist;
int main()
{
	string str;
	getline(cin,str);
	string ans;
	for (int i = 0; i < str.length(); ++i)
	{
		str[i]=tolower(str[i]);
		while (isalnum(str[i]))
		{
			ans+=str[i];
			i++;
		}
		if (ans.length()>0)
		{
			exist[ans]++;
		}
		ans.clear();
		//printf("%d\n", i);
	}
	int max=-1;
	for (map<string,int>::iterator i = exist.begin(); i != exist.end(); ++i)
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