#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100010;
int origin[maxn]={};
int temp[maxn]={};
int ans[maxn]={};
int main()
{
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&origin[i]);
		temp[i]=origin[i];
	}
	sort(origin,origin+n);
	int max=-1;
	int cnt=0;
	for (int i = 0; i < n; ++i)
	{
		if (origin[i]==temp[i]&&temp[i]>max)
		{
			ans[cnt++]=origin[i];	
		}
		if (temp[i]>max)
		{
			max=temp[i];
		}
	}
	printf("%d\n",cnt);
	for (int i = 0; i < cnt; ++i)
	{
        if(i!=0){
            printf(" ");
        }
		printf("%d",ans[i]);
	}
    printf("\n");
	return 0;
}