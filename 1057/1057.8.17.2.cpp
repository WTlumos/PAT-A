#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
const int maxn=316;
stack<int> s;
int block[317]={};
int table[100010]={};
void update(int x)
{
	block[x/maxn]++;
	table[x]++;
}
void pop(int x)
{
	block[x/maxn]--;
	table[x]--;
	printf("%d\n",x);
}
void peekMedian()
{
	int k=s.size();
	if (k%2==1)
	{
		k=(k+1)/2;
	}else{
		k=k/2;
	}
	int num=0;
	int sum=0;
	int idx=0;
	while(sum+block[idx]<k){
		sum+=block[idx++];
	}
	num=idx*maxn;
	while(sum+table[num]<k){
		sum+=table[num++];
	}
	printf("%d\n",num);
}
int main()
{
	int n;
	scanf("%d",&n);
	char c[11];
	int x;
	for (int i = 0; i < n; ++i)
	{
		scanf("%s",c);
		if (strcmp(c,"Push")==0)
		{
			scanf("%d",&x);
			s.push(x);
			update(x);
			
		}else if (strcmp(c,"Pop")==0){
			if (s.empty())
			{
				printf("Invalid\n");
			}else{
				pop(s.top());
				s.pop();
			}
		}else{
			if (s.empty())
			{
				printf("Invalid\n");
			}else{
				peekMedian();
			}
		}
	}
	return 0;
}