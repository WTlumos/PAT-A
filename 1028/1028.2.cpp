#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node
{
	int id,grade;
	char name[10];
};
int n,c;
bool cmp()
{
	if(c==1){
		return a.id<b.id;
	}else if(c==2){
		if(strcmp(a.name,b.name)!=0){
			return strcmp(a.name,b.name)<0;
		}else{
			return a.id<b.id;
		}
	}else{
		if(a.grade!=b.grade){
			return a.grade<b.grade;
		}else{
			return a.id<b.id;
		}
	}
}
node recode[100010];
int main()
{
	scanf("%d%d",&n,&c);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%s%d",&recode[i].id,recode[i].name,&recode[i].grade);
	}
	sort(recode,recode+n,cmp);
	for (int i = 0; i < n; ++i)
	{
		printf("%06d %s %d\n",recode[i].id,recode[i].name,recode[i].grade);
	}
	return 0;
}