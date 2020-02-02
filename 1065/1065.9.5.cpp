#include<cstdio>
int main()
{
	int n;
	scanf("%d",&n);
	long long a,b,c,sum;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%lld%lld%lld",&a,&b,&c);
		printf("Case #%d: ",i);
		sum=a+b;
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
