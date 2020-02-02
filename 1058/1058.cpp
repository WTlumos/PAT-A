#include<cstdio>
int main()
{
	long long g1,s1,k1,g2,s2,k2;
	scanf("%lld.%lld.%lld %lld.%lld.%lld",&g1,&s1,&k1,&g2,&s2,&k2);
	long long a=g1*17*29+s1*29+k1;
	long long b=g2*17*29+s2*29+k2;
	long long sum=a+b;
    printf("%lld.%lld.%lld\n",sum/(17*29),sum/29%17,sum%29);
	return 0;
}