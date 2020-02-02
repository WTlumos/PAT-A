#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
struct node{
	string name;
	int height;
}person[10010];
char str[10];
bool cmp(node a,node b)
{
	if(a.height!=b.height)
	{
		return a.height>b.height;
	}else{
		return a.name<b.name;
	}
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int height;
	node temp;
	for (int i = 0; i < n; ++i)
	{
		scanf("%s%d",str,&height);
		temp.name=str;
		temp.height=height;
		person[i]=temp;
	}
	sort(person,person+n,cmp);
	int row=0;
	int m=0;
	int t=0;
	while(row<k)
	{
		if (row==0)
		{
			m=n/k+n%k;
		}else{
			m=n/k;
		}
		string ans[m];
		ans[m/2]=person[t].name;
		int j=m/2-1;
		for (int i = t+1; i < t+m; i+=2)
		{
			ans[j--]=person[i].name;
		}
		j=m/2+1;
		for (int i = t+2; i < t+m; i+=2)
		{
			ans[j++]=person[i].name;
		}
		for (int i = 0; i < m; ++i)
		{
			if (i!=0)
			{
				printf(" ");
			}
			printf("%s",ans[i].c_str());
		}
		printf("\n");
		t+=m;
		row++;
	}

	return 0;
}