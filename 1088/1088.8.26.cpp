#include<cstdio>
#include<algorithm>
using namespace std;
long long gcd(int a,int b)
{
	if (b==0)
	{
		return a;
	}
	return gcd(b,a%b);
}
struct node
{
	long long up,down;
};
void init(node &f){
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
void print(node f)
{
	if (f.up<0)
	{
		printf("(");
	}
	if (f.down==1)
	{
		printf("%lld",f.up);
	}else if(abs(f.up)>f.down){
		printf("%lld %lld/%lld", f.up/f.down,abs(f.up)%f.down,f.down);
	}else{
		printf("%lld/%lld",f.up,f.down);
	}
	if (f.up<0)
	{
		printf(")");
	}
}
int main()
{
	node f1,f2;
	scanf("%lld/%lld %lld/%lld",&f1.up,&f1.down,&f2.up,&f2.down);
    node result;
    init(f1); init(f2);
    result.down=f1.down*f2.down;
    result.up=f1.up*f2.down+f2.up*f1.down;
    init(result);
    print(f1);printf(" + ");print(f2);printf(" = ");print(result);printf("\n");

    result.down=f1.down*f2.down;
    result.up=f1.up*f2.down-f2.up*f1.down;
    init(result);
    print(f1);printf(" - ");print(f2);printf(" = ");print(result);printf("\n");

    result.down=f1.down*f2.down;
    result.up=f1.up*f2.up;
    init(result);
    print(f1);printf(" * ");print(f2);printf(" = ");print(result);printf("\n");

    print(f1);printf(" / ");print(f2);printf(" = ");
    if (f2.up==0)
    {
    	printf("Inf");
    }else{
	    result.up=f1.up*f2.down;
	    result.down=f2.up*f1.down;
	    init(result);
	    print(result);
    }
    printf("\n");
	return 0;
}