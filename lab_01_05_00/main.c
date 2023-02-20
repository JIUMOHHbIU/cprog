#include <stdio.h>

#define ERR_NO 0
#define ERR_INPUT 1

int my_pow(int, unsigned);

int main(void)
{
    int a;
    unsigned n;
    char tmp;
    int rc = ERR_NO;

    if ((((rc = scanf("%d%u%c", &a, &n, &tmp)) != 2 && rc != EOF) || tmp != '\n'))
    {
        rc = ERR_INPUT;
    }

    if (rc == ERR_NO)
    {
        printf("%d", my_pow(a, n));
    }

    return rc;
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
