#include<cstdio>
#include<algorithm>
using namespace std;
int coupon[100010]={};
int product[100010]={};
int main()
{
	int nc;
	scanf("%d",&nc);
	for (int i = 0; i < nc; ++i)
	{
		scanf("%d",&coupon[i]);
	}
	int np;
	scanf("%d",&np);
	for (int i = 0; i < np; ++i)
	{
		scanf("%d",&product[i]);
	}
	sort(coupon,coupon+nc);
	sort(product,product+np);
	int i=0;int j=0;
	int ans=0;
	while(i<nc&&j<np&&coupon[i]<0&&product[j]<0){
       ans+=coupon[i]*product[j];
       i++;
       j++;
	}
    i=nc-1; j=np-1;
	while(i>=0&&j>=0&&coupon[i]>0&&product[j]>0){
       ans+=coupon[i]*product[j];
       i--;
       j--;
	}
	printf("%d\n",ans);
	return 0;
}