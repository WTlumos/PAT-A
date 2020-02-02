#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100010;
struct node
{
	int address;
	int data;
	int next;
	int num;
	node(){
		num=2*maxn;
	}
}num[maxn];
int m[maxn]={};
bool cmp(node a,node b){
	return a.num<b.num;
}
int main()
{
	int first,n;
	scanf("%d%d",&first,&n);
	int a,k,e;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&a);
		num[a].address=a;
		scanf("%d%d",&num[a].data,&num[a].next);
	}
	int cnt1=0;
	int cnt2=0;

	for(int i=first;i!=-1;i=num[i].next)
	{
		if (m[abs(num[i].data)]==0)
		{
			num[i].num=cnt1++;
			m[abs(num[i].data)]++;	
		}else{
			num[i].num=cnt2+maxn;
			cnt2++;
		}
	}
	int cnt=cnt1+cnt2;
	sort(num,num+maxn,cmp);

	for (int i = 0; i < cnt; ++i)
	{
		if (i!=cnt1-1&&i!=cnt-1)
		{
			printf("%05d %d %05d\n", num[i].address,num[i].data,num[i+1].address);
		}else{
			printf("%05d %d -1\n", num[i].address,num[i].data);
		}
	}
	return 0;
}