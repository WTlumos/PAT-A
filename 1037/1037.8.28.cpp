#include<cstdio>
#include<algorithm>
using namespace std;
int coupons[100010]={};
int products[100010]={};
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	int nc;
	scanf("%d",&nc);
	for (int i = 0; i < nc; ++i)
	{
		scanf("%d",&coupons[i]);
	}
	int np;
	scanf("%d",&np);
	for (int i = 0; i < np; ++i)
	{
		scanf("%d",&products[i]);
	}
	sort(coupons,coupons+nc,cmp);
	sort(products,products+np,cmp);
	int i=0; int j=0; int temp;
	int sum=0;
	while(i<nc&&j<np&&coupons[i]>0&&products[j]>0){

		temp=coupons[i]*products[j];
		sum+=temp;	
		i++; j++;
	}
    i=nc-1;  j=np-1;
    while(i>=0&&j>=0&&coupons[i]<0&&products[j]<0){

		temp=coupons[i]*products[j];
		sum+=temp;	
		i--; j--;
	}
	printf("%d\n",sum);
	return 0;
}