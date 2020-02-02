#include<cstdio>
#include<stack>
#include<cstring>
#define lowbits(i) ((i)&(-i))
using namespace std;
const int maxn=100010;
int c[maxn]={};
stack<int> s;
void update(int x,int v)
{
	for (int i = x; i <maxn; i+=lowbits(i))
	{
		c[i]+=v;
	}
}
int getsum(int x)
{
	int sum=0;
	for (int i = x; i > 0 ; i-=lowbits(i))
	{
		sum+=c[i];
	}
	return sum;
}
void peekMedian()
{
	int left=1; 
	int right=maxn; 
	int k=(1+s.size())/2;
	while(left<right){
		int mid=(left+right)/2;
		if (getsum(mid)>=k)
		{
			right=mid;
		}else{
			left=mid+1;
		}
	}
	printf("%d\n",left);
}
int main()
{
	int n,x;
	scanf("%d",&n);
	char c[11];
	for (int i = 0; i < n; ++i)
	{
		//printf("%d\n",i);
		scanf("%s",c);
		if (strcmp(c,"Pop")==0)
		{
			if (s.empty())
			{
				printf("Invalid\n");
			}else{
				x=s.top();
				update(x,-1);
				printf("%d\n",x);
				s.pop();
			}
		}else if(strcmp(c,"PeekMedian")==0){
			if (s.empty())
			{
				printf("Invalid\n");
			}else{
				peekMedian();
			}
		}else{
			scanf("%d",&x);
			//printf("%d\n",x);
			s.push(x);
			update(x,1);
		}
	}
	return 0;
}