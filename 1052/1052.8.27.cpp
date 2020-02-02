#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
	int address,data,nextaddress;
};
map<int,int> address,data,nextaddress;
vector<node> v;
bool cmp(node a,node b)
{
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
    int cnt=0;
	for (int i = first; i != -1 ; i=nextaddress[i])
	{
        cnt++;
		node temp;
		temp.address=address[i];
		temp.data=data[i];
		temp.nextaddress=nextaddress[i];
		v.push_back(temp);
	}
    if(cnt==0){
    	//测试点4 错误原因
        printf("0 -1");
    }else{
		sort(v.begin(),v.end(),cmp);
		printf("%d %05d\n",(int)v.size(),v[0].address);
		for (int i = 0; i < v.size(); ++i)
		{
			if (i<v.size()-1)
			{
				printf("%05d %d %05d\n",v[i].address,v[i].data,v[i+1].address);
			}else{
				printf("%05d %d -1\n",v[i].address,v[i].data);
			}
		}
    }
	return 0;
}