#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cstring>
#include<string>
#include<map>
#include<vector>
using namespace std;
struct node
{
	string school;
	int cnt,tws;
};
bool cmp(node a,node b)
{
	if (a.tws!=b.tws)
	{
		return a.tws>b.tws;
	}else if (a.cnt!=b.cnt)
	{
		return a.cnt<b.cnt;
	}else{
		return a.school<b.school;
	}
}
char id[7],school[7];
map<string,int> cnt;
map<string,double> score;
vector<node> v;
int main()
{
	int n;
	scanf("%d",&n);
	int grade;
	for (int i = 0; i < n; ++i)
	{
		scanf("%s%d%s",id,&grade,school);
		string str;
		for (int i = 0; i < strlen(school); ++i)
		{
			str+=tolower(school[i]);
		}
		cnt[str]++;
		if (id[0]=='A'){  score[str]+=grade; }
		if (id[0]=='B'){  score[str]+=grade/1.5; }
		if (id[0]=='T'){  score[str]+=grade*1.5; }
	}
	for(map<string,int>::iterator i=cnt.begin();i!=cnt.end();i++)
	{
		node temp;
		temp.school=i->first;
		temp.cnt=i->second;
		temp.tws=score[i->first];
		v.push_back(temp);
	}
	sort(v.begin(), v.end(),cmp);
	printf("%lu\n", v.size());
	int r=1;
	for (int i = 0; i < v.size(); ++i)
	{
		if (i>0&&v[i].tws!=v[i-1].tws)
		{
			r=i+1;
		}
		printf("%d %s %d %d\n",r,v[i].school.c_str(),v[i].tws,v[i].cnt);		
	}
	return 0;
}