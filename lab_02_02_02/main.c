#include <stdio.h>

#define ERR_NO 0
#define ERR_INPUT 1
#define ERR_EMPTY_NEW_ARR 2

#define MAX_N 10

int input_array(int*, int*);

int fill_new_array(int*, int*, int*, int);

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
		rc = fill_new_array(new_arr, &new_n, arr, n);
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

	if (scanf("%d", n) != 1 || *n > MAX_N || *n < 1)
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

int fill_new_array(int *new_arr, int *new_n, int *arr, int n)
{
	int rc = ERR_NO;

	*new_n = 0;
	for (int i = 0; i < n; ++i)
	{
		*(new_arr + *new_n) = *(arr + i);

		int t = *(arr + i);
		t *= (t < 0) * -1 + (t > 0) * 1;

		int first_digit, last_digit = t % 10;

		while (t)
		{
			first_digit = t % 10;
			t /= 10;
		}

		*new_n += first_digit == last_digit;
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