#include<iostream>
#include<string>
#include<map>
using namespace std;
map<string,int> winner;
int main(){
	int m,n,s;
	cin>>m>>n>>s;
	string str;
	int flag=0;
	for (int i = 1; i <= m; ++i)
	{
		cin>>str;
		if (winner[str]>0)
		{
			s++;
		}
		if (i==s&&winner[str]==0)
		{
			cout<<str<<endl;
			winner[str]++;
			s+=n;
			flag=1;
		}	
	}
	if (flag==0)
	{
		cout<<"Keep going..."<<endl;
	}
	return 0;
}