#include<cstdio>
const int maxn=200010;
long long s1[maxn]={};
long long s2[maxn]={};
int n1,n2;
long long median()
{
	int l1=0; int h1=n1-1; int mid1=0;
	int l2=0; int h2=n2-1; int mid2=0;
	while(l1!=h1||l2!=h2){
		mid1=(l1+h1)/2;
		mid2=(l2+h2)/2;
		if(s1[mid1]<s2[mid2]){
			//个数为奇数，舍弃A，B中间点以前的部分保留中间点
			if ((l1+h1)%2==0)
			{
				l1=mid1;
				h2=mid2;
			}else{
				l1=mid1+1;
				h2=mid2;
			}
		}else if(s1[mid1]>s2[mid2]){
			if((l2+h2)%2==0){
				h1=mid1;
				l2=mid2;
			}else{
				h1=mid1;
				l2=mid2+1;
			}
		}else{
			return s1[mid1];
		}
	}
	return s1[l1]>s2[l2]?s2[l2]:s1[l1];
}
int main()
{
	scanf("%d",&n1);
	for (int i = 0; i < n1; ++i)
	{
		scanf("%lld",&s1[i]);
	}
	scanf("%d",&n2);
	for (int i = 0; i < n2; ++i)
	{
		scanf("%lld",&s2[i]);
	}
	printf("%lld\n",median());

	return 0;
}