#include<cstdio>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
map<int,int> estate,area,cnt;
set<int> family;
int father[100000]={};
void init()
{
	for (int i = 0; i < 100000; ++i)
	{
		father[i]=i;
	}
}
int findFather(int x)
{
	int a=x;
	while(x!=father[x]){
		x=father[x];
	}
	while(a!=father[a]){
		int z=a;
		a=father[a];
		father[z]=x;
	}
	return x;
}
void together(int a,int b){
	int fatherA=findFather(a);
	int fatherB=findFather(b);
	if (fatherA!=fatherB)
	{
		father[fatherA]=fatherB;
	}
}
struct node{
	int id,count,father;
	double area,estate;
};
bool cmp1(node a,node b){
	if (a.father!=b.father){
		return a.father<b.father;
	}
	else{
		return a.id<b.id;
	}
}
bool cmp(node a,node b){

	if (a.area!=b.area)
	{
		return a.area>b.area;
	}else{
		return a.id<b.id;
	}
}
vector<node> v;
int main()
{
	init();
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int id;
		scanf("%d",&id);
		family.insert(id);
		int fa,mo;
		scanf("%d%d",&fa,&mo);
		if (fa!=-1)
		{
			together(id,fa);
			family.insert(fa);
		}
		if (mo!=-1)
		{
			together(id,mo);
			family.insert(mo);
		}
		int k;
		scanf("%d",&k);
		int child;
		for (int i = 0; i < k; ++i)
		{
			scanf("%d",&child);
			together(id,child);
			family.insert(child);
		}
		scanf("%d%d",&estate[id],&area[id]);
	}
	for (set<int>::iterator i = family.begin(); i != family.end(); ++i)
	{
		cnt[findFather(*i)]++;
		if (findFather(*i)==*i)
		{
			continue;
		}
		estate[findFather(*i)]+=estate[*i];
		area[findFather(*i)]+=area[*i];
	}
	for (set<int>::iterator i = family.begin(); i != family.end(); ++i)
	{
		node temp;
		temp.id=*i;
		temp.count=cnt[findFather(*i)];
		temp.estate=estate[findFather(*i)]*1.0/cnt[findFather(*i)];
		temp.area=area[findFather(*i)]*1.0/cnt[findFather(*i)];
		temp.father=findFather(*i);
		v.push_back(temp);
	}
	sort(v.begin(),v.end(),cmp1);
	// for (int i = 0; i < v.size(); ++i)
	// {
	// 	printf("%d %d\n", v[i].id,v[i].father);
	// }
	vector<node> ans;
	int first=0;
	for (int i = 1; i < v.size(); ++i)
	{
		if (v[i].father!=v[first].father)
		{
			ans.push_back(v[first]);
			first=i;
		}	
	}
	ans.push_back(v[first]);
	sort(ans.begin(),ans.end(),cmp);
    printf("%lu\n",ans.size());
    for (int i = 0; i < ans.size(); ++i)
    {
    	printf("%04d %d %.3f %.3f\n", ans[i].id,ans[i].count,ans[i].estate,ans[i].area);
    }
	return 0;
}