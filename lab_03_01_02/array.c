#include <stdio.h>

#include "rc.h"
#include "array.h"

int input_array(int *arr, int *n)
{
	int rc = ERR_NO;

	if (scanf("%d", n) != 1 || *n > MAX_N_ARRAY || *n < 1)
	{
		rc = ERR_INPUT;
	}

	if (rc == ERR_NO)
	{
		int good_input = 1;
		for (int i = 0; i < *n && good_input; ++i)
		{
			good_input *= scanf("%d", (arr + i)) == 1;
		}
		if (!good_input)
		{
			rc = ERR_INPUT;
		}
	}

	return rc;
}

void print_array(int *arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", *(arr + i));
	}
	printf("\n");
}