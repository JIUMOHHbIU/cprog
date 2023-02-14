#include <stdio.h>

#define ERR_NO 0

int main(void)
{
    double r1, r2, r3;
    scanf("%lf%lf%lf", &r1, &r2, &r3);

    double resistance = 1 / ((1 / r1) + (1 / r2) + (1 / r3));

    printf("%lf", resistance);
    return ERR_NO;
}
