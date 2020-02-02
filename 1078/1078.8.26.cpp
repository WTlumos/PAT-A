#include<cstdio>
#include<cmath>
#include<map>
using namespace std;
int num[10010];
map<int,int> hashmap;
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
	int msize,n;
	scanf("%d%d",&msize,&n);
	while(!isPrime(msize)){
		msize++;
	}
	int cnt=0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&num[i]);
		int flag=0;
		for (int j = 0; j < msize; ++j)
		{
			int h=(num[i]+j*j)%msize;
			if (hashmap[h]==0)
			{
				flag=1;
				if (cnt==0)
				{
					printf("%d",h);
					cnt++;
				}else{
					printf(" %d",h);
				}
				hashmap[h]++;
				break;
			}
		}
		if (flag==0)
		{
			if (cnt==0)
			{
				printf("-");
				cnt++;
			}else{
				printf(" -");
			}
		}
	}
	printf("\n");
	return 0;
}