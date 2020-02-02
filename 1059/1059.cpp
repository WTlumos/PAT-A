#include<cstdio>
#include<cmath>
const int maxn=100000;
int prime[maxn]={0};
bool p[maxn]={false};
int index=0;
void getPrime(){
	for (int i = 2; i < maxn; ++i)
	{
		if (!p[i])
		{
			prime[index++]=i;
		}
		for (int j = i+i; j < maxn; j=j+i)
		{
			p[j]=true;
		}		
	}	
}
int main()
{
	long long n;
	scanf("%lld",&n);
	printf("%lld=",n);
	getPrime();
	if (n==1)
	{
		printf("1");
		return 0;
	}
	int state=false;
	for (int i = 0; i < index; ++i)
	{
		//printf("%d\n", prime[i]);
		int cnt=0;
		int flag=0;
		while(n%prime[i]==0){
			flag=1;
			cnt++;
			n=n/prime[i];
		}
		if (flag>0)
		{
			if(state){
				printf("*");
			}
			printf("%d",prime[i]);
			state=true;
			if (cnt>1)
			{
				printf("^%d",cnt);
			}
		}
	}
	return 0;
}