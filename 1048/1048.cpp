#include<cstdio>
#include<algorithm>
using namespace std;
int coins[100010]={0};
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&coins[i]);	
	}
	sort(coins,coins+n);
	int i=0; int j=n-1;
	bool flag=true;
	while(i<j){
		if(coins[i]+coins[j]==m){
			flag=false;
			printf("%d %d\n",coins[i],coins[j]);
			break;
		}else if(coins[i]+coins[j]>m){
			j--;
		}else{
			i++;
		}
	}
	if (flag)
	{
		printf("No Solution\n");
	}
	return 0;
}