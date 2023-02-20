#include <stdio.h>

#define ERR_NO 0

int my_pow(int, unsigned);

int main(void)
{
    int a;
    unsigned n;
    scanf("%d%u", &a, &n);

    printf("%d", my_pow(a, n));
}

int my_pow(int a, unsigned n)
{
    int result = 1;
    for (int i = 0; i < n; ++i)
    {
        result *= a;
    }

    return result;
}