#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int c;
struct node
{
	int id,grade;
	string name;
	node(){}
	node(int Id,string Name,int Grade){
		id=Id;
		name=Name;
		grade=Grade;
	}
};
bool cmp1(node a,node b)
{
	return a.id<b.id;
}
bool cmp2(node a,node b)
{
	if(a.name!=b.name){
		return a.name<b.name;
	}else{
		return a.id<b.id;
	}
}
bool cmp3(node a,node b)
{
	if(a.grade!=b.grade){
		return a.grade<b.grade;
	}else{
		return a.id<b.id;
	}
}
node record[100010];
int main()
{
	int n;
	scanf("%d%d",&n,&c);
	int id,grade; string name;
	char ch[10];
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%s%d",&id,ch,&grade);
		name=ch;
		record[i]=node(id,name,grade);	
	}
	if (c==1)
	{
		sort(record,record+n,cmp1);
	}else if(c==2){
		sort(record,record+n,cmp2);
	}else if(c==3){
		sort(record,record+n,cmp3);
	}
	for (int i = 0; i < n; ++i)
	{
		printf("%06d %s %d\n",record[i].id,record[i].name.c_str(),record[i].grade);
	}
	return 0;
}