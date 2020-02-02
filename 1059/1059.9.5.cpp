#include<cstdio>
const int maxn=100010;
int prime[maxn]={};
bool visit[maxn]={false};
int idx=0;
void init()
{
	for (int i = 2; i < maxn; ++i)
	{
		if (visit[i]==false)
		{
			prime[idx++]=i;
			//printf("%d\n", i);
			for (int j = i+i; j < maxn; j+=i)
			{
				visit[j]=true;
			}
		}
	}
}
int main()
{
	init();
	long long n;
	scanf("%lld",&n);
	if (n==0)
	{
		printf("0=0\n");
		return 0;
	}
	if (n==1)
	{
		printf("1=1\n");
		return 0;
	}
	printf("%lld=",n);
	int key=0;
	for (int i = 0; i < idx; ++i)
	{
		int flag=0; int cnt=0;
		while(n%prime[i]==0){
			flag=1;
			cnt++;
			n/=prime[i];
		}
		if (flag==1)
		{
			if (key>0)
			{
				printf("*");
			}else{
				key++;
			}
			printf("%d",prime[i]);
			if (cnt>1)
			{
				printf("^%d",cnt);
			}
		}
		if (n==0)
		{
			break;
		}
	}
	printf("\n");
	return 0;
}