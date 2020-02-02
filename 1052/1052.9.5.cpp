#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
map<int,int> address,data,nextaddress;
struct node
{
	int address,data;
};
vector<node> v;
bool cmp(node a,node b){
	return a.data<b.data;
}
int main()
{
	int n,first;
	scanf("%d%d",&n,&first);
	int a;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&a);
		address[a]=a;
		scanf("%d%d",&data[a],&nextaddress[a]);
	}
	for (int i = first; i !=-1 ; i=nextaddress[i])
	{
		node temp;
		temp.address=i;
		temp.data=data[i];
		v.push_back(temp);
	}
	if ((int)v.size()==0))
	{
		printf("0 -1\n");
		return 0;
	}
	sort(v.begin(),v.end(),cmp);
	printf("%lu %05d\n", v.size(),v[0].address);
	for (int i = 0; i < v.size(); ++i)
	{
		if (i<v.size()-1)
		{
			printf("%05d %d %05d\n", v[i].address,v[i].data,v[i+1].address);
		}else{
			printf("%05d %d -1\n", v[i].address,v[i].data);
		}
	}
	return 0;
}