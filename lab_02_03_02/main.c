#include <stdio.h>

#define ERR_NO 0
#define ERR_INPUT 1
#define ERR_EMPTY_NEW_ARR 2

#define MAX_N 10

int input_array(int*, int*);

int is_square(int);

int filter_arr(int*, int*, int*, int);

void print_array(int*, int);

int main()
{
	int rc = ERR_NO;
	int arr[MAX_N];
	int n;

	rc = input_array(arr, &n);

	if (rc == ERR_NO)
	{
		int new_arr[MAX_N];
		int new_n;
		rc = filter_arr(new_arr, &new_n, arr, n);
		if (rc == ERR_NO)
		{
			print_array(new_arr, new_n);
		}
	}

	return rc;
}

int input_array(int *arr, int *n)
{
	int rc = ERR_NO;

	if (scanf("%d", n) != 1 || *n > 10 || *n < 1)
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
			rc= ERR_INPUT;
		}
	}

	return rc;
}

int is_square(int x)
{
	int l = 0, r = x + 1;
	while (r - l > 1)
	{
		int t = (r + l) / 2;
		if (t * t > x)
		{
			r = t;
		}
		else
		{
			l = t;
		}
	}

	return l * l == x;
}

int filter_arr(int* new_arr, int* new_n, int* arr, int n)
{
	int rc = ERR_NO;
	*new_n = 0;

	for (int i = 0; i < n; ++i)
	{
		if (!is_square(*(arr + i)))
		{
			*(new_arr + (*new_n)++) = *(arr + i);
		}
	}

	if (*new_n == 0)
	{
		rc = ERR_EMPTY_NEW_ARR;
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