#include <stdio.h>

#define ERR_NO 0
#define ERR_INPUT 1

unsigned int cyclic_shift_number(unsigned int, int);

int main(void)
{
    unsigned int number;
    int n;
    int rc = ERR_NO;
    if ((scanf("%u%d", &number, &n) != 2) && (n < 0))
    {
        rc = ERR_INPUT;
    }

    if (rc == ERR_NO)
    {
        unsigned int new_number = cyclic_shift_number(number, n);

        for (int i = 31; i > -1; i--)
        {
            printf("%d", (new_number >> i) % 2);
        }
        printf("\n");
    }

    return rc;
}

unsigned int cyclic_shift_number(unsigned int number, int n)
{
    n = (n % 32 + 32) % 32;
    unsigned int new_number = (number >> n) | (number << (32 - n));

    return new_number;
}

