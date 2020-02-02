#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
struct node
{
	char card[20];
	int score;
};
bool cmp(node a,node b)
{
	if(a.card[0]!=b.card[0]){
		return a.card[0]<b.card[0];
	}else if(a.score!=b.score){
		return a.score>b.score;
	}else{
		return strcmp(a.card,b.card)<0;
	}
}
struct byear
{
	int site,cnt;
	byear(int Site,int Cnt){
		site=Site;
		cnt=Cnt;
	}
};
bool cmpyear(byear a,byear b)
{
	if (a.cnt!=b.cnt)
	{
		return a.cnt>b.cnt;
	}else{
		return a.site<b.site;
	}
}
vector<node> v;
map<int,int> site;
map<int,int> siteCnt;
void dealLevel(char ans[])
{
	int flag=0;
	for (int i = 0; i < v.size(); ++i)
	{
		if(v[i].card[0]==ans[0]){
			flag=1;
			printf("%s %d\n",v[i].card,v[i].score);
		}
	}
	if (flag==0)
	{
		printf("NA\n");
	}
}
void dealsite(char ans[])
{
	int num=0;
	for (int i = 0; i < strlen(ans); ++i)
	{
		num=num*10+ans[i]-'0';
	}
	if (siteCnt[num]>0)
	{
		printf("%d %d\n",siteCnt[num],site[num]);
	}else{
		printf("NA\n");
	}
}
void dealyear(char ans[])
{
	char year[7]; 
	map<int,int> getCnt; 
	vector<byear> vyear;
	for (int i = 0; i < v.size(); ++i)
	{
		//180908
		for (int j = 4; j < 10; ++j)
		{
			year[j-4]=v[i].card[j];
		}
		//printf("%s\n",year);
		if(strcmp(year,ans)==0){
			int sites=0;
			for (int j = 1; j < 4; ++j)
			{
				sites=sites*10+v[i].card[j]-'0';
			}
			//printf("%d\n",sites);
			getCnt[sites]++;		
		}		
	}
	for (map<int,int>::iterator i=getCnt.begin(); i!=getCnt.end(); ++i)
	{
		vyear.push_back(byear(i->first,i->second));
	}
	sort(vyear.begin(),vyear.end(),cmpyear);
	int flag=0;
	for (int i = 0; i < vyear.size(); ++i)
	{
		flag=1;
		printf("%d %d\n",vyear[i].site,vyear[i].cnt);
	}
	if (flag==0)
	{
		printf("NA\n");
	}
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	node temp;
	for (int i = 0; i < n; ++i)
	{
		scanf("%s%d",temp.card,&temp.score);
         v.push_back(temp);

         //get site 123
         int getSite=0;
         for (int i = 1; i < 4; ++i)
         {
         	getSite=getSite*10+temp.card[i]-'0';       	
         }
         site[getSite]+=temp.score;
         siteCnt[getSite]++;
	}
    sort(v.begin(), v.end(),cmp);
	char ans[8]; int index;
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d %s",&index,ans);
		printf("Case %d: %d %s\n",i,index,ans);
		if (index==1)
		{
			dealLevel(ans);
		}else if(index==2){
			dealsite(ans);
		}else if(index==3){
			dealyear(ans);
		}else{
			printf("NA\n");
		}
	}
	return 0;
}