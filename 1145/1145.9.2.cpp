#include<cstdio>
#include<cmath>
#include<map>
using namespace std;
map<int,int> hashtable;
bool isPrime(int x){
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
	int msize,n,m;
	scanf("%d%d%d",&msize,&n,&m);
	while(!isPrime(msize)){
		msize++;
	}
	int a;
	for (int i = 0; i < n; ++i)
	{
		int flag=0;
		scanf("%d",&a);
		for (int j = 0; j < msize; ++j)
		{
			int h=(a+j*j)%msize;
			if (hashtable[h]==0)
			{
				flag=1;
				hashtable[h]=a;
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
			int h=(a+j*j)%msize;
			if (hashtable[h]==a||hashtable[h]==0)
			{
				break;
			}
		}
	}
	printf("%.1f\n", 1.0*ans/m);
	return 0;
}