#include<cstdio>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
set<int> s;
map<int,int> estate,area;
const int maxn=10000;
int father[maxn]={};
map<int,int> totale,totala;
void init(){
	for (int i = 1; i < maxn; ++i)
	{
		father[i]=i;
	}
}
int findFather(int x)
{
	int a=x;
	while(x!=father[x])
	{
		x=father[x];
	}
	while(a!=father[a])
	{
		int z=a;
		a=father[a];
		father[z]=x;
	}
	return x;
}
void together(int a,int b)
{
	int fatherA=findFather(a);
	int fatherB=findFather(b);
	if (fatherA!=fatherB)
	{
		father[fatherA]=fatherB;
	}
}
struct node
{
	int children,root;
	node(int Children,int Root){
		children=Children;
		root=Root;
	}
};
bool cmp(node a,node b)
{
	if (a.root!=b.root)
	{
		return a.root<b.root;
	}else{
		return a.children<b.children;
	}
}
struct family
{
	int smallest,total;
	double avesate,avarea;
};
bool cmp1(family a,family b)
{
	if (a.avarea!=b.avarea)
	{
		return a.avarea>b.avarea;
	}else{
		return a.smallest<b.smallest;
	}
}
int main()
{
	init();
	int n;
	scanf("%d",&n);
	int id,fa,mo,k,child,mestate,marea;
	while(n--)
	{
		scanf("%d%d%d%d",&id,&fa,&mo,&k);
		s.insert(id);
		if (fa!=-1)
		{
			s.insert(fa);
			together(id,fa);
		}
		if (mo!=-1)
		{
			s.insert(mo);
			together(id,mo);
		}
		for (int i = 0; i < k; ++i)
		{
			scanf("%d",&child);
			s.insert(child);
			together(id,child);
		}
		scanf("%d%d",&mestate,&marea);
	    estate[id]+=mestate;
	    area[id]+=marea;	
	}
	vector<node> v;
	for (set<int>::iterator i=s.begin();i!= s.end();i++){
		id=*i;
		totale[findFather(id)]+=estate[id];
		totala[findFather(id)]+=area[id];
		v.push_back(node(id,findFather(id)));
	}
	sort(v.begin(), v.end(),cmp);
	int small=v[0].children;
	int cnt=1;
	vector<family> ans;
	family temp;
	for (int i = 1; i < v.size(); ++i)
	{
		if (v[i].root==v[i-1].root)
		{
			cnt++;
		}
		else{
			temp.smallest=small;
			temp.total=cnt;
			temp.avesate=1.0*totale[v[i-1].root]/cnt;
			temp.avarea=1.0*totala[v[i-1].root]/cnt;
			ans.push_back(temp);
			cnt=1;
			small=v[i].children;
		}
		if (i==v.size()-1)
		{
			temp.smallest=small;
			temp.total=cnt;
			temp.avesate=1.0*totale[v[i].root]/cnt;
			temp.avarea=1.0*totala[v[i].root]/cnt;
			ans.push_back(temp);
		}
	}
	sort(ans.begin(), ans.end(),cmp1);
	printf("%lu\n",ans.size());
	for (int i = 0; i < ans.size(); ++i)
	{
		printf("%04d %d %.3f %.3f\n",ans[i].smallest,ans[i].total,ans[i].avesate,ans[i].avarea);
	}
	return 0;
}