/*
1001 A+B Format (20 point(s))
Calculate a+b and output the sum in standard format -- that is, the digits must be separated into groups of three by commas (unless there are less than four digits).

Input Specification:
Each input file contains one test case. Each case contains a pair of integers a and b where −10^6≤a,b≤10^6. The numbers are separated by a space.

Output Specification:
For each test case, you should output the sum of a and b in one line. The sum must be written in the standard format.

Sample Input:
-1000000 9
Sample Output:
-999,991
*/
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	int sum=a+b;
	if(sum<0){
		printf("-");
		sum=-sum;
	}
	string str=to_string(sum);
	int cnt=1;
	string ans;
	for (int i = str.length()-1; i>=0; i--)
	{
		ans+=str[i];
		if(cnt%3==0&&i!=0){
			ans+=',';
		}
		cnt++;
	}
	reverse(ans.begin(), ans.end());
	printf("%s\n",ans.c_str());


	return 0;
}