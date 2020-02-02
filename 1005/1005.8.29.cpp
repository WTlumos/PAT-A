#include<cstdio>
char str[110];
int num[110]={};
char ans[][7]={"zero","one","two","three","four","five","six","seven","eight","nine"};
int main()
{
	scanf("%s",str);
	int sum=0;
	for (int i = 0; str[i] != '\0'; ++i)
	{
		sum+=str[i]-'0';
	}
	if (sum==0)
	{
		printf("%s\n",ans[0]);
		return 0;
	}
	//printf("%d\n",sum);
	int idx=0;
	while(sum){
		num[idx++]=sum%10;
		sum/=10;
	}
	printf("%s",ans[num[idx-1]]);
	for (int i = idx-2; i >= 0 ; i--)
	{
		printf(" %s",ans[num[i]]);
	}
	printf("\n");
	return 0;
}