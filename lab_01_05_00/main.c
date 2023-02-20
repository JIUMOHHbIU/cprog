#include <stdio.h>

#define ERR_NO 0
#define ERR_INPUT 1

int my_pow(int, unsigned);

int input_integer(int *number);

int input_unsigned_integer(unsigned int *number);

int main(void)
{
    int a;
    unsigned n;
    int rc = ERR_NO;

    if (input_integer(&a))
    {
        rc = ERR_INPUT;
    }
    if (rc == ERR_NO)
    {
        if (input_unsigned_integer(&n))
        {
            rc = ERR_INPUT;
        }
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

int input_integer(int *number)
{
    char tmp;
    int rc;

    int success = (((rc = scanf("%d%c", number, &tmp)) != 2 && rc != EOF) || tmp != '\n');

    return success;
}

int input_unsigned_integer(unsigned *number)
{
    char tmp;
    int rc;

    int success = (((rc = scanf("%u%c", number, &tmp)) != 2 && rc != EOF) || tmp != '\n');

    return success;
}
