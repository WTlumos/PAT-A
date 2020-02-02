#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
map<int,int> address,data,nextaddress;
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
		scanf("%d%d",&data[a],&nextaddress[a]);
	}
	int cnt=0;
	for (int i = first; i != -1; i=nextaddress[i])
	{
		cnt++;
		v.push_back(i);
	}
	for (int i = 0; i <cnt-cnt%k ; i+=k)
	{
		reverse(v.begin()+i,v.begin()+i+k);
	}
    for (int i = 0; i < cnt; ++i)
    {
    	if (i<cnt-1)
    	{
    		printf("%05d %d %05d\n",address[v[i]],data[v[i]],address[v[i+1]]);
    	}else{
    		printf("%05d %d -1\n",address[v[i]],data[v[i]]);
    	}
    }
	return 0;
}