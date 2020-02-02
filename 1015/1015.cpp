#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
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
	while(scanf("%d",&n)!=EOF){
		if(n<0)
			break;
		scanf("%d",&d);
		if (!isPrime(n))
		{
			printf("No\n");
			continue;
		}
		int num[100];
		int ans=0;
		int index=0;
		do
		{
			num[index++]=n%d;
			n/=d;
		}while(n);
		for (int i = 0;i<index;i++)
		{
			ans=ans*d+num[i];
		}
		if(isPrime(ans)){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}

	return 0;
}