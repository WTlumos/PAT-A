#include<cstdio>
#include<string>
using namespace std;
int num[100]={};
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	int sum=a+b;
	if (sum<0)
	{
		printf("-");
		sum=-sum;
	}
	if (sum==0)
	{
		printf("0\n");
		return 0;
	}
	int idx=0;
	while(sum){
		num[idx++]=sum%10;
		sum/=10;
	}
	int cnt=1;
	string ans;
	for (int i = 0; i < idx ; i++)
	{
		ans+=(num[i]+'0');
		if (cnt%3==0&&i!=idx-1)
		{
			ans+=',';
		}
		cnt++;	
	}
	for (int i = ans.length()-1; i >=0 ; i--)
	{
		printf("%c",ans[i]);
	}
	printf("\n");
	return 0;
}