#include<cstdio>
#include<map>
#include<cmath>
using namespace std;
map<int,int> people,exist;
bool isprime(int x)
{
	if(x<2){
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
	int n;
	scanf("%d",&n);
	int id;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d",&id);
		people[id]=i;
	}
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&id);
		printf("%04d: ", id);
		if (people[id]==0)
		{
			printf("Are you kidding?\n");
		}else if(exist[id]>0){
			printf("Checked\n");
		}else if(people[id]==1){
			printf("Mystery Award\n");
		}else if (isprime(people[id]))
		{
			printf("Minion\n");
		}else{
			printf("Chocolate\n");
		}
		exist[id]++;

	}
	return 0;
}