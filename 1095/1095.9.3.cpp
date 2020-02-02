#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<map>
using namespace std;
struct node
{
	string number;
	int flag,time;
}car[10010];
char name[10],day[10],status[10];
bool cmp(node a,node b)
{
	if (a.number!=b.number)
	{
		return a.number<b.number;
	}else{
		return a.time<b.time;
	}
}
bool cmp2(node a,node b)
{
	return a.time<b.time;
}
vector<node> ans;
map<string,int> stay;
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	node temp;
	int h,m,s;
	for (int i = 0; i < n; ++i)
	{
		scanf("%s %d:%d:%d %s",name,&h,&m,&s,status);
		temp.number=name;
		temp.time=h*3600+m*60+s;
		if (strcmp(status,"in")==0)
		{
			temp.flag=1;
		}else if(strcmp(status,"out")==0){
			temp.flag=-1;
		}
		car[i]=temp;	
	}
	sort(car,car+n,cmp);
	int max=-1;
	for (int i = 0; i < n-1; ++i)
	{
		if (car[i].number==car[i+1].number&&car[i].flag==1&&car[i+1].flag==-1)
		{
			ans.push_back(car[i]);
			ans.push_back(car[i+1]);
			stay[car[i].number]+=car[i+1].time-car[i].time;
			if (stay[car[i].number]>max)
			{
				max=stay[car[i].number];
			}
			i++;
		}
	}
	sort(ans.begin(),ans.end(),cmp2);
	int cnt[n];
	cnt[0]=ans[0].flag;
	for (int i = 1; i < ans.size(); ++i)
	{
		cnt[i]=ans[i].flag+cnt[i-1];
	}
	int idx=0;
	for (int i = 0; i < k; ++i)
	{
		scanf("%d:%d:%d",&h,&m,&s);
		int nowtime=h*3600+m*60+s;
		int j=0;
		for (j = idx; j < ans.size(); ++j)
		{
			if (ans[j].time>nowtime)
			{
				printf("%d\n", cnt[j-1]);
				break;			
			}else if(j==ans.size()-1){
				printf("%d\n",cnt[j]);

			}
		}
		idx=j;
	}
	for (map<string,int>::iterator i = stay.begin(); i != stay.end(); ++i)
	{
		if (i->second==max)
		{
			printf("%s ",i->first.c_str());
		}
	}
	printf("%02d:%02d:%02d\n", max/3600,(int)(max/60%60),max%60);
	return 0;
}