#include <stdio.h>
#include <math.h>

#define ERR_NO 0

double circumstance(double, double, double, double, double, double);

int main(void)
{
    double xa, ya, xb, yb, xc, yc;
    printf("Point's coords:\n");
    scanf("%lf%lf%lf%lf%lf%lf", &xa, &ya, &xb, &yb, &xc, &yc);

    double circum = circumstance(xa, ya, xb, yb, xc, yc);

    printf("Length of triangle: %lf\n", circum);
    return ERR_NO;
}

double circumstance(double xa, double ya, double xb, double yb, double xc, double yc)
{
    return sqrt(pow(yb - ya, 2) + pow(xb - xa, 2)) +
        sqrt(pow(yc - yb, 2) + pow(xc - xb, 2)) +
        sqrt(pow(ya - yc, 2) + pow(xa - xc, 2));
}
