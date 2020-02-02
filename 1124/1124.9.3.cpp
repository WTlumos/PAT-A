#include<iostream>
#include<map>
#include<string>
using namespace std;
map<string,int> exist;
int main()
{
	int m,n,s;
	cin>>m>>n>>s;
	string str; int flag=0;
    for (int i = 1; i <= m; ++i)
    {
    	cin>>str;
    	if (exist[str]>0)
    	{
    		s++;
    	}
    	if (s==i&&exist[str]==0)
    	{
    		flag=1;
    		cout<<str<<endl;
    		s+=n;
    		exist[str]++;
    	}
    }
    if (flag==0)
    {
    	cout<<"Keep going..."<<endl;
    }
	return 0;
}