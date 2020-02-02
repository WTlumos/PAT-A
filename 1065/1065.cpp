#include<cstdio>
int main()
{
	int t;
	scanf("%d",&t);
	long long a,b,c,sum;
	for (int i = 1; i <= t; ++i)
	{
		scanf("%lld%lld%lld",&a,&b,&c);
		sum=a+b;
		printf("Case #%d: ",i);
		if (a>0&&b>0&&sum<0)
		{
			printf("true\n");
		}else if(a<0&&b<0&&sum>=0){
			printf("false\n");
		}else if(sum>c){
			printf("true\n");
		}else{
			printf("false\n");
		}	
	}
	return 0;
}