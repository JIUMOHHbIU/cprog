#include <stdio.h>
#include <math.h>

#define ERR_NO 0

int main(void)
{
    double xa, ya, xb, yb, xc, yc;
    scanf("%lf%lf%lf%lf%lf%lf", &xa, &ya, &xb, &yb, &xc, &yc);


    printf("Периметр треугольника: %lf", circum);
    return ERR_NO;
}

double area_trig(double xa, double ya, double xb, double yb, double xc, double yc)
{
    double area;
    double BA = sqrt(pow(yb - ya, 2) + pow(xb - xa, 2)),
           CB = sqrt(pow(yc - yb, 2) + pow(xc - xb, 2)),
           AC = sqrt(pow(ya - yc, 2) + pow(xa - xc, 2));

    double circum_half = (BA + CB + AC) / 2;

    area = sqrt(circum_half * (circum_half - BA) * (circum_half - CB) * (circum_half - AC));

    return area;
}

