#include<cstdio>
#include<string>
using namespace std;
char a[110],b[110];
int n;
string dealWith(string str,int &e)
{
	int k=0;
	//000.1234
	while (str[0]=='0'&&str.length()>0)
	{
		str.erase(str.begin());
	}
	if(str[0]=='.'){ //小数.00123
		str.erase(str.begin());
		while (str[0]=='0'&&str.length()>0)
		{
			str.erase(str.begin());
			e--;
		}
	}else{//1234
		while (str[k]!='.'&&k<str.length())
		{
			e++;
			k++;		
		}
		if(k<str.length()){
			str.erase(str.begin()+k);
		}
	}
	if (str.length()==0)
	{
		e=0;
	}
	k=0;
	string ans="0.";
	int num=0;
	while(num<n)
	{
		if (k<str.length())
		{
			ans+=str[k++];
		}else{
			ans+='0';
		}
		num++;
	}
	return ans;

}
int main()
{
	scanf("%d%s%s",&n,a,b);
	string str1,str2;
	str1=a; str2=b;
	int e1=0;
	int e2=0;
	string ans1=dealWith(str1,e1);
	string ans2=dealWith(str2,e2);
	if (ans1==ans2&&e1==e2)
	{
		printf("YES %s*10^%d\n",ans1.c_str(),e1);
	}else{
		printf("NO %s*10^%d %s*10^%d\n",ans1.c_str(),e1,ans2.c_str(),e2);
	}
	return 0;
}