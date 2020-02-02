#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
bool isPrime(int a){
	if(a<2){
		return false;
	}
	int sqr=sqrt(1.0*a);
	for (int i = 2; i <= sqr; ++i)
	{
		if(a%i==0){
			return false;
		}
	}
	return true;
}
int main()
{
	int n,d;
	char c[100];
	while(scanf("%s%d",c,&d)!=EOF){
		int len=strlen(c);
		reverse(c,c+len);
		int p=1;
		for (int i = len-1; i >=0 ; i--)
		{
			n+=(c[i]-'0')*p;
			p=p*d;
		}
		if(isPrime(n)){
			printf("Yes\n");
		}eles{
			printf("No\n");
		}
	}



	return 0;
}