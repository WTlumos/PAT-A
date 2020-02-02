/*
首先这一题第二行给的每个老鼠的体重，而这里并没有说老鼠和程序员是怎样对应的，
我原来以为是按照程序员上场的时间先后老鼠重量和程序员一一对应，后来发现老鼠重量直接就是和程序员编号一一对应的。。。。

然后是第三行，题目中说第三行描述了程序员出场的顺序，题目中并没有说是怎样描述的，
我原来以为是第i个数据表示第i个程序员第几个出场，结果第I个数据表示的是第i个出场的是第几个程序员，
这里的数据和程序员对应的方式和第一组数据不一样，我也是醉了

知道题目意思之后就简单了，使用一个队列记录当前参与比赛的选手，然后每隔Ng个取一组，
取里面最重的老鼠作为这一组的胜利者，剩下的程序员的rank为当前回合胜利者的数量加一
*/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
    int weight, index, rank, index0;
};
bool cmp1(node a, node b) {
    return a.index0 < b.index0;
}
int main() {
    int n, g, num;
    scanf("%d%d", &n, &g);
    vector<int> v(n);
    vector<node> w(n);
    for(int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    for(int i = 0; i < n; i++) {
        scanf("%d", &num);
        w[i].weight = v[num];
        w[i].index = i;
        w[i].index0 = num;
    }
    queue<node> q;
    for(int i = 0; i < n; i++)
        q.push(w[i]);
    while(!q.empty()) {
        int size = q.size();
        if(size == 1) {
            node temp = q.front();
            w[temp.index].rank = 1;
            break;
        }
        int group = size / g;
        if(size % g != 0)
            group += 1;
        node maxnode;
        int maxn = -1, cnt = 0;
        for(int i = 0; i < size; i++) {
            node temp = q.front();
            w[temp.index].rank = group + 1;
            q.pop();
            cnt++;
            if(temp.weight > maxn) {
                maxn = temp.weight;
                maxnode = temp;
            }
            if(cnt == g || i == size - 1) {
                cnt = 0;
                maxn = -1;
                q.push(maxnode);
            }
        }
    }
    sort(w.begin(), w.end(), cmp1);
    for(int i = 0; i < n; i++) {
        if(i != 0) printf(" ");
        printf("%d", w[i].rank);
    }
    return 0;
}