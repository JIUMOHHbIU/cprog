#include <stdio.h>

#define maxN 10

#define ERR_NO 0
#define ERR_INPUT 1
#define ERR_MAX_SIZE 2

void input(int *arr, int &rc);

int main()
{
	int arr[maxN];
	int rc = ERR_NO;

	if (rc == ERR_NO)
	{
		input(arr, &rc);
	}
	if (rc == ERR_NO)
	{

	}

	return rc;
}