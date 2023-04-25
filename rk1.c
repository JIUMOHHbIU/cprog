#include <stdio.h>

#define ERR_NO 0
#define ERR_INPUT 1

#define MAX_N 12

int input_matrix(int matr[][MAX_N], int*);

void print_matrix(int matr[][MAX_N], int);

int check_all_cells(int matr[][MAX_N], int);

int main(void)
{
	int n, rc = ERR_NO;

	int matr[MAX_N][MAX_N];

	for (int i = 0; i < MAX_N; ++i)
	{
		for (int j = 0; j < MAX_N; ++j)
		{
			matr[i][j] = 0;
		}
	}

	rc = input_matrix(matr, &n);

	if (rc == ERR_NO)
	{
		int is_good_matr = check_all_cells(matr, n);
		print_matrix(matr, n);

		if (is_good_matr == 0)
		{
			printf("Good matrix\n");
		}
		else
		{
			printf("Bad matrix\n%d errors were detected\n", is_good_matr / 2);
		}
	}
	else
	{
		printf("Wrong input\n");
	}

	return rc;
}

int check_all_cells(int matr[][MAX_N], int n)
{
	int is_good_matr = 0;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (matr[i][j])
			{
				is_good_matr += !(matr[i + 1][j + 1] == 0);
				is_good_matr += !(matr[i - 1][j + 1] == 0);
				is_good_matr += !(matr[i + 1][j - 1] == 0);
				is_good_matr += !(matr[i - 1][j - 1] == 0);

				is_good_matr += !(matr[i - 1][j] == matr[i][j] || !matr[i - 1][j]);
				is_good_matr += !(matr[i + 1][j] == matr[i][j] || !matr[i + 1][j]);
				is_good_matr += !(matr[i][j - 1] == matr[i][j] || !matr[i][j - 1]);
				is_good_matr += !(matr[i][j + 1] == matr[i][j] || !matr[i][j + 1]);

				is_good_matr += ((matr[i - 1][j] || matr[i + 1][j]) && (matr[i][j - 1] || matr[i][j + 1]));

			}
		}
	}

	return is_good_matr;
}

int input_matrix(int matr[][MAX_N], int *n)
{
	int rc = ERR_NO;

	if ((scanf("%d", n) != 1) || (*n < 1) || (*n > MAX_N - 2))
	{
		rc = ERR_INPUT;
	}

	for (int i = 1; i <= *n; ++i)
	{
		for (int j = 1; j <= *n; ++j)
		{
			if (scanf("%d", *(matr + i) + j) != 1)
			{
				rc = ERR_INPUT;
			}
		}
	}

	return rc;
}

void print_matrix(int matr[][MAX_N], int n)
{
	printf("%d\n", n);

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			printf("%d ", *(*(matr + i) + j));
		}
		printf("\n");
	}
}
