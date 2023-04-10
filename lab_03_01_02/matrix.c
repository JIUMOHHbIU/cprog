#include <stdio.h>

#include "rc.h"
#include "matrix.h"

int input_matrix(Matrix matrix, int *n, int *m)
{
	int rc = ERR_NO;
	if (scanf("%d", n) != 1 || *n > MAX_N_MATRIX || *n < 1)
	{
		rc = ERR_INPUT;
	}

	if (scanf("%d", m) != 1 || *m > MAX_M_MATRIX || *m < 1)
	{
		rc = ERR_INPUT;
	}

	if (rc == ERR_NO)
	{
		int good_input = 1;
		for (int i = 0; i < *n && good_input; ++i)
		{
			for (int j = 0; j < *m && good_input; ++j)
			{
				good_input *= scanf("%d", *(matrix + i) + j) == 1;
			}
		}
		if (!good_input)
		{
			rc = ERR_INPUT;
		}
	}

	return rc;
}