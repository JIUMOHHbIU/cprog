#include <stdio.h>

#define ERR_NO 0
#define ERR_INPUT 1

long long int my_pow(long long int, long long int);

int main(void)
{
    long long int a;
    long long int n;
    int rc = ERR_NO;

    if ((scanf("%lld%lld", &a, &n) != 2) || (n < 0))
    {
        rc = ERR_INPUT;
    }

    if (rc == ERR_NO)
    {
        printf("%lld", my_pow(a, n));
    }

    return rc;
}

long long int my_pow(long long int a, long long int n)
{
    long long int result = 1;
    for (long long int i = 0; i < n; ++i)
    {
        result *= a;
    }

    return result;
}
