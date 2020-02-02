/*
分析：1.用数组arr标记两个人是否是朋友（邻接矩阵表示），用v标记所有人的同性朋友（邻接表表示）
2.对于一对想要在一起的A和B，他们需要先找A的所有同性朋友C，再找B的所有同性朋友D，当C和D两人是朋友的时候则可以输出C和D
3.A在寻找同性朋友时，需要避免找到他想要的伴侣B，所以当当前朋友就是B或者B的同性朋友就是A时舍弃该结果
4.输出时候要以4位数的方式输出，所以要%04d
5.如果用int接收一对朋友，-0000和0000对于int来说都是0，将无法得知这个人的性别，也就会影响他找他的同性朋友的那个步骤，所以考虑用字符串接收，因为题目中已经表示会以符号位加四位的方式给出输入，所以只要判断字符串是否大小相等，如果大小相等说明这两个人是同性
6.结果数组因为必须按照第一个人的编号从小到大排序（当第一个相等时按照第二个人编号的从小到大排序），所以要用sort对ans数组排序后再输出结果
*/
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
using namespace std;
const int maxn=10000;
vector<int> v[maxn];
map<int,int> match;
struct node 
{
	int first,second;
	node(int First,int Second)
	{
		first=First;
		second=Second;
	}
};
bool cmp(node a,node b){
	if (a.first!=b.first)
	{
		return a.first<b.first;
	}else{
		return a.second<b.second;
	}
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int a,b;
    for (int i = 0; i < m; ++i)
    {
    	char c1[6],c2[6];
    	scanf("%s%s",c1,c2);
    	string str1=c1;
    	string str2=c2;
    	a=atoi(str1.c_str()); b=atoi(str2.c_str());
    	//printf("%d %d\n",a,b);
    	if (str1.length()==str2.length())
    	{
    		v[abs(a)].push_back(abs(b));
    		v[abs(b)].push_back(abs(a));	
    	}
    	match[maxn*abs(a)+abs(b)]=match[maxn*abs(b)+abs(a)]=1;	
    }
    int k;
    scanf("%d",&k);
    while(k--)
    {
    	scanf("%d%d",&a,&b);
    	vector<node> ans;
    	for (int i = 0; i < v[abs(a)].size(); ++i)
    	{
    		for (int j = 0; j < v[abs(b)].size(); ++j)
    		{
    			if (v[abs(a)][i]==abs(b)||v[abs(b)][j]==abs(a))
    			{
    				continue;
    			}
    			if (match[v[abs(a)][i]*maxn+v[abs(b)][j]]==1)
    			{
    				ans.push_back(node(v[abs(a)][i],v[abs(b)][j]));
    			}
    		}
    	}
    	printf("%lu\n",ans.size());
    	sort(ans.begin(), ans.end(),cmp);
    	for (int i = 0; i < ans.size(); ++i)
    	{
    		printf("%04d %04d\n",ans[i].first,ans[i].second); 		
    	}
    }
	return 0;
}