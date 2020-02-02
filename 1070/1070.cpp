#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct node
{
	double amount,price,unit;
	node(double Amount)
	{
		amount=Amount;
	}
};
bool cmp(node a,node b)
{
	return a.unit>b.unit;
}
int main()
{
	int n,d;
	scanf("%d%d",&n,&d);
	double a;
	vector<node> v;
	for (int i = 0; i < n; ++i)
	{
		scanf("%lf",&a);
		v.push_back(node(a));
	}
	for (int i = 0; i < n; ++i)
	{
		scanf("%lf",&v[i].price);
		v[i].unit=v[i].price/v[i].amount;
	}
	sort(v.begin(), v.end(),cmp);
	double ans=0;
	for (int i = 0; i < n; ++i)
	{
		if (v[i].amount<d)
		{
			d-=v[i].amount;
			ans+=v[i].price;
		}else{
			ans+=v[i].unit*d;
			break;
		}
	}
	printf("%.2f\n",ans );
	return 0;
}