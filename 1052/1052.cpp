#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=100010;
int address[maxn];
int data[maxn];
int nextAdd[maxn];
struct node
{
	int address,data,next;
	node(int Address,int Data,int Next){
		address=Address;
		data=Data;
		next=Next;
	}
	bool operator < (const node &a) const{
		return data<a.data;
	}
};
vector<node> v;
int main()
{
	int n,first;
	scanf("%d%d",&n,&first);
	int a,d,ne;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d%d",&a,&d,&ne);
		address[a]=a;
		data[a]=d;
		nextAdd[a]=ne;
	}
	int cnt=0;
	for (int i = first; i!=-1 ; i=nextAdd[i])
	{
		cnt++;
		v.push_back(node(i,data[i],nextAdd[i]));	
	}
	sort(v.begin(), v.end());
    printf("%d %05d\n",cnt,v[0].address);
	for (int i = 0; i < v.size()-1; ++i)
	{
		printf("%05d %d %05d\n",v[i].address,v[i].data,v[i+1].address);
	}
	printf("%05d %d -1\n",v[cnt-1].address,v[cnt-1].data);
	return 0;
}