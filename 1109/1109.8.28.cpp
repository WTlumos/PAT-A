#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
struct node
{
	char name[10];
	int height;
}people[10010];
bool cmp(node a,node b)
{
	if(a.height!=b.height){
		return a.height>b.height;
	}else{
		return strcmp(a.name,b.name)<0;
	}
}
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    node temp;
    for (int i = 0; i < n; ++i)
    {
    	scanf("%s%d",temp.name,&temp.height);
    	people[i]=temp;
    }
    sort(people,people+n,cmp);
    int row=0;
    int t=0;
    int num=0;
    while(row<k){
    	if (row==0)
    	{
    		num=n/k+n%k;
    	}else{
    		num=n/k;
    	}
    	node v[num];
    	v[num/2]=people[t];
    	int j=num/2-1;
    	for (int i = t+1; i <t+num ; i+=2)
    	{
    		v[j--]=people[i];
    	}
    	j=num/2+1;
    	for (int i = t+2; i < t+num; i+=2)
    	{
    		v[j++]=people[i];
    	}
    	for (int i = 0; i < num; ++i)
    	{
    		if (i!=0)
    		{
    			printf(" ");
    		}
    		printf("%s",v[i].name);
    	}
    	printf("\n");
    	t=t+num;
    	row++;
    }
	return 0;
}