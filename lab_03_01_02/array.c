#include <stdio.h>

#include "rc.h"
#include "array.h"

void print_array(int *arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", *(arr + i));
	}
	printf("\n");
}