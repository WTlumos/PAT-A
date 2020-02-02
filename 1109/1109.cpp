#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
struct node
{
	char name[10];
	int height;
};
bool cmp(node a,node b)
{
	if(a.height!=b.height){
		return a.height>b.height;
	}else{
		return strcmp(a.name,b.name)<0;
	}
}
vector<node> group;
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	node temp;
	for (int i = 0; i < n; ++i)
	{
		scanf("%s%d",temp.name,&temp.height);
		group.push_back(temp);	
	}
	sort(group.begin(), group.end(),cmp);
	int t=0;
	int rows=0;
	int number=0;
	while(rows<k){
		if (rows==0)
		{
			number=n/k+n%k;
		}else{
			number=n/k;
		}
		char ans[number+1][10];
		strcpy(ans[number/2],group[t].name);
		int j=number/2-1;
		for (int i = t + 1; i < t + number; i = i + 2)
		{
			strcpy(ans[j--],group[i].name);
		}
		j=number/2+1;
		for (int i = t + 2; i < t + number; i = i + 2)
		{
			strcpy(ans[j++],group[i].name);
		}
		printf("%s",ans[0]);
		for (int i = 1; i < number; ++i)
		{
			printf(" %s", ans[i]);
		}
		printf("\n");
		t = t + number;
		rows++;
	}
	return 0;
}