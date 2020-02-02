#include<cstdio>
#include<set>
using namespace std;
struct node
{
	int value,cnt;
	bool operator < (const node &a) const{
		if(cnt!=a.cnt){
			return cnt>a.cnt;
		}else{
			return value<a.value;
		}
	}
};
set<node> s;
int total[50010]={};
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int a;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&a);
		int cnt=0;
		if (i>0)
		{
			printf("%d:", a);
			for (set<node>::iterator t = s.begin(); t != s.end()&&cnt<k; ++t)
			{
				printf(" %d",t->value);
				cnt++;
			}
			printf("\n");
		}
		node temp;
		temp.value=a;
		temp.cnt=total[a];
		set<node>::iterator t=s.find(temp);
		if (t!=s.end())
		{
			s.erase(t);
		}
		total[a]++;
		temp.cnt=total[a];
		s.insert(temp);
	}
	return 0;
}