#include <stdio.h>

#define ERR_NO 0

int hours_from_global_secs(int);

int minutes_from_global_secs(int);

int seconds_from_global_secs(int);

int main(void)
{
    long global_seconds;
    printf("Enter time in seconds:\n");
    scanf("%ld", &global_seconds);

    int hours, minutes, seconds;

    hours = hours_from_global_secs(global_seconds);
    minutes = minutes_from_global_secs(global_seconds);
    seconds = seconds_from_global_secs(global_seconds);

    printf("Time in h_m_s format: %d %d %d\n", hours, minutes, seconds);

    return ERR_NO;
}

int hours_from_global_secs(int global_seconds)
{
    return global_seconds / 3600;
}

int minutes_from_global_secs(int global_seconds)
{
    return global_seconds / 60 % 60;
}

int seconds_from_global_secs(int global_seconds)
{
    return global_seconds % 60;
}