#include <stdio.h>
#include "consts.h"

int get_matrix(int matrix[][10], int *n, int *m)
{
	int rc = ERR_NO;

	if (scanf("%d", n) != 1 || *n > 10 || *n < 1)
	{
		rc = ERR_INPUT;
	}

	if (scanf("%d", m) != 1 || *m > 10 || *m < 1)
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

void process_columns(int matrix[][10], int n, int m, int *arr)
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

void print_array(int *arr, int n)
{
	for (int i = 0; i < n; ++i)
		printf("%d ", *(arr + i));
}

int solve()
{
	int matrix[10][10];
	int n, m;

	int rc = get_matrix(matrix, &n, &m);

	if (rc == ERR_NO)
	{
		int arr[10];
		process_columns(matrix, n, m, arr);
		print_array(arr, m);
	}

	return rc;
}
