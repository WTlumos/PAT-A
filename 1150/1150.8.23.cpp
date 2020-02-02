#define INF 0x7fffffff
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
const int MAXN=210;
 
int N,M,K,Nk;
int vex[MAXN][MAXN];
int mind=INF,minID=0;
int main()
{
    fill(vex[0],vex[0]+MAXN*MAXN,INF);
    int u,v,w;
    scanf("%d%d",&N,&M);
    for(int i=0;i<M;++i){
        scanf("%d%d%d",&u,&v,&w);
        vex[u][v]=vex[v][u]=w;
    }
    scanf("%d",&K);
    for(int i=1;i<=K;++i){
        bool vis[MAXN]={false},sim=true,cycle=true,na=false;
        scanf("%d%d",&Nk,&u);
        int td=0,S=u;
        for(int j=1;j<Nk;++j){
            scanf("%d",&v);
            if(vex[u][v]!=INF)
                td+=vex[u][v];
            else{
                na=true;
                cycle=false;
            }
            if(vis[v]) sim=false;
            vis[v]=true;
            u=v;
        }
        for(int j=1;j<=N;++j)
            if(vis[j]==false) cycle=false;
        if(S!=v || cycle==false){
            printf("Path %d: %s (Not a TS cycle)\n",i,na?"NA":to_string(td).c_str());
            continue;
        }
        if(sim)
            printf("Path %d: %s (TS simple cycle)\n",i,na?"NA":to_string(td).c_str());
        else
            printf("Path %d: %s (TS cycle)\n",i,na?"NA":to_string(td).c_str());
        if(mind>td){
            mind=td;
            minID=i;
        }
    }
    printf("Shortest Dist(%d) = %d\n",minID,mind);
    return 0;
}