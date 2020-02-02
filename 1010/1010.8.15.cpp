#include<cstdio>
#include<cstring>
long long getNum(char c[],long long radix)
{
	long long p=1l;
	int len=strlen(c);
	long long ans=0l;
	for (int i = len-1; i >=0; i--)
	{
		if(c[i]>='0'&&c[i]<='9'){
			ans+=(c[i]-'0')*p;
		}else if(c[i]>='a'&&c[i]<='z'){
			ans+=((c[i]-'a')+10)*p;
		}
		p=p*radix;	
	}
	return ans;
}
int getMax(char c[])
{
	int len=strlen(c);
	int index=-1;
	int num=0;
	for (int i = 0; i < len; ++i)
	{
		if(c[i]>='0'&&c[i]<='9'){
			num=c[i]-'0';
		}else if(c[i]>='a'&&c[i]<='z'){
			num=(c[i]-'a')+10;
		}
		if(num>index){
			index=num;
		}
		
	}
	return index;
}
void differTag(char c1[],char c2[],long long radix)
{
	long long n1,n2;
	int index;
	long long left,right,mid;
	long long ans;
	bool flag=true;

	n1=getNum(c1,radix);
	index=getMax(c2);
	left=index+1;
	right=n1+1;

	while(left<=right)
	{
		mid=(left+right)/2;
		ans=getNum(c2,mid);
		if (ans==n1)
		{
			flag=false;
			printf("%lld\n",mid);
			break;
		}else if (ans>n1||ans<0)
		{
			right=mid-1;
		}else{
			left=mid+1;
		}
	}
	if (flag)
	{
		printf("Impossible\n");
	}

}
int main()
{
	char c1[20],c2[20];
	int tag,radix;
	scanf("%s%s%d%d",c1,c2,&tag,&radix);
	if (tag!=1&&tag!=2)
	{
		printf("Impossible\n");
		return 0;
	}

	if (tag==1)
	{
		differTag(c1,c2,radix);
		
	}else if(tag==2){
		differTag(c2,c1,radix);

	}
	return 0;
}