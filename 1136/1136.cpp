#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	string str;
	cin>>str;
	int cnt=10;
	while(cnt--){
		string rever=str;
		reverse(str.begin(), str.end());
		if (rever==str)
		{
			cout<<str<<" is a palindromic number."<<endl;
			break;
		}
		cout<<rever<<" + "<<str<<" = ";
		string ans;
		int carry=0;
		for (int i = str.length()-1; i >= 0; i--)
		{
			int temp=(str[i]-'0')+(rever[i]-'0')+carry;
			ans+=temp%10+'0';
			carry=temp/10;		
		}
		if (carry>0)
		{
			ans+=carry+'0';
		}
		reverse(ans.begin(), ans.end());
		cout<<ans<<endl;
		str=ans;
	}
	if (cnt<0)
	{
		cout<<"Not found in 10 iterations."<<endl;
	}
	return 0;
}