#include<cstdio>
int main()
{
	int n;
	scanf("%d",&n);
	int left=0; int right=0; int a=1; int now=0;
	int sum=0;
	while(n/a){
		left=n/(a*10);
		right=n%a;
		now=n/a%10;
		if (now==0)
		{
			sum+=left*a;
		}else if(now==1){
			sum+=left*1+right+1;
		}else{
			sum+=(left+1)*a;
		}
		a=a*10;
	}
	printf("%d\n",sum);
	return 0;
}