#include<cstdio>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
const int maxn=100000;
map<int,int> contact;
vector<int> v[maxn];
struct node
{
	int a,b;
	node(int A,int B){a=A; b=B;}
};
bool cmp(node a,node b){
	if (a.a!=b.a)
	{
		return a.a<b.a;
	}else{
		return a.b<b.b;
	}
}
vector<node> ans;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	char ca[7],cb[7];
	string stra,strb;
	int a,b;
	//0000 -0000 int无法记录
	for (int i = 0; i < m; ++i)
	{
		scanf("%s%s",ca,cb);
		stra=ca;
		strb=cb;
		a=abs(atoi(stra.c_str()));
		b=abs(atoi(strb.c_str()));
		if (stra.length()==strb.length())
		{
			v[a].push_back(b);
			v[b].push_back(a);
		}
		contact[a*maxn+b]=contact[b*maxn+a]=1;
	}
	int k;
	scanf("%d",&k);
	while(k--){
		ans.clear();
		scanf("%s%s",ca,cb);
		stra=ca;
		strb=cb;
		a=abs(atoi(stra.c_str()));
		b=abs(atoi(strb.c_str()));
		for (int i = 0; i < v[a].size(); ++i)
		{
			for (int j = 0; j < v[b].size(); ++j)
			{
				if (v[a][i]==b||v[b][j]==a)
				{
					continue;
				}
				if (contact[v[a][i]*maxn+v[b][j]]==1)
				{
					ans.push_back(node(v[a][i],v[b][j]));
				}
			}
		}
		sort(ans.begin(), ans.end(),cmp);
		printf("%lu\n",ans.size());
		for (int i = 0; i < ans.size(); ++i)
		{
			printf("%04d %04d\n",ans[i].a,ans[i].b);
		}
	}
	return 0;
}