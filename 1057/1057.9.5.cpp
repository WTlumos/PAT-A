#include<cstdio>
#include<stack>
#include<cstring>
#define lowbits(i) ((i)&(-i))
using namespace std;
const int maxn=100010;
char str[10];
int c[maxn]={};
stack<int> s;
void update(int x,int num){
	for (int i = x; i < maxn; i+=lowbits(i))
	{
		c[i]+=num;
	}
}
int getsum(int x){
	int sum=0;
	for (int i = x; i > 0 ; i-=lowbits(i))
	{
		sum+=c[i];
	}
	return sum;
}
void peekmedian(){
	int left=1; int right=maxn; int k=(1+(int)s.size())/2;
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
	int n;
	scanf("%d",&n);
	int x;
	for (int i = 0; i < n; ++i)
	{
		scanf("%s",str);
		if (strcmp(str,"Pop")==0)
		{
			if (s.empty())
			{
				printf("Invalid\n");
			}else{
				printf("%d\n",s.top());
				update(s.top(),-1);
				s.pop();
			}
		}else if(strcmp(str,"PeekMedian")==0){
			if (s.empty())
			{
				printf("Invalid\n");
			}else{
				peekmedian();
			}
		}else{
			scanf("%d",&x);
			s.push(x);
			update(x,1);
		}

	}

	return 0;
}