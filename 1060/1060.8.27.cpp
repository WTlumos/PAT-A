#include<iostream>
#include<string>
using namespace std;
int n;
string pattern(string str,int &e)
{
	int k=0;
	while(str.length()>0&&str[0]=='0'){
		str.erase(str.begin());
	}
	if (str[0]=='.')
	{
	    //.000123
		str.erase(str.begin());
		while(str.length()>0&&str[0]=='0'){
			str.erase(str.begin());
			e--;
		}
	}
	else{
		//123.45
		while(k<str.length()&&str[k]!='.'){
			k++;
			e++;
		}
		if (k<str.length())
		{
			str.erase(str.begin()+k);
		}
	}
	if (str.length()==0)
	{
		e=0;
	}
	k=0; int cnt=0; string ans;
	while(cnt<n)
	{
		if(k<str.length()){
			ans+=str[k];
			k++;
		}else{
			ans+='0';
		}
		cnt++;
	}
	return ans;
}
int main()
{
	string a,b;
	cin>>n>>a>>b;
	string str1,str2;
	int e1,e2;
	e1=e2=0;
	str1=pattern(a,e1);
	str2=pattern(b,e2);
	if (str1==str2&&e1==e2)
	{
		printf("YES 0.%s*10^%d\n",str1.c_str(),e1);
	}else{
		printf("NO 0.%s*10^%d 0.%s*10^%d\n",str1.c_str(),e1,str2.c_str(),e2);
	}
	return 0;
}