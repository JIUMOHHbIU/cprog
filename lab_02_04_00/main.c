#include <stdio.h>

#define ERR_NO 0
#define ERR_INPUT 1
#define ERR_SPECIAL_OVERFLOW 100

#define MAX_N 10

int input_array_terminal_char(int*, int*);

void bubble_sort(int*, int);

void print_array(int*, int);

int main()
{
	int rc = ERR_NO;
	int arr[MAX_N];
	int n;

	rc = input_array_terminal_char(arr, &n);

	if (rc == ERR_NO || rc == ERR_SPECIAL_OVERFLOW)
	{
		bubble_sort(arr, n);
		print_array(arr, n);
	}

	return rc;
}

int input_array_terminal_char(int *arr, int *n)
{
	int rc = ERR_NO;
	*n = 0;
	int t;
	int bad_seq = 0;

	while (scanf("%d", &t) == 1)
	{
		if (*n > MAX_N - 1)
		{
			bad_seq = 1;
		}
		else
		{
			*(arr + (*n)++) = t;
		}
	}

	if (bad_seq)
	{
		rc = ERR_SPECIAL_OVERFLOW;
	}
	if (*n == 0)
	{
		rc = ERR_INPUT;
	}

	return rc;
}

void bubble_sort(int *arr, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = 0; j < n - i - 1; ++j)
		{
			if (*(arr + j) > *(arr + j + 1))
			{
				int t = *(arr + j);
				*(arr + j) = *(arr + j + 1);
				*(arr + j + 1) = t;
			}
		}
	}
}

void print_array(int *arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", *(arr + i));
	}
	printf("\n");
}