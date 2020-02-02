#include<cstdio>
const int maxn=100010;
int prime[maxn]={};
bool visit[maxn]={false};
int cnt=0;
void init()
{
	for (int i = 2; i < maxn; ++i)
	{
		if (visit[i]==false)
		{
			prime[cnt++]=i;
		}
		for (int j = 2*i; j < maxn; j=j+i)
		{
			visit[j]=true;
		}
	}
}
int main()
{
	long long n;
	scanf("%lld",&n);
	printf("%lld=",n);
	if(n==1)
    {
        printf("1");
        return 0;
    }
    init();
    int key=0;
    int i=0;
    for(int i=0;i<cnt;i++)
   {
    	int cnt=0; int flag=0;
    	while (n%prime[i]==0)
    	{
    		//printf("%d",prime[i]);
    		flag=1;
    		n=n/prime[i];
    		cnt++;
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
	return 0;
}