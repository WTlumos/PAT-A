#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string str;
void add(string b){
	int len=str.length();
	int carry=0;
	for (int i = 0; i < len; ++i)
	{
		int temp=(str[i]-'0')+(b[i]-'0')+carry;
		str[i]=temp%10+'0';
		carry=temp/10;		
	}
	if (carry!=0)
	{
		str+=carry+'0';
	}
	reverse(str.begin(), str.end());
}
int main()
{
	int k;
	cin>>str>>k;
	int i=0;
	for(;i<=k;i++)
	{
		string t=str;
		reverse(t.begin(), t.end());
		if(t==str||i==k){
	    	break;
	    }
	    add(t);
	}
    cout<<str<<"\n"<<i<<endl;
	return 0;
}