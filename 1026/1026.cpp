#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
struct node
{
	char time[10];
	int play,vip;
};
bool cmp(node a,node b)
{
	return strcmp(a.time,b.time)<0;
}
node club[10010];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s%d%d",club[i].time,&club[i].play,&club[i].vip);	
	}
	sort(club,club+n,cmp);
	int k,m;
	scanf("%d%d",&k,&m);
	return 0;
}