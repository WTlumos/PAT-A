#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
const int num=316;
char str[10];
stack<int> s;
int block[317]={};
int table[100010]={};
void push(int x){
	block[x/num]++;
	table[x]++;
}
void pop(int x){
	block[x/num]--;
	table[x]--;
}
void peekmedian(){
	int idx=0; int sum=0;
	int k=(1+(int)s.size())/2;
	while(sum+block[idx]<k){
		sum+=block[idx++];
	}
	int ans=idx*num;
	while(sum+table[ans]<k){
		sum+=table[ans++];
	}
	printf("%d\n", ans);
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
				pop(s.top());
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
			push(x);
		}
	}
	return 0;
}