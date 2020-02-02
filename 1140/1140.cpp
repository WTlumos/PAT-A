#include<cstdio>
#include<string>
using namespace std;
int main()
{
	int d,n;
	scanf("%d%d",&d,&n);
	string str;
	if (n==1)
	{
		printf("%d\n",d);
		return 0;
	}else{
		str=d+'0';
	}
	while(--n){
		string ans; int cnt=1;
		for (int i = 0; i < str.length(); ++i)
		{
			if(str[i]==str[i+1]){
				cnt++;
			}else{
				ans+=str[i];
				ans+=cnt+'0';
				cnt=1;
			}	
		}
		str=ans;
	}
	printf("%s\n",str.c_str());
	return 0;
}