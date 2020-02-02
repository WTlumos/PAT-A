#include<cstdio>
char str[100010];
int leftP[100010]={};
const int mod=1000000007;
int main()
{
	scanf("%s",str);
	int len=0;
	for (int i = 0; str[i] != '\0'; ++i)
	{
		len++;
		if (i>0)
		{
			leftP[i]=leftP[i-1];
		}
		if (str[i]=='P')
		{
			leftP[i]++;
		}
	}
	int righT=0; int ans=0;
	for (int i = len-1; i >= 0 ; i--)
	{
		if (str[i]=='T')
		{
			righT++;
		}else if(str[i]=='A'){
			ans=(ans+leftP[i]*righT)%mod;
		}
	}
	printf("%d\n", ans);
	return 0;
}