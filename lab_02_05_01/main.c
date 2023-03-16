#include <stdio.h>

#define ERR_NO 0
#define ERR_INPUT 1
#define ERR_NO_SPECS_ELMS 5

#define MAX_N 10

int input_array(int**, int**);

int evaluate_expression(int*, int*, int*);

int main()
{
	int rc = ERR_NO;
	int arr[MAX_N];
	int *arr_begin = arr;
	int *arr_end = arr;

	rc = input_array(&arr_begin, &arr_end);
	if (rc == ERR_NO)
	{
		int result;
		rc = evaluate_expression(arr_begin, arr_end, &result);
		if (rc == ERR_NO)
		{
			printf("%d\n", result);
		}
	}

	return rc;
}

int input_array(int **arr_begin, int **arr_end)
{	
	int rc = ERR_NO;

	int n;
	if (scanf("%d", &n) != 1 || n > 10 || n < 1)
	{
		rc = ERR_INPUT;
	}
	if (rc == ERR_NO)
	{
		int succesful_input = 1;
		while ((*arr_end != (*arr_begin) + n) && succesful_input)
		{
			if (scanf("%d", (*arr_end)++) != 1)
			{
				succesful_input = 0;
			}
		}

		if (!succesful_input)
		{
			rc = ERR_INPUT;
		}
	}

	return rc;
}


int evaluate_expression(int *arr_begin, int *arr_end, int *result)
{
	int rc = ERR_NO;
	*result = 0;

	int *p1 = arr_begin, *p2 = arr_end - 1;
	int has_ended = 0;
	int was_occurance = 0;
	while ((p1 != arr_end) && (p2 != arr_begin - 1) && !has_ended)
	{
		while (!(has_ended |= p1 == arr_end) && (*p1 >= 0)) 
			p1++;

		while (!(has_ended |= p2 == arr_begin - 1) && (*p2 <= 0)) 
			p2--;

		if (!has_ended)
		{
			*result += *p1 * *p2;
			was_occurance = 1;
			++p1, --p2;
		}
	}

	if (!was_occurance)
	{
		rc = ERR_NO_SPECS_ELMS;
	}

	return rc;
}
