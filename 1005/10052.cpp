#include<iostream>
#include<string>
using namespace std;
int main()
{
	string ans[]={"zero","one","two","three","four","five","six","seven","eight","nine"};
	string str;
	cin>>str;
	int sum=0;
	for (int i = 0; i < str.length(); ++i)
	{
		sum+=str[i]-'0';	
	}
	if(sum==0){
		cout<<"zero"<<endl;
		return 0;
	}
	int num[100];
	int index=0;
	while(sum){
		num[index++]=sum%10;
		sum/=10;
	}
	for (int i = index-1; i >=0 ; i--)
	{
		cout<<ans[num[i]];
		if(i>0){
			cout<<" ";
		}else{
			cout<<endl;
		}
	}
	return 0;
}