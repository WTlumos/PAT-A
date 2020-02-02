#include<cstdio>
bool isPrime(int n)
{
	for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}
int main()
{
	printf("%d\n",isPrime(1));
	return 0;
}