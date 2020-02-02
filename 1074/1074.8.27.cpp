#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
map<int,int> adddress;
map<int,int> data;
map<int,int> nextAdddress;
vector<int> arr;
int main()
{
	int first,n,k;
	scanf("%d%d%d",&first,&n,&k);
	int a;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&a);
		adddress[a]=a;
		scanf("%d%d",&data[a],&nextAdddress[a]);
	}
	for (int i = first; i !=-1 ; i=nextAdddress[i])
	{
		arr.push_back(i);
	}
	int size=arr.size();
	for (int i = 0; i < size-size%k; i+=k)
	{
		reverse(arr.begin()+i,arr.begin()+i+k);
	}
	for (int i = 0; i < arr.size(); ++i)
	{
		if (i<arr.size()-1)
		{
			printf("%05d %d %05d\n",adddress[arr[i]],data[arr[i]],adddress[arr[i+1]]);
		}else{
			printf("%05d %d -1\n",adddress[arr[i]],data[arr[i]]);
		}
	}
	return 0;
}