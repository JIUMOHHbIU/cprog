#include <stdio.h>

#define ERR_NO 0
#define ERR_INPUT 1

int my_pow(int, unsigned);

int input_values(int *number, unsigned int *n);

int main(void)
{
    int a;
    unsigned n;
    int rc = ERR_NO;

    if (input_values(&a, &n))
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

int input_values(int *number, unsigned int *n)
{
    char tmp;
    int rc;

    int success = (((rc = scanf("%d%u%c", number, n, &tmp)) != 3 && rc != EOF) || (tmp != '\n' && tmp != '\r'));

    return success;
}
