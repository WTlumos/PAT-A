#include<cstdio>
int main()
{
	int g1,s1,k1,g2,s2,k2;
	scanf("%d.%d.%d %d.%d.%d",&g1,&s1,&k1,&g2,&s2,&k2);
	int a=g1*17*29+s1*29+k1;
	int b=g2*17*29+s2*29+k2;
	int sum=a+b;
    printf("%d.%d.%d\n",sum/(17*29),sum/29%17,sum%29);
	return 0;
}