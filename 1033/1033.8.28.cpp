#include<cstdio>
#include<algorithm>
using namespace std;
const int Inf=312312312;
struct node
{
	double price,distance;
}v[510];
bool cmp(node a,node b){
	return a.distance<b.distance;
}
int main()
{
	int cmax,d,davg,n;
	scanf("%d%d%d%d",&cmax,&d,&davg,&n);
	node temp;
	temp.price=0; temp.distance=d;
	v[0]=temp;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%lf%lf",&temp.price,&temp.distance);
		v[i]=temp;
	}
	sort(v,v+n+1,cmp);

	double nowprice=0; 
	double nowdis=0; double maxdis=0; double totalPrice=0; 
	double leftdis=0;
    if(v[0].distance != 0) {
        printf("The maximum travel distance = 0.00\n");
        return 0;
    } else {
        nowprice = v[0].price;
    }
    while(nowdis < d) {
        maxdis = nowdis + cmax * davg;
        double minPriceDis = 0, minPrice = Inf;
        int flag = 0;
		for (int i = 1; i <= n&&v[i].distance<=maxdis; ++i)
		{
			if(v[i].distance <= nowdis) continue;
            if(v[i].price < nowprice) {
                totalPrice += (v[i].distance - nowdis - leftdis) * nowprice / davg;
                leftdis = 0.0;
                nowprice = v[i].price;
                nowdis = v[i].distance;
                flag = 1;
                break;
            }
            if(v[i].price < minPrice) {
                minPrice = v[i].price;
                minPriceDis = v[i].distance;
            }
        }
        if(flag == 0 && minPrice != Inf) {
            totalPrice += (nowprice * (cmax - leftdis / davg));
            leftdis = cmax * davg - (minPriceDis - nowdis);
            nowprice = minPrice;
            nowdis = minPriceDis;     
        }
        if(flag == 0 && minPrice == Inf) {
            nowdis += cmax * davg;
            printf("The maximum travel distance = %.2f\n", nowdis);
            return 0;
        }
    }
    printf("%.2f\n", totalPrice);
    return 0;
}