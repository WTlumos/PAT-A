#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
vector<int> result;
vector<int> temp;
int main()
{
    int n;
    scanf("%d",&n);
    v.resize(n);
    temp.resize(n);
    result.resize(n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&v[i]);
        temp[i]=v[i];
    }
    sort(v.begin(),v.end());
    int max = 0; int cnt = 0;
    for(int i=0;i<n;i++)
    {
        if(v[i]==temp[i]&&temp[i]>max)
        {
            result[cnt++] = v[i];
        }
        if (temp[i] > max)
            max = temp[i];
    }
    printf("%d\n",cnt);
    for(int i=0;i<cnt;i++)
    {
        if(i!=0)
            printf(" ");
        printf("%d",result[i]);
    }
    printf("\n");
    return 0;
}