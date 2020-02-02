#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int num[100]={};
bool isPrime(int x){
	if (x<2)
	{
		return false;
	}
	int sqr=sqrt(1.0*x);
	for (int i = 2; i <= sqr; ++i)
	{
		if (x%i==0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int n,d;
	while(true){
		scanf("%d",&n);
		if (n<0)
		{
			break;
		}
		scanf("%d",&d);
		int sum1=n;
		int idx=0;
		do{
			num[idx++]=n%d;
			n/=d;
		}while(n!=0);
		int sum=0;
		for (int i = 0; i < idx; ++i)
		{
			sum=sum*d+num[i];
		}
		if (isPrime(sum1)&&isPrime(sum))
		{
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}

	return 0;
}