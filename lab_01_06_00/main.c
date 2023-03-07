#include <stdio.h>
#include <math.h>

#define ERR_NO 0
#define ERR_INPUT 1
#define ERR_IMPOSSIBLE_TRIANGLE 2

#define EPS 1e-6

int type_of_triangle(double, double, double, double, double, double);

double distance(double, double, double, double);

void swap(double *, double *);

int main(void)
{
    double xa, ya, xb, yb, xc, yc;
    int rc = ERR_NO;

    printf("Enter vertex coords:\n");
    if (scanf("%lf%lf%lf%lf%lf%lf", &xa, &ya, &xb, &yb, &xc, &yc) != 6)
    {
        rc = ERR_INPUT;
    }

    int type = -1;
    if (rc == ERR_NO)
    {
        type = type_of_triangle(xa, ya, xb, yb, xc, yc);
    }
    if (type == -1)
        rc = ERR_IMPOSSIBLE_TRIANGLE;

    if (rc == ERR_NO)
    {
        printf("Type of triangle: %d\n", type);
    }

    return rc;
}

void swap(double *a, double *b)
{
    double t = *a;
    *a = *b;
    *b = t;
}

int type_of_triangle(double xa, double ya, double xb, double yb, double xc, double yc)
{
    int type;

    double ba, cb, ac;
    ba = distance(xb, yb, xa, ya);
    cb = distance(xc, yc, xb, yb);
    ac = distance(xa, ya, xc, yc);

    if (ba > cb)
        swap(&ba, &cb);
    if (ac > cb)
        swap(&cb, &ac);

    if (fabs(ba + ac - cb) < EPS)
    {
        type = -1;
    }
    else
    {
        if (fabs(cb * cb - ba * ba - ac * ac) < EPS)
        {
            type = 1;
        }
        else if (cb * cb > ba * ba + ac * ac)
        {
            type = 2;
        }
        else
        {
            type = 0;
        }
    }

    return type;
}

double distance(double xa, double ya, double xb, double yb)
{
    double result = sqrt((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb));

    return result;
}
