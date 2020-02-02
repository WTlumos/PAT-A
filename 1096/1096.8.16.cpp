#include <stdio.h>
#include <cmath>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int first = 0;
    int len = 0;
    int maxnum = sqrt(n);
    
    for(int i = 2; i<= maxnum;i ++)
    {
        int j = 0;
        int temp = 1;
        for(j = i;j<=maxnum;j++)
        {
            temp *= j;
            if(n % temp != 0)
                break;
        }
        if(j-i>len)
        {
            len = j-i;
            first=i;
        }
    }
    
    if(first == 0)
    {
        printf("1\n%d",n);
    }
    else{
        printf("%d\n",len);
        for(int i =0 ;i < len; i++)
        {
            if(i != 0)
            {
                printf("*");
            }
            printf("%d",first + i);
        }
    }
    printf("\n");
    return 0;
}