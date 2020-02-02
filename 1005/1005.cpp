#include<iostream>
#include<string>
using namespace std;
int main()
{
	string english[]={"zero","one","two","three","four","five","six","seven","eight","nine"};
	string str;
	cin>>str;
	int sum=0;
	for (int i = 0; i < str.length(); ++i)
	{
		sum+=str[i]-'0';	
	}
	string ans=to_string(sum);
	for (int i=0;i<ans.length();i++)
	{
		cout<<english[ans[i]-'0'];
		if(i<ans.length()-1){
			cout<<" ";
		}else{
			cout<<endl;
		}
	}
	return 0;
}