#include<cstdio>
#include<map>
#include<string>
#include<set>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
map<string,int> online;
map<string,int> mid;
map<string,int> final;
set<string> s;
struct node{
	string id;
	int score[4];
};
bool cmp(node a,node b){
	if (a.score[3]!=b.score[3])
	{
		return a.score[3]>b.score[3];
	}else{
		return a.id<b.id;
	}
}
vector<node> v;
int main()
{
	int p,m,n;
	scanf("%d%d%d",&p,&m,&n);
	char name[21]; int grade; string str;
	for (int i = 0; i < p; ++i)
	{
		scanf("%s%d",name,&grade);
		str=name;
		online[str]=grade+1;
		s.insert(str);
	}
	for (int i = 0; i < m; ++i)
	{
		scanf("%s%d",name,&grade);
		str=name;
		mid[str]=grade+1;
		s.insert(str);
	}
	for (int i = 0; i < n; ++i)
	{
		scanf("%s%d",name,&grade);
		str=name;
		final[str]=grade+1;
		s.insert(str);
	}
	node temp; double gfinal; int g;
	for (set<string>::iterator i=s.begin(); i!=s.end(); ++i)
	{
		if(mid[*i]>final[*i]){
			gfinal=(mid[*i]-1)*0.4+(final[*i]-1)*0.6;
		}else{
			gfinal=(final[*i]-1);
		}
		g=round(gfinal);
		if ((online[*i]-1)>=200&&g<=100&&g>=60)
		{
			temp.id=*i;
			temp.score[0]=online[*i];
			temp.score[1]=mid[*i];
			temp.score[2]=final[*i];
			temp.score[3]=g+1;
			v.push_back(temp);
		}	
	}
	sort(v.begin(), v.end(),cmp);
	for (int i = 0; i < v.size(); ++i)
	{
		printf("%s",v[i].id.c_str());
		for (int j = 0; j < 4; ++j)
		{
			if (v[i].score[j]==0)
			{
				printf(" -1");
			}else{
				printf(" %d",v[i].score[j]-1);
			}
		}
		printf("\n");
	}
	return 0;
}