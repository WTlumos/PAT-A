#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool cmp(string a,string b)
{
	return a+b<b+a;
}
string str[10010];
int main()
{
	int n;
	scanf("%d",&n);
	char c[10];
	for (int i = 0; i < n; ++i)
	{
		scanf("%s",c);
		str[i]=c;	
	}
	sort(str,str+n,cmp);
	string ans;
	for (int i = 0; i < n; ++i)
	{
		ans+=str[i];
	}
	while(ans.length()>0&&ans[0]=='0')
	{
		ans.erase(ans.begin());
	}
	if(ans.length()>0){
        printf("%s\n",ans.c_str());
    }else{
        printf("0");
    }

	return 0;
}