#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
struct node{
	int value,cnt;
	bool operator < (const node &a) const{
		if(cnt!=a.cnt){
			return cnt>a.cnt;
		}else{
			return value<a.value;
		}
	}
};
int calcnt[50010]={};
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int a;
	set<node> s;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a);
		int cnt=0;
		if(i>0)
		{
			printf("%d:",a);
			for (set<node>::iterator it=s.begin(); it!= s.end() && cnt<k; ++it)
			{
				printf(" %d",it->value);
				cnt++;
			}
			printf("\n");
		}
		node temp;
		temp.value=a; temp.cnt=calcnt[a];
		set<node>::iterator it=s.find(temp);
		if (it!=s.end())
		{
			s.erase(it);
		}
		calcnt[a]++;
		temp.cnt=calcnt[a];
		s.insert(temp);
	}
	return 0;
}