#include<iostream>
#include<cmath>
using namespace std;
bool isPrime(int x)
{
	if (x<2)
	{
		return false;
	}
	int sqr=sqrt(1.0*x);
	for (int i = 2; i <= sqr; ++i)
	{
		if (x%i==0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	string str;
	int n,k;
	cin>>n>>k;
	cin>>str;
	int flag=0;
	for (int i = 0; i <= n-k; ++i)
	{
		string ans=str.substr(i,k);
		int dig=atoi(ans.c_str());
		if (isPrime(dig))
		{
			flag=1;
			cout<<ans<<endl;
			break;
		}
	}
	if (flag==0)
	{
		cout<<"404"<<endl;
	}
	return 0;
}