#include<cstdio>
#include<algorithm>
using namespace std;
long long gcd(long long a,long long b)
{
	if (b==0)
	{
		return a;
	}
	else{
		return gcd(b,a%b);
	}
}
struct node
{
	long long up,down;
};
void init(node &f)
{
	if (f.down<0)
	{
		f.up=-f.up;
		f.down=-f.down;
	}
	if (f.up==0)
	{
		f.down=1;
	}else{
		long long d=gcd(abs(f.up),abs(f.down));
		f.up/=d;
		f.down/=d;
	}
}
void print(node f){
	if (f.down==1)
	{
		printf("%lld\n",f.up);
	}else if(abs(f.up)>f.down){
		printf("%lld %lld/%lld\n",f.up/f.down,abs(f.up)%f.down,f.down);
	}else{
		printf("%lld/%lld\n",f.up,f.down);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	node f1,f2,result;
    if (n==1)
    {
    	scanf("%lld/%lld",&f1.up,&f1.down);
    	print(f1);
    	return 0;
    }else{
    	scanf("%lld/%lld",&f1.up,&f1.down);
    	init(f1);
    	for (int i = 1; i < n; ++i)
    	{
    		scanf("%lld/%lld",&f2.up,&f2.down);
    		init(f2);
    		result.up=f1.up*f2.down+f2.up*f1.down;
    		result.down=f1.down*f2.down;
    		init(result);
    		f1=result;
    	}
    }
    print(result);
	return 0;
}