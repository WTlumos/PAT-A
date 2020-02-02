#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
map<int,int> address;
map<int,int> data;
map<int,int> nextAddress;
map<int,int> exist;
vector<int> ans;
vector<int> reply;
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
	for(int i=first;i!=-1;i=nextAddress[i])
	{
		if(exist[abs(data[i])]==0){
			ans.push_back(i);
			exist[abs(data[i])]++;
		}else{
			reply.push_back(i);
		}
	}
	for (int i = 0; i < ans.size(); ++i)
	{
		if (i<ans.size()-1)
		{
			printf("%05d %d %05d\n",address[ans[i]],data[ans[i]],address[ans[i+1]]);
		}else{
			printf("%05d %d -1\n",address[ans[i]],data[ans[i]]);
		}
	}
	for (int i = 0; i < reply.size(); ++i)
	{
		if (i<reply.size()-1)
		{
			printf("%05d %d %05d\n",address[reply[i]],data[reply[i]],address[reply[i+1]]);
		}else{
			printf("%05d %d -1\n",address[reply[i]],data[reply[i]]);
		}
	}
	return 0;
}