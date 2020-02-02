#include<iostream>
#include<string>
using namespace std;
int n;
string getans(string str,int &e){
	int k=0;
	while(str.length()>0&&str[0]=='0'){
		str.erase(str.begin());
	}
	if (str[0]=='.')
	{
		str.erase(str.begin());
		while(str[0]=='0'&&str.length()>0){
			str.erase(str.begin());
			e--;
		}
	}else{
		while(k<str.length()&&str[k]!='.'){
			k++;
			e++;
		}
		if (str[k]=='.')
		{
			str.erase(str.begin()+k);
		}
	}
	if (str.length()==0)
	{
		e=0;
	}
	k=0; string ans;
	int idx=0;
	while(idx<n){
		if (k<str.length())
		{
			ans+=str[k++];	
		}else{
			ans+='0';
		}
		idx++;
	}
	return ans;

}
int main()
{
	cin>>n;
	string str1,str2;
	cin>>str1>>str2;
	int e1=0; int e2=0;
	string ans1=getans(str1,e1);
	string ans2=getans(str2,e2);
	if (ans1==ans2&&e1==e2)
	{
		cout<<"YES 0."<<ans1<<"*10^"<<e1<<endl;
	}else{
		cout<<"NO 0."<<ans1<<"*10^"<<e1<<" 0."<<ans2<<"*10^"<<e2<<endl;
	}
	return 0;
}