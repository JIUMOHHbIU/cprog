#include <stdio.h>

#define ERR_NO 0

double resistance_of_three(double, double, double);

int main(void)
{
    double r1, r2, r3;
    printf("Enter resistances value's:\n");
    scanf("%lf%lf%lf", &r1, &r2, &r3);

    double resistance = resistance_of_three(r1, r2, r3);

    printf("Resistance of whole segment: %lf\n", resistance);
    return ERR_NO;
}

double resistance_of_three(double r1, double r2, double r3)
{
	return 1 / ((1 / r1) + (1 / r2) + (1 / r3));
}
