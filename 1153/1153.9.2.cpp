#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
char str[20]; int n;
map<int,int> cnt;
map<int,int> score;
struct node
{
	char id[14];
	int grade;
}stu[10010];
bool cmp(node a,node b){
	if(a.id[0]!=b.id[0]){
		return a.id[0]<b.id[0];
	}
	else if (a.grade!=b.grade)
	{
		return a.grade>b.grade;
	}else{
		return strcmp(a.id,b.id)<0;
	}
}
struct node2
{
	int site,cnt;
};
bool cmp2(node2 a,node2 b){
	if (a.cnt!=b.cnt)
	{
		return a.cnt>b.cnt;
	}else{
		return a.site<b.site;
	}
}
void dealevel(char c)
{
	int count=0;
	for (int i = 0; i < n; ++i)
	{
		if (stu[i].id[0]==c)
		{
			printf("%s %d\n",stu[i].id,stu[i].grade);
			count++;
		}
	}
	if (count==0)
	{
		printf("NA\n");
	}
}
void dealsite(char c[])
{
	int temp=0;
	for (int i = 1; i < 4; ++i)
	{
		temp=temp*10+c[i]-'0';
	}
	if (cnt[temp]!=0)
	{
		printf("%d %d\n",cnt[temp],score[temp]);
	}else{
		printf("NA\n");
	}
}
void dealyear(char c[])
{
	map<int,int> sites;
	vector<node2> vTemp;
	int year=0; int flag=0;
	for (int j = 0; j < 6; ++j)
	{
		year=year*10+c[j]-'0';
	}
	for (int i = 0; i < n; ++i)
	{
		int id=0; 
		for (int j = 4; j < 10; ++j)
		{
			id=id*10+stu[i].id[j]-'0';
		}
		//printf("%s %s\n",id.c_str(),year.c_str());
		if (id==year)
		{
			flag=1;
			int ans=0;
			for (int j = 1; j < 4; ++j)
			{
				ans=ans*10+stu[i].id[j]-'0';
			}
			sites[ans]++;
		}
	}
	if (flag==0)
	{
		printf("NA\n");
	}else{
		node2 temp;
		for (map<int,int>::iterator i = sites.begin(); i != sites.end(); ++i)
		{
			temp.site=i->first;
			temp.cnt=i->second;
			vTemp.push_back(temp);
		}
		sort(vTemp.begin(),vTemp.end(),cmp2);
		for (int i = 0; i < vTemp.size(); ++i)
		{
			printf("%d %d\n",vTemp[i].site,vTemp[i].cnt);
		}
	}
}
int main()
{
	int m;
	scanf("%d%d",&n,&m);
	node temp; 
	for (int i = 0; i < n; ++i)
	{
		scanf("%s%d",temp.id,&temp.grade);
		stu[i]=temp;
		int site=0;
		for (int j = 1; j < 4; ++j)
		{
			site=site*10+temp.id[j]-'0';
		}
		//printf("%s\n",site.c_str());
		cnt[site]++;
		score[site]+=temp.grade;
	}
	sort(stu,stu+n,cmp);
	int idx;
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d%s",&idx,str);
		printf("Case %d: %d %s\n",i,idx,str);
		if (idx==1)
		{
			dealevel(str[0]);
		}else if (idx==2)
		{
			dealsite(str);
		}else if (idx==3)
		{
			dealyear(str);
		}else{
			printf("NA\n");
		}

	}

	return 0;
}