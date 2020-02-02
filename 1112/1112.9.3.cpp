#include<iostream>
#include<string>
#include<map>
using namespace std;
map<char,bool> good,bad;
int main()
{
	int k;
	cin>>k;
	string str;
	cin>>str;
	int cnt=1;
	for (int i = 0; i < str.length(); ++i)
	{
		if (str[i]==str[i+1])
		{
			cnt++;
		}else{
			if (cnt%k==0)
			{
				bad[str[i]]=true;
			}else{
				good[str[i]]=true;
			}
			cnt=1;
		}
	}
	for (int i = 0; i < str.length(); ++i)
	{
		if (good[str[i]])
		{
			bad[str[i]]=false;
		}
	}
	string broken;
	for (int i = 0; i < str.length(); ++i)
	{
		if (bad[str[i]]&&broken.find(str[i])==string::npos)
		{
			broken+=str[i];
		}
	}
	string ans;
	for (int i = 0; i < str.length(); ++i)
	{
		if (bad[str[i]]==false)
		{
			ans+=str[i];
		}else{
			ans+=str[i];
			i+=k-1;
		}
	}
	cout<<broken<<"\n"<<ans<<endl;

	return 0;
}