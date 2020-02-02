#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
const int maxn=100001;
const int sqrn=316;
char c[10];
stack<int> s;
int block[317]={0};
int table[maxn]={0};
void pushValue(int a){
	table[a]++;
	block[a/sqrn]++;
}
void popValue(int a)
{
	table[a]--;
	block[a/sqrn]--;
}
void peekmedian(int k)
{
	int sum=0;
	int index=0;
	while(sum+block[index]<k)
	{
		sum+=block[index++];
	}
	int num=index*sqrn;
	while(sum+table[num]<k){
		sum+=table[num++];
	}
	printf("%d\n",num);

}
int main()
{
	int n;
	scanf("%d",&n);
	int a;
	for (int i = 0; i < n; ++i)
	{
		scanf("%s",c);
		if (strcmp(c,"Push")==0)
		{
			scanf("%d",&a);
			s.push(a);
			pushValue(a);
		}else if(strcmp(c,"Pop")==0){
			if (s.empty())
			{
				printf("Invalid\n");
			}else{
				printf("%d\n",s.top());
				popValue(s.top());
				s.pop();
			}
		}else{
			int k=s.size();
			if(k%2==0){
				k/=2;
			}else{
				k=(k+1)/2;
			}
            if(s.empty()){
                printf("Invalid\n");
            }else{
			    peekmedian(k);
            }
		}
		
	}
	return 0;
}