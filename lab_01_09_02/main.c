#include <stdio.h>
#include <math.h>

#define ERR_NO 0
#define ERR_INPUT 1

double gx(int*);

int main(void)
{
    int rc = ERR_NO;

    int success = 1;
    double gx_value = gx(&success);
    if (!success)
        rc = ERR_INPUT;

    if (rc == ERR_NO)
    {
        printf("%.6lf\n", gx_value);
    }
    return rc;
}

double gx(int *success)
{
    double x, sum = 0;
    int n = 0;
    int is_ended = 0;
    for (; (*success) && !is_ended;)
    {
        if (scanf("%lf", &x) != 1)
        {
            *success = 0;
        }
        else if (x >= 0)
            sum += sqrt(++n + x);
        else
            is_ended = 1;
    }

    *success *= n;
    return sum / n;
}
