#include <stdio.h>
#include <math.h>

double evaluate_approx(double, double, double);

int main(void)
{
    double x, epsilon;
    scanf("%lf%lf", &x, &epsilon);

    double fx = exp(x);
    double sx = evaluate_approx(x, epsilon, fx);

    double deviation = fabs(fx - sx);
    double normalized_deviation = fabs((fx - sx) / fx);

    printf("%lf %lf %lf %lf", sx, fx, deviation, normalized_deviation);
    printf("\n");

    return 0;
}

double evaluate_approx(double x, double epsilon, double fx)
{
    double result = 0, a_i = 1;
    for (int i = 1; fabs(a_i) >= epsilon; result += a_i, a_i *= x / i, ++i);

    return result + a_i;
}
