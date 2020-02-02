#include<iostream>
#include<string>
#include<cmath>
using namespace std;
bool isPrime(int x){
	if(x<2){
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
	int l,k; string str;
	cin>>l>>k>>str;
	for (int i = 0; i <= l-k; ++i)
	{
		string ans=str.substr(i,k);
		if(isPrime(stoi(ans))){
			cout<<ans<<endl;
			return 0;
		}
	}
	cout<<"404"<<endl;
	return 0;
}