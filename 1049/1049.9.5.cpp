#include<cstdio>
int main()
{
	int n;
	scanf("%d",&n);
	int a=1;
	int ans=0;
	while(n/a){
		int left=n/(a*10);
		int now=n/a%10;
		int right=n%a;
		if (now==0)
		{
			ans+=left*a;
		}else if(now==1){
			ans+=left*a+right+1;
		}else{
			ans+=(left+1)*a;
		}
		a*=10;
	}
	printf("%d\n",ans);
	return 0;
}