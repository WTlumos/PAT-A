#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
struct node{
	string id;
	int grade;
};
bool cmp(node a,node b){
	if (a.grade!=b.grade)
	{
		return a.grade>b.grade;
	}else if(a.id[0]!=b.id[0]){
		return a.id[0]<b.id[0];
	}else{
		return a.id<b.id;
	}
}
struct node2
{
	string id;
	int cnt;
	node2(string Id,int Cnt){
		id=Id; cnt=Cnt;
	}
};
bool cmp1(node2 a,node2 b){
	if(a.cnt!=b.cnt){
		return a.cnt>b.cnt;
	}else{
		return a.id<a.id;
	}
}
vector<node> stu;
map<string,int> site,sitecnt; 
char c[1000];
int n;
void dealyear(string str)
{
	vector<node2> datevector;
	map<string,int> datesite;
	int flag=0;
	for (int j = 0; j < n; ++j)
	{
		if (stu[j].id.substr(4,6)==str)
		{
			string csite=stu[j].id.substr(1,3);
			datesite[csite]++;
		}
	}
	for (map<string,int>::iterator t = datesite.begin(); t != datesite.end(); ++t)
	{
		datevector.push_back(node2(t->first,t->second));
	}
	sort(datevector.begin(), datevector.end(),cmp1);
	for (int j = 0; j < datevector.size(); ++j)
	{
		flag=1;
		printf("%s %d\n",datevector[j].id.c_str(),datevector[j].cnt);
	}
	if(flag==0){
		printf("NA\n");
	}
}
int main()
{
	int m;
	scanf("%d%d",&n,&m);
	node temp;
	string str;
	for (int i = 0; i < n; ++i)
	{
		scanf("%s%d",c,&temp.grade);
		str=c;
		temp.id=str;
		//B123180908127
		string classroom=str.substr(1,3);
		site[classroom]+=temp.grade;
		sitecnt[classroom]++;

		stu.push_back(temp);
	}
	sort(stu.begin(), stu.end(),cmp);
	int a;
	for(int i=1;i<=m;i++){
		scanf("%d%s",&a,c);
		printf("Case %d: %d %s\n",i,a,c);
		str=c;
		if (a==1)
		{
			int flag=0;
			for (int j = 0; j < n; ++j)
			{
				if (stu[j].id[0]==c[0])
				{
					flag=1;
					printf("%s %d\n",stu[j].id.c_str(),stu[j].grade);
				}
			}
			if(flag==0){
				printf("NA\n");
			}
		}else if (a==2)
		{
			if (sitecnt[c]>0)
			{
				printf("%d %d\n",sitecnt[c],site[c]);
			}else{
				printf("NA\n");
			}
			
		}else if (a==3){
			dealyear(str);	
		}else{
			printf("NA\n");
		}
	}
	return 0;
}