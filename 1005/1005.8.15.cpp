#include<cstdio>
#include<cstring>
int main()
{
	char ans[][6]={"zero","one","two","three","four","five","six","seven","eight","nine"};
	char c[101];
	scanf("%s",c);
	int len=strlen(c);
	int sum=0;
	for (int i = 0; i < len; ++i)
	{
		sum+=c[i]-'0';
	}
	if (sum<10)
	{
		printf("%s\n",ans[sum]);
	}else{
		int num[101];
		int index=0;

		while(sum){
			num[index++]=sum%10;
			sum/=10;
		}
		for (int i = index-1; i >=0; i--)
		{
			printf("%s", ans[num[i]]);
			if (i>0)
			{
				printf(" ");
			}
		}
	}
	return 0;
}