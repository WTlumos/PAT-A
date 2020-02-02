#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
struct node{
    int uid,total=0,num=0,rank=0;
    bool shown = false;
    vector<int> s;
    bool operator < (const node &a) const{
        if(total!=a.total)
        {
            return total>a.total;
        }else if(num != a.num)
        {
            return num>a.num;
        }else{
            return uid<a.uid;
        }
    }
};
set<int> s;
int main()
{
    int m,n,k,id,pid,grade;
    scanf("%d %d %d",&n,&m,&k);
    vector<int> score(m+1,0);
    vector<node> v(n+1);
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&score[i]);
    }
    for(int i = 0;i<k;i++)
    {
        scanf("%d %d %d",&id,&pid,&grade);
        s.insert(id);
        v[id].uid = id;
        v[id].s.resize(m+1,-100);
        if(grade == -1)
        {
            grade = 0;
        }else{
            v[id].shown = true;
        }
        if(v[id].s[pid] < grade){
            v[id].s[pid] = grade;
        }
    }
    for(auto i = s.begin();i!=s.end();i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(v[*i].s[j] == score[j])
            {
                v[*i].num++;
            }
            if(v[*i].s[j]>=0)
            {
                v[*i].total+=v[*i].s[j];
            }
        }
    }
    sort(v.begin()+1, v.end());
    for(int i = 1;i<=n;i++)
    {
        if(v[i].shown){
            if(i==1){
                v[i].rank=1;
            }else if(v[i].total == v[i-1].total){
                v[i].rank = v[i-1].rank;
            }else{
                v[i].rank=i;
            }
            printf("%d %05d %d ",v[i].rank,v[i].uid,v[i].total);
            for(int j=1;j<=m;j++)
            {
                if(j!=1)
                    printf(" ");
                if(v[i].s[j]<0){
                    printf("-");
                }else{
                    printf("%d",v[i].s[j]);
                }
            }
            printf("\n");
            }
        }
    return 0;
} 