#include <stdio.h>

#define ERR_NO 0

unsigned my_pow(unsigned, unsigned);

int main(void)
{
    unsigned a, n;
    scanf("%u%u", &a, &n);

    printf("%u", my_pow(a, n));
}

unsigned my_pow(unsigned a, unsigned )