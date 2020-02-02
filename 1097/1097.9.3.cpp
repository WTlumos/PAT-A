#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
map<int,int> address,data,nextAddress,exist;
vector<int> v,other;
int main()
{
	int first,n;
	scanf("%d%d",&first,&n);
	int a;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&a);
		address[a]=a;
		scanf("%d%d",&data[a],&nextAddress[a]);
	}
	for (int i = first; i != -1; i=nextAddress[i])
	{
		if (exist[abs(data[i])]==0)
		{
			v.push_back(i);
			exist[abs(data[i])]++;
		}else{
			other.push_back(i);
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
	for (int i = 0; i < other.size(); ++i)
	{
		if (i<other.size()-1)
		{
			printf("%05d %d %05d\n",address[other[i]],data[other[i]],address[other[i+1]]);
		}else{
			printf("%05d %d -1\n",address[other[i]],data[other[i]]);
		}
	}

	return 0;
}