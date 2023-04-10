#include <stdio.h>

#include "rc.h"
#include "matrix.h"
#include "array.h"

void process_columns(Matrix matrix, int n, int m, int *arr)
{
	for (int j = 0; j < m; ++j)
	{
		*(arr + j) = 1;
		int value = *(*(matrix + 0) + j);

		for (int i = 1; i < n; ++i)
		{
			*(arr + j) *= value * *(*(matrix + i) + j) < 0;
			value = *(*(matrix + i) + j);
		}
	}
}

int main()
{
	Matrix matrix;
	int n, m;

	int rc = input_matrix(matrix, &n, &m);

	
	if (rc == ERR_NO)
	{
		int arr[MAX_N_ARRAY];
		process_columns(matrix, n, m, arr);
		print_array(arr, m);
	}

#ifdef DEBUG
	view_rc(rc);
#endif

	return rc;
}
