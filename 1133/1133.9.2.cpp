#include<cstdio>
#include<map>
#include<vector>
using namespace std;
map<int,int> address,data,nextAddress;
vector<int> v;
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
	for (int i = first; i != -1; i=nextAddress[i])
	{
		if (data[i]<0)
		{
			v.push_back(i);
		}	
	}
	for (int i = first; i != -1; i=nextAddress[i])
	{
		if (data[i]>=0&&data[i]<=k)
		{
			v.push_back(i);
		}	
	}
	for (int i = first; i != -1; i=nextAddress[i])
	{
		if (data[i]>k)
		{
			v.push_back(i);
		}	
	}
	for (int i = 0; i < v.size(); ++i)
	{
		if (i<v.size()-1)
		{
			printf("%05d %d %05d\n",address[v[i]],data[v[i]],address[v[i+1]]);
		}else{
			printf("%05d %d -1\n",address[v[i]],data[v[i]]);
		}
	}
	return 0;
}