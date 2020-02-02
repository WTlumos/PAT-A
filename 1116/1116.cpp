#include<cstdio>
#include<map>
#include<cmath>
using namespace std;
map<int,int> contestants;
map<int,int> checked;
bool isPrime(int x){
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
int main()
{
	int n;
	scanf("%d",&n);
	int a;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d",&a);
		contestants[a]=i;
	}
	int k;
	scanf("%d",&k);
	for (int i = 0; i < k; ++i)
	{
		scanf("%d",&a);
		printf("%04d: ",a);
		if (contestants[a]==0)
		{
			printf("Are you kidding?\n");
		}
		else if(checked[a]>0){
			printf("Checked\n");
		}
		else if (contestants[a]==1)
		{
			printf("Mystery Award\n");
		}else if(isPrime(contestants[a])){
			printf("Minion\n");
		}else{
			printf("Chocolate\n");
		}
		checked[a]++;
	}
	return 0;
}