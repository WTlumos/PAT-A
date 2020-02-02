#include<cstdio>
#include<string>
using namespace std;
int num[20]={};
string ge[]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
string shi[]={"","Shi","Bai","Qian","Wan","Shi","Bai","Qian","Yi"};
int main(){
	int n;
	scanf("%d",&n);

	if (n<0)
	{
		printf("Fu ");
		n=-n;
	}else if(n==0){
		printf("ling\n");
		return 0;
	}
	int idx=0;
    do{
    	num[idx++]=n%10;
    	n/=10;
    }while(n!=0);
    
    //008001
    int pos=0;
    while(num[pos]==0&&pos<idx){
    	pos++;
    }
    //printf("%d\n",pos);
    string ans[20];
    int t=0;
    for (int i = pos; i < idx; ++i)
    {
    	if (i!=0&&(num[i]!=0||i==4||i==8))
    	{
    		ans[t++]=shi[i];
    	}
    	ans[t++]=ge[num[i]];
    }
    for (int i = t-1; i >=0 ; i--)
    {
    	int cnt=0;
    	while(ans[i]=="ling"&&i>=0){
    		i--;
    		cnt++;
    	}
    	if (cnt>0&&ans[i]!="Wan")
    	{
    		printf("ling ");
    	}
    	printf("%s",ans[i].c_str());
    	if (i>0)
    	{
    		printf(" ");
    	}else{
    		printf("\n");
    	}
    }

	return 0;
}