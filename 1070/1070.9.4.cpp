#include<cstdio>
#include<algorithm>
using namespace std;
struct node
{
	double amount,price,single;
	bool operator < (const node &a) const{
		return single>a.single;
	}
}v[1100];
int main()
{
	int n,d;
	scanf("%d%d",&n,&d);
	for (int i = 0; i < n; ++i)
	{
		scanf("%lf",&v[i].amount);
	}
	for (int i = 0; i < n; ++i)
	{
		scanf("%lf",&v[i].price);
		v[i].single=v[i].price/v[i].amount;
	}
	sort(v,v+n);
	double ans=0;
	for (int i = 0; i < n; ++i)
	{
		if (v[i].amount<d)
		{
			d-=v[i].amount;
			ans+=v[i].price;
		}else{
			ans+=v[i].single*d;
			break;
		}
		
	}
	printf("%.2f\n",ans);
	return 0;
}