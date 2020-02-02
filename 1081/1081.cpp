#include<cstdio>
#include<algorithm>
using namespace std;
struct node
{
	long long up;
	long long down;
}f1,f2,result;
int gcd(long long a,long long b){
	if (b==0)
	{
		return a;
	}else{
		return gcd(b,a%b);
	}
}
void init(node &result)
{
	if (result.down<0)
	{
		result.up=-result.up;
		result.down=-result.down;
	}
	if (result.up==0)
	{
		result.down=1;
	}else{
		long long d=gcd(abs(result.up),abs(result.down));
		result.up/=d;
		result.down/=d;
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	long long up,down;
	scanf("%lld/%lld",&f1.up,&f1.down);
	init(f1);
	for (int i = 1; i < n; ++i)
	{
		scanf("%lld/%lld",&f2.up,&f2.down);
		init(f2);
		result.up=f1.up*f2.down+f1.down*f2.up;
		result.down=f1.down*f2.down;
		init(result);
		f1=result;	
	}
	
    if(result.down==1){
		printf("%lld\n",result.up);
	}
	else if(abs(result.up)>result.down){
		printf("%lld %lld/%lld\n",result.up/result.down,abs(result.up)%result.down,result.down);
	}else{
		printf("%lld/%lld\n",result.up,result.down);
	}
	return 0;
}