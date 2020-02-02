#include<cstdio>
#include<cmath>
#include<cstring>
bool isPrime(int n)
{
	for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}
int main()
{
	int msize,n,m;
	scanf("%d%d%d",&msize,&n,&m);
	while(!isPrime(msize))
	{
		msize++;
	}
	int table[msize];
	memset(table,0,sizeof(table));
    int a;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&a);
		int flag=0; 
		for (int j = 0; j < msize; ++j)
		{
			int pos=(a+j*j)%msize;
			if (table[pos]==0)
			{
				table[pos]=a;
				flag=1;
				break;
			}
		}
		if (flag==0)
		{
			printf("%d cannot be inserted.\n",a);
		}
	}
	int ans=0;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d",&a);
		for (int j = 0; j <= msize; ++j)
		{
			ans++;
			int pos=(a+j*j)%msize;
			if (table[pos]==a||table[pos]==0)
			{
				break;
			}
		}	
	}
	printf("%.1f\n",ans*1.0/m);
	return 0;
}