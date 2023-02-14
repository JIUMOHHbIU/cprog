#include <stdio.h>

#define ERR_NO 0

int main(void)
{
    long global_seconds;
    scanf("%ld", &global_seconds);

    int hours, minutes, seconds;

    hours = global_seconds / 3600;
    minutes = global_seconds / 60 % 60;
    seconds = global_seconds % 60;

    printf("%d %d %d", hours, minutes, seconds);

    return ERR_NO;
}
