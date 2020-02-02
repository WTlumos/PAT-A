#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	string str,ans;
	cin>>str;
	int cnt=0;
    while(cnt<10){
    	ans=str;
    	reverse(str.begin(),str.end());
    	if (ans==str)
    	{
    		cout<<ans<<" is a palindromic number."<<endl;
    		return 0;
    	}
    	string temp;
    	int carry=0;
    	for (int i = str.length()-1; i >= 0 ; i--)
    	{
    		int sum=(str[i]-'0')+(ans[i]-'0')+carry;
    		temp+=sum%10+'0';
    		carry=sum/10;		
    	}
    	if (carry>0)
    	{
    		temp+=carry+'0';
    	}
    	reverse(temp.begin(),temp.end());
    	cout<<ans<<" + "<<str<<" = "<<temp<<endl;
    	str=temp;
    	cnt++;
    }
    if (cnt==10)
    {
    	cout<<"Not found in 10 iterations."<<endl;
    }
	return 0;
}