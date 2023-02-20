#include <stdio.h>

double evaluate_approx(double, double);

int main(void)
{
    double x, epsilon;
    scanf("%lf%lf", &x, &epsilon);

    unsigned int new_number = cyclic_shift_number(number, n);

    for (int i = 31; i > -1; i--)
    {
        printf("%d", (new_number >> i) % 2);
    }
    printf("\n");

    return 0;
}

double evaluate_approx(double x, double epsilon)
{
    
}
