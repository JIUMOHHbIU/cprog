#include <stdio.h>

#define ERR_NO 0
#define ERR_INPUT 1
#define ERR_NO_NEG 2

#define MAX_N 10

int input_array(int*, int*);

int average_of_negs(int*, int, double*);

int main()
{
	int rc = ERR_NO;
	int arr[MAX_N];
	int n;

	rc = input_array(arr, &n);

	if (rc == ERR_NO)
	{
		double result;
		rc = average_of_negs(arr, n, &result);
		printf("%.6lf\n", result);
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

int average_of_negs(int *arr, int n, double *result)
{
	int rc = ERR_NO;
	*result = 0;

	int counter_neg = 0;
	for (int i = 0; i < n; ++i)
	{
		counter_neg += *(arr + i) < 0;
		*result += *(arr + i) * (*(arr + i) < 0);
	}

	if (counter_neg)
	{
		*result /= counter_neg;
	}
	else
	{
		rc = ERR_NO_NEG;
	}

	return rc;
}
