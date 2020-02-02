/*
给定n个加油站,给出每个加油站的加油的价格,与原点的距离,并且给出汽车油箱的容量,
以及每升汽油能跑多远,问能否到达给定的终点, 如果不能, 输出汽车最多能跑多远
1> 如果能找到,就可以直接跳到那一个站点

       (1)如果此时油箱里的油足够, 就不需要加油了

       (2)如果不够,然后冲恰好到那一点的油

2>如果找不到,判断能不能由这个点直接到达终点

       (1)如果能,那么冲上到终点的油量就可以了

       (2)如果不能,先看能否到下一站点,如果不能,GG,如果可以则转移到下一站点.
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int inf = 99999999;
struct station {
    double price, dis;
};
bool cmp1(station a, station b) {
    return a.dis < b.dis;
}
int main() {
    double cmax, d, davg;
    int n;
    scanf("%lf%lf%lf%d", &cmax, &d, &davg, &n);
    vector<station> sta(n + 1);
    sta[0] = {0.0, d};
    for(int i = 1; i <= n; i++)
        scanf("%lf%lf", &sta[i].price, &sta[i].dis);
    sort(sta.begin(), sta.end(), cmp1);
    double nowdis = 0.0, maxdis = 0.0, nowprice = 0.0, totalPrice = 0.0, leftdis = 0.0;
    if(sta[0].dis != 0) {
    	//初始位置0处必须有加油站，要不然没油可加
        printf("The maximum travel distance = 0.00");
        return 0;
    } else {
        nowprice = sta[0].price;
    }
    while(nowdis < d) {
        maxdis = nowdis + cmax * davg;
        double minPriceDis = 0, minPrice = inf;
        int flag = 0;
        for(int i = 1; i <= n && sta[i].dis <= maxdis; i++) {
            if(sta[i].dis <= nowdis) continue;
            if(sta[i].price < nowprice) {
                totalPrice += (sta[i].dis - nowdis - leftdis) * nowprice / davg;
                leftdis = 0.0;
                nowprice = sta[i].price;
                nowdis = sta[i].dis;
                flag = 1;
                break;
            }
            if(sta[i].price < minPrice) {
                minPrice = sta[i].price;
                minPriceDis = sta[i].dis;
            }
        }
        if(flag == 0 && minPrice != inf) {
            totalPrice += (nowprice * (cmax - leftdis / davg));
            leftdis = cmax * davg - (minPriceDis - nowdis);
            nowprice = minPrice;
            nowdis = minPriceDis;     
        }
        if(flag == 0 && minPrice == inf) {
            nowdis += cmax * davg;
            printf("The maximum travel distance = %.2f", nowdis);
            return 0;
        }
    }
    printf("%.2f", totalPrice);
    return 0;
}