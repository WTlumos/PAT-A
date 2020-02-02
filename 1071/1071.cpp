#include<iostream>
#include<string>
#include<map>
#include<cctype>
using namespace std;
map<string,int> m;
int main()
{
	string str;
	getline(cin,str);
	string temp;
	int i=0;
	while(i<str.length()){
		while(isalnum(str[i])){
			temp+=tolower(str[i]);
			i++;
		}
		if (temp.length()>0)
		{
			m[temp]++;
		}
		temp.clear();
		i++;
	}
	int max=-1;
	string ans;
	for (map<string,int>::iterator i=m.begin();i!=m.end(); ++i)
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