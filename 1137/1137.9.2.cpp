#include<cstdio>
#include<map>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
char str[30];
map<string,int> online,midterm,final;
set<string> student;
struct node{
   string id;
   int score[4];
};
vector<node> ans;
bool cmp(node a,node b){
	if (a.score[3]!=b.score[3])
	{
		return a.score[3]>b.score[3];
	}else{
		return a.id<b.id;
	}
}
int main()
{
	int p,m,n;
	scanf("%d%d%d",&p,&m,&n);
	int score; string id;
	for (int i = 0; i < p; ++i)
	{
		scanf("%s%d",str,&score);
		id=str;
		online[id]+=score+1;
		student.insert(id);
	}
	for (int i = 0; i < m; ++i)
	{
		scanf("%s%d",str,&score);
		id=str;
		midterm[id]+=score+1;
		student.insert(id);
	}
	for (int i = 0; i < n; ++i)
	{
		scanf("%s%d",str,&score);
		id=str;
		final[id]+=score+1;
		student.insert(id);
	}
	for (set<string>::iterator i = student.begin(); i != student.end(); ++i)
	{
		int total=0;
		node temp;
		temp.id=*i;
		temp.score[0]=online[*i];
		temp.score[1]=midterm[*i];
		temp.score[2]=final[*i];
		if (midterm[*i]>final[*i])
		{
			total=round((midterm[*i]-1)*0.4+(final[*i]-1)*0.6)+1;
		}else{
			total=final[*i];
		}
		temp.score[3]=total;
		if (online[*i]>=201&&total>=61&&total<=100)
		{
			ans.push_back(temp);
		}
	}
	sort(ans.begin(), ans.end(),cmp);
	for (int i = 0; i < ans.size(); ++i)
	{
		printf("%s", ans[i].id.c_str());
		for (int j = 0; j < 4; ++j)
		{
			if (ans[i].score[j]==0)
			{
				printf(" -1");
			}else{
				printf(" %d",ans[i].score[j]-1);
			}
		}
		printf("\n");
	}
	return 0;
}