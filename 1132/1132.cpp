#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		string str;
		cin>>str;
		int len=str.length();
		string str1=str.substr(0,len/2);
		string str2=str.substr(len/2,len/2);

		long long z=atoi(str.c_str());
		long long a=atoi(str1.c_str());
		long long b=atoi(str2.c_str());
		if ((a*b)!=0&&z%(a*b)==0)
		{
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
		
	}
	return 0;
}