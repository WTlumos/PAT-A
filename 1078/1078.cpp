#include<cstdio>
#include<vector>
#include<map>
#include<cmath>
using namespace std;
bool isPrime(int x)
{
	if(x<2)
		return false;
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
map<int,int> hashMap;
int main()
{
	int m,n;
	scanf("%d%d",&m,&n);
	while(!isPrime(m))
	{
		m++;
	}
	int a,h;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&a);
		bool flag=true;
		if (i!=0)
		{
			printf(" ");
		}
		for (int j = 0; j < m; ++j)
		{
			h=(a+j*j)%m;
			if (hashMap[h]==0)
			{
				printf("%d",h);
				flag=false;
				hashMap[h]++;
				break;
			}
		}
		if (flag)
		{
			printf("-");
		}
	}

	return 0;
}