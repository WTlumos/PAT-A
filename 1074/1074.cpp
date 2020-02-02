#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
map<int,int> address;
map<int,int> data;
map<int,int> nextAddress;
vector<int> v;
int main()
{
	int first,n,k;
	scanf("%d%d%d",&first,&n,&k);
	int address;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&address);
		scanf("%d%d",&data[address],&nextAddress[address]);
	}
	for(int i=first;i!=-1;i=nextAddress[i])
	{
		v.push_back(i);
	}
	int len=v.size();
	for (int i = 0; i < len-len%k; i=i+k)
	{
		reverse(v.begin()+i, v.begin()+i+k);
	}
	for (int i = 0; i < len-1; ++i)
	{
		printf("%05d %d %05d\n", v[i],data[v[i]],v[i+1]);
	}
	printf("%05d %d -1\n",v[len-1],data[v[len-1]]);

	return 0;
}