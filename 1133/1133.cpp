#include<cstdio>
#include<vector>
#include<map>
using namespace std;
const int maxn=100000;
struct node
{
	int address,data,next;
	node(int Address,int Data,int Next){
		address=Address;
		data=Data;
		next=Next;
	}
};
vector<node> v;
map<int,int> address;
map<int,int> data;
map<int,int> nextAddress;
int main()
{
	int first,n,k;
	scanf("%d%d%d",&first,&n,&k);
	int a;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&a);
		address[a]=a;
		scanf("%d%d",&data[a],&nextAddress[a]);
	}
	for (int i = first; i !=-1 ; i=nextAddress[i])
	{
		if (data[i]<0)
		{
			v.push_back(node(i,data[i],nextAddress[i]));
		}
	}
	for (int i = first; i !=-1 ; i=nextAddress[i])
	{
		if (data[i]>=0&&data[i]<=k)
		{
			v.push_back(node(i,data[i],nextAddress[i]));
		}
	}
	for (int i = first; i !=-1 ; i=nextAddress[i])
	{
		if (data[i]>k)
		{
			v.push_back(node(i,data[i],nextAddress[i]));
		}
	}
	for (int i = 0; i < v.size(); ++i)
	{
		if(i<v.size()-1){
			printf("%05d %d %05d\n",v[i].address,v[i].data,v[i+1].address);
		}else{
			printf("%05d %d -1\n",v[i].address,v[i].data);
		}
	}
	return 0;
}