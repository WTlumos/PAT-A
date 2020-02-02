#include<cstdio>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<cstring>
using namespace std;
struct node
{
	string id;
	int time;
	int status;
	node(string Id,int Time,int Status):id(Id),time(Time),status(Status){};
};
vector<node> recoded;
bool cmp1(node a,node b){
	if(a.id!=b.id){
		return a.id<b.id;
	}else{
		return a.time<b.time;
	}
}
bool cmp2(node a,node b)
{
	return a.time<b.time;
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	char c[10]; 
	char flag[4];
	int time=0;
	int status=0;
	int h,m,s;
	h=m=s=0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%s %d:%d:%d %s",c,&h,&m,&s,flag);
		time=h*3600+m*60+s;
		status=strcmp(flag,"in")==0?1:-1;
		recoded.push_back(node(c,time,status));
	}
	sort(recoded.begin(), recoded.end(),cmp1);
	vector<node> car;
	map<string,int> stay;
	int maxtime=-1;
	for (int i = 0; i < recoded.size()-1; ++i)
	{
		if (recoded[i].id==recoded[i+1].id&&recoded[i].status==1&&recoded[i+1].status==-1)
		{
			car.push_back(recoded[i]);
			car.push_back(recoded[i+1]);
			stay[recoded[i].id]+=recoded[i+1].time-recoded[i].time;
			if (stay[recoded[i].id]>maxtime)
			{
				maxtime=stay[recoded[i].id];
			}
		}
	}
	sort(car.begin(), car.end(),cmp2);
	int cnt[n];
	cnt[0]=car[0].status;
	for (int i = 1; i < car.size(); ++i)
	{
		cnt[i]=cnt[i-1]+car[i].status;
	}
	int index=0;
	for (int i = 0; i < k; ++i)
	{
		scanf("%d:%d:%d",&h,&m,&s);
		time=h*3600+m*60+s;
		int j;
		for (j = index; j < car.size(); ++j)
		{
			if (car[j].time>time)
			{
				printf("%d\n",cnt[j-1]);
				break;
			}else if(j==car.size()-1){
				printf("%d\n",cnt[j]);
			}
		}
		index=j;

	}
	for (map<string,int>::iterator i=stay.begin();i!=stay.end(); ++i)
	{
		if(i->second==maxtime){
			printf("%s ", i->first.c_str());
		}
	}
	printf("%02d:%02d:%02d\n",maxtime/3600,maxtime/60%60,maxtime%60);

	return 0;
}